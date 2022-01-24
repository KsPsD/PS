#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

using namespace std;


int N, M;
// arr[i] : i ���� ����� �ϴ� �ǹ� 
set<int> arr[501];
// num[i] : i �ǹ� ���� �ð�
ll num[501];
// dp[x] : x �� �ϰ��ɶ� ���� �� �ð�
ll dp[501];

ll dfs(int a){
    ll &temp = dp[a];
    if(temp!=0) return temp;
    // �⺻������ �ڽ��� ���� �ð��� �ʿ��ϴ�
    temp += num[a];
    // a �ǹ����� ����Ǿ� ���������ϴ� �ǹ����� �ϰ��ð� �� �ִ�
    ll BeforeBuilding = 0LL;
    for (auto pre : arr[a])
        BeforeBuilding = max(BeforeBuilding,dfs(pre)); 
    
    temp += BeforeBuilding;
    return temp;
}
int main(){
	fastio;
cin >> N;	

for (int i = 1; i <= N; ++i){
    int ww;
    cin >> ww;
    num[i] = ww;
    while(1){
        int pre;
        cin >> pre;
        if(pre == -1) break;
        arr[i].insert(pre);
    }
}
for (int i = 1; i <= N; ++i)
    cout << dfs(i) << '\n';

return 0;
}
