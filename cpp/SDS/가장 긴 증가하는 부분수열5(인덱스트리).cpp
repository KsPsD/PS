#include <stdio.h>
#include <algorithm>
#include <memory.h>
#define PIV (1<<20) 
#define INF 1000000005
using namespace std;
int tree[PIV * 2];


void update(int n, int v)
{
    tree[n += PIV] = v;
    while (n >>= 1)
        tree[n] = max(tree[n], v);
}


int query(int n)
{
    int l = PIV, r = n + PIV;
    int ret = 0;
    while (l <= r)
    {
        if (l & 1) ret = max(ret, tree[l++]);
        if (!(r & 1)) ret = max(ret, tree[r--]);
        l >>= 1, r >>= 1;
    }
    return ret;
}


int N, b[PIV], p[PIV], r[PIV];
struct st {
    int n, th;
};
bool operator<(st a, st b)
{
    if (a.n == b.n)
        return a.th > b.th;
    return a.n < b.n;
}
st a[PIV];
int main()
{
#ifdef _DEBUG
    freopen("c:\\study\\b14003.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0, n; i < N; i++)
        scanf("%d", &n), a[i] = { n, i }, p[i] = n;
    sort(a, a + N);
    int ans = 0, retval;
    for (int i = 0; i < N; i++)
    {
        int ret = query(a[i].th - 1);
        retval = ret + 1;
        update(a[i].th, retval);
        b[a[i].th] = retval;
        ans = max(ans, retval);
    }
    printf("%d\n", ans);

    int cnt = ans, ret = INF;
    for (int i = N - 1; i >= 0; i--)
        if (b[i] == cnt && p[i] < ret)
            r[--cnt] = p[i], ret = p[i];
    for (int i = 0; i < ans; i++)
        printf("%d ", r[i]);
    printf("\n");

}
