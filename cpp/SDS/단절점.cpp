#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>

using namespace std;
#define MAXV 10010
int V, E, counter=0, discovered[MAXV];
bool isCutVertex[MAXV];
vector<int> graph[MAXV];

int dfs(int A, bool isRoot){
    discovered[A]= ++counter;
    int ret = discovered[A];
    
    int child=0; //���� A�� ��Ʈ ��� �� ��츦 ����ؼ� DFS���д� Ʈ�������� �ڽ� �� �����ش�.
    for(int i = 0 ;  i<(int)graph[A].size() ; i++){
        int next = graph[A][i];
        if(!discovered[next]){
            child++;
            //low : ���� A�� �ڽ� ��尡 �� �� �ִ� ����� ���� ���� �湮�� ���
            int low = dfs(next, false);
            if(!isRoot && low >= discovered[A]) isCutVertex[A] = true;
            ret=  min(ret, low);
        }else{
            ret = min(ret, discovered[next]);
        }
    }
    
    if(isRoot)
        isCutVertex[A] = (child >=2);
    return ret;
}

int main(){
    scanf("%d%d", &V, &E);
    for(int i =1 ; i<= E; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= V; i++){
        if(!discovered[i])
            dfs(i, true);
    }

    int cnt=0;
    for(int i = 1 ; i<= V; i++){
        if(isCutVertex[i])
            cnt++;
    }
    printf("%d\n", cnt);
    for(int i =1 ; i<= V; i++){
        if(isCutVertex[i])
            printf("%d ", i);
    }
    return 0;
}
