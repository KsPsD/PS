#include<bits/stdc++.h>

#define ll long long
#define MAX (long long)2 << 31
 #define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
 
ll arr[103];
 
int main()
{
	fastio;
    int n, k;
    cin>>k>>n;
 
    // 弥家 赛栏肺 备泅等 q
    priority_queue <ll, vector<ll>, greater<ll>> pq;
 
    for (int i = 0; i < k; i++) {
        cin>>arr[i];
        pq.push(arr[i]);
    }
 
 
    ll cnt = 0;
 	ll cur=0;
  while(n--){
  	cur =pq.top();
  	pq.pop();
  	for(auto &e: arr){
  		if((ll) e * cur>=MAX) break;
  		pq.push(e*cur);
  		if(cur%e ==0) break;
	  }
  }
       
 	
 	cout<<cur<<endl;
 	
    return 0;
}



