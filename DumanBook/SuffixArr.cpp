#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;

#define vi vector<int>
#define vipii vector<pair<int,int> >
#define pii  pair<int,int>
#define vvi vector<vi >
#define MOD 1000000007

struct Comparator{
		 vector<int>  group;
	int t;
	Comparator(const vector<int> & _group, int _t) : group(_group),t(_t){
		group =_group; t=_t;
	}
	
	bool operator() (int a, int b){
		if(group[a] != group[b]) return group[a]<group[b];
		return group[a+t] < group[b+t];
	}
};


vector<int> getSuffixArray(const string &s){
	int n= s.size();
	int t=1;
	vector<int> group(n+1);
	for(int i=0; i<n; ++i) group[i] =s[i];
	group[n]=-1;
	vector<int> perm(n);
	for(int i=0; i<n;i++) perm[i] = i;
	while(t<n){
		Comparator compareUsing2T(group,t);
		sort(perm.begin(), perm.end(), compareUsing2T);
		t*=2;
		if(t>=n)break;
		vector<int> newGroup(n+1);
		newGroup[n] =-1;
		newGroup[perm[0]] =0;
		for(int i=1; i<n ;i++){
			if(compareUsing2T(perm[i-1], perm[i])) newGroup[perm[i]] = newGroup[perm[i-1]]+1;
			else newGroup[perm[i]] = newGroup[perm[i-1]];
		}
		group =newGroup;
		
	}
	
	return perm;
}
