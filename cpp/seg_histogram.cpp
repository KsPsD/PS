#include<bits/stdc++.h>
using namespace std;


typedef long long ll;		
const int MAX = 100000;
ll arr[MAX];
int n;
void init(vector<int> &tree, int node, int start, int end)
{
    
    if (start == end)
        tree[node] = start; 
 
    
    else
    {
        int mid = (start + end) / 2;
        init( tree, node * 2, start, mid);
        init( tree, node * 2 + 1, mid + 1, end);
 
        
        if (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]])
            tree[node] = tree[node * 2];
        else
            tree[node] = tree[node * 2 + 1];
    }
}
int query( vector<int> &tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return -1;
 
    if (left <= start && end <= right)
        return tree[node];
 
    int mid = (start + end) / 2;
    int m1 = query( tree, node * 2, start, mid, left, right);
    int m2 = query(tree, node * 2 + 1, mid + 1, end, left, right);
 
    if (m1 == -1)
        return m2;
 
    else if (m2 == -1)
        return m1;
 
    else
    {
        if (arr[m1] <= arr[m2])
            return m1;
        else
            return m2;
    }
}
 
ll getMax( vector<int> &tree, int start, int end)
{
    int m = query(tree, 1, 0, n - 1, start, end);
 
    ll area = (ll)(end - start + 1)*(ll)arr[m];
 
    if (start <= m - 1)
    {
        ll tmp = getMax( tree, start, m - 1);
 
        if (area < tmp)
            area = tmp;
    }
 
    if (m + 1 <= end)
    {
        ll tmp = getMax( tree, m + 1, end);
        if (area < tmp)
            area = tmp;
    }
 
    return area;
}
 




int main() {
   
  	
  	cin>>n;
  	
  	for(int i =0 ;i<n ;i++){
  		cin>>arr[i];
	  }
  	
  	
  	int  h= (int)(ceil(log2(n))+1e-9);
  	int tree_size = (1<<(h+1));
  	
  	vector<int> tree(tree_size);
  	init(tree, 1, 0,n-1);
  	
  	
  	cout<<getMax(tree, 0,n-1);

  	
    return 0;
}
