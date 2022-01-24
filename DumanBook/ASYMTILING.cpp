#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000007
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;


int cache[101];

int tiling(int n){
	if(n<=1) return 1;
	
	int &ret = cache[n];
	if(ret != -1) return ret;
	return ret =  (tiling(n-2) + tiling(n-1) ) %INF;

}



int asymmetric(int w){
	if(w %2 ==1) return(tiling(w) - tiling(w/2) +INF ) % INF;
	int ret = tiling(w);
	ret  = (ret - tiling(w/2) + INF) % INF;
	ret = (ret - tiling(w/2-1) + INF) % INF;
	return ret;

}





int main(){


	int c;cin>>c;
	while(c--){
		memset(cache ,-1 ,sizeof(cache));
		int n;cin>>n;
		if(n==2) cout<<0<<endl;
		else cout<<asymmetric(n)<<endl;
			
	}
	

	return 0;	
}

