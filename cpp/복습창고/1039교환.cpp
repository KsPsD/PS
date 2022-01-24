#include<bits/stdc++.h>

#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
using namespace std;



int main(){
	
	string s;cin>>s;
	int k;cin>>k;
	
	queue<string> q;
	
	if(s.size() == 1 || (s.size()==2 && stoi(s) % 10 ==0)){
		cout<<-1<<endl;
		exit(0);
	}

	int cnt =0;
	int ans =0;
	
	q.push(s);
	
	while(!q.empty() && cnt< k){
			
		int size= q.size();
		set<string> ch;
		
		
		for(int n=0; n<size; n++){
			
			string tmp = q.front();
			q.pop();
		
		
		
		for(int i=0; i<s.size()-1 ;i++){
			for(int j=i+1; j< s.size(); j++){
				
				if(i==0 && tmp[j] =='0') continue;
				
				
				swap(tmp[i] , tmp[j]);
				if(ch.find(tmp) == ch.end()){
					
					if(k-1==cnt &&  ans < stoi(tmp)){
						ans = stoi(tmp);
					}
					q.push(tmp);
					ch.insert(tmp);
				}
				swap(tmp[i], tmp[j]);
				}
			
			}
				
		}
		cnt++;
		
	}
	
	
	if (cnt != k) cout << "-1" << endl;
	else cout<<ans<<endl;
	
	
	
	
	
	
	
	
	return 0;
} 
