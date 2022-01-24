#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;

//하나씩 빼는 문제 max min sum 등으로 응용 가능한 문제임// 
int gcd(int a, int b){
	if(b==0) return a;
	else return gcd(b, a%b);
}

int n;
int arr[1000001],ltor[1000001],rtol[1000001];
int main(){
	fastio;
	  
  	int answer=-1;
  	int who=0;
  	cin >>n;
  	
  	for(int i=1;i<=n; i++){
  		cin>>arr[i];
	  }
	  
	  
	  for (int i = 1; i <= n; i++) {
		ltor[i] = gcd(ltor[i - 1], arr[i]);
		}
  	
  		for(int i=n; i>=1 ;i--){
  			rtol[i] = gcd(rtol[i+1], arr[i]);
		  }
  	
  	
  		for(int i=1; i<=n ;i++){
  			int cur =gcd(ltor[i-1], rtol[i+1]);
  			if (arr[i] % cur == 0) continue;
  		
            if (answer < cur) {
                answer = cur;
                who = arr[i];
            }
        }
        if (answer == -1) {
            cout<<answer<<endl;
        }
        else {
           cout<<answer<<" "<<who;
        }
  	
  
}
