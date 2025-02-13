import math
import random
import numpy as np
import matplotlib.pyplot as plt

from scipy.stats import poisson
from scipy.stats import norm
from scipy.integrate import nquad 
import configparser


#python program to check if a directory exists
import os

path = 'plots/final'
# Check whether the specified path exists or not
isExist = os.path.exists(path)
if not isExist:
   # Create a new directory because it does not exist
   os.makedirs(path)
   #print("The new directory is created!")


plt.rcParams['text.usetex'] = True


# Create a ConfigParser object
config = configparser.ConfigParser()

# Read the INI file
config.read('parameters.ini')

BACKGROUND_SYST_UC = float(config['Uncertainties']['BACKGROUND_FLUX_UC'])
EFF_SYST_UC = float(config['Uncertainties']['EFF_SIGNAL_UC'])
NA_DUNE_UC = float(config['Uncertainties']['NUMBER_NA_UC'])

N_THROWS= int(config['Loop']['THROWS'])
N_BINS = int(config['Loop']['BINS'])
DECIMALS_PRECISION = int(config['Loop']['DECIMALS_PRECISION'])
STEPS_PROBING_GZ4 = int(config['Loop']['STEPS'])

# Number of target Argon nuclei and livetime of DUNE
NA_dune = 4 * 1.5e32             # 40 kton
livetime_dune = 10.0 * 3.154e7   # 10 years

# BDM flux / g_Z' ^ 4
flux_list = [634.1, 303.6, 117.7, 36.38, 468.3, 203.4, 72.48, 19.10, 28.12, 7.521, 2.455, 0.431]
#argon cross section / g_Z' ^ 4
xsec_list = [9.057 * 1e-30, 1.063 * 1e-29, 1.220 * 1e-29, 1.278 * 1e-29, 4.978 * 1e-29, 5.609 * 1e-29, 5.965 * 1e-29, 6.152 * 1e-29, 1.270 * 1e-27, 1.377 * 1e-27, 1.437 * 1e-27, 1.470 * 1e-27]

#txt files with signal strength, expected background and signal efficiency for each nuclear configuration model
infiles = ['Eff_Bkg_index_00a.txt',  'Eff_Bkg_index_00b.txt',  'Eff_Bkg_index_01a.txt',  'Eff_Bkg_index_01b.txt',  'Eff_Bkg_index_02a.txt',  'Eff_Bkg_index_02b.txt']
#Sample labels
labelsamples= ["b1p1_m05","b1p1_m10","b1p1_m20","b1p1_m40","b1p5_m05","b1p5_m10","b1p5_m20","b1p5_m40","b10_m05","b10_m10","b10_m20","b10_m40"]

list_samples_latex = [r'$m_\chi = 5 ~\textrm{ GeV}, \; \gamma=1.1$',
                       r'$m_\chi = 10 ~\textrm{ GeV}, \; \gamma=1.1$',
                         r'$m_\chi = 20 ~\textrm{ GeV}, \; \gamma=1.1$',
                           r'$m_\chi = 40 ~\textrm{ GeV}, \; \gamma=1.1$',
                             r'$m_\chi = 5 ~\textrm{ GeV}, \; \gamma=1.5$',
                               r'$m_\chi = 10 ~\textrm{ GeV}, \; \gamma=1.5$',
                                 r'$m_\chi = 20 ~\textrm{ GeV}, \; \gamma=1.5$',
                                   r'$m_\chi = 40 ~\textrm{ GeV}, \; \gamma=1.5$',
                                     r'$m_\chi = 5 ~\textrm{ GeV}, \; \gamma=10$',
                                       r'$m_\chi = 10 ~\textrm{ GeV}, \; \gamma=10$',
                                         r'$m_\chi = 20 ~\textrm{ GeV}, \; \gamma=10$',
                                           r'$m_\chi = 40 ~\textrm{ GeV}, \; \gamma=10$' ]  

