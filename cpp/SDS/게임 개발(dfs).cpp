#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

using namespace std;


int N, M;
// arr[i] : i 전에 지어야 하는 건물 
set<int> arr[501];
// num[i] : i 건물 짓는 시간
ll num[501];
// dp[x] : x 가 완공될때 까지 총 시간
ll dp[501];

ll dfs(int a){
    ll &temp = dp[a];
    if(temp!=0) return temp;
    // 기본적으로 자신을 짓는 시간은 필요하다
    temp += num[a];
    // a 건물보다 선행되어 지어져야하는 건물들의 완공시간 중 최대
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
