def minOperations(n):
	numbers = []
	#numbers.append(n)
	bn = 2;
	while bn <= n:
		if n % bn == 0:
			n = n / bn
			numbers.append(bn)
		else:
			bn += 1
	print(numbers)
	return sum(numbers)
