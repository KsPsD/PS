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

struct fish
{
    int dist;
    int y;
    int x;
};

struct compare
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

void bfs()
{
    int size = 2;
    int eat = 0;
    int time = 0;
    // 이동할 곳이 없을 때 까지 while문 수행
    while (true)
    {
        // 먹을 수 있는 물고기들을 저장하는 우선순위 큐 초기화
        priority_queue<fish, vector<fish>, compare> pq;

        // bfs탐색 수행
        // 현재 위치에서 먹을 수 있는 모든 물고기들을 pq에 저장
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
        // ch 배열 초기화
        memset(ch, false, sizeof(ch));
        // pq가 비어있지 않으면 pq의 top이 먹어야 할 물고기
        if (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            arr[cur.y][cur.x] = 0; // 물고기를 먹었으니 값을 0으로 설정
            eat++; // 먹은 물고기 개수
            time = cur.dist; // 생존 시간
            q.push({cur.dist, cur.y, cur.x}); // 다음 아기 상어의 위치 push
            ch[cur.y][cur.x] = true;
        }
        // 먹을 수 있는 물고기가 없으므로 생존시간 출력 후 while문 탈출
        else
        {
            cout << time << '\n';
            break;
        }
        // 먹은 개수가 아기상어의 크기와 같다면
        // 크기 1증가, 먹은 개수 0으로 초기화
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
