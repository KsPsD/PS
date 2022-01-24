#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;


int main() {
    fastio;
        int N;
        cin >> N;

        vector<int> v(N);
        for (int i = 0; i < N; ++i)
                cin >> v[i];

        sort(v.begin(), v.end());

        int answer = INT_MAX;
        for (int i = 0; i < N - 3; ++i) {
                for (int j = i + 3; j < N; ++j) {

                        int lt = i + 1;
                        int rt = j - 1;

                        while (lt < rt) {
                int a = v[i] + v[j];
                int e = v[lt] + v[rt];
                                int result = e - a;

                                answer = min(answer, abs(result));

                                if (result > 0)
                                        rt = rt - 1;
                                else
                                        lt = lt + 1;
                        }
                }
        }
        cout << answer;
}%