#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
using namespace std;

int main(){
	
	string s1;
	string s2;
	
	cin>>s1>>s2;
	int ans =0;
	vector<vector<int>> v(s1.size()+1,vector<int>(s2.size()+1,0));
	
	for(int i=1 ;i<=s1.size(); i++){
		for(int j=1;j<=s2.size(); j++){
			if(s1[i-1] ==s2[j-1]){
				v[i][j] = v[i-1][j-1]+1;
				ans = max(ans, v[i][j]);
			}
		}
	}
	cout<<ans<<endl;
	
	
	return 0;
} 
