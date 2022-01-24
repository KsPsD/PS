#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;




int main(){
	string n;cin>>n;
	int sum =0;
	bool zero =false;
	for(int i=0 ; i< n.size(); i++){
		sum+=(n[i]-'0');
		if(!(n[i]-'0')){
			zero =true;
		}
	}
		
		if(sum %3 || !zero) cout<<-1<<endl;
		else{
			sort(n.begin(), n.end(),greater<char>());
			cout<<n<<endl;
		}
	
	
	
	
	return 0;
}
