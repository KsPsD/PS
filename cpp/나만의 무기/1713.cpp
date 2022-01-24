#include<bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

#define ABS_MAX 1e9
#define ll long long


int n;
int num;
vector<pair<int ,int> > v(num, {0,0});
int like[101];



int main(){
	

cin>>n>>num;
for(int i=0; i<num; i++){
	int a;cin>>a;
	bool flag= false;
	if(v.size() < n){
		for(auto it = v.begin(); it !=v.end(); it++){
			if(it->first == a){
				like[a]++;
				flag=true;
				break;
			}
		}
		if(!flag){
			v.push_back({a,i});
			like[a]=1;
		}	
			
			
	}
	
	else{
		bool flag2 =false;
		for(auto it = v.begin(); it !=v.end(); it++){
			if(it->first == a){
				like[a]++;
				flag2=true;
				break;
			}
		}
	
		if(flag2) continue;
		auto idx=v.begin();
		auto it = idx++;
		for(it; it !=v.end(); it++){
			if(like[idx->first] == like[it->first]){
				if(it->second < idx->second){
					idx=it;
				}
			}
			
			else if(like[idx->first] > like[it->first]){
					idx=it;				
			}
		}
		v.erase(idx);
		v.push_back({a,i});
		like[a]=1;
		
	}
	
	
}	

	sort(v.begin(),v.end());
	for(auto e:v){
		cout<<e.first<<" ";
	}
	



	
	return 0;
} 
