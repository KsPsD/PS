#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000007
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;
#define MOD 10000000

int n,d,p,q;

double cache[51][101];

int arr[51][51] , deg[51];

double search3(int here,int days){
	if(days==0) return (here == p? 1.0: 0.0);
	double &ret = cache[here][days];
	
	if(ret> -0.5 ) return ret;
	ret =0.0;
	for(int there =0 ;there<n ;there++)
	{
		if(arr[here][there])
		 ret +=search3(there,days-1) / deg[there];
		 
	}
	
	return ret;
}


int main(){

	int c;cin>>c;
	while(c--){
		
		cin>>n>>d>>p;
		for(int i=0 ;i<n ;i++){
			for(int j= 0; j<n; j++){
				cin>>arr[i][j];
			}
		}
		memset(cache ,-1,sizeof(cache));
		memset(deg, 0 ,sizeof(deg));
		
		for(int i=0; i < n ; i++){
			for(int j= 0 ;j<n ;j++){
				deg[i]+=arr[i][j];
			}
		}
		
		int s_num ;
		cin>>s_num;
		
		for(int i=0 ;i<s_num; i++){
			int x;cin>>x;
			cout.precision(8);
			
			cout<<search3(x,d)<<" ";
		}
		
	cout<<endl;
			
	}
	

	return 0;
}

