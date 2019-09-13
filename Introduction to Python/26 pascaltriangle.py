n = int(input("Enter the number of rows"))
pt = []
for i in range(n):
    pt.append([])
    pt[i].append(1)
    for j in range(1,i):
        pt[i].append(pt[i-1][j-1] + pt[i-1][j])
        if i!=0:
            pt[i].append(1)
    for i in range(n):
        print("" * (n-i), end = "")
        for j in range(i+1):
            print("{0:6}".format(pt[i][j]),end = "", sep = "")
        print()
