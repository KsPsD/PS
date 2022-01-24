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
int main() {
    int n, i; scanf("%d", &n);
    for (i = 2; i * i <= n; i++)
        while (n % i == 0) { printf("%d\n", i); n /= i; }
    if (n > 1)
        printf("%d\n", n);
}

