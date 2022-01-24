#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;

int gcd(int a, int b){
	if(b==0) return a;
	else return gcd(b, a%b);
}


int main(){
	fastio;
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int p= a*d + b*c;
	int q=  b*d;
	int g= gcd(p,q);
	cout<<p/g <<" " <<q/g<<endl;
	
	
	return 0;
} 
