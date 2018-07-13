import math
ans = 0
cnt = 6
flag = 0
for i in range(14, 100000000):
	root = int(math.sqrt(i)) + 1
	flag = 0
	for j in range(2, root):
		if i % j == 0:
			flag = 1
			break
	if flag == 0:
		cnt = cnt + 1
	if cnt == 10001:
		print(i)
		break
