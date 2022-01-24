#include<bits/stdc++.h>

using namespace std;
 
int waysToBuy(const vector<int>& psum, int K) {
    const int MOD = 20091101;
    int result = 0;
 
    //psum[]�� �� ���� �� ���̳� �� �� �ִ��� ���
    vector<long long> count(K, 0);
    for (int i = 0; i < psum.size(); i++) {
        count[psum[i]]++;
    }
 
    // �� �� �̻� �� �� �ִٸ� �� �� �� �� ���� �����ϴ� ����� ���� ���Ѵ�
    // ��, count[i]�� �� 2���� �� ����� �� (���� ���� �̿�)
    for (int i = 0; i < K; i++)
        if (count[i] >= 2)
            result = (result + ((count[i] * (count[i] - 1)) / 2)) % MOD;
    return result;
}
 
int maxBuys(const vector<int>& psum, int K) {
    vector<int> dp(psum.size(), 0);
    vector<int> prev(K, -1);
 
    for (int i = 0; i < psum.size(); i++) {
        //i��° ���ڸ� �ƿ� ������� �ʴ� ���
        if (i > 0)
            dp[i] = dp[i - 1];
        else
            dp[i] = 0;
        // psum[i]�� ������ �� ���� �ִٸ�, prev[psum[i]]+1���� ������� ���� ����
        int loc = prev[psum[i]];
        if (loc != -1) {
            // i ��° ���ڸ� �� ���� ���� ���� ���
            dp[i] = max(dp[i], dp[loc] + 1);
        }
        //prev[]�� ���� ��ġ ���
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
 
        // ��̵鿡�� ������ ��� �����ַ��� ������ �� ���� K�� ��������ϹǷ�
        // �κ��� ���ϱ� (K�� ���� �������� �� ����)
        for (int i = 1; i <= N; i++) {
            psum[i] = (psum[i - 1] + v[i - 1]) % K;
        }
 
        cout << waysToBuy(psum, K) << " " << maxBuys(psum, K) << endl;
    }
}

