#include<bits/stdc++.h>


using namespace std;

int arr[601][601];
int ans[301][301];
int h,w,x,y;

int main(){
	
	cin>>h>>w>>x>>y;
	
	for(int i=1; i<= h+x; i++){
		for(int j=1; j<=w+y; j++){
			cin>>arr[i][j];
		}
	}
	
	for(int i=1;i <= h; i++){
		for(int j=1; j<=w; j++){
			if(i-x >=1 && j-y >=1)
				ans[i][j]  = arr[i][j] - ans[i-x][j-y] ;
				
			else
				ans[i][j] = arr[i][j];
			
			}
		}
	
	
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			cout<<ans[i][j] << " ";
		}
		cout<<endl;
	}
	
	
	return 0;
}
