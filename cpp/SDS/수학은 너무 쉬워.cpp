#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;

#define MAX 1000000
bool prime[MAX + 1];
int ch[MAX + 1];


int power(int y,int x){
	int res=1;
	while(x>0){
		if(x%2){
			res = res* y;
			
		}
		x/=2;
		y=y*y;	
	}
	return res;
}

 
int main(){
	fastio;
	memset(prime ,1, sizeof(prime));
	
	for(int i=2; i*i<MAX; i++)
		if(prime[i] ==1){
			for(int j =i+i ; j<MAX; j+=i){
				prime[j] =false;
			}
		}
			int n;cin>>n;
		
		vector<int> pv;
		for(int i=2; i<=MAX; i++){
			if(prime[i]) pv.push_back(i);
		}
		vector<vector<int> > v(n, vector<int>(pv.size(), 0)); 
		
		
		for(int i=0 ;i<n; i++){
			int score;cin>>score;
			for(int j=0; j<pv.size(); j++){
				if(score==1) break;
				while(score % pv[j] ==0){
					score/=pv[j];
					ch[pv[j]]++;
					v[i][j]++;
				}
			}
		}
		
		
		int ans=1;
		int cnt=0;
		
		for(int i=0; i<pv.size(); i++){
			int curP = ch[pv[i]] / n;
			for(int j=0; j<n; j++){
				if(v[j][i] < curP){
					cnt+= curP-v[j][i];
				}
			}
			ans *= power(pv[i],curP);
		}
		
		cout<<ans<<" "<<cnt<<endl;
		
		
	
	
		
	
	
	
	
	
	
	
	
	return 0;
}
