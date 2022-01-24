#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;


using namespace std;

bool che[3200];
vector<int> prime;
int n;

int main() {
    for (int i = 2 ; i < 3200 ; i++) {
        if (che[i]) continue;
        for (int j = i + i ; j < 3200 ; j += i) {
            che[j] = true;
        }
    }
    for (int i = 2 ; i < 3200 ; i++) {
        if (!che[i]) {
            prime.push_back(i);
        }
    }
    scanf("%d", &n);
    if (n == 1) {
        return 0;
    }
    for (int i = 0 ; i < prime.size() ; i++) {
        while (n % prime[i] == 0) {
            printf("%d\n", prime[i]);
            n /= prime[i];
        }
    }
    if (n > 1) {
        printf("%d\n", n);
    }
}
