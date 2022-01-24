#include<bits/stdc++.h>

using namespace std;

int unf[1001];
vector<int> elc;
struct Edge{
	int s,e,val;
	
	Edge(int a,int b, int c){
		s=a;
		e=b;
		val=c;
	}
	
	bool operator < (const Edge& b) const{
		return val < b.val;
	}
};


int Find(int v){
	if(v==unf[v]) return v;
	return unf[v] =Find(unf[v]);
}

void Union(int a,int b){
	a= Find(a);
	b= Find(b);
	if(a!=b) unf[a] =b;
}

int n,m,k;

int main(){
	cin>>n>>m>>k;
	
	int res=0;
	vector<Edge> v;
	
	for(int i=0 ;i<k; i++){
		int x;
		cin>>x;
		elc.push_back(x);
	}
	
	for(int i=1; i<=n; i++){
		unf[i]=i;
	}
	
	for(int i=1; i<=m ; i++){
		int s,e,val; cin>>s>>e>>val;
		v.emplace_back(Edge(s,e,val));
	}
	
	
	for (int i = 0; i < k - 1; i++) {
		int now = elc[i];
		int next = elc[i+1];
		Union(now, next);
	}
	sort(v.begin(),v.end());
	
	for(int i= 0; i<m; i++){
		int fa = Find(v[i].s);
		int fb = Find(v[i].e);
		if(fa!=fb){
			res+=v[i].val;
			Union(fa,fb);
		}
	}
	
	cout<<res<<endl;
	
	
	
	
	return 0;
}
