#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define INF  1000000005
#define PIV (1<<20) 

using namespace std;


 struct Pair {
    int n, th;
//    Pair(int a,int b){
//    	n=a;
//    	th=b;
//	}


};

bool operator<(Pair a, Pair  b) 
{
    if (a.n == b.n)
        return a.th > b.th;
    return a.n < b.n;
}

int n, b[PIV], p[PIV], r[PIV];
int tree[4*PIV];
Pair a[INF];


void update(int node, int s,int e, int target, int val){
	if(target< s || target>e) return ;
	if (s == e) tree[node] = max(tree[node],val);
	
	else{
			int mid = (s+e)/2;
		update(node * 2+1, s, mid, target, val);
		update(node * 2 + 2, mid + 1, e, target, val);
		tree[node] = max(val,tree[node]);
	}

    
	
	
}

int query(int node ,int s,int e, int l,int r){
	if(r< s || l> e ) return 0;
	if(l<=s && e<=r) return tree[node];
	int mid =(s+e)/2;
	return  max(query(2*node+1, s, mid ,l,r) ,query(2*node+2, mid+1, e, l,r) );
}



int main(){
	fastio;
	cin>>n;
	for(int i=0, num; i<n; i++){
		cin>>num; a[i] = {num,i}, p[i] =num; 
	}
	
	sort(a,a+n);
	int ans = 0, retval;
	
	 for (int i = 0; i < n; i++)
    {
        int ret = query(0,0, n-1, 0, a[i].th - 1);
         retval = ret + 1;
        update(0, 0, n-1,  a[i].th, retval);
        b[a[i].th] = retval;
        ans = max(ans, retval);
    }
	
	cout<<ans<<endl;
	
	int cnt = ans, ret = INF;
  	for(int i=n-1; i>=0; i--){
  		if(b[i] ==cnt && p[i] <ret ){
  			r[--cnt] =p[i]; ret= p[i];
		  }
	  }
	  for (int i = 0; i < ans; i++)
        cout<<r[i]<<" ";
		cout<<endl;  	
	
	
	
	return 0;
} 
