#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;


ll num[100010];
ll tree[400040];

int n,q;
 
void update(int n, int s, int e, int t, ll diff){
	if(s<=t && t<=e ) tree[n] +=diff;
	else return;
	if(s==e)
		return;
	int mid = (s+e)/2;
	update(n*2 ,s, mid ,t, diff);
	update(n*2+1 ,mid+1, e, t,diff);
}


ll sum(int n, int l, int r , int s, int e){
	if(r<s || l>e) return 0;
	if(l<=s && e<=r) return tree[n];
	
	int mid = (s+e)/2;
	return sum(2*n ,l,r,s,mid) +sum(2*n+1,l,r, mid+1,e);
}


ll init(int n, int s, int e){
	if(s==e) return tree[n] = num[s];
	int mid =(s+e)/2;
	return tree[n] = init(n*2, s,mid) + init(n*2+1, mid+1, e);
}

int main(){
	
	fastio;
	cin>>n>>q;
	
	for(int i=1 ;i<=n; i++){
		cin>>num[i];
	}
	
	init(1, 1,n);
	
	for(int i=0; i<q; i++){
		int x,y,a,b;cin>>x>>y>>a>>b;
		
		cout<<sum(1,min(x,y), max(x,y), 1,n)<<endl;
	
	
		ll diff=b-num[a];
		num[a] =b;
		update(1, 1,n, a,diff);
		
	}
	
	
	
	
	
	return 0;
} 
