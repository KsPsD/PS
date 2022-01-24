#include<bits/stdc++.h>

using namespace std;





int main(){
	
	
	string s;
	cin>>s;

	int ans=0;
	for(int i=0; i<s.size();){
		if(s[i] == 'c'){
			if(s[i+1]== '='){
				ans++;
				i+=2;	
			}
			else if(s[i+1] =='-'){
				ans++;
				i+=2;
			}
			else{
				ans++;
				i+=1;
			}
		}
		
		else if(s[i]=='d'){
			if(s[i+1]=='z'){
				if(s[i+2] =='='){
					ans++;
					i+=3;
				}
				else{
					ans+=2;
					i+=2;
				}
			}
			else if(s[i+1]=='-'){
				ans++;
				i+=2;
			}
			else{
				ans++;
				i+=1;
			}
		}
		
		else{
			if(s[i]=='l'){
				if(s[i+1]=='j') {
					ans++;
					i+=2;
				}
				else{
					ans++;
					i+=1;
				} 
			}
			else if(s[i] =='n'){
				if(s[i+1]=='j') {
					ans++;
					i+=2;
				}
				else{
					ans++;
					i+=1;
				} 
			}
			else if(s[i]=='s'){
				if(s[i+1]=='=') {
					ans++;
					i+=2;
				}
				else{
					ans++;
					i+=1;
				} 
			}
			else if(s[i] == 'z'){
				if(s[i+1]=='=') {
					ans++;
					i+=2;
				}
				else{
					ans++;
					i+=1;
				} 
			}
			
			else{
				ans++;
				i+=1;
			}
		}
	}
	
	
	cout<<ans<<endl;
	
	
	
	
	return 0;
	
}
