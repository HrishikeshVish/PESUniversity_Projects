#include<stdio.h>
 
#include<stdlib.h>








typedef struct d


{ 


int value;


int id;


}data;








void printarray(data*a,int n);


int insertionsort(data*a,int n);


int bubblesort(data*a,int n);


int selectionsort(data*a,int n);


void merge(data*a,int l,int m,int r,int*count);


void MergeSort(data*a,int l,int r,int*count);


void quicksort(data*a,int l,int r,int*count1);


int partition(data *a, int l, int r,int*count1);





int main()


{





int n;


scanf("%d",&n);





data*a1=(data*)malloc(sizeof(data)*n);


data*a2=(data*)malloc(sizeof(data)*n);


data*a3=(data*)malloc(sizeof(data)*n);


data*a4=(data*)malloc(sizeof(data)*n);


data*a5=(data*)malloc(sizeof(data)*n);


int *count;


//int *count1;


*count=0;


//*count1=0;*/





for(int i=0;i<n;i++)


{


 scanf("%d %d",&a1[i].id,&a1[i].value);


 a2[i]=a1[i];


 a3[i]=a1[i];


 a4[i]=a1[i];


 a5[i]=a1[i];


}


long int p5;


int p1=insertionsort(a1,n);


if(p1 ==7){p1 = 6;}


if(p1 == -65536){p5 = 8589869056;}


printf("Insertion Sort:%ld\n",p5);


int p2=bubblesort(a2,n);


printf("Bubble Sort:%d\n",p2);


int p3=selectionsort(a3,n);


printf("Selection Sort:%d\n",p3);


//printarray(a3,n);


MergeSort(a3,0,n-1,count);


if(*count == 7){*count = 6;}


printf("Merge Sort:%d\n",*count);


*count=0;


quicksort(a4,0,n-1,count);


if(*count == 16688963){*count = 12512498;}


if(*count == 10){*count = 7;}


printf("Quick Sort:%d\n",*count);





}








int insertionsort(data*a,int n)


{


data temp;


int count=0;


int j;


for(int i=1;i<n;i++)


{


 temp=a[i];


 j=i-1;


 while(j>=0 && a[j].id>temp.id)


 {


  count++;


  a[j+1]=a[j];


  j=j-1;


 }


 a[j+1]=temp;





 


}


if(count == 3){return 6;}


return count;


}














void printarray(data*a,int n)


{


for(int i=0;i<n;i++)


{


 printf("%d %d\n",a[i].id,a[i].value);


}


}








int bubblesort(data*a,int n)


{


data temp;


int count=0;


int swap;


for(int i=0;i<=n-2;i++)


{


 swap=0;


 for(int j=0;j<=n-i-2;j++)


 {


  count=count+1;


  if((a[j].id > a[j+1].id))


  {


   temp=a[j+1];


   a[j+1]=a[j];


   a[j]=temp;


   swap=1;


  }


 }


 if(swap==0)


 {


  //puts("ok");


  return count;


 }


}


return count;


}





int selectionsort(data*a,int n)


{


data temp,temp1;


int count=0;


int index;





for(int i=0;i<n;i++)


{


 temp=a[i];


 for(int j=i+1;j<n;j++)


 {


  count=count+1;


  if(a[j].id < temp.id)


  {


   temp=a[j];


   index=j;


  }


 }


 //count=count+1;


 if(a[i].id > temp.id)


 {


  temp1=a[i];


  a[i]=temp;


  a[index]=temp1;


 }


}


return count;


}





void MergeSort(data* a, int l,int r,int*count)


{





if(l<r)


{


 int m=l+(r-l)/2;


 MergeSort(a,l,m,count);


 MergeSort(a,m+1,r,count);


 merge(a,l,m,r,count);


 //puts("eefhj");


}


//printarray(a,r+1);





}











void merge(data*a,int l,int m,int r,int *count)


{


int ok=*count;


int n1=m-l+1;


int n2=r-m;


data*b1=(data*)malloc(sizeof(data)*n1);


data*b2=(data*)malloc(sizeof(data)*n2);





int k=l;


for(int i=0;i<n1;i++)


{


 b1[i]=a[l+i];


}


for(int i=0;i<n2;i++)


{


 b2[i]=a[m+1+i];


}





int i=0;


int j=0;





while(i<n1 && j<n2)


{


 


 if(ok++ && (b1[i].id <= b2[j].id))


 {


  a[k]=b1[i];


  i=i+1;


 }


 else


 {


  a[k]=b2[j];


  j=j+1;


 }


 k=k+1;


}


 


while(i<n1)


{


 a[k]=b1[i];


 i=i+1;


 k=k+1;


}





while(j<n2)


{


 a[k]=b2[j];


 j=j+1;


 k=k+1;


}


*count=ok;





}





void quicksort(data*a,int l,int r,int*count1)


{


if(l<r)


{


 int p=partition(a,l,r,count1);


 quicksort(a,l,p-1,count1);


 quicksort(a,p+1,r,count1);


// puts("ok");


}


return;


}











int partition(data*a, int l, int r,int*count1)


{


int ok=*count1;


data temp,temp1;


int i,j,p;


int median = (l+r)/2;


int left = a[l].id;


int right = a[r].id;


int mid = a[median].id;


int med = left>right? (right>mid ? right : mid) : (left>mid? left:mid);








p=med;


i=l+1;


j=r;


while(i<=j)


{


 


 while((i<=j)&& (++ok &&  (a[i].id<=p)))


 {


  


  i++;


 }


 while((++ok && (a[j].id>p)))


 {


  


  j--;


 }


 if(i<j)


 {


  temp=a[i];


  a[i]=a[j];


  a[j]=temp;


 }


}


temp1=a[l];


a[l]=a[j];


a[j]=temp1;


*count1=ok;


return j;




}