import math
import numpy as np

from scipy.stats import poisson
from scipy.stats import norm


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

poi =0 # parameter of interest ===> g_Z'^8 

optimals = readtxt(infiles) # read values from the optimal cuts
print(optimals)

for index, optimal_Eff in enumerate(optimals): #Each nuclear configuration model

    OUTPUT_FILE =open("Sens_"+ infiles[index] ,"w")
    OUTPUT_FILE.write('indexSample\t ExpSigEvts\t ExpBkgEvts\t UpperLimit_gZ^4\n')
    for i in range(12): #Each BDM sample gamma and mass value 

        result = np.array([i,s,b,np.sqrt(poi)]) 
        b = round(optimal_Eff[i][1]) # number of expected Bkg
        eff = optimal_Eff[i][0] # Signal Efficiency
        print(eff)
        print(b)
        results = []
        signalevts_number = np.arange(round(0.3*b),round(3*b),1)
        higher_prob = poisson.pmf(b,b) #implementing FC upperlimit, highest probability is when you observe the expected number of background interactions

        for evt_num in signalevts_number:
            R_test = poisson.pmf(evt_num,b)/higher_prob #R, ordering principle for FC
            results.append([evt_num,R_test,poisson.pmf(evt_num,b)])

        results = np.array(results)
         #print(results.sort(lambda results: results[1],reverse=True))
        s=0
        prob = 0
        for rlt in results:
            prob = prob + rlt[2]
            #print(prob)
            if prob >= 0.9: #Construct the limit until the sum of probabilities give the CL, i.e., 90% 
                print(prob,rlt)
                s = rlt[0]-b #Get the UL for the number of signal events (s)
                break

        #print(s)
        #print(NA_dune)
        #print(livetime_dune)
        #print(flux_list[i])
        #print(xsec_list[i])
        #print(optimal_Eff[i][0])
        #print(NA_dune*xsec_list[i])
        #print(livetime_dune*flux_list[i]*optimal_Eff[i][0])
        #print(NA_dune*xsec_list[i]*livetime_dune*flux_list[i]*optimal_Eff[i][0])
        poi= s/(NA_dune*xsec_list[i]*livetime_dune*flux_list[i]*optimal_Eff[i][0])  #get the parameter of interest ==> g_Z'^8
        print(np.sqrt(poi))
        result = np.array([i,s,b,np.sqrt(poi)]) 
        np.savetxt(OUTPUT_FILE,result.reshape(1, result.shape[0]), fmt ='%.5e')

print("Finished!")