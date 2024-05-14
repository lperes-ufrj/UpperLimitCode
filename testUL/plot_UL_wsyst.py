import numpy as np
from array import *
import matplotlib.pyplot as plt
import math
import time


prob_hA_BR = np.loadtxt('Sens_Eff_Bkg_hA_BR.txt', usecols=(0,1,7,8), skiprows=2)


################################################################
#                 PLOT FIGURE          gamma = 1.1             #
################################################################

fig = plt.figure(dpi=150)
ax1 = fig.add_subplot(111)

plt.rc('text', usetex=True)
plt.rc('font', size=15)

print(prob_hA_BR[:,3][prob_hA_BR[:,3]>1])
#ax1.plot(MA[:4],conser_res[:4], '--', label='conservative',color='grey')
#ax1.plot(MA[:4],opt_res[:4], '--', label='optimistic',color='blue')
ax1.hist(prob_hA_BR[:,3], bins = 100)



#ax1.plot(MA[:4],paper_result[:4], '--', label='Phenomenological',color='darkorange')
#plt.fill_between(MA[:4], conser_res[:4], opt_res[:4], color='royalblue', alpha=0.4,label = 'ConsistencyRegion', ec=None)

ax1.set_yscale('log')
#ax1.set_xscale('log')

#ax1.set_xticks([1.1e1,1.5e1,1e2])
#ax1.set_xticklabels(['11','15','100'])

ax1.set_xlabel(r'$\frac{Prob(n,b|s;b;\vec{\sigma})}{Prob(n,b|s;b;\hat{\vec{\sigma}})}$  ', fontsize=10)
ax1.set_ylabel('# Throws', fontsize=10, labelpad=25)

ax1.minorticks_off()
plt.tight_layout()
plt.savefig('Last_Prob_b1p1_m05_'+str(time.strftime("%Y%m%d"))+'.pdf', format='pdf', dpi=600)
plt.show()