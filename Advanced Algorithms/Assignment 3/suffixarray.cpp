#include<iostream>
#include<string.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>	

using namespace std;
struct suffix{
	int start;
	char* sfx;
};

struct details{
	int docno;
	int offset;
};
struct subset{
	int docoffset;
	int start;
	int end;
	int len;
};

struct index{
	int first;
	int second;
};
struct results{
	string matched_string;
	vector<struct index>indices;
};

int pstrcmp(const void *a, const void *b) {
    
    return strcmp((const char *)*(char **)a, (const char *)*(char **)b);
}
int lcp(char *a, char *b) {
    int len1, len2;
    int i;
    len1 = strlen(a);
    len2 = strlen(b);
    for (i = 0; (i < len1) && (i < len2); ++i) {
        if (a[i] != b[i]) break;
    }
    return i;
}

void LCS(char*a, char *b, char *out) {
    int i;
    char **ap;      //suffix pointers array
    int len1, len2;
    char *cstr;
    int lcslen = 0, lcplen, lcssufpos = -1;
    len1 = strlen(a);
    len2 = strlen(b);
    ap = (char**)malloc((len1+len2)*sizeof(char*));
    cstr = (char*)malloc((len1+len2)*sizeof(char));
    cstr = strcat(a, b);
    
    for (i = 0; i < len1+len2; ++i) {
        ap[i] = &(cstr[i]);
    }
	
  
    qsort(ap, len1+len2, sizeof(char *), pstrcmp);

    
    for (i = 0; i < len1 + len2 - 1; ++i) {
        if ((ap[i] - cstr >= len1) && (ap[i+1] - cstr >= len1)) {
            //both starts with suffix of second string
            continue;
        } else if ((ap[i] - cstr < len1) && (ap[i+1] - cstr < len1)) {
            //both starts with suffix of first string
            continue;
        } else {
            lcplen = lcp(ap[i], ap[i+1]);
            if (lcplen > lcslen) {
                lcslen = lcplen;
                lcssufpos = i;
            }
        }
    }
    
    if (lcssufpos == -1) {
    	
    
    	strcpy(out, "");
    	
    	return;
    } else {
    	
    	char buf[3000];
    	snprintf(buf, 3000, "%.*s", lcslen, ap[lcssufpos]);
    	
    	strcpy(out, buf);
    
    
        //printf("%.*sn", lcslen, ap[lcssufpos]);
    }
}


int comp(struct suffix s1, struct suffix s2){
	return strcmp(s1.sfx, s2.sfx)<0?1:0;
}

void buildarray(char *s, struct suffix *suffixarray, int *suford, int len){
	for(int i = 0; i<len; i++){
		suffixarray[i].start = i;
		suffixarray[i].sfx = s+i;
	}
	sort(suffixarray, suffixarray+len, comp);
	
	for(int i = 0; i<len; i++){
		suford[i] = suffixarray[i].start;
		
	}
	
}

vector <int> find(char *search, char *input,int *suford, int len){
	int patlen = strlen(search);
	vector<int> foundindices;
	int left = 0;
	int mid, result;
	int right = len-1;
	
	for(int i = 0; i<len; i++){
		
		if(suford[i] + patlen <=len){
		
		result = 0;
		for(int j = 0; j<patlen; j++){
			
			if(input[suford[i]+j] != search[j]){
				result = -1;
				break;
			}
			else{
			
				
			}
		}
		result = strncmp(search, input + suford[i], patlen);
		if(result == 0){
			foundindices.push_back(suford[i]);
		
		}
	}
	
	}
		
	
	
	

	return foundindices;
}

void substring(char *dest, char *src, int start, int offset){
	int c =0;
	int length = offset-start+1;
	while(c<length){
		dest[c] = src[start+c];
		c++;
	}
	dest[c] = '\0';
	return;
	
}

int find_LCS(char *sub, char *s, int *suford, int len){

	int patlen = strlen(sub);
	vector<int> foundindices;
	int left = 0;
	int mid, result;
	int right = len-1;
	
	for(int i = 0; i<len; i++){
		
		if(suford[i] + patlen <=len){
		
		result = 0;
		for(int j = 0; j<patlen; j++){
			
			if(s[suford[i]+j] != sub[j]){
				result = -1;
				break;
			}
			else{
			
				
			}
		}
		result = strncmp(sub, s + suford[i], patlen);
		if(result == 0){
			foundindices.push_back(suford[i]);
			
		}
	}
	
	}
	if(foundindices.empty() == true){
		return -1;
	}
	
	sort(foundindices.begin(), foundindices.end());
	return foundindices[0];
}

