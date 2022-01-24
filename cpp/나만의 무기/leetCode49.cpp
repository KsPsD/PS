#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> sorted_string_to_anagrams;
        
        for(const string & s: strs){
            string sorted_str(s);
            sort(begin(sorted_str), end(sorted_str) );
            sorted_string_to_anagrams[sorted_str].emplace_back(s);
        }
        
        vector<vector<string>>anagram_groups;
        
        for(const auto & [key, group]: sorted_string_to_anagrams){
            if(size(group) >=1){
                anagram_groups.push_back(group);
            }
        }
        
        return anagram_groups;
    }
};
