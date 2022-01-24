#include<bits/stdc++.h>

#define  ll long long

using namespace std;

ll gcd(ll a, ll b){
	if(b==0)
		return a;
	else{
		return gcd(b ,a%b);
	}
}


int main(){
	
	int W =8;
	int H =12;
	
	
	cout<<W*H - (W+H-gcd(W,H))<<endl;
	
	
	
	
	
	return 0;
}
