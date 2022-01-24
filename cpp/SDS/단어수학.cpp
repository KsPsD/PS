#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std;



vector<string> words;
vector<char> alpha;
int ch[10] ;
vector<int> num;
vector<int> alphaToNum(26);
int ans =-1;
void calc(){
	for(int i=0; i<alpha.size(); i++){
		alphaToNum[alpha[i]] =num[i];
	}
	int sum=0;
	for(int i=0; i<words.size(); i++){
		int now=0;
		for(int j=0; j<words[i].size(); j++){
			now *=10;
			now+=alphaToNum[words[i][j]];
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

void deleteOverLap(){
	for(int i=0; i<words.size() ;i++){
		for(int j=0; j<words[i].size(); j++){
			alpha.push_back(words[i][j]); 
		}
	}
	
	sort(alpha.begin(), alpha.end());
	alpha.erase(unique(alpha.begin(), alpha.end()) , alpha.end());
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
   	deleteOverLap();
    dfs();
   cout<<ans<<endl;
}
