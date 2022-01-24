#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef struct { int x, y; }point;
int r, c, n, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
string map[105];
bool visit[105][105] = { 0 };

bool safe(int x, int y) { return x >= 0 & x < c && y >= 0 && y <= r; }

point locationToDestroy(bool turn, int height) {    //�ش� �Ͽ� ��� ��ǥ�� �ı��ؾ� �ϳ�?
	point p={-1,height};
    if (turn) {    //Ȧ�� ���϶��� ��-> ��
        p.x = 0;
		while (p.x < c && map[p.y][p.x] == '.')    //�̳׶��� ���� �� ���� �̵�
			p.x++;
	}
	else {        //��-> ��
		p.x = c-1;
		while (p.x >= 0 && map[p.y][p.x] == '.')
			p.x--;
	}
    
    return p;    //�ı��� ��ǥ return
}

bool existCluster() {    //���ߺξ��� Ŭ�����Ͱ� �ִ��� �˻��ϰ�, �׷��� Ŭ�����͸� üũ�ϴ� �޼ҵ�
	queue<point> q;
	memset(visit, false, sizeof(visit));

	visit[r][0] = 1;    //������ ���� �������� BFS�� �����ϸ� �� ���� ���� �� �ִ�
	q.push({ 0,r });

	while (!q.empty()) {    //������ BFS
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
			if (map[i][j] == 'x' && !visit[i][j])    //'x'�ε� visit���� �ʾҴٸ� ���� �̾����� ���� �̳׶��̹Ƿ� Ŭ������
				return true;    //Ŭ�����Ͱ� �������� ��ȯ

	return false;
}

void gravity() {
	int min = r;
	for (int j = 0; j < c; j++) {

		for (int i = r; i > 0; i--) {
			if (map[i][j] != 'x'||!visit[i][j])continue;    //�����̰ų� Ŭ�������� ��쿡�� �Ÿ��� ���� �ʾƵ� ��

			int h = 0;    //�߰� ���̸� ī��Ʈ�� ����
			
            for (int k = i - 1; k >= 0; k--) {    //�ش� �������� Ŭ�����͸� ���� �� ���� ī��Ʈ
				if (map[k][j] == 'x') {
					if (!visit[k][j])
						min = h < min ? h : min;    //ī��Ʈ�� ���̷� �ּҰ� ����
					break;
					
				}
				else h++;
			}
		}
	}

	for(int j=0;j<c;j++)
		for (int i = r - 1; i >= 0; i--) 
			if (!visit[i][j] && map[i][j]=='x'){    //Ŭ�����͸� ������ �ּҰ���ŭ �Ʒ��� ������
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
		point p = locationToDestroy(b, r-h);    //�̳׶��� �����ϴ� ��ġ ��ȯ
		if (p.x >= 0 && p.x < c) {    //���� ���� ���� ���(�Է¹��� ���̿� �̳׶��� ���� ���� ������) ����
			map[p.y][p.x] = '.';
		}

		if (existCluster())gravity();    //���� ���ߺξ��� Ŭ�����Ͱ� �����Ѵٸ� �Ʒ��� �����ֱ�
		//print();
		//cout << existCluster()<<'\n';
		b ^= 1;

	}
	print();
}
