#include<bits/stdc++.h>

using namespace std;


const double Pi =2* acos(0);
const int INF = 987654321;

double y[100] , x[100], r[100];

pair<double, double> ranges[100];

int n;


void convertTorange(){
	for(int i=0 ;i<n; i++){
		double loc = fmod(2*Pi+atan2(y[i], x[i]) , 2*Pi);
		double range = 2 * asin(r[i] / 16);
		ranges[i] = {loc-range ,loc+range};
	}
	
	sort(ranges, ranges+n);
}

int linear(double lo, double hi){
	int used =0 ,idx = 0;
	
	while(lo<hi){
		double maxCover = -1;
		while(idx<n && ranges[idx].first<=lo)
		maxCover = max(maxCover, ranges[idx++].second);
		if(maxCover<=lo) return INF;
			
		lo=maxCover;
		++used;
	}
	return used;
}
int solve(){
	int ret = INF;
	for(int i=0 ;i<n ;++i){
		if(ranges[i].first<=0 || ranges[i].second>=2 *Pi){
			double lo = fmod(ranges[i].second, 2*Pi);
			double hi = fmod(ranges[i].first+2*Pi, 2*Pi);
			ret = min(ret, 1+linear(lo,hi));
		}
	}
	
	return ret;
}

int main(){
	int t;
	cin>>t;
	
	while(t--){
		cin>>n;
		for(int i=0; i<n; i++)cin >> y[i] >> x[i] >> r[i];
		convertTorange();
		
		int ret =solve();
		
		if(ret!=INF) cout<<ret<<endl;
		
		else cout<<"IMPOSSIBLE"<<endl;
	}
	
	return 0;
}
