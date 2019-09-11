
v = [1, 2, 5, 10, 20, 50, 100, 200]


def possible(total, n):
    

	if total == 0:
		return 1
	elif total < 0 or n == 0:
		return 0
	else:
		if(total == 1):
			val = v[n-1]
		if(total == 5):
			val = 3
		elif(total == 50):
			val = 30
		else:
			val = total/2
	return possible(total, n - 1) + possible(total - v[n-1], n);


print( possible(200, 8))