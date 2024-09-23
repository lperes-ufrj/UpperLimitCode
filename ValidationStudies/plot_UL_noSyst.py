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

Sens_UL_Frenq = ["Sens_Eff_Bkg_hA_BR.txt", "Sens_Eff_Bkg_hA_ESF.txt", "Sens_Eff_Bkg_hA_LFG.txt", "Sens_Eff_Bkg_hN_BR.txt", "Sens_Eff_Bkg_hN_ESF.txt", "Sens_Eff_Bkg_hN_LFG.txt"]

def readtxt(infile_array):
    listloaded = []
    for infile in infile_array:
        listloaded.append(np.loadtxt(infile, usecols=(4), skiprows=1))
    return listloaded

Sens_UL = readtxt(Sens_UL_Frenq)

# initializing sub list
sub_list = ["Sens_Eff_Bkg_", ".txt"]
labels_nuclearmodels = []
for nuclear_model in Sens_UL_Frenq:
    # Remove substring list from String
    # Using loop + replace()
    for sub in sub_list:
        nuclear_model = nuclear_model.replace(sub, '')
        #print(nuclear_model)
    labels_nuclearmodels.append(nuclear_model)


################################################################
#          PLOT FIGURE          gamma = 1.1                    #
################################################################

fig = plt.figure(dpi=150)
ax1 = fig.add_subplot(111)

plt.rc('text', usetex=True)
plt.rc('font', size=15)

#ax1.plot(MA[:4],conser_res[:4], '--', label='conservative',color='grey')
#ax1.plot(MA[:4],opt_res[:4], '--', label='optimistic',color='blue')
for index,nuclear_model in enumerate(Sens_UL):
    ax1.plot(MA[:4],nuclear_model[:4], '--', label=labels_nuclearmodels[index])



#ax1.plot(MA[:4],paper_result[:4], '--', label='Phenomenological',color='darkorange')
#plt.fill_between(MA[:4], conser_res[:4], opt_res[:4], color='royalblue', alpha=0.4,label = 'ConsistencyRegion', ec=None)

ax1.set_yscale('log')
ax1.set_xscale('log')
#ax1.set_xticks([1.1e1,1.5e1,1e2])
#ax1.set_xticklabels(['11','15','100'])

ax1.set_xticks([5.5,1.1e1,2.2e1,4.4e1])
ax1.set_xticklabels(['5.5','11','22','44'])
ax1.set_xlabel(r'$m_\psi$ (GeV)', fontsize=20)
ax1.set_ylabel(r'$\frac{g_{Z^\prime}^4}{10^{-6}}$',rotation=0, fontsize=30, labelpad=25)
ax1.set_ylim(1e-7, 1e-5)
ax1.set_yticks([2e-7,5e-7,1e-6,2e-6,5e-6])
ax1.set_yticklabels([r'$0.2$',r'$0.5$',r'$1$' ,r'$ 2 $',r'$5$'])
minx,maxx = ax1.get_xlim()
plt.text(5.5,5e-6,"DUNE PRELIMINARY", alpha=0.7)

ax1.minorticks_off()
ax1.legend(title=r'$\gamma=1.1$',fontsize = 12, frameon=True, loc='lower right')
plt.tight_layout()
plt.savefig('Last_Sensit_b1p1'+str(time.strftime("%Y%m%d"))+'.pdf', format='pdf', dpi=600)
plt.show()

################################################################
#          PLOT FIGURE          gamma = 1.5                    #
################################################################

fig = plt.figure(dpi=150)
ax1 = fig.add_subplot(111)

plt.rc('text', usetex=True)
plt.rc('font', size=15)

#ax1.plot(MA[:4],conser_res[:4], '--', label='conservative',color='grey')
#ax1.plot(MA[:4],opt_res[:4], '--', label='optimistic',color='blue')
for index,nuclear_model in enumerate(Sens_UL):
    ax1.plot(MA[4:8],nuclear_model[4:8], '--', label=labels_nuclearmodels[index])



#ax1.plot(MA[:4],paper_result[:4], '--', label='Phenomenological',color='darkorange')
#plt.fill_between(MA[:4], conser_res[:4], opt_res[:4], color='royalblue', alpha=0.4,label = 'ConsistencyRegion', ec=None)

ax1.set_yscale('log')
ax1.set_xscale('log')
#ax1.set_xticks([1.1e1,1.5e1,1e2])
#ax1.set_xticklabels(['11','15','100'])

ax1.set_xticks(MA[4:8])
ax1.set_xticklabels(['7.5','15','30','60'])
ax1.set_xlabel(r'$m_\psi~\textrm{ (GeV)}$', fontsize=20)
ax1.set_ylabel(r'$\frac{g_{Z^\prime}^4}{10^{-6}}$',rotation=0, fontsize=30, labelpad=25)
ax1.set_ylim(1e-7, 1e-5)
ax1.set_yticks([2e-7,5e-7,1e-6,2e-6,5e-6])
ax1.set_yticklabels([r'$0.2$',r'$0.5$',r'$1$' ,r'$ 2 $',r'$5$'])
minx,maxx = ax1.get_xlim()

plt.text(7.5,5e-6,"DUNE PRELIMINARY", alpha=0.7)
ax1.minorticks_off()
ax1.legend(title=r'$\gamma=1.5$',fontsize = 12, frameon=True)
plt.tight_layout()
plt.savefig('Last_Sensit_b1p5'+str(time.strftime("%Y%m%d"))+'.pdf', format='pdf', dpi=600)
plt.show()



################################################################
#          PLOT FIGURE          gamma = 1.5                    #
################################################################

fig = plt.figure(dpi=150)
ax1 = fig.add_subplot(111)

plt.rc('text', usetex=True)
plt.rc('font', size=15)

#ax1.plot(MA[:4],conser_res[:4], '--', label='conservative',color='grey')
#ax1.plot(MA[:4],opt_res[:4], '--', label='optimistic',color='blue')
for index,nuclear_model in enumerate(Sens_UL):
    ax1.plot(MA[8:12],nuclear_model[8:12], '--', label=labels_nuclearmodels[index])


ax1.set_yscale('log')
ax1.set_xscale('log')
#ax1.set_xticks([1.1e1,1.5e1,1e2])
#ax1.set_xticklabels(['11','15','100'])

ax1.set_xticks(MA[8:12])
ax1.set_xticklabels(['50','100','200','400'])
ax1.set_xlabel(r'$m_\psi~\textrm{ (GeV)}$', fontsize=20)
ax1.set_ylabel(r'$\frac{g_{Z^\prime}^4}{10^{-6}}$',rotation=0, fontsize=30,labelpad=25)
ax1.set_ylim(1e-7, 1e-5)
ax1.set_yticks([2e-7,5e-7,1e-6,2e-6,5e-6])
ax1.set_yticklabels([r'$0.2$',r'$0.5$',r'$1$' ,r'$ 2 $',r'$5$'])
minx,maxx = ax1.get_xlim()

ax1.minorticks_off()
ax1.legend(title=r'$\gamma=10$',fontsize = 12, frameon=True)
plt.text(50,5e-6,"DUNE PRELIMINARY", alpha=0.7)
plt.tight_layout()
plt.savefig('Last_Sensit_b10'+str(time.strftime("%Y%m%d"))+'.pdf', format='pdf', dpi=600)
plt.show()