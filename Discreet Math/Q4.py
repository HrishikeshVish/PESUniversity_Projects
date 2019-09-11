

def fact(a):
	p = 1;
	for i in range(1, a+1):
		p = p *i;
	return p

def numroutes(row, col):
	a = fact(row);
	b = fact(col);
	c = fact(row + col);
	return (c//(a*b));

print("The Number of possible routes in a 20x20 square are : " + str(numroutes(20,20)));
