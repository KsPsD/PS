#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;

vector<int> h;

int solve(int left, int right){
	if(left==right)return h[left];
	int mid =(left+right)/2;
	int ret = max(solve(left,mid), solve(mid+1 ,right));
	
	int lo = mid ,hi =mid+1;
	int height = min(h[lo], h[hi]);
	
	ret= max(ret,height*2);
	while(left<lo || hi<right){
		if(hi< right && (lo == left || h[lo-1] < h[hi+1])){
			++hi;
			height = min(height,h[hi]);
		}
		else{
			--lo;
			height = min(height,h[lo]);
		}
		
		ret = max(ret,height * (hi-lo +1));
	}
	return ret;
}




int main(){
	int c;cin>>c;
	for(int i=0; i<c;i++){
		int n;cin>>n;
		h.resize(n,0);
		for(int j=0 ;j<n ;j++){
			cin>>h[j];
		}
		
		int ans =solve(0, n-1);
		
		cout<<ans<<endl;	
	}	
}
