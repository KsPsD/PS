#include<bits/stdc++.h>


using namespace std;

#define MAX 1005

struct st{
    char type;
    int num;
}room[1005];
int n,b,c;
char a;
bool ans,ch[MAX];
vector<int> v[MAX];

void dfs(int in,int money)
{
    if(room[in].type=='L'&&money<room[in].num)
        money=room[in].num;
    if(room[in].type=='T')
        if(money<room[in].num)
            return;
        else
            money-=room[in].num;
    if(in==n)
    {
        ans=true;
        return;
    }
    
    ch[in]=true;
    for(int i=0;i<v[in].size();i++)
    {
        int next=v[in][i];
        if(ch[next]==false)
            dfs(next,money);
      
    }
    ch[in]=false;
}

int main() {
    
    scanf("%d",&n);
    while(n!=0)
    {
        for(int i=0;i<MAX;i++)
            v[i].clear();
        ans=false;
        // 초기화
        
        for(int i=1;i<=n;i++)
        {
            getchar();
            scanf("%c%d%d",&a,&b,&c);
            room[i]={a,b};
            while(c!=0)
            {
                v[i].push_back(c);
                scanf("%d",&c);
            }
        }
        // 입력 다받고 dfs로 돌리기
        
        dfs(1,0);
        if(ans)
            printf("Yes\n");
        else
            printf("No\n");
        scanf("%d",&n);
    }
    return 0;
}