poi_m05_b1p1 = np.linspace(0.9e-6,8e-6,STEPS_PROBING_GZ4)
poi_m10_b1p1 = np.linspace(1e-6,1e-5,STEPS_PROBING_GZ4)
poi_m20_b1p1 = np.linspace(2e-6,2e-5,STEPS_PROBING_GZ4)
poi_m40_b1p1 = np.linspace(3e-6,2.5e-5,STEPS_PROBING_GZ4)
poi_m05_b1p5 = np.linspace(1e-7,1e-6,STEPS_PROBING_GZ4)
poi_m10_b1p5 = np.linspace(1e-7,2.5e-6,STEPS_PROBING_GZ4)
poi_m20_b1p5 = np.linspace(1e-7,3e-6,STEPS_PROBING_GZ4)
poi_m40_b1p5 = np.linspace(5e-7,8e-6,STEPS_PROBING_GZ4)
poi_m05_b10 = np.linspace(7e-8,5e-7,STEPS_PROBING_GZ4)
poi_m10_b10 = np.linspace(1e-7,8.5e-7,STEPS_PROBING_GZ4)
poi_m20_b10 = np.linspace(1e-7,2e-6,STEPS_PROBING_GZ4)
poi_m40_b10 = np.linspace(5e-7,5e-6,STEPS_PROBING_GZ4)

poi = [poi_m05_b1p1, poi_m10_b1p1, poi_m20_b1p1, poi_m40_b1p1, poi_m05_b1p5, poi_m10_b1p5, poi_m20_b1p5, poi_m40_b1p5, poi_m05_b10, poi_m10_b10, poi_m20_b10, poi_m40_b10]


#function to read the list of txt files
def readtxt(infile_array):
    listloaded = [] 
    for infile in infile_array:
        listloaded.append(np.loadtxt(infile, usecols=(3,4), skiprows=1))
    return listloaded

optimals = readtxt(infiles) # read values from the optimal cuts

#optimals === first collumn nuclear model 
#==== second collumn BDM sample 
#==== third collumn firt entry overall signal efficiency second entry expected background number

