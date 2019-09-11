int main(){


int n;





scanf("%d", &n);


int a[n];


for (int i = 0; i <n; i++){


 scanf("%d", &a[i]);


}





int k;


scanf("%d", &k);


// struct timespec start,end;





// clock_gettime(CLOCK_REALTIME, &start); 


printf("%d", seqsearch(a, n, k));


// clock_gettime(CLOCK_REALTIME, &end);





// double timeinseconds= end.tv_nsec - start.tv_nsec;


// printf("\n %lf", timeinseconds);





}




 int seqsearch(int *arr, int n, int key){
 
arr[n] = key;


int i = 0;


while(arr[i] != key){


 i++;


 }


if(i>=n){


 return -1;


 }


return i;


}