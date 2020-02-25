import random
import matplotlib.pyplot as plt

def simplegrad(w0, t, o):
    w_val = []
    i = 0
    while(w0*x !=t and i<200):
        w_val.append(w0)
        w0 = w0 - 0.01*45*(t-o)
        i+=1
        o = w0*45.0
    return w_val
def momentum(w0, t, o):
    m_val = []
    m0 = 0.01
    beta = 1-0.01
    i = 0
    
    while(w0*x!=t and i<200):
        m0 = beta*m0 + (1-beta)*45*(t-o)
        m_val.append(w0)
        w0 = w0 - m0
        o = w0*45.0
        i+=1
    return m_val
def rmsprop(w0, t, o):
    r_val = []
    n = 0.01
    i = 0
    sdw = 0
    
    while(w0*x!=t and i<200):
        r_val.append(w0)
        sdw = (1-0.01)*sdw + 0.01*((45*(t-o))**2)
        w0 = w0 - 0.01*(45*(t-o))/((sdw+0.001)**0.5)
        o = w0*45
        i+=1
    return r_val
def adam(w0, t, o):
    a_val = []
    n = 0.01
    i = 0
    sdw = 0
    m0 = 0
    beta = 1-0.01
    while(w0*x!=t and i<200):
        a_val.append(w0)
        sdw = beta*sdw + (1-beta)*((45*(t-o))**2)
        m0 = m0*beta + (1-beta)*(45*(t-o))
        w0 = w0 - 0.01*m0/((sdw+0.001)**0.5)
        o = w0*45
        i+=1
    return a_val

    
        
        
        
        

expected_o = 0.2375
actual_o = 100.0

x = 45.0
w0 = 100.0/45.0

n = 0.01

withoutmom = simplegrad(w0, expected_o, actual_o)
withmom = momentum(w0, expected_o, actual_o)
rmsop = rmsprop(w0, expected_o, actual_o)
adamop = adam(w0, expected_o, actual_o)
a = range(1,201)
plt.plot(a, withoutmom, color="blue")
plt.plot(a, withmom, color="red")
plt.plot(a, rmsop, color="green")
plt.plot(a, adamop, color="yellow")
plt.show()
print(withoutmom)
print(withmom)
print(rmsop)
print(adamop)
