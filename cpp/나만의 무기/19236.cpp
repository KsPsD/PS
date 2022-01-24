#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;

#define vi vector<int>
#define vipii vector<pair<int,int> >
#define pii  pair<int,int>
#define vvi vector<vi >
#define MOD 1000000007


const int MAX = 4;

struct Dir
{
	int y, x;
};

Dir moveDir[9] = { {0, 0}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1} };

struct Fish
{
	int idx, dir;
	int y, x;
};

int result;

Fish fishes[MAX * MAX + 1];
int fishTank[MAX][MAX];

void go(Fish fishes[MAX * MAX+1] , int fishTank[MAX][MAX], Fish shark, int total){
	
	result = max(result, total);
	
	for(int i=1; i<MAX*MAX+1; i++){
		int y = fishes[i].y;
		int x= fishes[i].x;
		int dir = fishes[i].dir;
		
		if(dir==0)
			continue;
			
		int yy= y+moveDir[dir].y;
		int xx= x+moveDir[dir].x;
		
		int dirCnt =0;
		
		for(int i=0; i<dirCnt; i++){
			yy= y+moveDir[dir].y;
			xx= x+moveDir[dir].x;
			 
			if(yy<0 || yy>=MAX || xx<0 ||xx>=MAX){
				fishes[i].dir = (dir  ==8 ) ? 1: dir+1;
				dir = fishes[i].dir;
				
				continue;
			}
				
			if(yy == shark.y && xx== shark.x){
				fishes[i].dir = (dir == 8) ? 1 : dir + 1;
				dir = fishes[i].dir;

				continue;
			}
			
			break;
		}
		
		
		if(dirCnt ==8 )
			continue;
		
		int nextIdx = fishTank[yy][xx];
		if(nextIdx){
			fishTank[y][x] = nextIdx;
			fishes[nextIdx].y=y;
			fishes[nextIdx].x =xx;
		}
		
		else
			fishTank[y][x] = 0;
		
		
		fishes[i].y= yy;
		fishes[i].x=xx;
		fishTank[yy][xx] = i;
	}
	
		int y = shark.y;
	int x = shark.x;
	int dir = shark.dir;


	for(int i=1; i<=3; i++){
		
		Fish tempFishes[MAX * MAX + 1];
		
		memmove(tempFishes , fishes, sizeof(fishes));
		int tempFishTank[MAX][MAX];
		memmove(tempFishTank , fishTank, sizeof(fishTank));


		int yy=  y+moveDir[dir].y*i;
		int xx=  y+moveDir[dir].x*i;
		
		if(yy<0 || yy>=MAX || xx<0 || xx>=MAX)
			continue;
		if(tempFishTank[yy][xx] ==0)
			continue;
		
		shark.y= yy;
		shark.x = xx;
		
		
		
		int score = tempFishTank[yy][xx];
		tempFishTank[yy][xx] = 0;

		shark.dir = tempFishes[score].dir;
		tempFishes[score].dir = 0;

		go(tempFishes, tempFishTank, shark, total + score);
	}
	
	
	
	
}

int main(){
	
	Fish shark;
	
	for (int y = 0; y < MAX; y++)
	{
		for (int x = 0; x < MAX; x++)
		{
			int idx, dir;
			cin >> idx >> dir;

			if (y == 0 && x == 0)
			{
				shark = { idx, dir, y, x };
				continue;
			}

			fishes[idx] = { idx, dir, y, x };
			fishTank[y][x] = idx;
		}
	}
	
	go(fishes, fishTank, shark, shark.idx);
	
	
	cout<<result<<endl;
	return 0;
}
