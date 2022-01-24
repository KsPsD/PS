#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

using namespace std;

int n,m,k;


ll tree[3000000];
ll num[1000001];

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
	cin>>n>>m>>k;
	for(int i=1;i<=n; i++){
		cin>>num[i];
	}	
	
	
	init(1,1,n);
	
	for(int i=0;i<m+k;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		
		if(a==1){
			ll diff=c-num[b];
			num[b] =c;
			update(1,1,n,b,diff);
		}
		else cout<<sum(1,b,c,1,n)<<endl;
	}
	
	return 0;
		
}

