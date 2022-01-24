#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

using namespace std;

int main(){
	fastio;
	int n;
	queue<int> q;
	cin>>n;
	string cmd;
	int num;
	for(int i=0; i<n; i++){
		cin>>cmd;
		if(cmd=="push"){
			cin>> num;
			q.push(num);
		}
		else if(cmd=="front"){
			if(q.empty()) {
				cout<<-1<<endl;
				continue;
			}
			cout<<q.front()<<endl;
		}
		else if(cmd=="size"){
			cout<<q.size()<<endl;
		}
		else if(cmd=="empty"){
			if(q.empty())cout<<1<<endl;
			else cout<<0<<endl;
		}
		else if(cmd=="pop"){
			if(q.empty()) {
				cout<<-1<<endl;
				continue;
			}
			cout<<q.front()<<endl;
			q.pop();
		}
		else{
			if(q.empty()) {
				cout<<-1<<endl;
				continue;
			}
			cout<<q.back()<<endl;
		}
	}
	
	
	
	
	return 0;
} 
