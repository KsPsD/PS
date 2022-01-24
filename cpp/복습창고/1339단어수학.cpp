#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std;



vector<string> words;
set<char> alpha;
int ch[10] ;
vector<int> num;
vector<int> alphaToNum(26);
int ans =-1;
void calc(){
	set<char>::iterator it=alpha.begin();
	for( int i=0; it!=alpha.end(); i++, it++){
		alphaToNum[*it -'A'] =num[i];
	}
	int sum=0;
	for(int i=0; i<words.size(); i++){
		int now=0;
		for(int j=0; j<words[i].size(); j++){
			now *=10;
			now+=alphaToNum[words[i][j] -'A'];
		}
		sum+=now;
	}
	ans=max(ans,sum);
}


void dfs(){
	if(num.size() == alpha.size()){
		calc();
		return;
	}
	
	for(int i=9; i>=0; i--){
		if(!ch[i]){
			num.push_back(i);
			ch[i] =1;
			dfs();
			ch[i]=0;
			num.pop_back();
		}
		
	}
}


   


int main(){
    fastio;
    int n;
    cin >>n;
    string temp;
    for(int i = 0 ; i < n ; i++){
        cin >> temp;
        words.push_back(temp);
    }
    for(int i=0; i<words.size(); i++){
    	for(int j=0; j<words[i].size(); j++){
    		alpha.insert(words[i][j]);
		}
	}
    
    
    dfs();
   cout<<ans<<endl;
}
