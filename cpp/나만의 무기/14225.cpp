#include<bits/stdc++.h>

using namespace std;



int s;
int arr[21];
int maxi;
vector<int> v;
void go(int sum, int depth,int num,int idx){
	if(depth==num){
		if(v[sum] ==0){
			v[sum]=1;
		}
	}
	
	for(int i=idx+1; i<s; i++){
		go(sum+arr[i], depth+1, num, i);
	}
	
}



int main(){
	
	
	cin>>s;
	
	for(int i=0; i<s; i++){
		cin>>arr[i];
	}
	maxi =accumulate(arr,arr+s, 0);
	v.resize(maxi+1,0);
	
	for(int i=1; i<=s; i++){
		for(int j=0; j<s; j++){
			go(arr[j],1,i,j);
		}
					
	}
	
	int ans= maxi+1;
	for(int i=1; i<=maxi; i++){
		if(v[i]==0){
			ans = min(ans,i);
		}
	}
	
	
	cout<<ans<<endl;
	
	
	
	
	
	return 0;
}



#define MAX 21
#define MAX_SUM 2000001
#define INF 987654321
using namespace std;

int n;
int arr[MAX];
bool num[MAX_SUM];

void dfs(int ind,int sum){
    // 노드의 끝까지 간 경우
    if(ind == n){
        num[sum] = true;
        return;
    }
    
    // ind 인덱스 노드를 포함하는 경우
    dfs(ind+1,sum+arr[ind]);
    // ind 인덱스 노드를 포함하지 않는 경우
    dfs(ind+1,sum);
}

int main(int argc, const char * argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    memset(num, false, sizeof(num));
    
    dfs(0,0);
    
    for(int i=1; i<MAX_SUM; i++){
        if(!num[i]){
            cout << i << "\n";
            break;
        }
    }
}

