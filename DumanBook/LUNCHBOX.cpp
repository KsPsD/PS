#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;

#define MAX 10000
int n;
 
int E[MAX], M[MAX];
 
int heat() {
    //어느 순서로 데워야 할지를 정한다.
    vector<pair<int, int> > order;
    for (int i = 0; i < n; i++)
        order.push_back(make_pair(-E[i], i));
    sort(order.begin(), order.end());
    //해당 순서대로 데워먹는 과정을 시뮬레이션한다.
    int ret = 0, beginEat = 0;
    for (int i = 0; i < n; i++) {
        int box = order[i].second;
        beginEat += M[box];
        ret = max(ret, beginEat + E[box]);
    }
    return ret;
}
 
int main(void) {
    int cases;
    cin >> cases;
    while (cases--) {
        memset(M, 0, sizeof(M));
        memset(E, 0, sizeof(E));
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> M[i];
        for (int i = 0; i < n; i++)
            cin >> E[i];
        cout << heat() << endl;
    }
    return 0;
}

