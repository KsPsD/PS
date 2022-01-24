#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

using namespace std;

map<int, pair<int,int> > m;
int n;
void pre(int num){
	if(num ==-1) return; 
	
	cout<<char(num+'A');

	pre(m[num].first);
	pre(m[num].second);

}
void in(int num){
	if(num ==-1) return; 
		

	
	in(m[num].first);
	cout<<char(num+'A');
	in(m[num].second);

}


void post(int num){

	
	if(num ==-1) return; 
		

	
	post(m[num].first);
	post(m[num].second);
	cout<<char(num+'A');

}




int main(){
	
	cin>>n;
	for(int i=0 ; i<n ;i++){
		char root;
		char l,r;
		cin>>root>>l>>r;
		m[root-'A'].first= l != '.'? l-'A' : -1;
		m[root-'A'].second =r != '.' ? r-'A' :-1;
	}
	

	pre(0);
	cout<<endl;
	in(0);
	cout<<endl;
	post(0);
	
	return 0;
} 
