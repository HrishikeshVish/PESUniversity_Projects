

T=int(input())

i=0
sum_list=[]
count =0
for i in range(0,T):
    N,K = input().split(" ")
    l=input().split()

    l=list(map(lambda x:int(x),l))
    l=sorted(l,reverse=True)
    
    
    mx = int(l[int(K)-1]);
    count =0
    length=len(l)
    for i in range(0,length):
        if int(l[i])>=mx:
            count = count+1
        
    print(count);
    
   