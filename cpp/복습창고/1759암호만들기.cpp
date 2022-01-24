#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
using namespace std;


int l,c;
char arr[16];

char vowel[] = {'a','e','i','o','u'};

bool check(string s){
	int v_cnt=0;
	int c_cnt= 0;
	for(int i=0; i<s.size(); i++){
		if(find(vowel, vowel+5,s[i]) != vowel+5){
			v_cnt++;
		}
		else c_cnt++;
	}
	
	if(v_cnt>=1 && c_cnt>=2) return true;
	 return false;
}


void dfs(int level, string s, int idx){
	if(level==l){
		if(check(s)){
			cout<<s<<endl;
			return;
		}
		else return ;
	}
	
	for(int i=idx; i<c; i++){
		string ss= s+arr[i];
		dfs(level+1, ss, i+1);
	}
}



int main(){
	fastio;
	cin>>l>>c;
	
	
	for(int i=0; i<c; i++){
		cin>>arr[i];
	}
	
	sort(arr,arr+c);
	
	
	string start ="";
	
	
	dfs(0, "", 0);
	
	
	
	
	
	
	
	
	return 0;
} 
