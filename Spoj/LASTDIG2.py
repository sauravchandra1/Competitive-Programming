t=int(input())
for i in range(t):
	num1,num2=map(int,input().split())
	num1=num1%10
	lastdig=num1
	if num2==0:
		print("1")
		continue
	ld=[]
	ld.append(lastdig)
	lookup=[]
	for i in range(10):
		lookup.append(0)
	lookup[lastdig]=1
	while True:
		lastdig=lastdig*num1
		lastdig=lastdig%10
		if lookup[lastdig]==1:
			break
		ld.append(lastdig)
		lookup[lastdig]=1
	id_len=int(len(ld))
	index=int(num2%id_len)
	index=index-1
	if index<0:
		index=id_len-1
	print(ld[index])

		
		
