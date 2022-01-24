#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b;i++)


bool ch[1000];

int main(){
	fastio;
	
	int n;cin>>n;
	memset(ch,true,sizeof(ch));
	for(int i= 123; i<=999; i++){
		string tmp = to_string(i);
		if(tmp[0]==tmp[1] || tmp[1]==tmp[2] || tmp[0] == tmp[2]) ch[i] =false;
		if(tmp[2]-'0' == 0|| tmp[1]-'0' == 0|| tmp[0]-'0' == 0 ) ch[i] = false;
	}
	
	for(int i=0 ;i<n;i++){
		int num,s,b;cin>>num>>s>>b;
		string origin= to_string(num);
	for(int j=123; j<=999;j++){
			int tmp_s=0;
			int tmp_b= 0;
		if(ch[j]==true){
				string tmp = to_string(j);
			for(int a=0 ;a<3; a++){
				for(int b= 0; b<3; b++){
					if(a==b && tmp[b] == origin[a]) tmp_s++;
					if(a!=b && tmp[b] == origin[a]) tmp_b++;
					}
				}
			if(s!=tmp_s || b!=tmp_b) ch[j] =false;
		}
			
	}
	
	}
	
	int ans =0;
	for(int i=123; i<=999; i++){
		if(ch[i]) {
			ans++;
		}
	}

cout<<ans<<endl;

	return 0;
	
}



