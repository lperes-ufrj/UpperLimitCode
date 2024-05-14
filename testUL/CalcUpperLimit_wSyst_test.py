import math
import numpy as np
import matplotlib.pyplot as plt

from scipy.stats import poisson
from scipy.stats import norm
from scipy.integrate import nquad 


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

poi = 0 # parameter of interest ===> g_Z'^8 

def li(d,s,b,bi, eff, effi):
    return poisson.pmf(d,bi+s)*norm.pdf(bi,b,0.1*b)*norm.pdf(effi,eff,0.1*eff)#*norm.pdf(num_targets,NA_dune,0.05*NA_dune)

#def l_max(d,s,b,bi, eff, effi):
 #   return poisson.pmf(d,d)*norm.pdf(bi,b,0.3*b)*norm.pdf(effi,eff,0.1*eff)#*norm.pdf(num_targets,NA_dune,0.05*NA_dune)

optimals = readtxt(infiles) # read values from the optimal cuts
#print(optimals)

num_targets_array = np.arange(0.95*NA_dune,1.05*NA_dune,0.005*NA_dune)

for index, optimal_Eff in enumerate(optimals): #Each nuclear configuration model
    #to test
    if index != 0: 
        break

    OUTPUT_FILE = open("Sens_"+ infiles[index] ,"w")
    OUTPUT_FILE.write('indexSample\t ExpSigEvts\t BkgEvts\t CentralBkgEvts\t Eff\t CentralEff\t Numtargets_tmp\t Probability\n')
    for i in range(12): #Each BDM sample gamma and mass value 

        if i != 0: 
            break
        b = round(optimal_Eff[i][1]) # number of expected Bkg
        eff = optimal_Eff[i][0] # Signal Efficiency
        results = []

        signalevts = np.arange(0,150,1)
        #bkgevts = np.arange(round(0.5*b),round(1.5*b),1)
        #eff_array = np.arange(0.5*eff,1.5*eff, 0.001)

        l_max = li(b,0.,b,b,eff,eff)
        
        llr_array=[]
        
        s=100
        
        for p in range(1000):
            b_tmp = np.random.normal(b,0.1*b)
            eff_tmp = np.random.normal(eff,0.1*eff)
            numtargets_tmp = np.random.choice(num_targets_array, 1, replace=False)[0]
            l_i = li(b+s,0.,b,b_tmp,eff,eff_tmp)
            l_s = li(b+s,s,b,b_tmp,eff,eff_tmp)  

            #def li(d,s,b,bi, eff, effi):
                #return poisson.pmf(d,b+s)*norm.pdf(bi,b,0.3*b)*norm.pdf(effi,eff,0.1*eff)#*norm.pdf(num_targets,NA_dune,0.05*NA_dune)

            
            nllh = -2*np.log(l_s/l_i)
            print(l_i,l_s,nllh)
            print(b_tmp, eff_tmp)

            llr_array.append(nllh)
        
        plt.figure(dpi=300)
        #plt.xlim([-5,10])
        plt.hist(llr_array,bins = 50)
        plt.show()
        
            
        #np.savetxt(OUTPUT_FILE,result.reshape(1, result.shape[0]), fmt ='%.5e')
    

print("Finished!")
        
