f = open("output.txt", "r")
count = 0;
correct = 0
total = 0
for i in f:
    print(i)
    count+=1
    if(count%2 == 0):
        a = int(input("Is it correct"))
        total = total+1
        correct = correct + a
    if(total >55):
        break;
print(correct/total)
        
