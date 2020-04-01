#include "../include/survival_of_the_fittest.hpp"
#include <vector>
#include<stdlib.h>
using namespace std;

struct record{
	int a;int p;int k;	
	double table[3];
	//vector<double> table;
};

struct outtable{
			double a;
			double b;
			double c;
};
	struct outtable finalout;
struct outtable probab(int, int, int, struct record ***);
class survival_of_the_fittest_implementation : public survival_of_the_fittest
{
public:
	

	struct outtable out;
    vector<double> solve(int, int, int);
};


struct outtable probab(int archers, int pikemen, int knights, struct record ***obj){
	
	
		int a = archers;
		int p = pikemen;
		int k = knights;
	
		
		if(obj[a][p][k].table[0] != -1.0 && obj[a][p][k].table[1] != -1.0 && obj[a][p][k].table[2] != -1.0)
		{
	
			
			finalout.a = obj[a][p][k].table[0];
			finalout.b = obj[a][p][k].table[1];
			finalout.c = obj[a][p][k].table[2];

			return finalout;
		}	

		finalout.a = 0.0;
		finalout.b = 0.0;
		finalout.c = 0.0;
		vector<double>a6;
		vector<double>a7;
		vector<double>a8;
		if(archers == 0.0 && pikemen ==0.0 && knights ==0.0){
			obj[a][p][k].table[0] = 0.0;
			obj[a][p][k].table[1] = 0.0;
			obj[a][p][k].table[2] = 0.0;
			return finalout;
		}
		if(archers == 0.0 && pikemen >0.0 && knights >0.0){
			obj[a][p][k].table[0]= 0.0;
			obj[a][p][k].table[1] = 1.0;
			obj[a][p][k].table[2] = 0.0;
			finalout.a = 0.0;
			finalout.b = 1.0;
			finalout.c = 0.0;
			return finalout;
		}
		if(archers>0.0 && pikemen == 0.0 && knights >0.0){
			obj[a][p][k].table[0] = 0.0;//.push_back(0);
			obj[a][p][k].table[1] = 0.0;//.push_back(0);
			obj[a][p][k].table[2] = 1.0;//.push_back(1.0);
			finalout.a = 0.0;
			finalout.b = 0.0;
			finalout.c = 1.0;
			return finalout;
		}
		if(archers>0.0 && pikemen >0.0 && knights ==0.0){
			obj[a][p][k].table[0] = 1.0;//.push_back(1.0);
			obj[a][p][k].table[1] = 0.0;//.push_back(0);
			obj[a][p][k].table[2] = 0.0;//.push_back(0);
			finalout.a = 1.0;
			finalout.b = 0.0;
			finalout.c = 0.0;
			return finalout;
		}
		if(archers == pikemen && archers == knights){
			obj[a][p][k].table[0] = 1.0/3.0;//.push_back(1.0/3.0);
			obj[a][p][k].table[1] = 1.0/3.0;//.push_back(1.0/3.0);
			obj[a][p][k].table[2] = 1.0/3.0;//.push_back(1.0/3.0);
			finalout.a = finalout.b = finalout.c = 1.0/3.0;
			return finalout;
		}

		
		
		struct outtable a1;
		a1.a = 0.0; 
		a1.b = 0.0;
		a1.c = 0.0;

		
		int den = ((a*p)+(p*k)+(k*a));
		
		a1 = probab(archers, pikemen-1, knights, obj);
		
		struct outtable a2;
		a2.a = 0.0;
		a2.b = 0.0;
		a2.c = 0.0;

		
		a2 = probab(archers-1, pikemen, knights, obj);
		
		struct outtable a3;
		a3.a = 0.0;
		a3.b = 0.0;
		a3.c = 0.0;

		
		a3 = probab(archers, pikemen, knights-1, obj);
		
		double ap = (double)a*(double)p/(double)den;
		double pk = (double)p*(double)k/(double)den;
		double ak = (double)k*(double)a/(double)den;

		
		obj[a][p-1][k].table[0] = a1.a;//.push_back(a1[0]);
		obj[a][p-1][k].table[1] = a1.b;//.push_back(a1[1]);
		obj[a][p-1][k].table[2] = a1.c;//.push_back(a1[2]);
		
		obj[a-1][p][k].table[0] = a2.a;//.push_back(a2[0]);
		obj[a-1][p][k].table[1] = a2.b;//.push_back(a2[1]);
		obj[a-1][p][k].table[2] = a2.c;//.push_back(a2[2]);
		
		obj[a][p][k-1].table[0] = a3.a;//.push_back(a3[0]);
		obj[a][p][k-1].table[1] = a3.b;//.push_back(a3[1]);
		obj[a][p][k-1].table[2] = a3.c;//.push_back(a3[2]);
		
		obj[a][p][k].table[0] = ap*a1.a+ak*a2.a+pk*a3.a;
		obj[a][p][k].table[1] = ap*a1.b+ak*a2.b+pk*a3.b;
		obj[a][p][k].table[2] = ap*a1.c+ak*a2.c+pk*a3.c;
		
		
	
		finalout.a = obj[a][p][k].table[0];
		finalout.b = obj[a][p][k].table[1];
		finalout.c = obj[a][p][k].table[2];
		return finalout;

		
	}
	vector<double> product(double frac, vector<double> a){
		a[0] = a[0] *frac;
		a[1] = a[1] *frac;
		a[2] = a[2] *frac;
		return a;
	}



vector<double> survival_of_the_fittest_implementation::solve(int a, int p, int k){
	struct outtable output;
	struct record ***t = (struct record ***)malloc(sizeof(struct record **)*(a+1));
		for(int i = 0; i<=a; i++){
			t[i] = (struct record **)malloc(sizeof(struct record *)*(p+1));
			for(int j = 0; j<=p; j++){
				t[i][j] = (struct record *)malloc(sizeof(struct record)*(k+1));
				for(int l = 0; l<=k; l++){
					t[i][j][l].table[0] = -1;
					t[i][j][l].table[1] = -1;
					t[i][j][l].table[2] = -1;
				
					
				}

			}
		}
	output = probab(a, p, k, t);
	vector<double>out;
	out.push_back(output.a);
	out.push_back(output.b);
	out.push_back(output.c);
	return out;
}
