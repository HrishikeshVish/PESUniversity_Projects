count = 0;
l = [1,2,3,4,5,6,7];

firjan = 1 + (365%7);
# in 1901
firmonth = 1 + (365%7);

sunday = 1;

nonleap = [31,28,31,30,31,30,31,31,30,31,30,31];
leap  = [31,29,31,30,31,30,31,31,30,31,30,31];
count = 0;

for i in range(1901,2001):
	if(i%4 == 0 and i%400 == 0):
		for j in leap:
			if(firmonth == 1):
				count = count + 1;
			firmonth = firmonth + (j%7);
			if(firmonth>7):
				firmonth= firmonth -7;
	else:
		for j in nonleap:
			if(firmonth == 1):
				count = count + 1;
			firmonth = firmonth + (j%7);
			if(firmonth>7):
				firmonth= firmonth -7;
print(count);