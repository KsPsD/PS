#include<bits/stdc++.h>

#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
using namespace std;

const int INF = 1000000001;
const int MAX =100001;

stack<pair<ll ,ll> > st;



int main(){
	
	 fastio;
	 while(1){
	 	int n;cin>>n;
	 	if(n==0) break;
	 	ll s =0;
	 	int tmp=0;
	 	for(int i= 0; i<n; i++){
	 	int a;cin>>a;
	 	tmp =0;
	 	while(!st.empty() &&  a<st.top().first){
	 		tmp+=st.top().second;
	 		s=max(s,tmp*st.top().first);
	 		st.pop();
		 }
		tmp++;
		st.push({a,tmp});
	 	
	 }
	 
	 tmp =0;
	 while(!st.empty()){
	 	tmp += st.top().second;
	 	s= max(s, tmp*st.top().first);
	 	st.pop();
	 }
	 
	 cout<<s<<endl;
	 	
	 	
	 	
	 }
	 
	
	
	
	
	
	
	
	return 0;
}
