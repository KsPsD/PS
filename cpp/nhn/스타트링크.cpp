#include<bits/stdc++.h>


using namespace std;

const int MAX = 1000001;

int F,S,G,U,D; 
int ch[MAX];

int main(){
	
	cin>>F>>S>>G>>U>>D;
	
	
	queue<pair<int ,int> > q;
	
	int cnt=-1;
	ch[S]=1;
	q.push({S,0});
	
	
	
	
	while(!q.empty()){
		pair<int,int> tmp = q.front();
		q.pop();
		if(tmp.first==G){
			cnt=tmp.second;
			break;
		}
		if(tmp.first+U<=F && tmp.first+U>=1 &&!ch[tmp.first+U]){
			q.push({tmp.first+U, tmp.second+1});
			ch[tmp.first+U] =1;
		}
		if(tmp.first-D>=1 && !ch[tmp.first-D]){
			q.push({tmp.first-D ,tmp.second+1});	
			ch[tmp.first-D] =1;
		}
		
	}
	
	
	if(cnt==-1)
		cout<<"use the stairs"<<endl;
	else
	cout<<cnt<<endl;
	
	
	return 0;
}
