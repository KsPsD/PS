#include<bits/stdc++.h>


using namespace std;

int n,k;

int main(){
	
	vector<int> v;
	cin>>n>>k;
	
	queue<int> q;
	
	for(int i=1; i<= n; i++){
		q.push(i);
	}
	int cnt=0;
	while(!q.empty()){
		int tmp  =q.front();
		q.pop();
		cnt++;
		if(cnt==k){
			cnt=0;
			v.push_back(tmp);
		}
		else{
			q.push(tmp);
		}
	}
	
	cout<<"<";
	for(int i=0; i<v.size()-1; i++){
		cout<<v[i]<<", ";
	}
	
	cout<<v[n-1]<<">";
	
	
	
	
	
	
	return 0;
}
