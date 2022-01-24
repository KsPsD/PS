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
        	//i���� ���� ����ؼ� j��� ���� �յѶ� �ִ� ��ġ 
            if (j >= Weight[i])    DP[i][j] = Max(DP[i - 1][j], DP[i - 1][j - Weight[i]] + Value[i]);
             //����� ���� ������ ��ƿ �� �ִ� ���԰� �� �����ϱ� ���� �� �״�� ���� 
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
//�����̶� ���� ������ ������ �賶�� ���� 1���� �ִ°��� ��� ������ 
//
//int item[102][2]; // 0 -���� / 1- ��ġ
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
//        cin >> w >> v;       //�� �������� ���Կ� ��ġ �Է�
//         
//        for (int j = k; j >=w; j--)  // ���� �뷮�� w ~ k �� ��� ���� ���ϱ�
//        {
//            d[j] = max(d[j - w] + v, d[j]);  //item�� �־��� ���� ���� ���� ���� ��ġ ū �� ����
//        }
//    }
// 
//    cout << d[k];  // ���湫�԰� k�� �� ��ġ�� �ִ� ��
// 
//    return 0;
//}
