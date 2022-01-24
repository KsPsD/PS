#include<bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std;

//
string num;
char Vowel[]={'a','e','i','o','u'};

int l,c;
string res;
char input[16];
int cnt;
bool check(string s){

	int vo=0;
	int co=0;
	for(int i=0; i<s.size(); i++){
		if(find(Vowel,Vowel+5,s[i]) !=Vowel+5){
			
			vo++;
		}
	
		else co++;
		
	}
	
	if(vo>=1 && co>=2) return true;
	
	return false;
}


void dfs(int idx,string  s,int level){
	if(level==l-1){
		if(check(s)) {
			cout<<s<<endl;
		return;	
		}
		else return;
	}
	
	for(int i=idx+1; i<c ;i++){
		string ss=s+input[i];
		dfs(i, ss,level+1);
	}
}


int main(){
	

	cin>>l>>c;
	for(int i=0 ;i<c; i++){
		cin>>input[i];
	}
	

	sort(input, input+c);
	for(int i=0 ;i<c; i++){
		res=input[i];
		dfs(i,res,0);
	}
	

	
	
	
	return 0;
} 
