#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;

const int MAXN = 65536;
#define Msize 65536
#define ll long long


int tree[Msize * 4];
int N, K;
int input[250250];
ll ans;


int query(int val, int node, int nodeLeft, int nodeRight) {
		if (nodeLeft == nodeRight) return nodeLeft;

		int mid = (nodeLeft + nodeRight) / 2;
		if (val <= tree[node * 2]) return query(val, node * 2, nodeLeft, mid);
		else return query(val - tree[node * 2], node * 2 + 1, mid + 1, nodeRight);
	}
	
	
int update(int idx, int val, int node, int nodeLeft, int nodeRight) {
		if (idx < nodeLeft || idx > nodeRight) return tree[node];

		if (nodeLeft == nodeRight) {
			tree[node] += val;
			return tree[node];
		}

		int mid = (nodeLeft + nodeRight) / 2;

		tree[node] = update(idx, val, node * 2, nodeLeft, mid) + update(idx, val, node * 2 + 1, mid + 1, nodeRight);

		return tree[node];
	}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; ++i) {
		cin >> input[i];
	}

	for (int i = 0; i < K; ++i) {
		update(input[i], 1, 1, 0, Msize);
	}

	ans = query((K + 1) / 2, 1, 0, Msize);

	for (int i = K; i < N; ++i) {

	update(input[i], 1, 1, 0, Msize);
	update(input[i - K], -1, 1, 0, Msize);

		int medium = query((K + 1) / 2, 1, 0, Msize);
		ans += medium;
	}

	printf("%lld\n", ans);

	return 0;
}
