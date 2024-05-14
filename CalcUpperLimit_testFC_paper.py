import math
import numpy as np

def factorial(n):
    if n==0:
        return 1
    return n*factorial(n-1)

def poisson_prob(n,mu,b):
    return math.e**(-(mu+b))*(mu+b)**n/factorial(n)

nbkg = 3
nobs_evts = np.arange(0,round(3*nbkg),1)
mu = 0.
results_ul=[]
ul=0.9
ul_tmp=.0
for nobs in nobs_evts:
    if nobs <= nbkg:
        mu_best = 0
    else:
        mu_best = nobs - nbkg 
    
    higher_prob = poisson_prob(nobs,mu_best,nbkg)
    prob_tmp = poisson_prob(nobs,mu,nbkg)
    R_test = prob_tmp/higher_prob
    results_ul.append([nobs,mu_best,R_test,prob_tmp])


results_ul = np.array(results_ul) 
index = np.flip(np.argsort(results_ul[:,2]))  

# To get sorted array using sorted indices 
# c is temp array created of same len as of b 
#c = np.zeros(len(index), dtype = int) 
for i in range(0, len(index)): 
    if ul_tmp<=ul:
        ul_tmp=ul_tmp+results_ul[index[i]][3]
    else:
        print(i)
print(ul_tmp)
