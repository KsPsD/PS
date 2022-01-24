#include<bits/stdc++.h>


using namespace std;


int main(){
	
	
	vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
	int ans =0;
	
	for(int i=1; i< v.size()-1; i++){
		int lt,rt=0;
		for(int j=0; j<i; j++){
		 if(lt<v[j])
                lt= v[j];
		}
		for(int j=v.size()-1; j>i; j--){
			if(rt<v[j])
                rt=v[j];
		}
		int val = min(lt,rt);
		ans += max(0,(val - v[i]));
	}	
	
	cout<<ans<<endl;
	
	
	
	return 0;
}
