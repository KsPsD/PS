#include<bits/stdc++.h>

using namespace std;
 
int waysToBuy(const vector<int>& psum, int K) {
    const int MOD = 20091101;
    int result = 0;
 
    //psum[]의 각 값을 몇 번이나 본 적 있는지 기록
    vector<long long> count(K, 0);
    for (int i = 0; i < psum.size(); i++) {
        count[psum[i]]++;
    }
 
    // 두 번 이상 본 적 있다면 이 값 중 두 개를 선택하는 방법의 수를 더한다
    // 즉, count[i]개 중 2개를 고를 경우의 수 (조합 공식 이용)
    for (int i = 0; i < K; i++)
        if (count[i] >= 2)
            result = (result + ((count[i] * (count[i] - 1)) / 2)) % MOD;
    return result;
}
 
int maxBuys(const vector<int>& psum, int K) {
    vector<int> dp(psum.size(), 0);
    vector<int> prev(K, -1);
 
    for (int i = 0; i < psum.size(); i++) {
        //i번째 상자를 아예 고려하지 않는 경우
        if (i > 0)
            dp[i] = dp[i - 1];
        else
            dp[i] = 0;
        // psum[i]를 전에도 본 적이 있다면, prev[psum[i]]+1부터 여기까지 전부 구매
        int loc = prev[psum[i]];
        if (loc != -1) {
            // i 번째 상자를 산 경우와 사지 않은 경우
            dp[i] = max(dp[i], dp[loc] + 1);
        }
        //prev[]에 현재 위치 기록
        prev[psum[i]] = i;
    }
    return dp.back();
}
 
 
int main(void) {
    int C;
    cin >> C;
 
    while (C--) {
        int N, K;
        cin >> N >> K;
        vector<int> v(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }
 
        vector<int> psum(N + 1);
        psum[0] = 0;
 
        // 어린이들에게 인형을 모두 나눠주려면 인형의 총 수가 K의 배수여야하므로
        // 부분합 구하기 (K로 나눈 나머지로 값 저장)
        for (int i = 1; i <= N; i++) {
            psum[i] = (psum[i - 1] + v[i - 1]) % K;
        }
 
        cout << waysToBuy(psum, K) << " " << maxBuys(psum, K) << endl;
    }
}

