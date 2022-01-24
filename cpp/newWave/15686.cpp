#include<bits/stdc++.h>

using namespace std;


int n ,m;
int arr[51][51];
vector<pair<int,int> > house;
vector<pair<int,int> > chicken;
int ans = 9999999;
int ch[14];
void go(int idx,int cnt){
	if(idx > chicken.size()){
		return;
	}
	if(cnt ==m){
		int s=0;
		for(int i=0 ; i<house.size(); i++){
			int dis=9999999;
			int yy=house[i].first;
			int xx = house[i].second;
			for(int j=0 ; j < chicken.size(); j++){
				if(ch[j]){
					dis =min(dis,abs(yy-chicken[j].first) + abs(xx-chicken[j].second));
				}
			}
			s+=dis;
		}
		ans= min(s,ans);
		return;
	}
	
	ch[idx] =1;
	go(idx+1, cnt+1);
	ch[idx]=0;
	go(idx+1,cnt);
}



int main(){
	
	cin>>n>>m;
	for(int i=0; i<n ;i++){
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
			if(arr[i][j] ==1){
				house.push_back({i,j});
				
			}
			else if(arr[i][j] ==2){
				chicken.push_back({i,j});
			}
		}
	}
	
	
	
	
	go(0,0);
	
	
	cout<<ans<<endl;
	
	
	
	
	
	return 0;
}
