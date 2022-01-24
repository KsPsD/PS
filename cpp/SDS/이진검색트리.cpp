#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

using namespace std;
const int MAX = 1e5;
int tree[MAX];

// [start, end)
void postOrder(int start, int end)
{
	if (start == end) return;
	

	if (start == end - 1)
	{
		cout << tree[start] << "\n";

		return;
	}

	int idx = start + 1;

	while (1)
	{
		
		if ((idx < end && tree[idx] < tree[start]) == false)
		{
			break;
		}

		idx++;
	}

	postOrder(start + 1, idx);
	postOrder(idx, end);

	cout << tree[start] << "\n";
}

int main(void)
{
	fastio;
	int idx=0;
	
	while(cin>>tree[idx]){
	
		idx++;
	}
	
	postOrder(0, idx);

	return 0;
}
