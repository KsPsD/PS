#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;


string num;

int check(int a, int b){
	
	string m  = num.substr(a, b-a+1);
	if(m== string(m.size(), m[0] )) return 1;
	bool progressive = true;
	for(int i=0 ; i<m.size()-1; i++){
		if(m[i+1] - m[i] != m[1] - m[0])
			progressive = false;
		}
	if(progressive && abs(m[1]- m[0]) == 1) return 2;
	
	bool alternate = true;
	
	for(int i=0 ;i<m.size(); i++)
	
	{
		if(m[i] != m[i%2])
			alternate = false;
	
	}
	
	if(alternate)  return 4;
	if(progressive)  return 5;
	return 10;

}
int cache[10002];

int memorize(int begin) {
	if(begin == num.size()) return 0;
	
	int &ret = cache[begin];
	
	if(ret != -1 ) return ret;
	
	ret=INF;
	
	for(int i =3; i<=5; i++)
	{
		if(begin+i<=num.size())
			ret = min(ret, memorize(begin+i) + check(begin, begin+i-1));
	}
	
	return ret;
}



int main()
{
	
	int c;cin>>c;
	
	while(c--){
		cin>>num;
		memset(cache, -1, sizeof(cache));
		cout<<memorize(0)<<endl;
			
	}
	
	
	
	return 0;

}

