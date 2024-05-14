import math
import random
import numpy as np
import matplotlib.pyplot as plt

from scipy.stats import poisson
from scipy.stats import norm
from scipy.integrate import nquad 

BACKGROUND_SYST_UC = 0.3
EFF_SYST_UC = 0.1
N_THROWS=100000

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

def li(d,s,b,bi, eff, effi):
    return poisson.pmf(d,b+s)*norm.pdf(bi,b,BACKGROUND_SYST_UC*b)*norm.pdf(effi,eff,0.1*eff)#*norm.pdf(num_targets,NA_dune,0.05*NA_dune)

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
        b = 200 #round(optimal_Eff[i][1]) # number of expected Bkg
        eff = optimal_Eff[i][0] # Signal Efficiency
        #results = []
        
        h0=[]
        h1=[]
        h2=[]
        s=20
        d=round(b)
        for p in range(N_THROWS):
            b_tmp = round(np.random.normal(b,BACKGROUND_SYST_UC*b))
            eff_tmp = np.random.normal(eff, EFF_SYST_UC*eff)
            #eff_tmp = np.random.normal(eff,0.1*eff)
            prob_h0 = li(d,0.,b,b_tmp, eff, eff_tmp)#,eff,eff_tmp)
            h0.append([b_tmp,prob_h0])

        for p in range(N_THROWS):
            b_tmp = round(np.random.normal(b,BACKGROUND_SYST_UC*b))
            prob_h1 = li(d,0.,b,b_tmp,eff,eff_tmp)
            h1.append([b_tmp,prob_h1])
            
        for p in range(N_THROWS):
            b_tmp = round(np.random.normal(b,BACKGROUND_SYST_UC*b))
            prob_h2 = li(d,s,b,b_tmp,eff,eff_tmp)
            h2.append([b_tmp+s,prob_h2])
            
            
    #def li(d,s,b,bi):#, eff, effi):
    #return poisson.pmf(d,bi+s)*norm.pdf(bi,b,0.3*b)

        h0 = np.array(h0)
        h1 = np.array(h1)
        h2 = np.array(h2)    
        
        

            
        nllr_h0 = np.minimum(2000., np.maximum(-2000., -2*np.log(h1[:,1]/h0[:,1])))
        nllr_h1 = np.minimum(2000., np.maximum(-2000., -2*np.log(h2[:,1]/h0[:,1])))
            #print(l_i,l_s,nllh)
            #print(b_tmp, eff_tmp)

            #llr_array.append(nllh)
        print(np.max(h0[:,0]))
        print(np.min(h0[:,0]))

        #print(h0[:,0])
        #print(h0[:,1])
        plt.figure(dpi=300)
#        plt.xlabel(r'$N_{obs}$')
        plt.hist(nllr_h0, bins=100, histtype='step', label = r'$-2\log\left(\frac{P()}{P(B_{ex}|B_{ex})}$')
        plt.hist(nllr_h1, bins=100, histtype='step')
        
        #plt.plot(h0[:,0],h0[:,1],'.')
        #plt.plot(h1[:,0],h1[:,1],'.')

        plt.show()
        
            
        #np.savetxt(OUTPUT_FILE,result.reshape(1, result.shape[0]), fmt ='%.5e')
    

print("Finished!")
        
