#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000007
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;
#define MOD 10000000
int cache[101][101];
int poly(int n, int first){
	if(n== first) return 1;
	
	int &ret = cache[n][first];
	if(ret != -1 ) return ret;
	
	ret = 0;
	for(int second=1; second<= n-first; second++){
		int add = second + first -1;
		add*= poly(n-first ,second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	
	return ret;
	


}



int main(){
	
	int c;cin>>c;
	while(c--){
	int n;cin>>n;
	int sum=0;
	memset(cache ,-1, sizeof(cache));
	for(int j =	1; j<=n ;j++){
		sum+=poly(n,j);
		sum%=MOD;
	
	}
	
	cout<<sum<<endl;
	
	
	}
	
	
	
	
}

