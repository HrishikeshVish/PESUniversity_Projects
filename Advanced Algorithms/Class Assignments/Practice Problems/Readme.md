October 21, 2019


Knapsack problem
given N items with weights w1, w2....wn, values v1, v2 ... vn and a knapsack of capacity w. Find the most valuable subset that 
fits into the knapsack. 
1. Define a solution space having feasible and infeasible solutions in it for the optimization problem
2. Design an exhaustive search algorithm and derieve the complexity of the algorithm
3. Design a recurrence with its state space tree representation
4. Design a backtracking algorithm using the recurrence and derieve the complexity of the algorithm
5. Design a greedy algorithm which is optimal but leads to an approximation algorithm
6. Design a branch and bound algorithm using the greedy approach
7. Design a dynamic programming algorithm with some constraints on the weights

Implement and Compare the algorithms for finding the Binomial Coefficient
1. Binomial_coeff(n, k, DP):

	DP[i,0] and DP[i,i] are initialized to 1. everything is initialized to -1
	
	if(DP[n,k] == -1):
	
		DP[n,k] = BC(n-1, k, DP) + BC(n-1, k-1, DP);
		
	return DP[n,k]
2. Binomial(n,k):

	for i <- 0 to n:
	
		for j<- 0 to min(i,k):
		
			if(j == 0 or j == i) DP[i,j] <- 1
			
			else DP[i,j] = DP[i-1, j-1] + DP[i-1, j]
			
	return DP[n,k]
3. Binomial(n, k):

	if(n-k<k) k<- n-k
	
	for i<-0 to n:
	
		for j<- max(0, k-(n-i)) to min(i,k):
		
			if(j = 0 or j = i) DP[i mod 2, j] = 1
			
			else DP[i mod 2, j] <- DP[i-1mod 2, j] + DP[i-1 mod 2, j-1]
			
	return DP[n mod 2, k]
	

BST Problem

We are given a sequence k = <k1, k2, ..., kn> of n distinct keys in sorted order so that k1<k2 ... kn, and we wish to build a 
BST from these keys. For each key ki, we have probability pi that a search will be for ki. Some searches may be for values not in
K, and so we also have n+1 dummy keys. d0, d1...dn representing values not in K. d0 represents all values less than k1. dn represents
all values greater than kn. i = 1,2,...n-1 the dummy key di represents all values between ki and ki+1. For each di, we have a probability
qi that a search will correspond to di. Note that each key ki is an internal node and each dummy key di is a leaf. 

Find a way of constructing an optimal BST of k such that the expectations of the search is minimized. return the optimal value. 


Eat Cake Problem
Wheatley is at the best party in the world: it has infinitely many cakes. Each cake is a square with an integer side length(in cm)
. the party has inifnitely many cakes of every possible integer side length. the cakes all have the same depth. We only
consider their areas. 
	
Wheatley is determined to eat one or more cakes that have a total combined area of exactly N cm. since he is health conscious, 
he wants to eat as few cakes as possible. calculate the minimum number of cakes. 


