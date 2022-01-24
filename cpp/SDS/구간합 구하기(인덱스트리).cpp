#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;
//
//#define MAX 1000000
////이건 조금 다르게 푸는거 
//typedef long long lld;
//
//lld n, m, k, a, b, c, OFFSET;
//lld datas[MAX+1], tree[4 * MAX];
//vector<lld> ans;
//
//void init(lld n) {
//	// OFFSET<n: 데이터 1부터 시작해서 
//	for (OFFSET = 1; OFFSET < n; OFFSET *= 2);
//
//	// leaf 채우기
//	for (lld i = 0; i < n; i++) tree[i + OFFSET] = datas[i];
//
//	// 포화이진트리, leaf 나머지 채움
//	for (lld i = n; i < OFFSET; i+	+) tree[i + OFFSET] = 0;
//
//	// parent 채우기, 구간합
//	for (lld i = OFFSET - 1; i > 0; i--) tree[i] = tree[i * 2] + tree[i * 2 + 1];
//}
//
//void update(lld idx, lld value) {
//	idx += OFFSET;
//	tree[idx] = value;
//	idx /= 2;
//	while (idx>0) {
//		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
//		idx /= 2;
//	}
//}
//
//lld query(lld start, lld end) {
//	start += OFFSET; end += OFFSET; 
//	lld ans = 0;
//
//	while (start <= end) {
//		if (start % 2 == 1) ans += tree[start++];
//		if (end % 2 == 0) ans += tree[end--];
//		start /=2, end /= 2;
//	}
//
//	return ans;
//}
//
//int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	cin >> n >> m >> k;
//	for (int i = 0; i < n; i++) {
//		cin >> datas[i];
//	}
//	init(n);
//	for (lld i = 0; i < m+k; i++) {
//		cin >> a >> b >> c;
//		if (a == 1) update(b - 1, c);
//		if(a==2) ans.push_back(query(b - 1, c - 1));
//	}
//
//	for (lld i = 0; i < ans.size(); i++)cout << ans[i] << '\n';
//	return 0;
//}

///이렇게 그냥 update로 해줘도됨 init을 


#define PIV (1 << 20)
using namespace std;
typedef long long ll;
ll n, m, k;
ll tree[PIV * 2];

void update(ll n, ll v) {
	n += PIV;
	tree[n] = v;
	while (n /= 2) {
		tree[n] = tree[n * 2] + tree[n * 2 + 1];
	}
}

ll query(ll l, ll r) {
	l += PIV, r += PIV;
	ll ret = 0;
	while (l <= r) {
		if (l % 2) ret += tree[l++];
		if (!(r % 2)) ret += tree[r--];
		l /= 2, r /= 2;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("test.in", "r", stdin);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		ll a;
		cin >> a;
		update(i, a);
	}
	for (int i = 0; i < m + k; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(b, c);
		else cout << query(b, c) << '\n';
	}
	return 0;


