#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;



const int MAX = 100+1;

int N,M,K;
string word;
bool noWord;
// dp[x][y] : x���� a�� y���� z�� ���� �� �ִ� ���ڿ� ��
int dp[MAX][MAX];
// dp �����
int possibleNumOfWord(int A, int Z){
	// ������ �����ϸ� 1 ����
    if(A==0 || Z==0) return 1;
    int &ret = dp[A][Z];
    // �ѹ� ���Ƽ� �� ���� �ȴٸ� �� ����
    if(ret!=-1) return ret;
    // dp[x][y] = dp[x-1][y] + dp[x][y-1]
    ret = min(possibleNumOfWord(A-1,Z)+possibleNumOfWord(A,Z-1), 1000000000+1);
    return ret;
}
// ������ �� �ܾ� �����
// a ����, z ����, ���� ����
void getWord(int A, int Z, int idx){
    if(A==0){
        for (int i = 0; i < Z; ++i) word+='z';
        return;
	}
    if(Z==0){
        for (int i = 0; i < A; ++i) word+='a';
        return;
    }
    // a�� �Ǿտ� �ٰ� ������ a-1, z �� ���� �� �ִ� ����
    int cnt = possibleNumOfWord(A-1,Z);
    // �Ǿտ� a�� ���̴� ���
    if(idx<cnt){
        word +='a';
        getWord(A-1,Z,idx);
    }
    // �Ǿտ� z�� ���̴� ���
    else{
        word +='z';
        getWord(A,Z-1,idx-cnt);
    }
}
int main(){
	fastio;

cin >> N >> M >> K;
// �ʱ� ���� -1
memset(dp,-1,sizeof(dp));
// K > dp[N][M] �̸� -1 ���
if(K>possibleNumOfWord(N,M)) noWord = true;
// ����ܾ� �����
else getWord(N,M,K-1);
if(noWord) cout << -1 << '\n';
else cout << word << '\n';

return 0;
}
