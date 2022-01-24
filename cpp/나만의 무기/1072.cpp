#include<bits/stdc++.h>

using namespace std;


double y,x;
int ans = 1000000001;

bool ch(int m){
	int curz = (y*100.0) /x;
	int newz = ((y+m)*100.0) /(x+m);
	
	if(newz> curz) return true;
	
	return false;
	
}


int main(){
	
	
	
	cin>>x>>y;

int lt= 0;
int rt=	ans-1;

if((y*100/x)>=99 ) {
	cout<<-1<<endl;
	exit(0);
}

while(lt<=rt){
	int mid =(lt+rt) /2;
	if(ch(mid)){
		ans=mid;
		
		rt=mid-1;
		
	}
	else lt=mid+1;
	
}
	
cout<<ans<<endl;
	
	
	
	
	return 0;
	
}
