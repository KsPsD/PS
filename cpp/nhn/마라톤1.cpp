#include<bits/stdc++.h>


using namespace std;


#define pii pair<int,int>

using namespace std;

vector<pair<int,int>> a;

int dist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first- b.first) + abs(a.second - b.second);
}

int main() {
	
	int n;cin>>n;
	int total=0;
	int sx ,sy=0;
	cin>>sx>>sy;
	a.push_back({sx,sy});
	for(int i=0; i<n-1; i++){
		int x, y;
		cin>>x>>y;
		a.push_back({x,y});
		total+=dist({sx,sy}, {x,y});
		sx=x;
		sy=y;
	}
	int skip=0;
	for(int i=1; i<n-1; i++){
		pii prev = a[i-1];
		pii cur = a[i];
		pii next =a[i+1];
		int origin = dist(prev,cur) +dist(cur,next);
		int modify = dist(prev,next);
		 skip = max(skip,origin - modify);
		
	}
	
	cout<<total-skip<<endl;
	
	
	return 0;
}
