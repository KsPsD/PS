#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
using namespace std;


vector<string> s;
int ch[26];

int n,k;
int ans =0;




void dfs(int idx ,int num){
	if(num==0){
		int cnt=0;
		for(int i=0; i<s.size(); i++){
			int flag=true;
		for(int j=0; j<s[i].size(); j++){
			if(ch[s[i][j]-'a'] == 0 ) {
				
				flag =false;
				break;
			}
			
		}
		if(flag) cnt++;
	}
	
		ans = max(ans, cnt);
		return ;
	}
	
	
	for(int i=idx; i<26; i++){
		if(ch[i]==0){
			ch[i]=1;
			num--;
			dfs(i , num);
			num++;
			ch[i] =0;
		}
	}
	
}




int main(){
	fastio;
	
	
cin>>n>>k;
if(k<5) {
	cout<<0<<endl;
	exit(0);
}
else if(k==26){
		cout<<n<<endl;
		return 0;
	}
int num = k-5;

	
ch['a'-'a'] =1;
ch['n'-'a'] =1;
ch['t'-'a'] =1;
ch['i'-'a'] =1;
ch['c'-'a'] =1;


for(int i=0; i< n; i++){
	string ss;cin>>ss;
	s.push_back(ss);
}
	
	
	dfs(0,num);
	
	
	cout<<ans<<endl;
	
	
	
	
	return 0;
} 
