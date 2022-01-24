#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl "\n"
#define pii pair<int,int>

using namespace std;
const int MAXN = 1000001;
int tree[MAXN];
int n;



void update(int node, int target, int s,int e,int val){
	if(target< s || target>e) return ;
	tree[index]+=val;
	if(s==e) return;
	int mid= (s+e)/2;
	update(2*node, target, s,mid, val);
	update(2*node+1, target, mid+1, e, val);
	
}

int query(int node, int target, int s,int e){
	if(start==end) return start;
	int mid =(s+e)/2;
	if(target<=tree[2*node]) return query(index *2 , target, start, mid);// 갯수 비교해서 순위가 작으면 왼쪽으로 
	else return query(2*index+1, target- tree[2*index], mid+1, e);  
}



int main(){
	
	cin>>n;
	
	for(int i=0; i<n; i++){
		int cmd;cin>>cmd;
		if(cmd==1){
			int b,c;cin>>b>>c;
			int f =query(1,b,1,MAXN);
			cout<<f<<endl;
			update(1,f,1,MAXN,-1);
		}
		else{
			int b,c;cin>>b>>c;
			update(1,b,1,MAXN,c);

			
		}
	}
	
	
	
	
	return 0;
}
