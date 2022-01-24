#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long

using namespace std;


int toNumber(char c){
	return c-'0';
}

struct Trie{
	bool is_terminal;
	Trie *next[10];
	
	Trie():is_terminal(false){
		memset(next, 0,sizeof(next));
		
	}
	
	~Trie(){
		for(int i=0; i<10; i++){
			if(next[i]){
				delete next[i];
			}
		}
	}
	
	void insert(const char *key){
		if(*key =='\0'){
			is_terminal=true;
		}
		
		else{
			int idx = toNumber(*key);
			if(next[idx]==0) next[idx] =new Trie();
			next[idx]->insert(key+1);
		}
	}
	bool find(const char *key){
		if(*key == '\0')return true;
		
		if(is_terminal)return false;
		
		int idx=toNumber(*key);
		return next[idx]->find(key+1);
	}
	
	
};



int main(){
	
	fastio;
	int t;
	char phones[10000][11];
	
	cin>>t;
	while(t--){
		int n;cin>>n;
	
		Trie * root = new Trie();
		
		for(int i=0 ;i < n; i++){
			cin>>phones[i];
			root->insert(phones[i]);
		}
		
		bool flag= true;
		for(int i=0; i<n; i++){
			if(root->find(phones[i]) ==false){
				flag= false;
				break;	
			}
		}
		
		delete root;
		
		
		flag? cout<<"YES"<<endl : cout<<"NO"<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
