#include<bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

#define ABS_MAX 1e9
#define ll long long



int like[101];
int order[21];
vector<int> v;



int main(){
	
	fastio;
	
	int size; cin>>size;
	int n;cin>>n;
	
	for(int i=0; i< n; i++){
		int cur ;cin>>cur;
		like[cur]++;
	
		if(v.size() < size){
		
			bool flag =false;
			for(int j =0 ;j<v.size(); j++){
				if(v[j] == cur) {
					flag=true;
					break;
				}
			}
			if(flag) continue;
		
			v.push_back(cur);
			order[v.size()-1] = i;
			
		}
		
		else{
			bool flag =false;
			for(int j =0 ;j<v.size(); j++){
				if(v[j] == cur) {
					flag=true;
					break;
				}
			}
			if(flag) continue;
			
			int idx=0;
			for(int j=1 ;j<v.size(); j++){
				if(like[v[idx]] == like[v[j]]){
					if(order[idx] > order[j] ) idx=j;
				}
				else if(like[v[idx]] > like[v[j]] ) idx= j;
			}
			
			like[v[idx]] = 0;
			order[idx]=i; ;
			v[idx] = cur;
		
		}
	}
	
	
	
	sort(v.begin(), v.begin() + v.size() );
	
	for(int i=0; i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;


	

	return 0;
}
