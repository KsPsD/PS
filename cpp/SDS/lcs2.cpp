#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
using namespace std;
int dp[1001][1001];
vector<char> v;
string s1,s2;
void go(int i, int j){
	if(dp[i][j] ==0)return;
	if(s1[i-1]==s2[j-1]){
		go(i-1,j-1);
		cout<<s1[i-1];
	}
	else dp[i-1][j]> dp[i][j-1] ? go(i-1,j) : go(i,j-1);
}


int main(){
	
	
	cin>>s1>>s2;
	
	for(int i=1; i<=s1.size(); i++){
		for(int j=1; j<=s2.size(); j++){
			if(s1[i-1] == s2[j-1] ) {
				dp[i][j] =dp[i-1][j-1]+1;
			}
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	
	cout<<dp[s1.size()][s2.size()]<<endl;
	
	go(s1.size(), s2.size());
	
	
	
	
	return 0;
}
