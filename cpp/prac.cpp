#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef struct { int x, y; }point;
int r, c, n, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
string map[105];
bool visit[105][105] = { 0 };

bool safe(int x, int y) { return x >= 0 & x < c && y >= 0 && y <= r; }

point locationToDestroy(bool turn, int height) {    //해당 턴에 어느 좌표를 파괴해야 하나?
	point p={-1,height};
    if (turn) {    //홀수 턴일때는 왼-> 오
        p.x = 0;
		while (p.x < c && map[p.y][p.x] == '.')    //미네랄을 만날 때 까지 이동
			p.x++;
	}
	else {        //오-> 왼
		p.x = c-1;
		while (p.x >= 0 && map[p.y][p.x] == '.')
			p.x--;
	}
    
    return p;    //파괴할 좌표 return
}

bool existCluster() {    //공중부양한 클러스터가 있는지 검사하고, 그러한 클러스터를 체크하는 메소드
	queue<point> q;
	memset(visit, false, sizeof(visit));

	visit[r][0] = 1;    //무조건 땅인 지점에서 BFS를 시작하면 한 번만 돌릴 수 있다
	q.push({ 0,r });

	while (!q.empty()) {    //땅에서 BFS
		point cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i], ny = cur.y + dy[i];

			if (safe(nx, ny) && !visit[ny][nx] && map[ny][nx] == 'x') {
				q.push({ nx,ny });
				visit[ny][nx] = 1;
			}
		}
		
	}

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (map[i][j] == 'x' && !visit[i][j])    //'x'인데 visit되지 않았다면 땅과 이어지지 않은 미네랄이므로 클러스터
				return true;    //클러스터가 존재함을 반환

	return false;
}

void gravity() {
	int min = r;
	for (int j = 0; j < c; j++) {

		for (int i = r; i > 0; i--) {
			if (map[i][j] != 'x'||!visit[i][j])continue;    //공기이거나 클러스터일 경우에는 거리를 재지 않아도 됨

			int h = 0;    //중간 높이를 카운트할 변수
			
            for (int k = i - 1; k >= 0; k--) {    //해당 지점에서 클러스터를 만날 때 까지 카운트
				if (map[k][j] == 'x') {
					if (!visit[k][j])
						min = h < min ? h : min;    //카운트한 높이로 최소값 갱신
					break;
					
				}
				else h++;
			}
		}
	}

	for(int j=0;j<c;j++)
		for (int i = r - 1; i >= 0; i--) 
			if (!visit[i][j] && map[i][j]=='x'){    //클러스터를 높이의 최소값만큼 아래로 내려줌
				map[i + min][j] = 'x';
				map[i][j] = '.';
	}

	return;
}

void print() {
	for (int i = 0; i < r; i++)
		cout << map[i]<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> map[i];
	for (int j = 0; j < c; j++)
		map[r].push_back('x');

	cin >> n;
	bool b = true;
	while (n--) {
		int h;
		cin >> h;
		point p = locationToDestroy(b, r-h);    //미네랄이 존재하는 위치 반환
		if (p.x >= 0 && p.x < c) {    //범위 내에 있을 경우(입력받은 높이에 미네랄이 없을 수도 있으니) 제거
			map[p.y][p.x] = '.';
		}

		if (existCluster())gravity();    //만약 공중부양한 클러스터가 존재한다면 아래로 내려주기
		//print();
		//cout << existCluster()<<'\n';
		b ^= 1;

	}
	print();
}
