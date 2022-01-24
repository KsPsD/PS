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
//�־��� �ܾ��κ��� ���ĺ� ���� ���İ��� �׷����� �����Ѵ�.
void makeGraph(const vector<string>& words) {
    adj = vector<vector<int> >(26, vector<int>(26, 0));
    for (int j = 1; j < words.size(); j++) {
        int i = j - 1, len = min(words[i].size(), words[j].size());
        //word[i]�� word[j]�տ� ���� ������ ã�´�.
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
//adj�� �־��� �׷����� ���������� ����� ��ȯ�Ѵ�.
//�׷����� DAG�� �ƴ϶�� �� ���͸� ��ȯ�Ѵ�.
vector<int> topologicalSort() {
    int m = adj.size();
    seen = vector<int>(m, 0);
    order.clear();
    for (int i = 0; i < m; i++) if (!seen[i]) dfs(i);
    reverse(order.begin(), order.end());
    //���� �׷����� DAG�� �ƴ϶�� ���� ����� ������ ������ �ִ�.
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            if (adj[order[j]][order[i]])
                return vector<int>();
    //���� ����� ���� �켱 Ž������ ���� ������ ��ȯ�Ѵ�.
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

