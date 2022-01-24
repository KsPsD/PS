#include<bits/stdc++.h>

using namespace std;


int n;
int ch[26];


bool check(string s){
	memset(ch,0,sizeof(ch));
	char prev= s[0];
	ch[s[0]-'a'] =1;
	for(int i=1; i<s.size(); i++){
		if(ch[s[i]-'a'] ==0){
			ch[s[i] - 'a'] =1;
		}
		else if(ch[s[i]-'a'] !=0  && prev == s[i] ){
			ch[s[i] -'a']++;
		} 
		else if(ch[s[i] -'a'] !=0 && prev !=s[i]){
			return false;
		}
		prev = s[i];
	}
	
	return true;		
}


int main(){
	cin>>n;
	int cnt=0;
	string s;
	for(int i=0;i<n ;i++){
		cin>>s;
		if(check(s)){
			
			cnt++;
		
		}
		else continue;
		
	}
	
	cout<<cnt<<endl;
	
	
	
	
	
	
	
	return 0;
}
