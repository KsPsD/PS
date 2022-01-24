#include<bits/stdc++.h>
#define MOD 1000000000
using namespace std;

//typedef long long ll;
//ll dp[10001];

//int main(){
//	int n, k;
//	scanf("%d %d", &n, &k);
//	k = n + k - 1;
//	
//	dp[0] = dp[1] = 1;
//	for(int i = 2; i <= k; i++) {
//		dp[i] = 1;
//		for(int j = i - 1; j > 0; j--){
//			dp[j] = (dp[j - 1] + dp[j]) % 1000000000;
//		}
//	}
//	printf("%lld", dp[n]);
//}
//
int N,K;
int cache[5001][5001];

int go(int n, int k){
	if(k==1)return 1;
	if(n==0) return 1;
	int &ret = cache[n][k];
	if(ret != -1) return ret;
	return ret = (go(n,k-1) + go(n-1,k))  %MOD;
}

int main(){
	
	memset(cache,-1,sizeof(cache));
	cin>>N>>K;
	cout<<go(N,K)<<endl;

	return 0;
}
//
//#include <cstdio>
//using namespace std;
//
//
//int main() {
////
//    int dp[5001][5001] = { 0, };
//    int n, k, i, j;
//
//    scanf("%d %d", &n, &k);
//
//    for (i = 0; i <= n; i++) dp[1][i] = 1;
//    for (i = 0; i <= k; i++) dp[i][0] = 1;
//
//    for(i = 2; i <= k; i++) {
//        for (j = 1; j <= n; j++) {
//            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % MOD;
//        }
//    }
//	//dp[i-1][0]���� dp[i-1][j-1]�� ��� ���� ���� dp[i][j-1]�� ����Ǿ��ֱ� �����̴�. �׷��� ���� ���ؾ� �ϴ� dp[i-1][j]�� �����ָ� �ȴ�.
//    printf("%d\n", dp[k][n]);
//
//    return 0;
//}
