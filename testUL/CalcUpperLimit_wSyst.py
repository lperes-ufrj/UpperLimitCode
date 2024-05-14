import math
import random
import numpy as np
import matplotlib.pyplot as plt

from scipy.stats import poisson
from scipy.stats import norm
from scipy.integrate import nquad 

BACKGROUND_SYST_UC = 0.3
EFF_SYST_UC = 0.1
N_THROWS=1000
N_BINS = 40

# Number of target Argon nuclei and livetime of DUNE
NA_dune = 4 * 1.5e32             # 40 kton
livetime_dune = 10.0 * 3.154e7   # 10 years

# BDM flux / g_Z' ^ 4
flux_list = [634.1, 303.6, 117.7, 36.38, 468.3, 203.4, 72.48, 19.10, 28.12, 7.521, 2.455, 0.431]
#argon cross section / g_Z' ^ 4
xsec_list = [9.057 * 1e-30, 1.063 * 1e-29, 1.220 * 1e-29, 1.278 * 1e-29, 4.978 * 1e-29, 5.609 * 1e-29, 5.965 * 1e-29, 6.152 * 1e-29, 1.270 * 1e-27, 1.377 * 1e-27, 1.437 * 1e-27, 1.470 * 1e-27]

#txt files with signal strength, expected background and signal efficiency for each nuclear configuration model
infiles = ['Eff_Bkg_hA_BR.txt', 'Eff_Bkg_hA_ESF.txt', 'Eff_Bkg_hA_LFG.txt', 'Eff_Bkg_hN_BR.txt', 'Eff_Bkg_hN_ESF.txt', 'Eff_Bkg_hN_LFG.txt']

#function to read the list of txt files
def readtxt(infile_array):
    listloaded = []
    for infile in infile_array:
        listloaded.append(np.loadtxt(infile, usecols=(3,4), skiprows=1))
    return listloaded

#poi = 0 # parameter of interest ===> g_Z'^8 
#def std_limits(histo, num_sigmas):


optimals = readtxt(infiles) # read values from the optimal cuts
#print(optimals)r'LLR$_{Only-BG}$'

num_targets_array = np.arange(0.95*NA_dune,1.05*NA_dune,0.005*NA_dune)

for index, optimal_Eff in enumerate(optimals): #Each nuclear configuration model
    #to test
    if index != 0: 
        break
    
    
    #print(optimal_Eff)
    #OUTPUT_FILE = open("Sens_"+ infiles[index] ,"w")
    #OUTPUT_FILE.write('indexSample\t ExpSigEvts\t BkgEvts\t CentralBkgEvts\t Eff\t CentralEff\t Numtargets_tmp\t Probability\n')
    for i in range(12): #Each BDM sample gamma and mass value 
  
        if i != 0: 
            break

        poi = []
        mean_bg = []
        std_bg = []
        mean_sig = []
        SoverB = []

        b = round(3*math.sqrt(optimal_Eff[i][1]))# number of expected Bkg
        eff = optimal_Eff[i][0] # Signal Efficiency

        B_syst = np.random.normal(b,BACKGROUND_SYST_UC*b,N_THROWS)
        B_syst = np.round(B_syst)
        B_syst = B_syst[B_syst>0]
        print(b)

        for s in range(1,120):
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
            #print(Q_0)
            #print(Q_1)
            nllr_h0 = np.minimum(500., np.maximum(-500., -2*np.log(Q_0)))
            nllr_h1 = np.minimum(500., np.maximum(-500., -2*np.log(Q_1)))
            np_nllr_h0, bins_nllr_h0 = np.histogram(nllr_h0, density=True, bins=N_BINS)
            np_nllr_h1, bins_nllr_h1 = np.histogram(nllr_h1, density=True, bins=N_BINS)
            
            #print(most_prob_value)
            mean_bkg_only = nllr_h0.mean()
            std_bkg_only = nllr_h0.std()
            #print(s)

            mean_bg.append(mean_bkg_only)
            std_bg.append(std_bkg_only)
            mean_sig.append(nllr_h1.mean())
            SoverB.append(float(s/b))

            if( s % 10 ==0):
                plt.figure(dpi=300)
                plt.title(f'S: {s:.0f} B: {b:.0f}')
                plt.hist(nllr_h0, bins=N_BINS, histtype='step', label="Only Background")
                plt.hist(nllr_h1, bins=N_BINS, histtype='step', label= "S+B")
                plt.axvline(x = mean_bkg_only+std_bkg_only,ls='--' ,color = 'g', label = r'$\pm 1\sigma$')
                plt.axvline(x = mean_bkg_only-std_bkg_only,ls='--' ,color = 'g')
                plt.axvline(x = mean_bkg_only+2*std_bkg_only,ls='--', color = 'r')
                plt.axvline(x = mean_bkg_only-2*std_bkg_only,ls='--', color = 'r', label = r'$\pm 2\sigma$')
                plt.axvline(x = mean_bkg_only,ls='--', color = 'gray', label = 'Mean - Only BG')

                plt.legend(title = f'Background UC {BACKGROUND_SYST_UC:.1f}')
                plt.savefig(f'plots/Sens_s{s:.0f}_'+infiles[index]+'_new.pdf', format='pdf', dpi=600)
            #plt.show()
        #np.savetxt(OUTPUT_FILE,result.reshape(1, result.shape[0]), fmt ='%.5e')

        fig, ax = plt.subplots(dpi=300)
        #plt.title(f'S: {s:.0f} B: {b:.0f}')

        poi = np.array(poi)
        mean_bg = np.array(mean_bg)
        mean_sig = np.array(mean_sig)
        std_bg = np.array(std_bg)
        SoverB = np.array(SoverB)

        #print(poi,
         #   mean_bg,
         #   mean_sig,
         #   std_bg)


        ax.plot(poi,mean_bg,linestyle='--', label = r'NLLR$_{BG-Only}$')
        plt.xlabel(r"$g_{Z'}^8$", fontsize = 15)
        plt.ylabel('NLLR', fontsize = 15)
        ax.plot(poi,mean_sig,linestyle='--', label = r'NLLR$_{S+B}$')
        ax.text(0,-75, r'$\gamma = 1.1$, hA+BR', fontsize=14)
        ax.fill_between(poi,mean_bg-std_bg, mean_bg+std_bg,alpha=0.5,label = r'$\pm 1\sigma$')
        
        ax.fill_between(poi,mean_bg-2*std_bg, mean_bg+2*std_bg,alpha=.5,label = r'$\pm 2\sigma$')
        ax2 = ax.twiny()
        ax2.plot(SoverB, mean_bg)
        ax2.set_xlabel("S/B")
        ax.legend(title = fr'Atm$-\nu$ Flux Unc. {BACKGROUND_SYST_UC*100:.0f}%', loc='upper left')
        fig.savefig(f'plots/LLR_s{s:.0f}_'+infiles[index]+'_new.pdf', format='pdf', dpi=600)


        
print("Finished!")
        
