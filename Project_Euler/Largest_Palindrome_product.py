#Project Euler
a = ""
b = ""
mul = 0
flag = 0
ans = 0
for i in range(999, 100, -1):
	for j in range(999, 100, -1):
		mul = i * j
		a = str(mul)
		b = "".join(reversed(a))
		if a == b:
			ans = max(ans, mul)
print(ans)
