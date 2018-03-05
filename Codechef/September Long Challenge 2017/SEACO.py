class commands:
	query=0
	l=0
	r=0
 
class two_query:
	first=0
	last=0
 
class one_query:
	first=0
	last=0
 
t=int(input())
 
for i in range(t):
 
	n,m=input().split()
	n=int(n)
	m=int(m)
 
	data=[commands() for i in range(m+1)]
	bot_top=[two_query() for i in range(m+1)]
	top_bot=[one_query() for i in range(n+1)]
 
	for i in range(1,m+1):
		e,f,g=input().split()
		data[i].query=int(e)
		data[i].l=int(f)
		data[i].r=int(g)
 
	flag=1
 
	for i in range(m,0,-1):
		flag=flag+bot_top[i].last
		if data[i].query==2:
			a=data[i].l
			b=data[i].r
			bot_top[a].first=bot_top[a].first+flag
			bot_top[b].last=bot_top[b].last+flag
		flag=flag-bot_top[i].first
 
	flag=1
 
	for i in range(1,m+1):
		flag=flag+bot_top[i].first
		if data[i].query==1:
			a=data[i].l
			b=data[i].r
			top_bot[a].first=top_bot[a].first+flag
			top_bot[b].last=top_bot[b].last+flag	
		flag=flag-bot_top[i].last
	flag=0
 
	for i in range(1,n+1):
		flag=flag+top_bot[i].first
		print(flag%1000000007,end=" ");
		flag=flag-top_bot[i].last
	print()
 
 
