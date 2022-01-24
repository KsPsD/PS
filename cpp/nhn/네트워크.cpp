#include<bits/stdc++.h>

using namespace std;
int ch[201];
int N=0;
void dfs(int cur, vector<vector<int>> & computers){
    
    for(int i=0; i< N; i++){
        if(cur==i) continue;
        if(ch[i] ==0 && computers[cur][i]==1){
            ch[i] =1;
            dfs(i ,computers);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N=n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n ;j++){
            
            if(ch[j] ==0 && computers[i][j]==1){
                
                ch[j]=1;
                dfs(j,computers);
                answer++;
            }
        }
    }
    
    
    
    
    return answer;
}
