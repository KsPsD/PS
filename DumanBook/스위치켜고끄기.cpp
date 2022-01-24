#include<bits/stdc++.h>


using namespace std;




int main(){
	
	
	int n;cin>>n;
	vector<int> v(n+1);
	for(int i=1; i<=n; i++){
		cin>>v[i];
	}
	int num;
	cin>>num;
	vector<pair<int ,int> > s;
	for(int i=1; i<=num; i++){
		int sex,idx;
		cin>>sex>>idx;
		
		if(sex==1){
			for(int i=1; i<=n;i++){
				if(i%idx==0){
					v[i]^=1;
				}
			}
		
		}
		
		else{
			for(int i=1; i<=n; i++){
				if(i==idx){
					int tmp=idx;
					v[tmp]^=1;
					int lt= tmp-1;
					int rt= tmp+1;
					while(lt>=1 && rt<=n){
						if(v[lt]==v[rt]){
							v[lt]^=1;
							v[rt]^=1;
							lt--;
							rt++;
						
						}
						else 
							break;
					}
				}
			}
		}
		
	}
	
	
	
	for(int i=1; i<=n; i++){
		cout<<v[i]<<" ";
		if(i%20==0)
			cout<<endl;
	}
		
	
	
	
	return 0;
}
