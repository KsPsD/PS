#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	unsigned t, n, p;
	scanf("%u", &t);
	while(t--)
	{
		scanf("%u", &n);
		if(n <= 2) { puts("2"); continue; }
		for(n|=1; ; n+=2)
		{
			for(p=3; p*p <= n && n%p; p+=2);
				if(p*p > n) break;
		}
		printf("%u\n", n);
	}

}
	
	


