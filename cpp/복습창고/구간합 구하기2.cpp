#include<bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
 
#define MOD 1000000007
#define INF 0x7fffffff
#define MAX_SIZE (int)1e6
 
using namespace std;
//ios::sync_with_stdio(false); cin.tie(0);
 
int arr[MAX_SIZE];
 
ll init(vll &tree, int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
 
    int mid = (start + end) / 2;
    return tree[node] = init(tree, node * 2, start, mid) + init(tree, node * 2 + 1, mid + 1, end);
}
 
void update_lazy(vll &tree, vll &lazy, int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += lazy[node] * (end - start + 1);
 
        if (start != end){ //leaf노드가 아닐 때만 전파
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
 
ll update_range(vll &tree, vll &lazy, int node, int start, int end, int left, int right, ll add) {
    update_lazy(tree, lazy, node, start, end);
 
    if (right < start || end < left) return tree[node];
    
    else if (left <= start && end <= right) {
        tree[node] += add * (end - start + 1);
 
        if (start != end) {
            lazy[node * 2] += add;
            lazy[node * 2 + 1] += add;
        }
 
        return tree[node];
    }
 
    int mid = (start + end) / 2;
    return tree[node] = update_range(tree, lazy, node * 2, start, mid, left, right, add) + update_range(tree, lazy, node * 2 + 1, mid + 1, end, left, right, add);
}
 
ll sum(vll &tree, vll &lazy, int node, int start, int end, int left, int right) {
    update_lazy(tree, lazy, node, start, end);
 
    if (right < start || end < left) return 0;
    else if (left <= start && end <= right) return tree[node];
 
    int mid = (start + end) / 2;
    return sum(tree, lazy, node * 2, start, mid, left, right) + sum(tree, lazy, node * 2 + 1, mid + 1, end, left, right);
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
 
    int height = (int)ceil(log2(n));
    vll tree(1 << (height + 1));
    vll lazy(1 << (height + 1));
 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    init(tree, 1, 0, n - 1);
 
    for (int i = 0; i < m + k; i++) {
        int cmd, a, b;
        ll add;
        cin >> cmd >> a >> b;
        a--, b--;
 
        if (cmd == 1) {
            cin >> add;
            update_range(tree, lazy, 1, 0, n - 1, a, b, add);
        }
        else {
            cout << sum(tree, lazy, 1, 0, n - 1, a, b) << '\n';
        }
    }
 
    return 0;
}

