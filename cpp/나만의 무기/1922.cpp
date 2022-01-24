#include<bits/stdc++.h>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long


int unf[10001];
struct Edge{
	int s,e,val;
	Edge(int a,int b,int c){
		s=a;
		e=b;
		val=c;
	}
	
	bool operator < (const Edge &b){
		return val<b.val;
	}
};

int N,M;


int find(int a){
	if(unf[a] ==a) return a;
	else return unf[a] = find(unf[a]);
}

void Union(int a, int b){
	int fa= find(a);
	int fb = find(b);
	if(fa!=fb) unf[a] = b;
}



int main(){
	
	fastio;
	
	cin>>N>>M;
	vector<Edge> v;
	for(int i=1; i<=n; i++){
		unf[i]=i;
	}
	
	for(int i=0; i<m; i++){
		int a,b,c;
		cin>>a>>b>>c;
		v.push_back({a,b,c});	
	}
	
	sort(v.begin(),v.end());
	int ret=0;
	
	for(int i=0; i<m; i++){
		int fa = find(Ed[i].s);
		int fb = find(Ed[i].e);
		if(fa!=fb){
			res+=Ed[i].val;
			Union(fa,fb);
		}
	}
	
	cout<<res<<endl;
	
	
	
	
	
	
	return 0;
}
