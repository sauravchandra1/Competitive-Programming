#include <bits/stdc++.h>
using namespace std;

int main(){

	while(1){

		int n;
		scanf("%d",&n);

		if(n==0)
			break;

		string s;
		cin>>s;

		unsigned int len=s.size();

		vector<char> v[3000];

		int j=0;

		for(int i=0;i<len;i++){

			v[j].push_back(s[i]);

			if((i+1)%n==0)
				j++;
		}

		for(int i=0;i<len/n;i++){

			if(i%2==1)
				reverse(v[i].begin(),v[i].end());
		}

		for(int i=0;i<n;i++){

			for(int j=0;j<len/n;j++)
				printf("%c",v[j][i]);
		}

		printf("\n");

	}
	return 0;
}