##print(str(path))
for i in range(0,12): #Each BDM sample gamma and mass value 
    

    Sensitivity_Info = open(path+'/Sensitivity_'+labelsamples[i]+'.dat', "a")
    Sensitivity_Info.write(" =========== SYSTEMATICS AND PARAMETERS INCLUEDED ============  \n")
    Sensitivity_Info.write('BACKGROUND_SYST_UC: '+str(BACKGROUND_SYST_UC)+'\n')
    Sensitivity_Info.write('EFF_SYST_UC: '+str(EFF_SYST_UC)+'\n')
    Sensitivity_Info.write('NA_DUNE_UC: '+str(NA_DUNE_UC)+'\n')
    Sensitivity_Info.write('N_THROWS: '+str(N_THROWS)+'\n')
    Sensitivity_Info.write('N_BINS: '+str(N_BINS)+'\n')
    Sensitivity_Info.write('DECIMALS_PRECISION: '+str(DECIMALS_PRECISION)+'\n')
    Sensitivity_Info.write(" =========== CENTRAL LIMIT FOR GZ'^4 AND BANDS WITH 1 AND 2 SIGMAS ============  \n")

    Debug_Info = open(path+'/Debug_Info_'+labelsamples[i]+'.dat', "a")

    median_bkg_only_arr = [] # array (list) of the median background-only distribution (-2*ln Q_{BG_Only}) 
    median_signal_bkg_arr = [] # array (list) of the median S+B distribution (-2*ln Q_{S+B}) 

    upband_onesigma_bkg_only_arr = []
    upband_twosigma_bkg_only_arr = []
    upband_onesigma_bkg_signal_arr = []
    upband_twosigma_bkg_signal_arr = []

    lowband_onesigma_bkg_only_arr = []
    lowband_twosigma_bkg_only_arr = []
    lowband_onesigma_bkg_signal_arr = []
    lowband_twosigma_bkg_signal_arr = []

    SoverB = [] # array (list) of the signal background ratio for each number of signal (fixed B)
    

    b_cv = round(optimals[0][i][1])# number of expected Bkg -- Defaulf model hA_BR (CentralValue)
    eff_cv = optimals[0][i][0] # Signal Efficiency -- Default model hA_BR (CentralValue)
    
   
    eff_syst = np.random.normal(eff_cv,EFF_SYST_UC*eff_cv,N_THROWS) # Throw the overall efficiency inside a systematic un.
    B_syst = np.random.normal(b_cv,BACKGROUND_SYST_UC*b_cv,N_THROWS) # Throw the background number inside a systematic un.
    NA_dune_syst = np.random.normal(NA_dune,NA_dune*NA_DUNE_UC, N_THROWS) #Throw the number of targets (Fiducial Mass) inside a systematic un.
    
    shifts_b_eff=[]      
    nm_shift = []
    
    if i == 10:
        # Define the possible values
        nm_indices = [0, 1, 3, 4, 5]
        # Generate the random array
        nm_shift = np.random.choice(nm_indices, size=N_THROWS)
    else:
        nm_shift = np.random.randint(0,6,size=N_THROWS) #Throw nuclear model


    for nuclear_model in range(N_THROWS):
        shifts_b_eff.append(optimals[nm_shift[nuclear_model]][i][:]/optimals[0][i][:])

    shifts_b_eff = np.array(shifts_b_eff)


    B_syst = np.round(B_syst) # take it as integer number
    B_syst = (NA_dune_syst/NA_dune)*B_syst

    eff_syst = shifts_b_eff[:,0]*eff_syst
    B_syst = np.round(B_syst[eff_syst>0])
    NA_dune_syst = NA_dune_syst[eff_syst>0] # Physical cut, only positive background events.
    eff_syst = eff_syst[eff_syst>0] 


    plt.figure(dpi=300)
    plt.hist(eff_syst, bins = N_BINS, label='eff throws syst.')
    plt.xlabel(r'Overall signal efficiency throw $\epsilon_{Ar}$')
    plt.ylabel('Number of Throws')
    plt.legend(title = list_samples_latex[i])
    plt.savefig(f'{path}/eff_syst_'+labelsamples[i]+'.pdf', format='pdf', dpi=600)
    plt.close()

    plt.figure(dpi=300)
    plt.hist(B_syst, bins = N_BINS, label='bkg number throws syst.')
    plt.xlabel(r'Expected Background Events ($b$) Throw')
    plt.ylabel('Number of Throws')
    plt.legend(title = list_samples_latex[i])
    plt.savefig(f'{path}/bkg_syst_'+labelsamples[i]+'.pdf', format='pdf', dpi=600)
    plt.close()
    
    limits = np.zeros(5)

    for gz4 in poi[i]: #Assumes the number of signal events
        
        ##print(gz4)
        S_syst = NA_dune_syst*xsec_list[i]*livetime_dune*flux_list[i]*eff_syst*(gz4**2) 
        ##print(S_syst)
        s_cv = NA_dune*xsec_list[i]*livetime_dune*flux_list[i]*eff_cv*(gz4**2) 
        ##print((gz4**2))
        ##print(s_cv)
        H_0 = np.random.poisson(B_syst[0],N_THROWS)
        H_1 = np.random.poisson(B_syst[0]+S_syst[0],N_THROWS)
        for index, bi in enumerate(B_syst[1:]):
            h0_i = np.random.poisson(bi,N_THROWS)
            H_0 = np.concatenate((H_0,h0_i))
            h1_i = np.random.poisson(bi+S_syst[index+1],N_THROWS)
            H_1 = np.concatenate((H_1,h1_i))
        Q_0 = poisson.pmf(H_0, s_cv+b_cv)/poisson.pmf(H_0, b_cv)
        Q_1 = poisson.pmf(H_1, s_cv+b_cv)/poisson.pmf(H_1, b_cv)
        #print(poisson.pmf(H_1, s_cv+b_cv), poisson.pmf(H_1, b_cv),Q_1)

        nllr_h0 = np.minimum(10000., np.maximum(-10000., -2*np.log(Q_0)))
        nllr_h1 = np.minimum(10000., np.maximum(-10000., -2*np.log(Q_1)))
        
        
        if -10000. in nllr_h0:
            print('Check!')
            indices = np.where(nllr_h0 == -10000)[0]
            print(indices)
            Debug_Info.write(f"{s_cv},{S_syst[indices % 1000]},{b_cv},{B_syst[indices % 1000]}")
        
        minus_inf_nllr_h1 = nllr_h1[nllr_h1==-10000].size
        
        nllr_h0 = nllr_h0[nllr_h1> -9999]
        nllr_h1 = nllr_h1[nllr_h1> -9999]
    
    ################################################################
    #          CENTRAL VALUE          --  PRINT AND SAVE           #
    ################################################################
        
        median_bkg_only = np.median(nllr_h0) #check for medium 
        std_bkg_only = nllr_h0.std()    
        median_signal_bkg = np.median(nllr_h1)
        std_signal_bkg = nllr_h1.std() 

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
            Sensitivity_Info.write("======== CENTRAL VALUE ========\n")
            Sensitivity_Info.write(str(gz4)+'\n')
            print("====== CENTRAL VALUE ========\n")
            print(gz4)
            plot_flag = True
            cl_sb = per95_signal_bkg
            limits[2] = gz4
        if (np.round(upband_onesigma_bkg_only,DECIMALS_PRECISION) == np.round(upband_onesigma_bkg_signal,DECIMALS_PRECISION)):
            Sensitivity_Info.write("======== -1 Sigma Expeceted BG ========\n")
            Sensitivity_Info.write(str(gz4)+'\n')
            print(" - 1 sigma: \n")
            print(gz4)
            plot_flag = True
            cl_sb = upband_onesigma_bkg_signal
            limits[1] = gz4
        if (np.round(upband_twosigma_bkg_only,DECIMALS_PRECISION) == np.round(upband_twosigma_bkg_signal,DECIMALS_PRECISION)):
            if (s_cv > 2):
                Sensitivity_Info.write("======== -2 Sigma Expeceted BG ========\n")
                Sensitivity_Info.write(str(gz4)+'\n')
                print(" - 2 sigma: \n")
                print(gz4)
                plot_flag = True
                cl_sb = upband_twosigma_bkg_signal
                limits[0] = gz4
        if (np.round(lowband_onesigma_bkg_only,DECIMALS_PRECISION) == np.round(lowband_onesigma_bkg_signal,DECIMALS_PRECISION)):
            Sensitivity_Info.write("======== +1 Sigma Expeceted BG ========\n")
            Sensitivity_Info.write('Number of S+B pseudo experiments with NLLR = -inf '+str(minus_inf_nllr_h1)+'\n')
            Sensitivity_Info.write(str(gz4)+'\n')
            print(" + 1 sigma: \n")
            print(gz4)
            plot_flag = True
            cl_sb = lowband_onesigma_bkg_signal
            limits[3] = gz4
        if (np.round(lowband_twosigma_bkg_only,DECIMALS_PRECISION) == np.round(lowband_twosigma_bkg_signal,DECIMALS_PRECISION)):
            Sensitivity_Info.write("======== +2 Sigma Expeceted BG ========\n")
            Sensitivity_Info.write('Number of S+B pseudo experiments with NLLR = -inf '+str(minus_inf_nllr_h1)+'\n')
            Sensitivity_Info.write(str(gz4)+'\n')
            print("+ 2 sigma: \n")
            print(gz4)
            plot_flag = True
            cl_sb = lowband_twosigma_bkg_signal
            limits[4] = gz4

        median_bkg_only_arr.append(median_bkg_only)
        median_signal_bkg_arr.append(median_signal_bkg)

        upband_onesigma_bkg_only_arr.append(upband_onesigma_bkg_only)
        upband_twosigma_bkg_only_arr.append(upband_twosigma_bkg_only)
        upband_onesigma_bkg_signal_arr.append(upband_onesigma_bkg_signal)
        upband_twosigma_bkg_signal_arr.append(upband_twosigma_bkg_signal)

        lowband_onesigma_bkg_only_arr.append(lowband_onesigma_bkg_only)
        lowband_twosigma_bkg_only_arr.append(lowband_twosigma_bkg_only)
        lowband_onesigma_bkg_signal_arr.append(lowband_onesigma_bkg_signal)
        lowband_twosigma_bkg_signal_arr.append(lowband_twosigma_bkg_signal)

        SoverB.append(s_cv/b_cv)
        
        if(nllr_h0.size != nllr_h1.size):
            Sensitivity_Info.write('Different number of pseudo experiments in H0 and H1 set:\n')
            Sensitivity_Info.write('NLLR H0 size  = '+ str(nllr_h0.size)+', and NLLR H1 size  = '+str(nllr_h1.size)+ '\n')
        
        if(plot_flag):
            #print(nllr_h0.size,nllr_h1.size)
            plt.figure(dpi=300)
            plt.title(fr'$log(g_Z^4)$: {math.log(gz4):.6f} B: {b_cv:.0f} \# PseudoExp : {nllr_h0.size}')
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
            
            plt.xlabel('NLLR')
            plt.ylabel('Number of Throws')
            plt.axvline(x = median_bkg_only,ls='--', color = 'black', label = 'Median - Only BG')

            plt.axvline(x = upband_onesigma_bkg_only, ls='--',color='blue', label =r'$\pm 1 \sigma$')
            plt.axvline(x = upband_twosigma_bkg_only, ls='--',color='green', label =r'$\pm 2 \sigma$')
            plt.axvline(x = lowband_onesigma_bkg_only, ls='--',color='blue')
            plt.axvline(x = lowband_twosigma_bkg_only, ls='--',color='green')

            plt.legend(title = list_samples_latex[i])
            plt.savefig(f'{path}/NLLR_'+labelsamples[i]+f'_{s_cv:.0f}_.pdf', format='pdf', dpi=600)
            ##print("Printed!")
            plt.close()  

    poi_sample = np.array(poi[i])
    median_bkg_only_arr = np.array(median_bkg_only_arr)
    median_signal_bkg_arr = np.array(median_signal_bkg_arr)

    upband_onesigma_bkg_only_arr = np.array(upband_onesigma_bkg_only_arr)
    upband_twosigma_bkg_only_arr = np.array(upband_twosigma_bkg_only_arr)
    upband_onesigma_bkg_signal_arr = np.array(upband_onesigma_bkg_signal_arr)
    upband_twosigma_bkg_signal_arr = np.array(upband_twosigma_bkg_signal_arr)

    lowband_onesigma_bkg_only_arr = np.array(lowband_onesigma_bkg_only_arr)
    lowband_twosigma_bkg_only_arr = np.array(lowband_twosigma_bkg_only_arr)
    lowband_onesigma_bkg_signal_arr = np.array(lowband_onesigma_bkg_signal_arr)
    lowband_twosigma_bkg_signal_arr = np.array(lowband_twosigma_bkg_signal_arr)

    SoverB = np.array(SoverB)


    ################################################################
    #          PLOT FIGURE        S/B CENTRAL VALUE                #
    ################################################################

    fig, ax = plt.subplots(dpi=300)
    plt.xlabel(r"$g_{Z^{\prime}}^4$", fontsize = 15)
    plt.ylabel(r'$\frac{S_{CV}}{B_{CV}}$', fontsize = 15, rotation = 90)
    ax.plot(poi_sample,SoverB,linestyle='--', label = r'$\frac{S_{CV}}{B_{CV}}$', color = 'red')
    ax.legend(title = list_samples_latex[i], loc='upper left')
    fig.savefig(f'{path}/signalBkgRatio_{s_cv:.0f}_'+labelsamples[i]+'.pdf', format='pdf', dpi=600)
    plt.close()  

    ################################################################
    #          PLOT FIGURE      BG ONLY WITH 90%CL LIMITS          #
    ################################################################
    fig, ax = plt.subplots(dpi=300)
    ax.plot(poi_sample,median_bkg_only_arr,linestyle='--', label = r'NLLR$_{BG-Only}$')
    plt.xlabel(r"$g_{Z^{\prime}}^4$", fontsize = 15)
    plt.ylabel('NLLR', fontsize = 15)
    ax.plot(poi_sample,median_signal_bkg_arr,linestyle='--', label = r'NLLR$_{S+B}$', color = 'red')
    #ax.text(0,-75, r'$\gamma = 1.1$, hA+BR', fontsize=14)
    ax.fill_between(poi_sample,lowband_onesigma_bkg_only_arr, upband_onesigma_bkg_only_arr,alpha=0.5,label = r'$\pm 1\sigma$')
    ax.fill_between(poi_sample,lowband_twosigma_bkg_only_arr, upband_twosigma_bkg_only_arr,alpha=.5,label = r'$\pm 2\sigma $')

    ax.legend(title = list_samples_latex[i], loc='upper left')
    fig.savefig(f'{path}/BG_ONLY_NLLR_'+labelsamples[i]+f'_{s_cv:.0f}_.pdf', format='pdf', dpi=600)
    plt.close()  
    
    np.savetxt(path+'/limits_'+labelsamples[i]+'.dat', limits, delimiter=',')   # X is an array
    Sensitivity_Info.close()

   
#print("Finished!")

   
