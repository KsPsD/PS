#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;


const long long NEGINF = numeric_limits<long long> ::min();
int n,m, A[100] ,B[100];
int cache[101][101];


int jlis(int indexA, int indexB){
	int &ret = cache[indexA+1][indexB+1];
	if(ret != -1 ) return ret;
	
	ret =2;
	ll a=  (indexA== -1? NEGINF : A[indexA]);
	ll b=  (indexB== -1? NEGINF : B[indexB]);
	ll maxEle = max(a,b);
	
	for(int nextA = indexA+1 ; nextA<n; ++nextA)
		if(maxEle < A[nextA])
			ret = max(ret,jlis(nextA,indexB) +1 );
	
	for(int nextB = indexB+1 ; nextB<m; ++nextB)
		if(maxEle < B[nextB])
			ret = max(ret,jlis(indexA,nextB) +1 );
			
	return ret;
}



int main(){
	
	int c;cin>>c;
	for(int i=0; i< c; i++){
		cin>>n>>m;
		memset(cache, -1, sizeof(cache));
		for(int j=0; j<n ;j++){
			cin>>A[j];
		}
	
		for(int k=0; k<m ;k++){
			cin>>B[k];
		}
	
	cout<<jlis(-1,-1) -2<<endl;
	}
	
}

