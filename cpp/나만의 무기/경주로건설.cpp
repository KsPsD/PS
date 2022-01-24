#include<bits/stdc++.h>

#define INF 999999 

using namespace std;



int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

int ch [25][25][4];

struct info{
    int y,x,dir,sum;
};

int solution(vector<vector<int>> board) {
    int answer = 0;
   
    int size = board.size();
    
    for(int i=0; i<25; i++){
        for(int j=0; j<25; j++){
            for(int k=0; k<4; k++){
                ch[i][j][k] =INF;
            }
        }
    }
     for (int i = 0; i < 4; ++i)
        ch[0][0][i] = 0;
queue<info> q;
    
     q.push({0,0,-1,0});
    while(!q.empty()){
        info tmp = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int yy = tmp.y+dy[i];
            int xx = tmp.x+dx[i];
            int newSum = tmp.sum;
            int dir = i;
            
            if(yy<0 || yy>=size || xx<0 || xx>=size ||board[yy][xx] ==1) continue;
           
                newSum+=100;
                if(tmp.dir ==0 || tmp.dir==2){
                    if(dir == 1 || dir==3){
                        newSum+=500;
                    }
                }
                if(tmp.dir==1 || tmp.dir==3){
                    if(dir==0 || dir==2){
                        newSum+=500;
                    }
                }
                
                if(newSum < ch[yy][xx][dir]){
                    ch[yy][xx][dir] = newSum;
                    q.push({yy,xx,dir,newSum});
                }
        }
        
    }
    
    answer = *min_element(ch[size-1][size-1] , ch[size-1][size-1]+4);
    
    return answer;
}
