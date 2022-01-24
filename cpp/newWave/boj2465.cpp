#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;
int n, h[MAX], s[MAX], idx[MAX], tree[4*MAX];
 
// segtree update
void upd(int node, int st, int ed, int idx, int v) {
    if (idx<st || idx>ed) return;
    if (st == ed) { tree[node] += v; return; }
    int mid = (st + ed) / 2;
    upd(2 * node, st, mid, idx, v);
    upd(2 * node + 1, mid + 1, ed, idx, v);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
 
// k-th number search
int kth(int node, int st, int ed, int k) {
    if (st == ed) return st;
    int mid = (st + ed) / 2;
    if (k <= tree[2 * node]) return kth(2 * node, st, mid, k);
    else return kth(2 * node + 1, mid + 1, ed, k - tree[2 * node]);
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    
    //일단 오름 차순으로 키 정렬
    sort(h + 1, h + n + 1);
   
    //각 노드에 1씩 넣어줌
    for (int i = 1; i <= n; i++) {
        upd(1, 1, n, i, 1);
    }
    //실제 정렬 되었을때 자기앞에 작은 사람 수들
    for (int i = 1; i <= n; i++) cin >> s[i];
    
    for (int i = n; i; i--) {
        //뒤에서 부터 하면 사람 키를 정렬 했으니까 자기보다 작은 사람 수만 세어서 그 수에 맞는 키의 인덱스를 찾아냄 그게 맨 뒤부터 채워 나가면됨
        idx[i]=kth(1, 1, n, s[i] + 1);
        // 한 사람은 0 처리 
        upd(1, 1, n, idx[i], -1);
    }
    for (int i = 1; i <= n; i++) {
        cout << h[idx[i]] << '\n';
    }
}
 
