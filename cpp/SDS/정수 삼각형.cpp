#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
using namespace std;

const int MAX = 500;
int n;

int a[502][502];

int main()

{

    int n;

    

    cin>>n;

    

    for(int i=1; i<=n; i++)

    {

        for(int j=1; j<=i; j++)

            cin>>a[i][j];

    }

    

    for(int i=1; i<=n; i++)

    {

        for(int j=1; j<=i; j++)

            a[i][j] = a[i][j] +  max(a[i-1][j],a[i-1][j-1]);

    }

    int res = 0;

    for (int i = 1; i <= n; i++)

        res = max(res, a[n][i]);

    cout<<res;
    
	return 0;
}


