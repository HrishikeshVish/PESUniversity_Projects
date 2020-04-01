#include "../include/the_messenger.hpp"
#include <vector>
#include <string>
#include<string.h>
using namespace std;

int min(int, int);
int mincost_memoize(int, int, int*, char*, int);
class the_messenger_implementation : public the_messenger
{
public:
    int solve(int, int, int, string);
};

int the_messenger_implementation::solve(int cost1, int cost2, int length, string inputstr){
	int arr[length];
	for(int i = 0; i<length; i++){
		arr[i] = -1;
	}
	char str[length+1];
	strcpy(str, inputstr.c_str());
	return mincost_memoize(cost1, cost2, arr, str, 0);	
}


int min(int a, int b){
	return a>b?b:a;
}

int mincost_memoize(int c1, int c2, int *arr, char *str, int secondhalf){
	
	if(secondhalf>=strlen(str)-1){
		return 0;
	}

	if(arr[secondhalf] !=-1){
		return arr[secondhalf];
	}
	
	int t = secondhalf;
	int initialsecond;
	int start = 0;

	if(t == 0){
		arr[t] = c1 + mincost_memoize(c1, c2, arr, str, secondhalf+1);
		return arr[t];
	}

	else{
	
	start = 0;
	initialsecond = secondhalf;
	int longest=0;
	while(start<initialsecond){
		if(t != initialsecond && str[start] != str[t] && start+1 !=initialsecond){
			if(t>=longest){
				longest = t;
			}
			t = initialsecond;
			
			
		}
		if(str[start] == str[t]){

			start++;
			t++;
		}
		else{
			start++;
		}
	}
	}

	if(t == secondhalf){
		arr[secondhalf] = c1 + mincost_memoize(c1, c2, arr, str, secondhalf+1);
	}
	
	else{

	arr[secondhalf] = min(c1+ mincost_memoize(c1, c2, arr, str, secondhalf+1), c2+ mincost_memoize(c1, c2, arr, str, t));

}

	return arr[secondhalf];
}
