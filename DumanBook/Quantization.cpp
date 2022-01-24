#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;





int n;
int A[101], psum[101], psqsum[101];

void precalc(){
	sort(A,A+n);
	psum[0] = A[0];
	psqsum[0] = A[0] * A[0];
	for(int i=1; i<n; i++){
		psum[i] = psum[i-1] + A[i];
		psqsum[i] = psqsum[i-1] + A[i]*A[i];
	}
	
}

int minError(int lo, int hi){
	int sum =psum[hi] -(lo == 0? 0:psum[lo-1]);
	int sqsum = psqsum[hi] - (lo == 0? 0:psqsum[lo-1]);
	
	int m = int(0.5 + (double)sum / (hi- lo +1));
	
	int ret = sqsum -2*m*sum+m*m*(hi-lo+1);
	return ret;
}

int cache[101][11];


int quantize(int from, int parts){
	if(from == n) return 0;
	if(parts == 0) return INF;
	int &ret = cache[from][parts];
	if(ret!=-1) return ret;
	ret = INF;
	for(int partSize = 1; from+partSize<= n; partSize++){
		ret = min(ret, minError(from,from+partSize-1) + quantize(from+partSize ,parts-1));	
	}
	
	return ret;
	
	
}



int main(){

	int c;cin>>c;
	while(c--){
		int s;
		cin>>n>>s;
		memset(cache, -1, sizeof(cache));
		for(int i=0; i<n ;i++){
			cin>>A[i];
		}
		precalc();
		cout<<quantize(0,s)<<endl;
	}
	


return 0;

}

