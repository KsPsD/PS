#include<bits/stdc++.h>

using namespace std;


int main(){
	
	
	vector<int> v ={1,2,3,4,5,6,7,8,9};
	
	reverse(v.begin(), v.begin()+2);
	reverse(v.begin()+2, v.end());
	reverse(v.begin(), v.end());
	
	
	for(auto e:v){
		cout<<e<<endl;
	}
	
	
	
	
	return 0;
}
