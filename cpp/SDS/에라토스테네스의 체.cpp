#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;



int n, k, cnt, c[1001],ans;
int main(){
	fastio;
    cin >> n >> k;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            if (c[j] == 0) { cnt++; c[j] = 1; }
            if (cnt == k) { ans = j; break; }
        }
        if (cnt == k)break;
    }
    cout << ans << '\n';
	return 0;
	
}
