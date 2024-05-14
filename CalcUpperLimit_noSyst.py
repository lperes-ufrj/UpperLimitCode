import math
import numpy as np

from scipy.stats import poisson
from scipy.stats import norm

#def poisson_prob(n,mu,b):
 #   return math.e**(-(mu+b))*(mu+b)**n/math.factorial(n)

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
#print(optimals)


mu=0.
ul=0.9


for index, optimal_Eff in enumerate(optimals): #Each nuclear configuration model

    OUTPUT_FILE =open("Sens_"+ infiles[index] ,"w")
    OUTPUT_FILE.write('indexSample\t indexULtry \t ExpBkgEvts\t ul_prob \t g^4 UL \t nobs \t mu_best \t R_test \t prob_tmp\n')
    for i in range(12): #Each BDM sample gamma and mass value 

        nbkg = round(optimal_Eff[i][1]) # number of expected Bkg
        eff = optimal_Eff[i][0] # Signal Efficiency
        #print(eff)
        #print(nbkg)
        results_ul = []
        nobs_evts = np.arange(round(0.3*nbkg),round(2*nbkg),1)
        ul_tmp=0.0
        i_ul=-1
        for nobs in nobs_evts:
            if nobs <= nbkg:
                mu_best = 0
            else:
                mu_best = nobs - nbkg
                
            #higher_prob = poisson_prob(nobs,mu_best,nbkg)
            higher_prob = poisson.pmf(nobs,mu_best+nbkg)
            #prob_tmp = poisson_prob(nobs,mu,nbkg)
            prob_tmp = poisson.pmf(nobs,mu+nbkg)
            R_test = prob_tmp/higher_prob

            results_ul.append([nobs,mu_best,R_test,prob_tmp])
        #print(results.sort(lambda results: results[1],reverse=True))
        results_ul = np.array(results_ul)
        index = np.flip(np.argsort(results_ul[:,2])) 

        for id in range(0, len(index)): 
            if ul_tmp<=ul:
                ul_tmp=ul_tmp+results_ul[index[id]][3]
                i_ul=id
        
        poi= math.sqrt((results_ul[i_ul][0]-nbkg)/(NA_dune*xsec_list[i]*livetime_dune*flux_list[i]*optimal_Eff[i][0]))  #get the parameter of interest ==> g_Z'^4
        result = np.append(np.array([i,i_ul,nbkg,ul_tmp, poi]), results_ul[i_ul])
        np.savetxt(OUTPUT_FILE,result.reshape(1, result.shape[0]), fmt ='%.5e')

print("Finished!")