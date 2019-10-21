/* A Naive recursive implementation of 0-1 Knapsack problem */
#include <bits/stdc++.h> 
#include<ctime>
using namespace std; 

struct Item 
{ 
	float weight; 
	int value; 
}; 

struct Node 
{ 
	int level, profit, bound; 
	float weight; 
}; 

bool cmp(Item a, Item b) 
{ 
	double r1 = (double)a.value / a.weight; 
	double r2 = (double)b.value / b.weight; 
	return r1 > r2; 
}


int bound(Node u, int n, int W, Item arr[]) 
{ 

	if (u.weight >= W) 
		return 0; 

	int profit_bound = u.profit; 

	int j = u.level + 1; 
	int totweight = u.weight; 

	while ((j < n) && (totweight + arr[j].weight <= W)) 
	{ 
		totweight += arr[j].weight; 
		profit_bound += arr[j].value; 
		j++; 
	} 

	if (j < n) 
		profit_bound += (W - totweight) * arr[j].value / 
										arr[j].weight; 

	return profit_bound; 
} 

int knapSack_branchnbound(int W, Item arr[], int n) 
{ 
	sort(arr, arr + n, cmp); 

	queue<Node> Q; 
	Node u, v; 

	u.level = -1; 
	u.profit = u.weight = 0; 
	Q.push(u); 

	int maxProfit = 0; 
	while (!Q.empty()) 
	{ 
		u = Q.front(); 
		Q.pop(); 

		if (u.level == -1) 
			v.level = 0; 

		if (u.level == n-1) 
			continue; 

		v.level = u.level + 1; 

		v.weight = u.weight + arr[v.level].weight; 
		v.profit = u.profit + arr[v.level].value; 

		if (v.weight <= W && v.profit > maxProfit) 
			maxProfit = v.profit; 

		v.bound = bound(v, n, W, arr); 

		if (v.bound > maxProfit) 
			Q.push(v); 

		v.weight = u.weight; 
		v.profit = u.profit; 
		v.bound = bound(v, n, W, arr); 
		if (v.bound > maxProfit) 
			Q.push(v); 
	} 

	return maxProfit; 
} 


int max(int a, int b) { return (a > b)? a : b; } 

int knapSack_backtracking(int W, int wt[], int val[], int n) 
{ 
	
 
if (n == 0 || W == 0) 
	return 0; 

if (wt[n-1] > W) 
	return knapSack_backtracking(W, wt, val, n-1); 

else return max( val[n-1] + knapSack_backtracking(W-wt[n-1], wt, val, n-1), 
					knapSack_backtracking(W, wt, val, n-1) ); 
} 

int knapSack_dp(int W, int wt[], int val[], int n) 
{ 
int i, w; 
int K[n+1][W+1]; 

 
for (i = 0; i <= n; i++) 
{ 
	for (w = 0; w <= W; w++) 
	{ 
		if (i==0 || w==0) 
			K[i][w] = 0; 
		else if (wt[i-1] <= w) 
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]); 
		else
				K[i][w] = K[i-1][w]; 
	} 
} 

return K[n][W]; 
}

 

double knapSack_greedy(int W, struct Item arr[], int n) 
{ 
 
	sort(arr, arr + n, cmp); 


	int curWeight = 0;  
	double finalvalue = 0.0;  

	 
	for (int i = 0; i < n; i++) 
	{ 
		
		if (curWeight + arr[i].weight <= W) 
		{ 
			curWeight += arr[i].weight; 
			finalvalue += arr[i].value; 
		} 

		else
		{ 
			int remain = W - curWeight; 
			finalvalue += arr[i].value * ((double) remain / arr[i].weight); 
			break; 
		} 
	} 

	
	return finalvalue; 
}
int main() 
{ 
	clock_t cur, next;
	int val[] = {60, 100, 120}; 
	int wt[] = {10, 20, 30}; 
	Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; 
	Item arr2[] = {{2, 40}, {3.14, 50}, {1.98, 100}, 
                  {5, 95}, {3, 30}}; 
	int W = 50; 
	int n = sizeof(val)/sizeof(val[0]); 
	cur = clock();
	cout<<knapSack_backtracking(W, wt, val, n)<<"\n"; 
	next = clock();
	cout<<"backtracking time taken = "<<(double)(next-cur)/ (double)(CLOCKS_PER_SEC / 1000)<<"\n";
	cur = clock();
	cout<<knapSack_dp(W, wt, val, n)<<"\n";
	next = clock();
	cout<<"DP time taken = "<<(double)(next-cur)/ (double)(CLOCKS_PER_SEC / 1000)<<"\n";
	int n2 = sizeof(arr)/sizeof(arr[0]);
	cur = clock();
	cout<<knapSack_greedy(W, arr, n2)<<"\n";
	next = clock();
	cout<<"Greedy time taken = "<<(double)(next-cur)/ (double)(CLOCKS_PER_SEC / 1000)<<"\n";
	int n3 = sizeof(arr2)/sizeof(arr2[0]);
	cur = clock();
	cout<<knapSack_branchnbound(10, arr2, n3)<<"\n";
	next = clock();
	cout<<"Branch and Bound time taken = "<<(double)(next-cur)/ (double)(CLOCKS_PER_SEC / 1000)<<"\n";
	return 0; 
}

 

 

