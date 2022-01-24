#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

using namespace std;

int arr[1001][1001];

int gcd(int a,int b){
	while(b!=0){
		int n= a%b;
		a=b;
		b=n;
	}
	return a;
}



int main(){
	
	int c;cin>>c;

	int cnt=3;
	while(c--){
		int n;cin>>n;
		for(int i =2; i<=n ;i++){
			int cur=0;
			for(int j=1; j<i ;j++){
				if(gcd(i,j)!=1) continue;
				cur++;
			}
			cur*=2;
			cnt+=cur;
		}
	
		cout<<cnt<<endl;
		
	}
	
	
	
	
	
	
	
	
	
	return 0;
} 
