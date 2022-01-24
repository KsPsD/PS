#include<bits/stdc++.h>



using namespace std;


int n,m;
 vector<int> v;
int ch[9] ;
int w=500;
int ans =0;
void go(int cnt){
	if(cnt == n) {
		ans++;
		return;	
	}
	
	for(int i=0; i<n; i++){
		if(!ch[i]){
			ch[i] =1;
			if(v[i]+w-m>=500){
				w+=v[i]-m;
				go(cnt+1);
				w-=v[i]-m;
				ch[i]=0;
			}
			else{
				ch[i] =0;
			}
		}
	}
}



int main(){
	

cin>>n>>m;

v.resize(n);
for(int i=0; i<n; i++){
	cin>>v[i];
}
	
	
	go(0);
	
	
	cout<<ans<<endl;
	
	
	
	
	
	return 0;
}
