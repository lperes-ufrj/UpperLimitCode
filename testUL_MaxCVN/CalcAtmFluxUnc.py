import sys
print(sys.version)
import numpy as np
import ROOT
from array import *
import matplotlib.pyplot as plt
import math

main_folder = '../FinalPlots/OptimalCuts/NuclearModelsOptSelectionApplication_MaxCVN/'

#Atmospheric Neutrino Angular Distributions 

CosSun_Atm_list = ['hA_BR/CosSun_Atm_00a.txt','hA_LFG/CosSun_Atm_01a.txt', 'hA_ESF/CosSun_Atm_02a.txt', 'hN_BR/CosSun_Atm_00b.txt','hN_LFG/CosSun_Atm_01b.txt', 'hN_ESF/CosSun_Atm_02b.txt']
OptimalAngCuts = np.loadtxt('Eff_Bkg_index_00a.txt', usecols=(1,2,4), skiprows=1)
#Sample labels
labelsamples= ["b1p1_m05","b1p1_m10","b1p1_m20","b1p1_m40","b1p5_m05","b1p5_m10","b1p5_m20","b1p5_m40","b10_m05","b10_m10","b10_m20","b10_m40"]
ExpectedNumber10kty = [4*10*2495.98, 4*10*2586.47, 4*10*2401.88]
print('========== SYSTEMATIC UNCERTAINTY PER NUCLEAR MODEL BY THE SIDE BAND CONSTRAINT ===========')

ExpectedBkgList = ExpectedNumber10kty

for index in range(0, len(labelsamples)):
    for i in range(0,len(CosSun_Atm_list)):
        
        ExpectedBkg = 0
        if i % 3 == 0:
            ExpectedBkg = ExpectedBkgList[0]
        if i % 3 == 1:
            ExpectedBkg = ExpectedBkgList[1]
        if i % 3 == 2:
            ExpectedBkg = ExpectedBkgList[2]

        print('====================================================\n')
        print('Atmospheric Nuclear Model: '+ CosSun_Atm_list[i])
        AtmosphericSample = np.loadtxt(main_folder+CosSun_Atm_list[i])
        print('Sample: '+labelsamples[index]+'\n')
        print(f'Total Expected Number of Neutrinos Interactions: {round(ExpectedBkg)}\n')
        print(f'Number of Atmospheric Neutrinos Events Reconstructed: {AtmosphericSample.size}')
        print(f'Optimal Cosine Cuts => cos(theta_Sun) < {OptimalAngCuts[index][0]} and cos(theta_Sun) > {OptimalAngCuts[index][1]}. \n')
        EventsWithinOptAngCuts = AtmosphericSample[AtmosphericSample < OptimalAngCuts[index][0]].size +  AtmosphericSample[AtmosphericSample > OptimalAngCuts[index][1]].size
        print(f'Number of Atmospheric Neutrino Events Reconstructed inside the Angular Cuts: {EventsWithinOptAngCuts} \n')
        ExpectedBkgWithinOptAngCuts = ExpectedBkg*(EventsWithinOptAngCuts/AtmosphericSample.size)
        print(f'Number of Expected Atmospheric Neutrino Events Reconstructed inside the Angular Cuts: {round(ExpectedBkgWithinOptAngCuts)} \n')
        print(f'Square root: {round(math.sqrt(ExpectedBkgWithinOptAngCuts))}')
        
        print(f'Uncertainty: {round(math.sqrt(ExpectedBkgWithinOptAngCuts)/ExpectedBkgWithinOptAngCuts,3)*100 }%')

#print(OptimalAngCuts[0])


