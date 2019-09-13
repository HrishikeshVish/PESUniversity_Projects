s = [("854", "x", (96,78,99)), ("123", "a", (90,98,89)), ("567", "p", (56,68,100))]
print("\n Increasing order of SRN :\n", sorted(s));
print("\n Alphabetical order :\n", sorted(s, key=lambda t:t[1]));
print("Decreasing Order of marks", sorted(s, key=lambda t:sum(t[2]), reverse=True));

s = ["Hello", "World", "Name", "Abcdef", "wxyz"];
print(max(s, key = lambda s=s:len(s));
print(list(filter(lambda s:s.endswith("xyz"),s)));
print(list(filter(lambda s:s.startswith("Hel"), s)));
print(list(filter(lambda s:"orl" in s,s)));
print(functools.reduce(lambda x,y:x+y, list(map(len,string)))/len(length));
      
def myreduce(fun, list1):
      r = list[0];
      for i in list1[1:]:
          r = fun(r,i)
      return r;
      
