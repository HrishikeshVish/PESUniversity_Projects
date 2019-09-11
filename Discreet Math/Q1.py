def biggest(i):
	j = i
	k = 2
	l = 0
	
	while (j>1):
		if(j%k == 0):
			if (k>l):
				l = k;
			j = j/ k;
			k = 2
		k = k + 1
			
	return l

def isprime(x):
	count = 0
	j = int(x/2)
	for i in range(1,j):
		if(x%i == 0):
			count =count +1
	return (count==2)




#i = int(input("Enter the value"))

print("The biggest prime factor of 600851475143 is " + str(biggest(600851475143)))

