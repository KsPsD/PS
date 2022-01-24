#include<bits/stdc++.h>


using namespace std;

int flag, cnt, c_f, maxi = 0;
int v[300001];
int check[3001];

int main(){
	
	
	int n,d,k,c;cin>>n>>d>>k>>c;

	 for(int i=0; i<n; i++){
	 	cin>>v[i];
	 }
	
	for(int i =0 ;i<n; i++){
		flag =0;
		c_f=1;
		for(int j=i ;j< i+k ;j++){
			if(check[v[j%n]] ==1) flag++;
			else check[v[j%n]] =1;
			
			if(v[j%n] == c) c_f =0;
		}
		maxi = max(maxi, k-flag+c_f);
		memset(check ,0, sizeof(check));
	}
	cout<<maxi<<endl;
	

	
	
	return 0;
}
