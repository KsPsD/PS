#include<bits/stdc++.h>


using namespace std;


map<string, int> cand;


void make_candidate(string s, string c , int depth){
	if(c.size() == depth) cand[c]++;
	else for(int i=0; i<s.size(); i++)
		make_candidate(s.substr(i+1), c+s[i], depth);
}


vector<string> solution(vector<string> orders, vector<int> course) {
	
	vector<string>ans;
	 for (string &order : orders)
        sort(order.begin(), order.end());
	
	for(auto c : course){
		for(string s: orders){
			make_candidate(s, "", c);
		}
		
		int maxi=0;
		for(auto it: cand)
			maxi = max(it.second,maxi);
		for(auto it:cand){
			if(maxi>=2 && it.second==maxi ){
				ans.emplace_back(it.first);	
			} 
		
		}
			cand.clear();
		
	}
	
	
	sort(ans.begin(), ans.end());
	
	return ans;

}
