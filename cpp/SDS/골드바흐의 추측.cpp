#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;


const int MAX = 1000000;
vector<int> prime;

int main() {
	fastio;
	
	vector<int> ch(MAX, true);
	
	for(int i=2 ;i*i <MAX; i++){
		if(ch[i] ==true){
			prime.push_back(i);
			for(int j=i+i ;j<=MAX; j+=i)ch[j] = false;
		}
		
			
		}
	


	

while(true){
	int n;cin>>n;
	if(n==0) break;
	for(int i = 0; i<=MAX ;i++){
		if(ch[n-prime[i]] == true){
			cout << n << " = " << prime[i]<< " + " << n - prime[i] << '\n';
                break;
		}
	}
}

    return 0;
}

