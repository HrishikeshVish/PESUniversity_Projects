lint = []
lstr = []
lset = []
ltuple = []
lfloat = []
llist = []
ldict = []
list1 = [4,6,8,"Hello", "Name", {2,3,4}, 6.8,3.1,[1,2,3], {1:4, 2:8}]
for i in range(len(list1)):
    if(type(list1[i]) == int):
        lint.append(list1[i])
    if(type(list1[i] == float):
       lfloat.append(list1[i])
    if(type(list1[i]) == str):
       lstr.append(list1[i])
    if(type(list1[i]) == set):
       lset.append(list1[i])
    if(type(list1[i]) == tuple):
       ltuple.append(list1[i])
    if(type(list1[i]) == dict):
       ldict.append(list1[i])
       
