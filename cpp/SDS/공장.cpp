#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>


using namespace std;
const int MAX = 1000000;
ll ans;
int tree[4*MAX];
int a[500000];
int b[MAX];
int ch[5000001]; //일련번호의 값이 2번째 배열에 나오는 순서 미리 저장

int n;

void update(int idx, int val){
	while(idx<=n){
		tree[idx] +=val;
		idx+= (idx & -idx);
	}
}

int query(int idx){
	int ret =0;
	while(idx){
		ret +=tree[idx];
		idx -= (idx & -idx);
	}
	
	return ret;
}


int main(){
	fastio;
	cin>>n;
	
	
	for(int i=1 ;i<=n; i++){
		cin>>a[i];
		
//		ch[a[i]]=i;
	}
	
	for(int i=1 ;i<=n; i++){
		int v;cin>>v;	
		b[v]=i;
//	
	}
	ll ans =0;
	for (int i = 1; i <= n; i++) { //b순서를 기준으로 숫자들 비교 
		ans += (long long)query(n) - (long long)query(b[a[i]]);
		update(b[a[i]] ,1); 
	}
//	
	
	
	
	
	cout<<ans<<endl;
	
	
	
	return 0;
} 
