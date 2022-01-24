#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;



const int MAX = 100+1;

int N,M,K;
string word;
bool noWord;
// dp[x][y] : x개의 a와 y개의 z로 만들 수 있는 문자열 수
int dp[MAX][MAX];
// dp 만들기
int possibleNumOfWord(int A, int Z){
	// 기저에 도착하면 1 리턴
    if(A==0 || Z==0) return 1;
    int &ret = dp[A][Z];
    // 한번 돌아서 그 값을 안다면 값 리턴
    if(ret!=-1) return ret;
    // dp[x][y] = dp[x-1][y] + dp[x][y-1]
    ret = min(possibleNumOfWord(A-1,Z)+possibleNumOfWord(A,Z-1), 1000000000+1);
    return ret;
}
// 정답이 될 단어 만들기
// a 개수, z 개수, 이전 순번
void getWord(int A, int Z, int idx){
    if(A==0){
        for (int i = 0; i < Z; ++i) word+='z';
        return;
	}
    if(Z==0){
        for (int i = 0; i < A; ++i) word+='a';
        return;
    }
    // a가 맨앞에 붙고 나머지 a-1, z 로 만들 수 있는 경우수
    int cnt = possibleNumOfWord(A-1,Z);
    // 맨앞에 a를 붙이는 경우
    if(idx<cnt){
        word +='a';
        getWord(A-1,Z,idx);
    }
    // 맨앞에 z를 붙이는 경우
    else{
        word +='z';
        getWord(A,Z-1,idx-cnt);
    }
}
int main(){
	fastio;

cin >> N >> M >> K;
// 초기 설정 -1
memset(dp,-1,sizeof(dp));
// K > dp[N][M] 이면 -1 출력
if(K>possibleNumOfWord(N,M)) noWord = true;
// 정답단어 만들기
else getWord(N,M,K-1);
if(noWord) cout << -1 << '\n';
else cout << word << '\n';

return 0;
}
