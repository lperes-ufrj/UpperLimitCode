import math
import random
import numpy as np
import matplotlib.pyplot as plt

from scipy.stats import poisson
from scipy.stats import norm
from scipy.integrate import nquad 

plt.rcParams['text.usetex'] = True


BACKGROUND_SYST_UC = 0.3
EFF_SYST_UC = 0.1
N_THROWS=1000
N_BINS = 40
STD_TO_90CL_SCALE = 1.318295

# Number of target Argon nuclei and livetime of DUNE
NA_dune = 4 * 1.5e32             # 40 kton
livetime_dune = 10.0 * 3.154e7   # 10 years

# BDM flux / g_Z' ^ 4
flux_list = [634.1, 303.6, 117.7, 36.38, 468.3, 203.4, 72.48, 19.10, 28.12, 7.521, 2.455, 0.431]
#argon cross section / g_Z' ^ 4
xsec_list = [9.057 * 1e-30, 1.063 * 1e-29, 1.220 * 1e-29, 1.278 * 1e-29, 4.978 * 1e-29, 5.609 * 1e-29, 5.965 * 1e-29, 6.152 * 1e-29, 1.270 * 1e-27, 1.377 * 1e-27, 1.437 * 1e-27, 1.470 * 1e-27]

#txt files with signal strength, expected background and signal efficiency for each nuclear configuration model
infiles = ['Eff_Bkg_hA_BR.txt', 'Eff_Bkg_hA_ESF.txt', 'Eff_Bkg_hA_LFG.txt', 'Eff_Bkg_hN_BR.txt', 'Eff_Bkg_hN_ESF.txt', 'Eff_Bkg_hN_LFG.txt']

#Sample labels
labelsamples= ["b1p1_m05","b1p1_m10","b1p1_m20","b1p1_m40","b1p5_m05","b1p5_m10","b1p5_m20","b1p5_m40","b10_m05","b10_m10","b10_m20","b10_m40"]
#function to read the list of txt files
def readtxt(infile_array):
    listloaded = []
    for infile in infile_array:
        listloaded.append(np.loadtxt(infile, usecols=(3,4), skiprows=1))
    return listloaded

optimals = readtxt(infiles) # read values from the optimal cuts

#num_targets_array = np.arange(0.95*NA_dune,1.05*NA_dune,0.005*NA_dune)

