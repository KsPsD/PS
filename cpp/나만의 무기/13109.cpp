#include<bits/stdc++.h>
#define ll long long
using namespace std;

string a;
string b;

int main(){
	cin>>a>>b;
	
	
	if(a==b){
		cout<<0<<endl;
		return 0;
	}
	
	string o_a = a;
	string o_b = b;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if(a !=b){
		cout<<-1<<endl;
		return 0;
	}
	
	a=o_a;
	b=o_b;
	
	int cnt =0;
	int i=0;
		
		for(i=a.size()-1 ; i>=0; i--){
			if(a[i] == b[a.size()-1-cnt]){
				cnt++;
			}
			
		}
	
	
	cout<<a.size() - cnt<<endl;	
	
	
	
	
	
	return 0;
}
