#include<bits/stdc++.h>


using namespace std;

int n,t,p; 
int timetable[25][60][101];

struct Time{
	int st;
	int sm;
	int et;
	int em;
};

bool cmp(const Time &a ,const Time &b){
	if(a.st==b.st){
		if(a.sm==b.sm){
			if(a.et ==b.et){
				return a.em< b.em;
			}
			return a.et<b.et;
		}
		return a.sm< b.sm;
	}
	return a.st<b.st;
}

int dist(int idx, int h, int m){
	int dist = 99999999;
	int minIdx =1;
	for(int i=1; i<=n; i++){
		if(idx ==i) continue;
		if(timetable[h][m][i]){
			int d = abs(idx-i);
			if(dist > d){
				dist= d;
				
			}
		}
	}
	
	return dist;
}



int findSeat(int h,int m){
	int idx=1;
	int maxDis =0;
	for(int i=1; i<=n; i++){
		if(!timetable[h][m][i]){
			int md=  dist(i,h,m);
			if(maxDis<md){
				maxDis=md;
				idx=i;
			}
		}
	}
	
	return idx;
}

vector<Time> v;
int main(){
	int a, b, res = 0;
	cin>>n>>t>>p;
	for(int i=0; i<t; i++){
		cin>>a>>b;
		int st=a/100;
		int sm=a%100;
		int et =b /100;
		int em =b %100;
		v.push_back({st,sm,et,em});
	}
	
	sort(v.begin(),v.end(),cmp);
	
	
	for(auto e: v){
		int st=e.st;
		int et =e.et;
		int sm = e.sm;
		int em = e.em;
		int idx  = findSeat(st,sm);
		
		for(int i=st; i<=et; i++){
			if(st==et){
				for(int j=sm; j<em; j++){
					timetable[i][j][idx]=1;
				}
				break;
			}
			
			if(i==st){
				for(int j=sm ; j<=59; j++){
					timetable[i][j][idx] = 1;
				}
			}
			
			else if(i==et){
				for(int j=0; j<em; j++){
					timetable[i][j][idx]=1;
				}
			}
			
			else{
				for(int j=0; j<=59; j++){
					timetable[i][j][idx]=1;
				}
			}
			
		}
		
	}
	for (int i = 9; i <= 20; i++) {
        for (int j = 0; j <= 59; j++)  {
            if (!timetable[i][j][p]) {
                res += 1;
            }
        }
    }
    cout << res;
    return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

