ans = 0
a = 1
b = 1
c = 0
lim = int(4 * 1e6)
for i in range(lim):
	c = a + b
	if c > lim :
		break
	if c % 2 == 0:
		ans += c
	a = b
	b = c
print(ans)