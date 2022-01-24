#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;


 
const int MAX = 500000;
int ab[MAX];
vector<int> sortedAb;
ll tree[4 * MAX];
 
ll sum(int index, int start, int end, int left, int right) {
    if (end < left || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[index];
    int mid = (start + end) / 2;
    return sum(2 * index + 1, start, mid, left, right) + sum(2 * index + 2, mid + 1, end, left, right);
}
 
ll update(int index, int start, int end, int changed, int diff) {
    if (changed < start || end < changed) return tree[index];
    if (start == end) return tree[index] = diff;
    int mid = (start + end) / 2;
    return tree[index] = update(index * 2 + 1, start, mid, changed, diff) + update(index * 2 + 2, mid + 1, end, changed, diff);
}
 
int main(void) {
    fastio;
 
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> ab[i];
        sortedAb.push_back(ab[i]);
    }
    sort(sortedAb.begin(), sortedAb.end());
 
    for (int i = 0; i < N; i++) {
        int ind = (lower_bound(sortedAb.begin(), sortedAb.end(), ab[i]) - sortedAb.begin());
        update(0, 0, N - 1, ind, 1);
        cout << (i + 1) - sum(0, 0, N - 1, 0, ind - 1) << endl;
    }
    return 0;
}

