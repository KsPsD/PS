#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;

#define vi vector<int>
#define vipii vector<pair<int,int> >
#define pii  pair<int,int>
#define vvi vector<vi >
#define MOD 1000000007
vector<vector<int> > adj;
vector<int> seen, order;
//주어진 단어들로부터 알파벳 간의 선후관계 그래프를 생성한다.
void makeGraph(const vector<string>& words) {
    adj = vector<vector<int> >(26, vector<int>(26, 0));
    for (int j = 1; j < words.size(); j++) {
        int i = j - 1, len = min(words[i].size(), words[j].size());
        //word[i]가 word[j]앞에 오는 이유를 찾는다.
        for(int k=0;k<len;k++)
            if (words[i][k] != words[j][k]) {
                int a = words[i][k] - 'a';
                int b = words[j][k] - 'a';
                adj[a][b] = 1;
                break;
            }
    }
}
 
void dfs(int here) {
    seen[here] = 1;
    for (int there = 0; there < adj.size(); there++) 
        if (adj[here][there] && !seen[there])
            dfs(there);
    order.push_back(here);
}
//adj에 주어진 그래프를 위상정렬한 결과를 반환한다.
//그래프가 DAG가 아니라면 빈 백터를 반환한다.
vector<int> topologicalSort() {
    int m = adj.size();
    seen = vector<int>(m, 0);
    order.clear();
    for (int i = 0; i < m; i++) if (!seen[i]) dfs(i);
    reverse(order.begin(), order.end());
    //만약 그래프가 DAG가 아니라면 정렬 결과에 역방향 간선이 있다.
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            if (adj[order[j]][order[i]])
                return vector<int>();
    //없는 경우라면 깊이 우선 탐색에서 얻은 순서를 반환한다.
    return order;
}
int main(void){
    int cases;
    cin >> cases;
    while (cases--) {
        int n;
        cin >> n;
        vector<string> words;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            words.push_back(s);
        }
        makeGraph(words);
        vector<int> solve = topologicalSort();
        if (solve.empty())
            cout << "INVALID HYPOTHESIS";
        else
            for (int i = 0; i < solve.size(); i++)
                cout << char(solve[i] + 'a');
        cout << "\n";
    }
    return 0;
}

