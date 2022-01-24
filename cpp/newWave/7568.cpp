#include<bits/stdc++.h>


using namespace std;


int n;
vector<pair<int, int> > v;
int main(){
	cin>>n;
	
	
	for(int i=0; i<n ; i++){
		int w,h;
		cin>>w>>h;
		v.push_back({w,h});
	}
	
	vector<int> order;
	for(int i=0; i<n ; i++){
		int cnt=0;
		int cur_w = v[i].first;
		int cur_h = v[i].second;
		for(int j=0; j<n; j++){
			if(j==i) continue;
			if(cur_w < v[j].first && cur_h < v[j].second){
				cnt++;
			}
		}
		order.push_back(cnt+1);
	}
	
	
	for(auto e: order){
		cout<<e<< " ";
	}
	cout<<endl;
	
	
	
	
	
	
	return 0;
}