struct results findoc(vector<string> document, char *search){
	int n = document.size();
	if(n == 0){
		struct results tt;
		
		return tt;
	}
	if(strlen(search) == 0){
		struct results tt;
		return tt;
	}
	int *suford;
	vector<struct details> out1;
	vector<struct subset> LCSArray;
	struct details d1;
	struct subset s1, temp;
	struct suffix *suffixarray;
	char s[50000];
	string sst;
	char longest[5000];
	for(int i = 0; i<n; i++){
		
		//Iterate through every document
		suffixarray = (struct suffix*)malloc(sizeof(struct suffix)*(document[i].length()));
		//suffixarray for document[i]
		suford = (int *)malloc(sizeof(int)*(document[i].length()));
		strcpy(s, document[i].c_str());
		buildarray(s,suffixarray,suford, document[i].length());
		char sub[5000];
		int inout = -1;

		string in1 = document[i];
		vector<int>found = find(search, s,suford, in1.length()); //Find the complete pattern
	
		if(found.empty()==false){
			sort(found.begin(), found.end()); //sort based on location
			d1.docno = i;
			d1.offset = found[0];
			out1.push_back(d1); //Output contains first occurence of pattern in text of document[i]
		
		}
		else if(found.empty() == true && out1.empty() == false){
			continue;
		}

		else{
		
			s1.docoffset = i; //Longest partial match in document[i]
			int patl = strlen(search);
			char stemp[50000];
		
			strcpy(stemp, document[i].c_str());
			
			LCS(stemp, search, longest);
			

			if(strlen(longest)==0){
				
				s1.start = -1;
				s1.len = 0;
			}
		//	printf("substr is %s\n", outp[0]);
			
			if(strlen(longest) != 0){
				//int inout;
				
				char *sp = (char*)malloc(sizeof(char)*3000);
				strcpy(sp, longest);
				inout = find_LCS(sp, s, suford,strlen(s) );
				s1.len = strlen(longest);
				s1.start = inout;
				
			}

			
			if(LCSArray.empty() == true && strlen(longest)>0){
				
				sst = string(longest);
				LCSArray.push_back(s1);	//Longest substring of document[i] pushed in.
			}
			if(LCSArray.empty() == false && LCSArray[0].len<strlen(longest)){
				
				sst = string(longest);
				LCSArray[0] = s1;
			}
		}
	
	}
	
	if(LCSArray.empty() && out1.empty()){ // No matches
		
		struct details s1;
		s1.docno = -1;
		s1.offset = -1;
		out1.push_back(s1);
		struct results r1;
		return r1;
		
	}
	else if(out1.empty() == false){ // Full Match in all documents
		struct results r1;
		r1.matched_string = string(search);
		struct index t1;
		for(int i = 0; i<out1.size();i++){
			t1.first = out1[i].docno;
			t1.second = out1[i].offset;
		//	printf("indices.size = %d", r1.indices.size());
			r1.indices.push_back(t1);
		}
		
		return r1;
	}
	else{
		struct results r1;
		r1.matched_string = sst;
		struct index t1;
		t1.first = LCSArray[0].docoffset;
		t1.second = LCSArray[0].start;
		r1.indices.push_back(t1);
		return r1;
		int n = LCSArray.size();
		for(int i = 0; i<n; i++){
			printf("%d %d\n", LCSArray[i].docoffset, LCSArray[i].start);
			break;
		}
	
	}
	
}
int main(){
	
	int n;
//	printf("Enter the number of documents\n");
	scanf("%d", &n);

	
	char *s = (char*)malloc(sizeof(char)*100000);
	vector<string> document;
//	printf("Enter the documents\n");
	for(int i = 0; i<n; i++){
		
		scanf("%s", s);

		
		document.push_back(s);
	
		
	}
	
	

	char *search;

	//scanf("%[^\n]%*c", search);

	int n2;
	//printf("Enter the number of patterns\n");
	scanf("%d", &n2);
	//printf("Enter the patterns\n");
	vector<struct details>d1;
	struct results r;
//	printf("n2 = %d\n", n2);

	for(int i = 0; i<n2; i++){
		search = (char*)malloc(sizeof(char)*300000);
		
		cin>>search;
		
		r = findoc(document, search);
		
		if(r.matched_string.empty() ==true && r.indices.empty() == true){
			printf("-1\n");
			
		}
	
		else{
		printf("%s \n", r.matched_string.c_str());
		for(int i = 0; i<r.indices.size(); i++){
			printf("%d %d\n", r.indices[i].first, r.indices[i].second);
		
	}
	
	}
	free(search);

}
}




