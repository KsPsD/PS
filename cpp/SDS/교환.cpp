#include<bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std;
string n; int k;
int len;

int tonum(string s){
    int res = 0;
    for (int i = 0 ; i<s.length() ; i++) {
        
        res =res+ (s[i] - '0');
        if(i!= s.length()-1) res= res* 10;
    }
    return res;
}



int main() {
	fastio;
	cin>>n>>k;
	len = n.length();
	if(len ==1 || (len==2 && tonum(n) %10==0)){
		cout<<-1<<endl;
		exit(0);
	}
	
	
	queue<string> q;
	q.push(n);
	int cur=0;
	int maxi=0;
	
	while (!q.empty()&& cur < k)
    {
        int qsize = q.size();
        set<string> Visit;
 
        for (int qq = 0; qq < qsize; qq++)
        {
            string cur_s = q.front();
            q.pop();
 
            for (int i = 0; i < len - 1; i++)
            {
                for (int j = i + 1; j < len; j++)
                {
                    if (i == 0 && cur_s[j] == '0') continue;
 
                    swap(cur_s[i], cur_s[j]);
                    if (Visit.find(cur_s) == Visit.end())
                    {
                        if (cur == k - 1 &&  maxi < tonum(cur_s))
                        {
                            maxi = tonum(cur_s);
                        }
                        q.push(cur_s);
                        Visit.insert(cur_s);
                    }
                    swap(cur_s[i], cur_s[j]);
                }
            }
        }
        cur++;
    }
 
    if (cur != k) cout << "-1" << endl;
    else cout << maxi << endl;
 

return 0;

}
