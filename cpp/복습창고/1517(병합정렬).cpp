#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define pii pair<int,int>
#define ll long long

using namespace std;
 
long long result = 0;
 
void merge(vector<int> &v, int start, int end) {
	int mid = (start + end) / 2;
	int left = start;
	int right = mid + 1;
	vector<int> temp;
 
	if (start == end) {
		return;
	}
	
	merge(v, start, mid);
	merge(v, mid + 1, end);
 
	while (left <= mid && right <= end) {
		if (v[left] <= v[right]) {
			temp.push_back(v[left++]);
		}
		else {
			temp.push_back(v[right++]);
			result += (mid + 1 - left);
		}
	}
	while (left <= mid) {
		temp.push_back(v[left++]);
	}
	while (right <= end) {
		temp.push_back(v[right++]);
	}
	for (int i = start, j = 0; i <= end; ++i, ++j) {
		v[i] = temp[j];
	}
}
 
int main()
{
	fastio;
	int n;
	vector<int> v;
 
	cin>>n;
	 
	v.resize(n);
 
	for (int i = 0; i < n; ++i) {
		cin>>v[i];
	}
 
	merge(v, 0, n - 1);
 
	cout<<result<<endl;
 
	return 0;
}




#include <iostream>

using namespace std;

#define MAX_N 500000

int n;
int A[MAX_N];
int B[MAX_N];

long long solve(int start, int end)
{
    if (start == end) return 0;
    int mid = (start + end) / 2;

    long long ans = solve(start, mid) + solve(mid + 1, end);

    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid || j <= end)
    {
        if (i <= mid && (j > end || A[i] <= A[j]))
        {
            B[k++] = A[i++];
        }
        else
        {
            // 왼쪽 배열의 남아있는 원소들의 개수
            ans += (long long)(mid - i + 1);
            B[k++] = A[j++];
        }
    }

    for (int i = start; i <= end; i++) {
        A[i] = B[i - start];
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> A[i];

    long long ans = solve(0, n - 1);

    cout << ans;

    return 0;
}


