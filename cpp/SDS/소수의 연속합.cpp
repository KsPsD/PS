#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;

vector<bool> check;
vector<int> prime;
int main(){
	fastio;
	int n;cin>>n;
	check.resize(n+1,true);
	for (int i = 2; i * i <= n; i++) {
                if (check[i] == true) {
                        for(int j = i + i; j <= n; j += i)
                                check[j] = false;
                }
        }
	
	for (int i = 2; i < n + 1; i++) {
                if (check[i] == true) 
                        prime.push_back(i);
        }
        
        
	int s=0,e=0;
	int sum=0;
	int cnt=0;
	while(s<prime.size() ){
		if(sum>=n){
			if(sum==n) cnt++; 
			sum-=prime[s++];
		}
		else{
			if(e==prime.size()) break;
			sum+=prime[e++];
		}
	}
	
	cout<<cnt<<endl;

	

	return 0;
}
