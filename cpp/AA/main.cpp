#include<bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int arr[20];
	int n,s;
	int result =0;
	vector<int> res;
	cin>>n>>s;
	
	for(int i= 0 ; i<n ;i++){
		cin>>arr[i];
		
	}
	for(int i= 1; i<(1<<n); i++){
		int sum = 0;
		for(int j =0; j<n ;j++){
			if(i & (1<<j)) {
			sum+=arr[j];
			res.push_back(arr[j]);
			}
		}
		if(sum==s) {
		result ++;
		for(int i =0 ; i<res.size(); i++)cout<<res[i]<<" ";
		cout<<endl;
		res.clear();
		}
		
		else{
			res.clear();
		}
	}
	
	
	cout<<result<<endl;
	return 0;
}
