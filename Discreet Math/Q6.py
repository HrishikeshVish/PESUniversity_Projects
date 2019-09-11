def factorial(i):
	p = 1
	for j in range(1,i+1):
		p = p*j
	return p


def fact(l, l2,j, y, x):
	if(x>=10):
		return l2


	l2[x] = l[int(j/factorial(y))]
	
	l.remove(l[int(j/factorial(y))])
	return fact(l, l2, j%factorial(y), y-1, x+1)



#i = int(input("Enter the term"))



l =[0,1,2,3,4,5,6,7,8,9]
y = 9
l2 = [0,0,0,0,0,0,0,0,0,0];

l2[0] = l[int((1000000-1)/factorial(y))]
l.remove(l[int((1000000-1)/factorial(y))])
j = (1000000-1)%factorial(y)
y = y - 1

print("The " + str(1000000)+"th permutation is " )

l3 = fact(l,l2,j,y,1);
for i in range(0, len(l3)):
	print(l3[i], end="")


