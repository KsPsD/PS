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


int main(){

	

	
int N, K;

        cin >> N >> K;

 

        int lt = 1, rt = K;

        int res = 0;

        while (lt <= rt)

        {
                 int cnt = 0;

                 int mid = (lt + rt) / 2;
                 for (int i = 1; i <= N; i++){
				 

                         cnt += min(mid / i, N); //mid보다 작은 j의 수(i * j <= mid)
                }
				 if (cnt < K)

                         lt = mid + 1;

                 else

                 {

                         res = mid;

                         rt = mid - 1;

                 }

        }
        cout << res << endl;

        return 0;



	
	return 0;
}
