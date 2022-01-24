#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;

int unf[1000001];
int n,m;

int find(int a ){
	if(a==unf[a]) return a;
	else return unf[a] = find(unf[a]);
}

void Union(int a, int b){
	a=find(a);
	b= find(b);
	if(a!=b) unf[a]= b;
	
}


int main(){
	fastio;
	cin>>n>>m;
	
	for(int i=0; i<=n; i++){
		unf[i] =i;
	}
	for(int i=0; i<m; i++){
		int cmd ,a, b;
		cin>>cmd>>a>>b;
		if(cmd==0){
			Union(a,b);
		}
		else{
			int sa=find(a);
			int sb= find(b);
			if(sa==sb) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
			}
		}
	
	
	
	
	return 0;
} 
