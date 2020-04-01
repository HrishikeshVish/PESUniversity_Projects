
import random 
import matplotlib.pyplot as plt
import time
def power(x, y, p): 
	

	res = 1; 

	x = x % p; 
	while (y > 0): 
		

		if (y & 1): 
			res = (res * x) % p; 

		y = y>>1; 
		x = (x * x) % p; 
	
	return res; 

def miillerTest(d, n): 

	a = random.randint(2, n//2)
	x = power(a, d, n);
	if (x == 1 or x == n - 1): 
		return True; 
 
	while (d != n - 1): 
		x = (x * x) % n; 
		d *= 2; 
		if (x == 1): 
			return False; 
		if (x == n - 1): 
			return True; 
	return False; 

def isPrime( n, k): 
	if (n <= 1 or n == 4): 
		return False; 
	if (n <= 3): 
		return True; 

	d = n - 1; 
	while (d % 2 == 0): 
		d //= 2; 

	for i in range(k): 
		if (miillerTest(d, n) == False): 
			return False; 

	return True;
"""
for i in range(10):
        a = int(input("Enter a Number"))
        for k in range(1,16):
                out = isPrime(a,k)
                print(" k = " + str(k) + " Output is " + str(out)) 

#k = 244; 
#a = input("Enter a Number")
#print(len(a))
#n = int(a)
#print(isPrime(n, k))
"""
def GenerateComposites(n):
        f = open("Composites.txt", "w")
        for i in range(1, n+1):
                if(isPrime(i, 15) == False):
                        f.write(str(i) + "\n")
        f.close()
def AccuracyPlot():
        f = open("D:\\Users\\Hrishi\\Documents\\PESU\\5th Semester\\Advanced Algorithms\\Assignment 4\\Composites.txt", "r")
        a = f.read()
        c_list = []
        accuracy_tuple = []
        for i in a.split("\n"):
                if(len(i)>0):
                        c_list.append(i)
        accuracy_tuple.append(0)        
        for k in range(1,10):
                count = 0
                for i in c_list:
                        if(isPrime(int(i), k) == True):
                                #print(True)
                                count+=1
                accuracy_tuple.append((len(c_list) - count)/len(c_list))
                print(count)
        print(accuracy_tuple)
        k = range(1,16)
        #plt.plot(k, accuracy_tuple)
        #plt.xlabel("K Value")
        #plt.ylabel("Accuracy")
        #plt.show()
        
#AccuracyPlot()

def plot():
        L = [220, 6, 0, 0,0,0,0,0,0,0]
        L2 = [0.9999527032866486, 0.9999987100896359, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0]
        K = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        plt.plot(K, L)
        plt.xlabel("K Value")
        plt.ylabel("Number of incorrectly labelled values")
        plt.show()
        plt.plot(K, L2)
        plt.xlabel("K Value")
        plt.ylabel("Accuracy")
        plt.show()
#plot()

def constantk():
    length = []
    timeel = []
    for i in range(5):
    
        n = input("Enter a Number")
        start = time.time()
        length.append(len(n))
        n = int(n)
        
        print(isPrime(n,5))
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

#constantk()
varyingk()
                

"""
k = 5;
f = open("Composites.txt", "r");
#a = f.readline()
#print(a)
#a = f.readline()
#print(a)
count = 0
composites = []
a = f.read()
l = list(a.split("\n"))
#print(l)
for i in range(len(l)):
        if(len(l[i])>0):
                b = int(l[i])
                if(isPrime(b,3) == True):
                        count+=1
                        print(True)
print((len(l)-count)/len(l)*100)
                
print("All primes smaller than 100: "); """"""
while(f.read(a) != "\0"):
        a = int(a)
        if (isPrime(a, 1) == True):
            print(a);
            #f.write(str(n)+ "\n")
f.close()"""

