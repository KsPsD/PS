#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;

int main()
{
    int arr[5001];
    int N;
    int cnt=2, mx=2;

    scanf("%d", &N);

    for(int i=1; i<=N; i++)
        scanf("%d", &arr[i]);

    for(int i=3; i<=N; i++)
    {
        if((arr[i-2] <= arr[i-1] && arr[i-1] <= arr[i]) || (arr[i-2] >= arr[i-1] && arr[i-1] >= arr[i]))
            cnt = 2;
        else
            cnt++;

        if(mx < cnt)
            mx = cnt;
    }

    printf("%d", mx);

    return 0;
}

