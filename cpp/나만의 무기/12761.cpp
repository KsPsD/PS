#include<bits/stdc++.h>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define MAX 100001

int A,B,N,M;
int ch[MAX];

int main(){
	
	cin>>A>>B>>N>>M;
	
	queue<pair<int,int>>q;
	
	q.push({N,0});
	ch[N] =1;
	while(!q.empty()){
		pair<int,int>  tmp = q.front();
		if(tmp.first == M ){
			cout<<tmp.second<<endl;
			break;
		}
		q.pop();
	
		if(tmp.first-1>=0 && ch[tmp.first-1]==0 ) {
			q.push({tmp.first-1, tmp.second+1});
			ch[tmp.first-1] =1;
		}
		 if(tmp.first+1<MAX && ch[tmp.first+1]==0 ){
		 q.push({tmp.first+1,tmp.second+1});
			ch[tmp.first+1] =1;
		}
	 if(tmp.first+A<MAX && ch[tmp.first+A]==0) {
			q.push({tmp.first+A,tmp.second+1});
			ch[tmp.first+A] =1;
		}
		if(tmp.first-A>=0 && ch[tmp.first-A]==0) {
		q.push({tmp.first-A,tmp.second+1});
			ch[tmp.first-A] =1;
		} 
		 if(tmp.first+B<MAX && ch[tmp.first+B]==0) {
			q.push({tmp.first+B,tmp.second+1});
			ch[tmp.first+B] =1;
		}
		 if(tmp.first-B>=0 && ch[tmp.first-B]==0){
			q.push({tmp.first-B,tmp.second+1});
			ch[tmp.first-B] =1;
		} 
		if(tmp.first*A<MAX && ch[tmp.first*A]==0){
			q.push({tmp.first*A,tmp.second+1});
			ch[tmp.first*A] =1;
		} 
		if(tmp.first*B<MAX && ch[tmp.first*B]==0) {
			q.push({tmp.first*B,tmp.second+1});
			ch[tmp.first*B] =1;
		}
		
	}
	
	
	
	return 0;
}
