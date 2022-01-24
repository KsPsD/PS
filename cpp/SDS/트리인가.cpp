#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

using namespace std;


int a,b ,root,cnt, indegree[100001], ch[100001];
unordered_set<int> num;
vector<int> tree[100001];
bool flag;

void Findway(int R){
	for (int child: tree[R]){
		// 이미 한번 갈 수 있는 점이나, root 자기 자신으로 가는 길이 있으면 틀린거.
		if(child==root||ch[child]==1){			
			flag = false;
			return;
		}
		// 해당 점을 가는 방법이 있음을 Way[child]=1로 저장.
		ch[child]=1;
		Findway(child);
	}
}
void isTree(){
	for(auto it:num){
		if(indegree[it] >1){
			flag=false;
			return;
		}
		else if(indegree[it]==0){
			if(root == -1) root =it;
			else{
				flag=false;
				return ;
			}
		}
		
	}
	
	
	if(root==-1){
		flag=false;
		return ;
	}
	Findway(root);
}




int main(){
	fastio;
	
	while(1){
		cnt++;
		root= -1;
		for(auto it :num) tree[it].clear();
		num.clear();
		memset(indegree, 0 ,sizeof(indegree));
		memset(ch,0, sizeof(ch));
		flag=true;
		cin>>a>>b;
		if(a<0 && b<0) break;
		else if(a==0&&b==0) cout<<"Case " << cnt << " is a tree."<<endl;
		else{
			num.insert(a);
			num.insert(b);
			tree[a].push_back(b);
			indegree[b]++;
			
			while(1){
				cin>>a>>b;
				if(a==0 && b==0){
					cout<<"Case "<<cnt;
					isTree();
					for(auto it: num){
						if(it==root) continue;
						if(ch[it] !=1) flag=false;
						
					}
					
					if(flag)cout<<" is a tree."<<endl;
					else cout<<" is not a tree."<<endl;
					break;
				}
				
				
				else{
					num.insert(a);
					num.insert(b);
					tree[a].push_back(b);
					indegree[b]++;
				}
				
				
				
			}
			
			
		}
		
		
	}
	
	return 0;
} 
