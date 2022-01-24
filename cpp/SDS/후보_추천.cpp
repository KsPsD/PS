#include<bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

#define ABS_MAX 1e9
#define ll long long

const int MAX = 101;

int like[MAX];

int main(){



	int n;cin>>n;
	int cn;cin>>cn;
	vector<pair<int ,int> > v(cn, {0,0});
	
	for(int i=0; i<cn ;i++){
		int num;cin>>num;
		like[num]++;
		bool flag=false;
		
		for(int j=0; j<n; j++){
			if(v[j].second ==0){
				v[j].first=i;
				v[j].second=num;
				flag=true;
				break;
			} 
			else if(v[j].second ==  num){
				flag=true;
				break;
			}
		}
		if(flag) continue;
		
		
		int idx=0;
		for(int j=1; j<n; j++){
			if(like[v[j].second] == like[v[idx].second]){
				if(v[j].first<v[idx].first){
					idx=j;
					
				}
			}
			else if(like[v[j].second] < like[v[idx].second]){
				idx=j;
			}
		}
		
		like[v[idx].second] =0;
		v[idx].first= i;
		v[idx].second=num;
		
	}
	
		vector<int> picture;
        for (int i = 0; i < n; i++)picture.push_back(v[i].second);

 

        sort(picture.begin(), picture.end());

        for (int i = 0; i < n; i++) cout << picture[i] <<" ";
       cout<<endl;
	

	return 0;
}
