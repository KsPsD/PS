#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;

int coverType[4][3][2] = {
    {{0,0},{1,0},{0,1}},
    {{0,0},{0,1},{1,1}},
    {{0,0},{1,0},{1,1}},
    {{0,0},{1,0},{1,-1}}
};


bool Set(vector<vector<int>>& board, int y, int x, int type, int delta){
    bool ok = true;
    for(int i=0;i<3;i++){
        int ny = y + coverType[type][i][0];
        int nx = x + coverType[type][i][1];
        if(ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
            ok = false;
        else if((board[ny][nx] += delta) > 1)
            ok = false;
    }
    return ok;
}

int cover(vector<vector<int>>& board){
    int y = -1;
    int x = -1;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j] == 0){
                y = i;
                x = j;
                break;
            }
        }
        if(y != -1) break;
    }

    if(y == -1) return 1;
    int ret = 0;
    for(int type=0;type<4;++type){
        if(Set(board,y,x,type,1))
            ret += cover(board);
        Set(board,y,x,type,-1);
    }
    return ret;
}

int main(){
    int test_case;
    cin >> test_case;

    int y,x;
    while(test_case--){
        cin >> y >> x;
        vector<vector<int>> board(y,vector<int>(x,0));
        string tmp;

        for(int i=0;i<y;i++){
            cin >> tmp;
            for(int j=0;j<tmp.size();j++){
                if(tmp[j] == '#')
                    board[i][j] = 1;
            }
        }

        cout << cover(board) << endl;

    }
}
