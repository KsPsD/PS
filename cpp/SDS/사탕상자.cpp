#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;

const int MAXN = 1000001;

int n;
int tree[MAXN * 4];

// ������ ����
void update(int index, int target, int diff, int start, int end) {
	if (target < start || target > end)
		return;
	tree[index] += diff;
	if (start == end)
		return;
	int mid = (start + end) / 2;
	update(index * 2, target, diff, start, mid);
	update(index * 2 + 1, target, diff, mid + 1, end);
}

// ���� ��� ����
int query(int index, int target, int start, int end) {
	if (start == end)
		return start;
	int mid = (start + end) / 2;
	if (target <= tree[index * 2])
		return query(index * 2, target, start, mid);
	else
		return query(index * 2 + 1, target - tree[index*2], mid + 1, end);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	while (n--) {
		int a, b, c;
		cin >> a;
		// B���� ������ ������ ���
		if (a == 1) {
			cin >> b;
			int favor = query(1, b, 1, MAXN);
			cout << favor << '\n';
			update(1, favor, -1, 1, MAXN);
		}
		// B���� C���� ������ �ִ� ���(�����ΰ��� ����)
		else {
			cin >> b >> c;
			update(1, b, c, 1, MAXN);
		}
	}
	return 0;
}
