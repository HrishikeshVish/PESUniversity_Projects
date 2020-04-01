import random
import time
import matplotlib.pyplot as plt

def rabinMiller(num, k):
   

    s = num - 1
    t = 0
    while s % 2 == 0:

        s = s // 2
        t += 1

    for trials in range(k):
        a = random.randrange(2, num - 1)
        v = pow(a, s, num)
        if v != 1: 
            i = 0
            while v != (num - 1):
                if i == t - 1:
                    return False
                else:
                    i = i + 1
                    v = (v ** 2) % num
    return True


def isPrime(n, k):


    if (n < 2 or (n%2 == 0 and n!=2)):
        return False
    if(n == 2):
        return True
    if(n==3 or n==5):
        return True

    return rabinMiller(n, k)


def generateLargePrime(keysize=1024):

    while True:
        num = random.randrange(2**(keysize-1), 2**(keysize))
        if isPrime(num):
            return num


def constantk():
    length = []
    timeel = []
    for i in range(5):
    
        n = input("Enter a Number")
        start = time.time()
        length.append(len(n))
        n = int(n)
        for k in range(1,16):
            print(isPrime(n,k))
        end = time.time()
        timeel.append(end-start)
    print(length)
    print(timeel)
    plt.plot(length, timeel)
    plt.xlabel("Length of input")
    plt.ylabel("Time taken to check if prime")
    plt.show()


def varyingk():
    ktuple = []
    ti = []
    n = int(input("Enter a Number"))

    for k in range(1,16):
        start = time.time()
        ktuple.append(k)
        print(isPrime(n,k))
        end = time.time()
        ti.append(end-start)
    plt.plot(ktuple, ti)
    plt.xlabel("K values (Constant length of 6168 digits)")
    plt.ylabel("time taken")
    plt.show()

    

    
        
