/*Wheatley is at the best party in the world: it has infinitely many cakes. Each cake is a square with an integer side length(in cm)
. the party has inifnitely many cakes of every possible integer side length. the cakes all have the same depth. We only
consider their areas. 

Wheatley is determined to eat one or more cakes that have a total combined area of exactly N cm. since he is health conscious, 
he wants to eat as few cakes as possible. calculate the minimum number of cakes. 
*/
#include <bits/stdc++.h> 
using namespace std; 


int getMinSquares(unsigned int n) 
{ 

	if (sqrt(n) - floor(sqrt(n)) == 0) 
		return 1; 
	if (n <= 3) 
		return n; 

	int res = n; 

	for (int x = 1; x <= n; x++) { 
		int temp = x * x; 
		if (temp > n) 
			break; 
		else
			res = min(res, 1 + getMinSquares(n - temp)); 
	} 
	return res; 
} 

int main() 
{ 
	cout << getMinSquares(9); 
	return 0; 
} 

