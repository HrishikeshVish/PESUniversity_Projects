def sumdia(a):
	if(a==0):
		return 1;

	t1 = 2*a + 1;
	t2 = t1**2;
	t2 = t2*4;
	return (t2 - (12*a) + sumdia(a-1));

print("The sum of the diagonals in a 1001x1001 spiral is " + str(sumdia(1001//2)))