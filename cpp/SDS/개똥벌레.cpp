#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;

//+1 -1기법 --> range update point query 

//int n, h, mini=200000, cnt;
//int seok[50001], jong[50001];

int n, h, answer, cnt;
int sum[500010];

int main() {
    scanf("%d %d", &n, &h);
    for (int i = 0 ; i < n ; i++) {
        int bar;
        scanf("%d", &bar);
        if (i & 1) {
            // 종유석
            sum[h - bar + 1]++;
        }
        else {
            // 석순
            sum[1]++;
            sum[bar + 1]--;
        }
    }
    answer = -1;
    for (int i = 1 ; i <= h ; i++) {
        sum[i] += sum[i - 1];
        if (answer == -1 || sum[i] < answer) {
            answer = sum[i];
            cnt = 1;
        }
        else if (sum[i] == answer) {
            cnt++;
        }
    }

    printf("%d %d", answer, cnt);
    return 0;
}
//정렬 풀이 
//int main() {
//    scanf("%d %d", &n, &h);
//    for (int i = 0 ; i < n ; i++) {
//    	int input; cin>>input;
//    	if(i%2==0){
//    		seok[input]++;
//		}else{
//			jong[h+1-input]++;
//		}
//    }
//    
//    for(int i=1; i<=h; i++){
//    	jong[i]+=jong[i-1];
//    	seok[h-i] += seok[h-i+1];
//	}
//    
//    
//    for(int i=1; i<=h; i++){
//    	if(mini> jong[i] + seok[i]){
//    		mini = jong[i] + seok[i];
//    		cnt=1;
//		}
//		else if(mini==(jong[i]+seok[i])) cnt++;
//	} 
//    
//    cout<<mini<<" "<< cnt;
//    
//}
