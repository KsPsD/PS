#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

using namespace std;
const int MAX = 50000;
// 2^16 > 50000
const int DMAX = 16;
const int INF = INT_MAX; 
typedef pair<int, int> pii;

int V, E;
// �� A, �� B �����ϴ� Edge , ����ġ�� W 
struct Edge{
	int A;
	int B;
	int W;
	bool Used = false; 
	Edge():Edge(0,0,0){}
	Edge(int a1, int b1, int w1): A(a1), B(b1), W(w1){}
};
// Edge �� ���� 
vector<Edge> Vec;
// ����ġ W �����ź��� 
bool cmp(const Edge &E1, const Edge &E2){
	return E1.W < E2.W;
}
// Union Find
// R[i] : i�� root 
int R[MAX+1];
int Find(int x){
	if(R[x]==0) return x;
	return R[x] = Find(R[x]);
}
void Union(int x, int y){
	int xRoot = Find(x);
	int yRoot = Find(y);
	if(xRoot == yRoot) return;
	R[yRoot] = xRoot;
}
//LCA �� ���� ��� 
// adj[i] : < i �� �ڽĳ�� , �ش� ����ġ >
vector<pii> adj[MAX+1];
int Depth[MAX+1];
// parent[i][k] = i�� 2^k ���� 
int parent[MAX+1][DMAX+1];
// Biggest[i][k] : i�� 2^k �������� ���� �濡 �ִ� <���� ū ���� , 2��°�� ū ����>
// ����ū���� != 2��°��ū���� ���� ������ش�.
// -> ��� edge �� ����ġ�� 1 �� ��� ���� ���� ���� 
// ������ ���� ���� �߰��� ���� ū �������� ��ü ���� ��� 
pii Biggest[MAX+1][DMAX+1];
// i ���� depth ���� 
void MakeDepth(int curr){
	for(auto child: adj[curr]){
		if(Depth[child.first]!=0) continue;
		Depth[child.first] = Depth[curr]+1;

		parent[child.first][0] = curr;
		// MST �� �����ϴ� edge ���� �ּҰ��� ����ϸ鼭 ������. (�ڵ� 52~54) 
		Biggest[child.first][0] = pii(child.second,-1);
		MakeDepth(child.first);
	}
}
// �߰��� Edge(a~b) �� ����� cycle �� LCA �� �̿��� ã��, cycle �ȿ� ��ü ������ ���� ū �� ã��
int HowAboutThis(Edge EE){
	int x = EE.A;
	int y = EE.B;
	int w = EE.W;
	// ��ü������ ������ ���� ū ����ġ. w �� �޶���Ѵ�.
	int ret = -1;
	if(Depth[x]<Depth[y]) swap(x,y);
	int diff = Depth[x] - Depth[y];
	int cnt = 0;
	while(diff){
		if(diff%2==1){
			//����� ���� ū ����ġ
			if(Biggest[x][cnt].first!=w)
				ret = max(ret, Biggest[x][cnt].first);
			//����� �ι�° ū ����ġ
			else if(Biggest[x][cnt].second!=-1)
				ret = max(ret, Biggest[x][cnt].second);
			
			x = parent[x][cnt];
		}
		diff/=2;
		cnt++;
	}
	if(x!=y){
		for (int i = DMAX; i >= 0; i--){
			if(parent[x][i]!=parent[y][i]){
				if(Biggest[x][i].first!=w)
					ret = max(ret, Biggest[x][i].first);
				else if(Biggest[x][i].second!=-1)
					ret = max(ret, Biggest[x][i].second);
				if(Biggest[y][i].first!=w)
					ret = max(ret, Biggest[y][i].first);
				else if(Biggest[y][i].second!=-1)
					ret = max(ret, Biggest[y][i].second);

				x = parent[x][i];
				y = parent[y][i];
			}
		}
		if(Biggest[x][0].first!=w)
			ret = max(ret, Biggest[x][0].first);
		else if(Biggest[x][0].second!=-1)
			ret = max(ret, Biggest[x][0].second);
		if(Biggest[y][0].first!=w)
			ret = max(ret, Biggest[y][0].first);
		else if(Biggest[y][0].second!=-1)
			ret = max(ret, Biggest[y][0].second);

		x = parent[x][0];
	}
	return ret;
}
int main(){ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);

cin >> V >> E;
for(int i=0; i<E; ++i){
	int a, b, w;
	cin >> a >> b >> w;
	Vec.push_back(Edge(a,b,w));
}
// �ּ� ���д� Ʈ�� ����� ������� 
int MST = 0;
// V-1 ���� Edge ������ MST �ϼ�! 
int cnt = 0; 
// ����ġ ������
sort(Vec.begin(), Vec.end(), cmp);
// MST
for(int i=0; i<E; ++i){
	int a = Vec[i].A;
	int b = Vec[i].B;
	int aRoot = Find(a);
	int bRoot = Find(b);
	if(aRoot == bRoot) continue;
	Union(a,b);
	MST += Vec[i].W; 
	Vec[i].Used = true;
	// LCA ������ ���� �ڽ� ����  
	adj[a].push_back(pii(b,Vec[i].W));
	adj[b].push_back(pii(a,Vec[i].W));
	cnt++;
	if(cnt==V-1) break;
}
// MST �� ���ʿ� ���� ���
if(cnt!=V-1 || E<=V-1){
	cout << -1 << '\n';
	return 0;
}
// LCA ����, 1�� ��带 Root�� ����
Depth[1] = 1;
// tree Depth �����
MakeDepth(1);
for (int k = 0; k <= DMAX; ++k){
	for (int i = 1; i <= V; ++i){
		int Father = parent[i][k];
		if(Father && parent[Father][k]!=0){
			// i�� 2^k ���� ���� ū ����ġ 2�� , < w1, w2 > (w1>w2)
			int w1 = Biggest[i][k].first;
			int w2 = Biggest[i][k].second;
			// father�� 2^k ���� ���� ū ����ġ 2�� , < f1, f2 > (f1>f2)
			int f1 = Biggest[Father][k].first;
			int f2 = Biggest[Father][k].second;
			// ū ����ġ ���ϱ�
			if(w1>f1){
				Biggest[i][k+1].first = w1;
				Biggest[i][k+1].second = max(f1,w2);
			}
			else if(w1<f1){
				Biggest[i][k+1].first = f1;
				Biggest[i][k+1].second = max(w1,f2);	
			}
			// w1==f1�̸�
			else
				Biggest[i][k+1] = pii(w1,max(w2,f2));

			parent[i][k+1] = parent[Father][k];
		}
	}
}
// �Ƚẻ Edge �Ἥ MST �ٷ� �� �� ���غ���! (2��° MST)
int Plus = INF;
for(int i=0; i<E; ++i){
	// MST ���� �� ����� �����̸� �н�
	if(Vec[i].Used) continue;
	int t = HowAboutThis(Vec[i]);
	if(t==-1 || t==Vec[i].W) continue;
	Plus = min(Plus, Vec[i].W-t);
}
if(Plus==INF) cout << -1 << '\n';
else cout << MST+Plus << '\n';
return 0;
}
