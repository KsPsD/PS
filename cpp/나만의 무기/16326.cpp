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



struct fish{
	int dist,y,x;
};

struct cmp
{
    bool operator()(fish a, fish b)
    {
        if (a.dist == b.dist)
        {
            if (a.y == b.y)
            {
                return a.x > b.x;
            }
            return a.y > b.y;
        }
        return a.dist > b.dist;
    }
};

int n;
int arr[21][21];
bool ch[21][21];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};
queue<fish> q;


void bfs(){
	
	int size = 2;
    int eat = 0;
    int time = 0;
	
	while(true){
		
		priority_queue<fish, vector<fish> ,cmp> pq;
		
		
		  while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                    continue;
                if (arr[ny][nx] > size || ch[ny][nx])
                    continue;
                q.push({cur.dist + 1, ny, nx});
                ch[ny][nx] = true;
                // 먹을 수 있는 물고기라면 pq에 저장
                if (arr[ny][nx] < size && arr[ny][nx] != 0)
                {
                    pq.push({cur.dist + 1, ny, nx});
                }
            }
        }
		
		memset(ch, false, sizeof(ch));

		
		
		if(!pq.empty()){
			auto cur =pq.top();
			pq.pop();
			arr[cur.y][cur.x] = 0; //
			eat++;
			time = cur.dist;
			q.push({cur.dist, cur.y, cur.x}); // 다음 아기 상어의 위치 push
            ch[cur.y][cur.x] = true;
		}
		
		else{
			cout<<time<<endl;
			break;
		}
		
		if (eat == size)
        {
            size++;
            eat = 0;
        }
	}
	
	
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력받기
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 9)
            {
                q.push({0, i, j});
                arr[i][j] = 0;
                ch[i][j] = true;
            }
        }
    }
    bfs();
    return 0;
}
