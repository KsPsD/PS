#include<bits/stdc++.h>


using namespace std;

int n;
int ch[10001];


int main(){
	
	cin>>n;
	vector<int>v;
	double avg=0;
	int mid=0;
	int most=0;
	int len=0;
	
	
	for(int i=0 ; i<n; i++){
		int a;cin>>a;
		avg+=a;
		v.push_back(a);
		ch[a+4000]++;
	}
	
	int res = *max_element(ch, ch+8001);
	int cnt=0;
	avg/=n;
	len =  *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
	sort(v.begin(), v.end());
	
	
	mid = v[n/2];
	

	
	for(int i=0 ; i<8001; i++){
	
		if(ch[i] == res){
			cnt++;
			most = i;
			if(cnt==2)
				break;
		}
		
		
	}
	most-=4000;
	
	
	cout<<round(avg)<<endl;
	cout<<mid<<endl;
	cout<<most<<endl;
	cout<<len<<endl;	
	
	
	
	
	return 0;
}
