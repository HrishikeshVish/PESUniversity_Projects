def swap(dict1):
    dict2 = {}
    for i in dict1:
        k = dict1[i];
        if k not in dict2:
            dict2[k] = []
        dict2[k].append(i)
        return dict2

dict1 = {"Apple":"Fruit", "Mango":"Fruit", "Dog":"Mammal", "Cat":"Mammal"}
print(swap(dict1));
