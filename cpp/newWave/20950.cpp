#include <bits/stdc++.h>

using namespace std;

int n, rgbi[3][30], rgbg[3], minimum = 1000;

void solution(int start, int idx, int r, int g, int b)
{
	if (idx > 1)
	{
		int tmp = 0;

		tmp += abs(rgbg[0] - (r / idx));
		tmp += abs(rgbg[1] - (g / idx));
		tmp += abs(rgbg[2] - (b / idx));

		if (tmp < minimum)
			minimum = tmp;
	}
	
	if (idx == (n < 7 ? n : 7))
		return;

	for (int i = start; i < n; i++)
		solution(i + 1, idx + 1, r + rgbi[0][i], g + rgbi[1][i], b + rgbi[2][i]);

	return;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> rgbi[j][i];
		}
	}
	
	for (int i = 0; i < 3; i++)
		cin >> rgbg[i];

	solution(0, 0, 0, 0, 0);

	cout << minimum;

	return 0;
}








#include <iostream>
#include <algorithm>
using namespace std;

int N, R[32], G[32], B[32], C;
int door=987654321;

int abs(int a) {
    if (a<0)
        return -a;
    return a;
}

void solve(int r, int g, int b, int i, int c) {
    if (c == C || i == N)
        return;
    door = min(door, abs((r + R[i])/(c+1)-R[30])+abs((g + G[i])/(c+1)-G[30])+abs((b + B[i])/(c+1)-B[30]));
    solve(r + R[i], g + G[i], b + B[i], i+1, c+1);
    solve(r, g, b, i+1, c);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    C = min(7, N);
    for (int i=0; i<N; i++) {
        cin >> R[i] >> G[i] >> B[i];
    }
    cin >> R[30] >> G[30] >> B[30];

    for (int i=0; i<N-1; i++) {
        solve(R[i], G[i], B[i], i+1, 1);
    }
    cout << door << "\n";

    return 0;
}
