import numpy as np
from array import *
import matplotlib.pyplot as plt
import math
import time



FOM_m10_b10_00a = np.loadtxt('../FinalPlots/OptimalCuts/BDT_CVN_Ang_Test/FOM_m10_b10.txt', delimiter=' ',  dtype=np.float32)
FOM_m05_b10_00a = np.loadtxt('../FinalPlots/OptimalCuts/BDT_CVN_Ang_Test/FOM_m05_b10.txt', delimiter=' ',  dtype=np.float32)
FOM_m20_b10_00a = np.loadtxt('../FinalPlots/OptimalCuts/BDT_CVN_Ang_Test/FOM_m20_b10.txt', delimiter=' ',  dtype=np.float32)
FOM_m40_b10_00a = np.loadtxt('../FinalPlots/OptimalCuts/BDT_CVN_Ang_Test/FOM_m40_b10.txt', delimiter=' ',  dtype=np.float32)

plt.rc('text', usetex=True)
plt.rc('font', size=12)

CosCutsToRight = np.linspace(-1.00,.99,100)
print(CosCutsToRight.size)
print(FOM_m05_b10_00a)
plt.figure(dpi=100)
plt.xlabel(r'$\cos (\theta_{Sun})$', fontsize = 18)
plt.plot(CosCutsToRight, FOM_m10_b10_00a*10**3, lw =1, color = 'blue', ls='-')
#plt.plot(CosCutsToRight, FOM_m05_b10_00a, label=r'$m_\chi=10 \textrm{ GeV}$ w/ CVN+BDT Selection',  color='darkorange',lw =1, ls='--')
#plt.plot(CosCutsToRight, FOM_m20_b10_00a, label=r'Atm-$\nu$',  lw =1, color = 'blue', ls= '-')
#plt.plot(CosCutsToRight, FOM_m40_b10_00a, label=r'$m_\chi=10 \textrm{ GeV}$',  lw =1,color = 'darkorange')
#plt.xlabel(r'$\cos(\theta_{\Sun})$')
plt.ylabel(r'$\frac{\epsilon_{Ar}}{\sqrt{b}} \times 10^{-3}$', rotation=90, fontsize=18)
plt.legend(title = r'$\gamma = 10,\;m_\chi = 10$ GeV hA_BR', fontsize=10)
plt.savefig('FOM_b10_'+str(time.strftime("%Y%m%d"))+'.pdf', format='pdf', dpi=600)
plt.show()
