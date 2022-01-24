#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;

int n,k;
vector<string> v;
int cnt=0;
unordered_map<string,int> m;
vector<int> ch;
void go(string cur ,int idx){
	if(idx==k){
		if(m.find(cur) ==m.end()){
			m.insert({cur,1});
			cnt++;
		}
		return;
	}
	
	for(int i=0 ; i<v.size(); i++){
		if(ch[i]==1) continue;
		ch[i] =1;
		go(cur+v[i], idx+1);
		ch[i]=0;
	}
}


int main(){
	
	
	cin>>n>>k;
	
	for(int i=0 ; i< n; i++){
		string s;cin>>s;
		v.push_back(s);
	}
	ch.resize(v.size(),0);
	go("",0);
	
	
	
	cout<<cnt<<endl;
	
	
	return 0;
} 
