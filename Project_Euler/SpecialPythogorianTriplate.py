a = 0
b = 0
c = 0
for i in range(1, 1000):
	for j in range(i + 1, 1000):
		k = 1000 - i - j
		if (i * i + j * j == k * k) and (i + j + k == 1000):
			print(i * j * k)
			break