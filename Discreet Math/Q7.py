
i = 1;
j = 1;
count =0
while(len(str(i)) <1000 or len(str(j)) <1000):
	i = i + j
	j = i + j
	count = count + 2
	

print ("Count is " + str(count))
#print(j)