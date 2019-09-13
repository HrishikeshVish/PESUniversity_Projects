def encode1(str1):
    l = len(str)
    str2 = ""
    str1 = str1.upper()
    for i in range(l):
        if(ord(str1[i]) <=77 and ord(str1[i])>=65):
            str2 = str2 + chr(ord(str1[i])+25 - ((ord(str1[i])-65)*2))
        elif (ord(str1[i])>77 and ord(str1[i])<=90):
            str2 = str2 + chr(78-(1+(ord(str1[i])-78)))
        else:
            str2 = str2 + str1[i];
    return str2
def decode1(str):
    l = len(str)
    str2 = ""
    str = str.upper()
    for i in range(l):
        if(ord(str[i])>78 and ord(str[i])<=90):
            str2 = str2 + chr(78-(1+ (ord(str[i]) -78)))
        elif (ord(str[i]) <=77 and ord(str[i])>=65):
            chr(ord(str[i])+25-((ord(str[i])-65)*2))
        else:
            str2 = str2 + str[i];
    return str2;

def encode2(str1):
    l = len(str1)
    str2 = ""
    str1 = str1.upper()
    for i in range(l):
        if(ord(str1[i])<90 and ord(str1[i])>65):
            str2 = str2 + chr(ord(str1[i])+1)
        elif(ord(str1[i]) == 90):
            str2 = str2 + 'a'
        else:
            str2 = str2 + str1[i];
    return str2;
