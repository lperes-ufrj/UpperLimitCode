import math
import random
import numpy as np
import matplotlib.pyplot as plt

from scipy.stats import poisson
from scipy.stats import norm
from scipy.integrate import nquad 

plt.rcParams['text.usetex'] = True


BACKGROUND_SYST_UC = 0.01
EFF_SYST_UC = 0.1
NA_DUNE_UC = 0.01
N_THROWS=500
N_BINS = 40
STD_TO_90CL_SCALE = 1.318295
DECIMALS_PRECISION = 2

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
    return np.array(listloaded)

optimals = readtxt(infiles) # read values from the optimal cuts

#optimals === first collumn nuclear model 
#==== second collumn BDM sample 
#==== third collumn firt entry overall signal efficiency second entry expected background number



for i in range(9,12): #Each BDM sample gamma and mass value 

    if i !=9:
        break
    #OUTPUT_FILE =open("Sens_"+ infiles[i] ,"w") 

    poi = [] #parameter of interest --> g_Z'^8
    median_bkg_only_arr = [] # array (list) of the median background-only distribution (-2*ln Q_{BG_Only}) 
    std_bkg_only_arr = [] # array (list) of the std of the background-only distribution (-2*ln Q_{BG_Only})
    median_signal_bkg_arr = [] # array (list) of the median S+B distribution (-2*ln Q_{S+B}) 
    per95_signal_bkg_arr = []
    per5_signal_bkg_arr = []
    std_signal_bkg_arr = [] # array (list) of the std of the S+B distribution (-2*ln Q_{S+B})
    SoverB = [] # array (list) of the signal background ratio for each number of signal (fixed B)
    

    b_cv = round(optimals[0][i][1])# number of expected Bkg -- Defaulf model hA_BR (CentralValue)
    eff_cv = optimals[0][i][0] # Signal Efficiency -- Default model hA_BR (CentralValue)
    
    nm_shift = np.random.randint(0,6,size=N_THROWS) #Throw nuclear model
    eff_syst = np.random.normal(eff_cv,EFF_SYST_UC*eff_cv,N_THROWS) # Throw the overall efficiency inside a systematic un.
    B_syst = np.random.normal(b_cv,BACKGROUND_SYST_UC*b_cv,N_THROWS) # Throw the background number inside a systematic un.
    NA_dune_syst = np.random.normal(NA_dune,NA_dune*NA_DUNE_UC, N_THROWS) #Throw the number of targets (Fiducial Mass) inside a systematic un.
    
    shifts_b_eff=[]

    for nuclear_model in range(N_THROWS):
        shifts_b_eff.append(optimals[nm_shift[nuclear_model]][i][:]/optimals[0][i][:])

    shifts_b_eff = np.array(shifts_b_eff)
    #print(shifts_b_eff)
    #print(shifts_b_eff[:,0])

    eff_syst = shifts_b_eff[:,0]*eff_syst
    eff_syst = eff_syst[eff_syst>0] # Physical cut, only positive background events.

    plt.figure(dpi=300)
    plt.hist(eff_syst, bins = 50, label='eff throws syst.')
    plt.xlabel(r'Overall signal efficiency throw $\epsilon_{Ar}$')
    plt.savefig('plots/eff_syst_'+labelsamples[i]+'.pdf', format='pdf', dpi=600)
    plt.close()

    B_syst = np.round(B_syst) # take it as integer number
    B_syst = (NA_dune_syst/NA_dune)*shifts_b_eff[:,1]*B_syst
    
    B_syst = B_syst[B_syst>0] # Physical cut, only positive background events.
    print(B_syst.size, eff_syst.size)

    plt.figure(dpi=300)
    plt.hist(B_syst, bins = 50, label='bkg number throws syst.')
    plt.xlabel(r'Expected Background Events ($b$) Throw')
    plt.savefig('plots/bkg_syst_'+labelsamples[i]+'.pdf', format='pdf', dpi=600)
    plt.close()


   # if i < 4:
   #     poi = np.logspace(-6.5,-5.3,num=200, base=10)
   # if i > 3 and i < 8:
   #     poi = np.logspace(-7.5,-6.2,num=150, base=10)
   # if i > 7:
   #     poi = np.logspace(-7.,-6.,num=900, base=10)

    poi = np.linspace(1.e-8,1.3e-6,1200)


    for gz4 in poi: #Assumes the number of signal events

        #print(gz4)
        S_syst = NA_dune_syst*xsec_list[i]*livetime_dune*flux_list[i]*eff_syst*(gz4**2) 
        #print(S_syst)
        s_cv = NA_dune*xsec_list[i]*livetime_dune*flux_list[i]*eff_cv*(gz4**2) 
        #print((gz4**2))
        #print(s_cv)
        H_0 = np.random.poisson(B_syst[0],N_THROWS)
        H_1 = np.random.poisson(B_syst[0]+S_syst[0],N_THROWS)
        for index, bi in enumerate(B_syst[1:]):
            h0_i = np.random.poisson(bi,N_THROWS)
            H_0 = np.concatenate((H_0,h0_i))
            h1_i = np.random.poisson(bi+S_syst[index],N_THROWS)
            H_1 = np.concatenate((H_1,h1_i))
        Q_0 = poisson.pmf(H_0, s_cv+b_cv)/poisson.pmf(H_0, b_cv)
        Q_1 = poisson.pmf(H_1, s_cv+b_cv)/poisson.pmf(H_1, b_cv)
        nllr_h0 = np.minimum(10000., np.maximum(-10000., -2*np.log(Q_0)))
        nllr_h1 = np.minimum(10000., np.maximum(-10000., -2*np.log(Q_1)))
        #nllr_h0 = -2*np.log(Q_0)
        #nllr_h1 = -2*np.log(Q_1)
        
 

    ################################################################
    #          CENTRAL VALUE          --  PRINT AND SAVE           #
    ################################################################
        
        median_bkg_only = np.median(nllr_h0) #check for medium 
        std_bkg_only = nllr_h0.std()    
        median_signal_bkg = np.median(nllr_h1)
        std_signal_bkg = nllr_h1.std() 

        per5_signal_bkg = np.percentile(nllr_h1,5)
        per95_signal_bkg = np.percentile(nllr_h1,95)

    ################################################################
    #          BANDS LIMITS          --  PRINT AND SAVE            #
    ################################################################


        upband_onesigma_bkg_only = np.percentile(nllr_h0,84) #CL_b = (.68/2)+.5= 0.84
        upband_twosigma_bkg_only = np.percentile(nllr_h0,98) #CL_b = (.95/2)+.5= 0.975
        upband_onesigma_bkg_signal = np.percentile(nllr_h1,99) #0.1 = CL_{s+b}/0.84 ==> CL_{s+b} = 0.084
        upband_twosigma_bkg_signal = np.percentile(nllr_h1,99) #0.1 = CL_{s+b}/0.975 ==> CL_{s+b}  = 0.0975
        
        lowband_onesigma_bkg_only = np.percentile(nllr_h0,16) #CL_b = 1-((.68/2)+.5)= 1-0.84 = 0.16
        lowband_twosigma_bkg_only = np.percentile(nllr_h0,3) #CL_b = 1-((.95/2)+.5)= 1-0.975 = 0.025
        lowband_onesigma_bkg_signal = np.percentile(nllr_h1,98) #0.1 = CL_{s+b}/0.16 ==> CL_{s+b} = 0.016
        lowband_twosigma_bkg_signal = np.percentile(nllr_h1,99) #0.1 = CL_{s+b}/0.025 ==> CL_{s+b}  = 0.0025
        
        
        plot_flag = False
        cl_sb = per95_signal_bkg

        if (np.round(per95_signal_bkg,DECIMALS_PRECISION)==np.round(median_bkg_only,DECIMALS_PRECISION)):
            print("============= g_Z'^4 BANDS ==============\n")
            print("====== CENTRAL VALUE ========\n")
            print(gz4)
            plot_flag = True
            cl_sb = per95_signal_bkg
        if (np.round(upband_onesigma_bkg_only,DECIMALS_PRECISION) == np.round(upband_onesigma_bkg_signal,DECIMALS_PRECISION)):
            print(" + 1 sigma: \n")
            print(gz4)
            plot_flag = True
            cl_sb = upband_onesigma_bkg_signal
        if (np.round(upband_twosigma_bkg_only,DECIMALS_PRECISION) == np.round(upband_twosigma_bkg_signal,DECIMALS_PRECISION)):
            print(" + 2 sigma: \n")
            print(gz4)
            plot_flag = True
            cl_sb = upband_twosigma_bkg_signal
        if (np.round(lowband_onesigma_bkg_only,DECIMALS_PRECISION) == np.round(lowband_onesigma_bkg_signal,DECIMALS_PRECISION)):
            print(" - 1 sigma: \n")
            print(gz4)
            plot_flag = True
            cl_sb = lowband_onesigma_bkg_signal
        if (np.round(lowband_twosigma_bkg_only,DECIMALS_PRECISION) == np.round(lowband_twosigma_bkg_signal,DECIMALS_PRECISION)):
            print("- 2 sigma: \n")
            print(gz4)
            plot_flag = True
            cl_sb = lowband_twosigma_bkg_signal

        median_bkg_only_arr.append(median_bkg_only)
        std_bkg_only_arr.append(std_bkg_only)
        median_signal_bkg_arr.append(median_signal_bkg)
        std_signal_bkg_arr.append(std_signal_bkg)
        per5_signal_bkg_arr.append(per5_signal_bkg)
        per95_signal_bkg_arr.append(per95_signal_bkg)
        SoverB.append(s_cv/b_cv)

        #print(nllr_h0.size,nllr_h1.size)
        
        if(plot_flag):
            plt.figure(dpi=300)
            plt.title(fr'$log(g_Z^4)$: {math.log(gz4):.6f} B: {b_cv:.0f}')
            plt.hist(nllr_h0, bins=N_BINS, histtype='step', label="Only Background")

            # Create the histogram
            counts, bins, patches = plt.hist(nllr_h1, bins=N_BINS, histtype='step', color = 'red',label= "S+B")
            
            # Define the vertical line
            vline = cl_sb # Example value for the vertical line
            #plt.axvline(vline, color='r', linestyle='-')
            
            # Fill the area to the right of the vertical line
            for j in range(len(bins) - 1):
                if bins[j] >= vline:
                    plt.fill_between([bins[j], bins[j+1]], 0, counts[j], color='red', alpha=1.)
                elif bins[j] < vline < bins[j+1]:
                    plt.fill_between([vline, bins[j+1]], 0, counts[j], color='red', alpha=1.,label = r'CL$_{s+b}$')

            plt.axvline(x = median_bkg_only,ls='--', color = 'gray', label = 'Median - Only BG')

            plt.axvline(x = upband_onesigma_bkg_only, ls='--',color='blue', label =r'$\pm 1 \sigma$')
            #plt.axvline(x = upband_twosigma_bkg_only, ls='--',color='blue', label =r'$+2 \sigma$')
            plt.axvline(x = lowband_onesigma_bkg_only, ls='--',color='blue')
            #plt.axvline(x = lowband_twosigma_bkg_only, ls='--',color='blue', label =r'$-2 \sigma$')

            plt.legend(title = f'Background UC {BACKGROUND_SYST_UC:.2f}')
            plt.savefig(f'plots/new_Sens_s{s_cv:.0f}_'+labelsamples[i]+'_wNASyst.pdf', format='pdf', dpi=600)
            #print("Printed!")
            plt.close()  

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
    plt.xlabel(r"$g_{Z^{\prime}}^4$", fontsize = 15)
    plt.ylabel('NLLR', fontsize = 15)
    ax.plot(poi,median_signal_bkg_arr,linestyle='--', label = r'NLLR$_{S+B}$', color = 'red')

    ax.fill_between(poi,median_signal_bkg_arr-std_signal_bkg_arr, median_signal_bkg_arr+std_signal_bkg_arr,alpha=0.5,label = r'$\pm 1\sigma$')
    ax.fill_between(poi,per5_signal_bkg_arr,per95_signal_bkg_arr,alpha=.5,label = r'$90\% C.L.$')

    ax.legend(title = r'$\gamma = 10,\; m_\chi = 10 \textrm{ GeV ,hA+BR}$', loc='lower left')
    fig.savefig(f'plots/new_S_PLUS_B_LLR_s{s_cv:.0f}_'+labelsamples[i]+'_wNASyst.pdf', format='pdf', dpi=600)
    plt.close()  

    ################################################################
    #          PLOT FIGURE      BG ONLY WITH 90%CL LIMITS          #
    ################################################################
    fig, ax = plt.subplots(dpi=300)
    ax.plot(poi,median_bkg_only_arr,linestyle='--', label = r'NLLR$_{BG-Only}$')
    plt.xlabel(r"$g_{Z^{\prime}}^4$", fontsize = 15)
    plt.ylabel('NLLR', fontsize = 15)
    ax.plot(poi,median_signal_bkg_arr,linestyle='--', label = r'NLLR$_{S+B}$', color = 'red')
    #ax.text(0,-75, r'$\gamma = 1.1$, hA+BR', fontsize=14)
    ax.fill_between(poi,median_bkg_only_arr-std_bkg_only_arr, median_bkg_only_arr+std_bkg_only_arr,alpha=0.5,label = r'$\pm 1\sigma$')
    ax.fill_between(poi,median_bkg_only_arr-(STD_TO_90CL_SCALE*std_bkg_only_arr), median_bkg_only_arr+(STD_TO_90CL_SCALE*std_bkg_only_arr),alpha=.5,label = r'$90\% C.L.$')

    ax.legend(title = r'$\gamma = 10,\quad m_\chi = 10 \textrm{ GeV, hA+BR}$', loc='upper left')
    fig.savefig(f'plots/new_BG_ONLY_LLR_s{s_cv:.0f}_'+labelsamples[i]+'_wNASyst.pdf', format='pdf', dpi=600)
    plt.close()  

    ################################################################
    #          PLOT FIGURE      Upperlimit S = 89                  #
    ################################################################

    # fig, ax = plt.subplots(dpi=300)
    # ax.plot(sig,median_bkg_only_arr,linestyle='--', label = r'NLLR$_{BG-Only}$')
    # plt.xlabel(r"$g_{Z'}^8$", fontsize = 15)
    # plt.ylabel('NLLR', fontsize = 15)
    # ax.plot(sig,median_signal_bkg_arr,linestyle='--', label = r'NLLR$_{S+B}$', color = 'red')
    # #ax.text(0,-75, r'$\gamma = 1.1$, hA+BR', fontsize=14)
    # ax.fill_between(sig,median_bkg_only_arr-std_bkg_only_arr, median_bkg_only_arr+std_bkg_only_arr,alpha=0.5,label = r'$\pm 1\sigma$')
    # ax.fill_between(sig,median_bkg_only_arr-(STD_TO_90CL_SCALE*std_bkg_only_arr), median_bkg_only_arr+(STD_TO_90CL_SCALE*std_bkg_only_arr),alpha=.5,label = r'$90\% C.L.$')
    # ax2 = ax.twiny()
    # ax2.plot(SoverB, median_bkg_only_arr)
    # ax2.set_xlabel("S/B")
    # ax.legend(title = r'$\gamma = 1.1,\quad m_\chi = 5 \textrm{ GeV, hA+BR}$', loc='upper left')
    # fig.savefig(f'plots/new_BG_ONLY_LLR_s{s_cv:.0f}_'+labelsamples[i]+'.pdf', format='pdf', dpi=600)
    # plt.close()  

    ################################################################
    #          PLOT FIGURE      Upperlimit S = 89                  #
    ################################################################

    # fig, ax = plt.subplots(dpi=300)
    # ax.plot(sig,median_bkg_only_arr,linestyle='--', label = r'NLLR$_{BG-Only}$')
    # plt.xlabel(r"$g_{Z'}^8$", fontsize = 15)
    # plt.ylabel('NLLR', fontsize = 15)
    # ax.hist(sig,median_signal_bkg_arr,linestyle='--', label = r'NLLR$_{S+B}$', color = 'red')
    # #ax.text(0,-75, r'$\gamma = 1.1$, hA+BR', fontsize=14)
    # ax2 = ax.twiny()
    # ax2.plot(SoverB, median_bkg_only_arr)
    # ax2.set_xlabel("S/B")
    # ax.legend(title = r'$\gamma = 1.1,\quad m_\chi = 5 \textrm{ GeV, hA+BR}$', loc='upper left')
    # fig.savefig(f'plots/new_BG_ONLY_LLR_s{s_cv:.0f}_'+labelsamples[i]+'.pdf', format='pdf', dpi=600)
    # plt.close()  
   
print("Finished!")
        
