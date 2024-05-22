import numpy as np
from array import *
import matplotlib.pyplot as plt
import math
import time

# lighter DM mass
MB = np.array([5,10,20,40])
# gamma
gam = np.array([1.1, 1.5, 10])
# Heavy DM mass = Lighter DM mass * gamma
MA = np.reshape(np.multiply.outer(gam,MB),12)


onesigmaplus = np.array([4.4523769808173476e-07,8.244537114261886e-07,1.2986822351959968e-06,3.138598999285204e-06])
centralvalue = np.array([3.0424520433694744e-07,5.780733944954129e-07,8.93561301084237e-07,2.171265189421015e-06])
onesigmaless = np.array([2.584737281067556e-07,4.6510425354462056e-07,7.494078398665556e-07,1.7921372408863473e-06])

################################################################
#                 PLOT FIGURE          gamma = 10              #
################################################################

fig = plt.figure(dpi=150)
ax1 = fig.add_subplot(111)

plt.rc('text', usetex=True)
plt.rc('font', size=15)


ax1.plot(MA[8:12],centralvalue, '--', label='Limit',color='darkorange')
plt.fill_between(MA[8:12], onesigmaless, onesigmaplus, color='royalblue', alpha=0.4,label = r'$ Expected \pm 1 \sigma$', ec=None)

ax1.set_yscale('log')
ax1.set_xscale('log')

ax1.set_xticks(MA[8:12])
ax1.set_xticklabels(['50','100','200','400'])
ax1.set_xlabel(r'$m_\psi$ (GeV)', fontsize=20)
ax1.set_ylabel(r'$\frac{g_{Z^\prime}^4}{10^{-6}}$ at 90% C.L.',rotation=90, fontsize=30,labelpad=25)
ax1.set_ylim(1e-7, 1e-5)
ax1.set_yticks([2e-7,5e-7,1e-6,2e-6,5e-6])
ax1.set_yticklabels([r'$0.2$',r'$0.5$',r'$1$' ,r'$ 2 $',r'$5$'])
minx,maxx = ax1.get_xlim()

ax1.minorticks_off()
ax1.legend(title=r'$\gamma=10$',fontsize = 12, frameon=True)
plt.text(50,5e-6,"DUNE PRELIMINARY", alpha=0.7)
plt.tight_layout()
plt.savefig('Last_Sensit_b10'+str(time.strftime("%Y%m%d"))+'.pdf', format='pdf', dpi=600)
plt.close()