#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;

int dy[8] ={-1,-1,-1,1,1,1,0,0};
int dx[8] ={-1,0,1,-1,0,1,-1,1};

char arr[5][5];
string word;
int ch[5][5][10];


int check(int y,int x,int idx){
	
		
	if(word[idx] != arr[y][x]) return 0;
	if (idx==(word.size()-1))  return 1;
	for(int i=0 ;i<8 ;i++){
		int yy = y+dy[i];
		int xx = x+dx[i];
		if(yy>=0 && xx>=0 && yy<5 && xx<5){
			if(ch[yy][xx][idx+1]) continue;
			if(check(yy,xx, idx+1)) return 1;
		}
		
	}
	
	return 0;
}





bool start(){
	int flag;
	for(int i=0; i<5; i++){
		flag=0;
		for(int j=0 ; j<5 ;j++){
			if(flag = check(i,j,0)) break;
		}
		if(flag) break;
	}
	
	if(flag) return true;
	else return false;
}

int main() {
	fastio;

	
	int c;cin>>c;
	while(c--){
		for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			cin>>arr[i][j];
		}
	}
	
	int n;cin>>n;
	for(int i=0 ;i<n ;i++){
		cin>>word;
		
		
		memset(ch, 0 ,sizeof(ch));
			
		bool flag =start();
		if(flag) cout<<word<<" "<< "YES"<<endl;
		else cout<<word<<" "<< "NO"<<endl;
	}
	}
	
	

    return 0;
}
