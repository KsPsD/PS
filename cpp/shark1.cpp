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
    // �̵��� ���� ���� �� ���� while�� ����
    while (true)
    {
        // ���� �� �ִ� �������� �����ϴ� �켱���� ť �ʱ�ȭ
        priority_queue<fish, vector<fish>, compare> pq;

        // bfsŽ�� ����
        // ���� ��ġ���� ���� �� �ִ� ��� �������� pq�� ����
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
                // ���� �� �ִ� ������� pq�� ����
                if (arr[ny][nx] < size && arr[ny][nx] != 0)
                {
                    pq.push({cur.dist + 1, ny, nx});
                }
            }
        }
        // ch �迭 �ʱ�ȭ
        memset(ch, false, sizeof(ch));
        // pq�� ������� ������ pq�� top�� �Ծ�� �� �����
        if (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            arr[cur.y][cur.x] = 0; // ����⸦ �Ծ����� ���� 0���� ����
            eat++; // ���� ����� ����
            time = cur.dist; // ���� �ð�
            q.push({cur.dist, cur.y, cur.x}); // ���� �Ʊ� ����� ��ġ push
            ch[cur.y][cur.x] = true;
        }
        // ���� �� �ִ� ����Ⱑ �����Ƿ� �����ð� ��� �� while�� Ż��
        else
        {
            cout << time << '\n';
            break;
        }
        // ���� ������ �Ʊ����� ũ��� ���ٸ�
        // ũ�� 1����, ���� ���� 0���� �ʱ�ȭ
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

    // �Է¹ޱ�
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