for index, optimal_Eff in enumerate(optimals): #Each nuclear configuration model
    #to test just the first nuclear model
    if index != 0: 
        break
    
    for i in range(12): #Each BDM sample gamma and mass value 
        if i != 0: 
            break

        poi = [] #parameter of interest --> g_Z'^8

        median_bkg_only_arr = [] # array (list) of the median background-only distribution (-2*ln Q_{BG_Only}) 
        std_bkg_only_arr = [] # array (list) of the std of the background-only distribution (-2*ln Q_{BG_Only})
        median_signal_bkg_arr = [] # array (list) of the median S+B distribution (-2*ln Q_{S+B}) 
        std_signal_bkg_arr = [] # array (list) of the std of the S+B distribution (-2*ln Q_{S+B})
        SoverB = [] # array (list) of the signal background ratio for each number of signal (fixed B)

        b = round(3*math.sqrt(optimal_Eff[i][1]))# number of expected Bkg --> 3 std away from statistical fluctuations
        eff = optimal_Eff[i][0] # Signal Efficiency

        B_syst = np.random.normal(b,BACKGROUND_SYST_UC*b,N_THROWS) # Throw the background number inside a systematic un.
        B_syst = np.round(B_syst) # take it as integer number
        B_syst = B_syst[B_syst>0] # Physical cut, only positive background events.
        
        #print(b)

        for s in range(1,120): #Assumes the number of signal events
            poi.append(s/(NA_dune*xsec_list[i]*livetime_dune*flux_list[i]*eff)) 
            H_0 = np.random.poisson(B_syst[0],N_THROWS)
            H_1 = np.random.poisson(B_syst[0]+s,N_THROWS)
            for bi in B_syst[1:]:
                h0_i = np.random.poisson(bi,N_THROWS)
                H_0 = np.concatenate((H_0,h0_i))
                h1_i = np.random.poisson(bi+s,N_THROWS)
                H_1 = np.concatenate((H_1,h1_i))
            Q_0 = poisson.pmf(H_0, s+b)/poisson.pmf(H_0, b)
            Q_1 = poisson.pmf(H_1, s+b)/poisson.pmf(H_1, b)


            nllr_h0 = np.minimum(500., np.maximum(-500., -2*np.log(Q_0)))
            nllr_h1 = np.minimum(500., np.maximum(-500., -2*np.log(Q_1)))
            np_nllr_h0, bins_nllr_h0 = np.histogram(nllr_h0, density=True, bins=N_BINS)
            np_nllr_h1, bins_nllr_h1 = np.histogram(nllr_h1, density=True, bins=N_BINS)
            
            median_bkg_only = np.median(nllr_h0) #check for medium 
            std_bkg_only = nllr_h0.std() 
            median_signal_bkg = np.median(nllr_h1)
            std_signal_bkg = nllr_h0.std() 


            median_bkg_only_arr.append(median_bkg_only)
            std_bkg_only_arr.append(std_bkg_only)
            median_signal_bkg_arr.append(median_signal_bkg)
            std_signal_bkg_arr.append(std_signal_bkg)
            SoverB.append(float(s/b))

            if( s % 10 ==0):
                plt.figure(dpi=300)
                plt.title(f'S: {s:.0f} B: {b:.0f}')
                plt.hist(nllr_h0, bins=N_BINS, histtype='step', label="Only Background")
                plt.hist(nllr_h1, bins=N_BINS, histtype='step', label= "S+B")
                plt.axvline(x = median_bkg_only+STD_TO_90CL_SCALE*std_bkg_only,ls='--' ,color = 'g', label = r'$\pm 1\sigma$')
                plt.axvline(x = median_bkg_only-STD_TO_90CL_SCALE*std_bkg_only,ls='--' ,color = 'g')
                plt.axvline(x = median_signal_bkg+STD_TO_90CL_SCALE*std_bkg_only,ls='--', color = 'r')
                plt.axvline(x = median_signal_bkg-STD_TO_90CL_SCALE*std_bkg_only,ls='--', color = 'r', label = r'$\pm 2\sigma$')
                plt.axvline(x = median_bkg_only,ls='--', color = 'gray', label = 'Mean - Only BG')
                plt.axvline(x = median_signal_bkg, ls='--',color='blue', label ='Mean - S+B')

                plt.legend(title = f'Background UC {BACKGROUND_SYST_UC:.1f}')
                plt.savefig(f'plots/Sens_s{s:.0f}_'+infiles[index]+'_'+labelsamples[i]+'.pdf', format='pdf', dpi=600)
            #plt.show()
        #np.savetxt(OUTPUT_FILE,result.reshape(1, result.shape[0]), fmt ='%.5e')


        #plt.title(f'S: {s:.0f} B: {b:.0f}')

        poi = np.array(poi)

        median_bkg_only_arr = np.array(median_bkg_only_arr)
        std_bkg_only_arr = np.array(std_bkg_only_arr)
        median_signal_bkg_arr = np.array(median_signal_bkg_arr)
        std_signal_bkg_arr = np.array(std_signal_bkg_arr)
        SoverB = np.array(SoverB)

        ################################################################
        #          PLOT FIGURE        S+B WITH 90%CL LIMITS            #
        ################################################################

        fig, ax = plt.subplots(dpi=300)
        ax.plot(poi,median_bkg_only_arr,linestyle='--', label = r'NLLR$_{BG-Only}$')
        plt.xlabel(r"$g_{Z'}^8$", fontsize = 15)
        plt.ylabel('NLLR', fontsize = 15)
        ax.plot(poi,median_signal_bkg_arr,linestyle='--', label = r'NLLR$_{S+B}$', color = 'red')
        #ax.text(0,-75, r'$\gamma = 1.1$, hA+BR', fontsize=14)
        ax.fill_between(poi,median_signal_bkg_arr-std_signal_bkg_arr, median_signal_bkg_arr+std_signal_bkg_arr,alpha=0.5,label = r'$\pm 1\sigma$')
        ax.fill_between(poi,median_signal_bkg_arr-(STD_TO_90CL_SCALE*std_signal_bkg_arr), median_signal_bkg_arr+(STD_TO_90CL_SCALE*std_signal_bkg_arr),alpha=.5,label = r'$90\% C.L.$')
        ax2 = ax.twiny()
        ax2.plot(SoverB, median_signal_bkg_arr, color = 'red')
        ax2.set_xlabel("S/B")
        ax.legend(title = r'$\gamma = 1.1, \quad m_\chi = 5 \textrm{ GeV ,hA+BR}$', loc='lower left')
        fig.savefig(f'plots/S_PLUS_B_LLR_s{s:.0f}_'+infiles[index]+'_'+labelsamples[i]+'.pdf', format='pdf', dpi=600)

        ################################################################
        #          PLOT FIGURE      BG ONLY WITH 90%CL LIMITS          #
        ################################################################


        fig, ax = plt.subplots(dpi=300)
        ax.plot(poi,median_bkg_only_arr,linestyle='--', label = r'NLLR$_{BG-Only}$')
        plt.xlabel(r"$g_{Z'}^8$", fontsize = 15)
        plt.ylabel('NLLR', fontsize = 15)
        ax.plot(poi,median_signal_bkg_arr,linestyle='--', label = r'NLLR$_{S+B}$', color = 'red')
        #ax.text(0,-75, r'$\gamma = 1.1$, hA+BR', fontsize=14)
        ax.fill_between(poi,median_bkg_only_arr-std_bkg_only_arr, median_bkg_only_arr+std_bkg_only_arr,alpha=0.5,label = r'$\pm 1\sigma$')
        ax.fill_between(poi,median_bkg_only_arr-(STD_TO_90CL_SCALE*std_bkg_only_arr), median_bkg_only_arr+(STD_TO_90CL_SCALE*std_bkg_only_arr),alpha=.5,label = r'$90\% C.L.$')
        ax2 = ax.twiny()
        ax2.plot(SoverB, median_bkg_only_arr)
        ax2.set_xlabel("S/B")
        ax.legend(title = r'$\gamma = 1.1,\quad m_\chi = 5 \textrm{ GeV, hA+BR}$', loc='upper left')
        fig.savefig(f'plots/BG_ONLY_LLR_s{s:.0f}_'+infiles[index]+'_'+labelsamples[i]+'.pdf', format='pdf', dpi=600)


        
print("Finished!")
        
