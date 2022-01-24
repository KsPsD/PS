#include<bits/stdc++.h>

 
#define endl "\n"
using namespace std;
 #define MAX 110

 
 
int N, K;
int Weight[MAX];
int Value[MAX];
int DP[MAX][100010];
 
int Max(int A, int B) { if (A > B) return A; return B; }
 
void Input()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> Weight[i] >> Value[i];
    }
}
 
void Solution()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
        	//i까지 물건 사용해서 j라는 무게 먼둘때 최대 가치 
            if (j >= Weight[i])    DP[i][j] = Max(DP[i - 1][j], DP[i - 1][j - Weight[i]] + Value[i]);
             //여기는 지금 가방이 버틸 수 있는 무게가 더 작으니까 전에 값 그대로 들고옴 
            else DP[i][j] = DP[i - 1][j];
        }
    }
    cout << DP[N][K] << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
//동전이랑 차이 동전은 여러개 배낭은 물건 1개만 넣는거임 계속 못넣음 
//
//int item[102][2]; // 0 -무게 / 1- 가치
//int d[100002];
// 
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
// 
//    int n, k;
//    cin >> n >> k;
// 
//    for (int i = 0; i < n; i++)
//    {
//        int w, v;
//        cin >> w >> v;       //각 아이템의 무게와 가치 입력
//         
//        for (int j = k; j >=w; j--)  // 가방 용량이 w ~ k 인 경우 전부 구하기
//        {
//            d[j] = max(d[j - w] + v, d[j]);  //item을 넣었을 때와 넣지 않은 것중 가치 큰 값 저장
//        }
//    }
// 
//    cout << d[k];  // 가방무게가 k일 때 가치의 최대 값
// 
//    return 0;
//}
