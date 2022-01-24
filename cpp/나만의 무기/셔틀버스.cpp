#include<bits/stdc++.h>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer="";
	vector<int> n_time;
	for(string t: timetable){
			int hour = (t[0] -'0') *10 + t[1]-'0';
		int minute = (t[3] -'0') *10 + t[4]-'0';
		int n_t = hour*60 + minute;
		n_time.push_back(n_t);
	}
	
	sort(n_time.begin(), n_time.end());
	
	int sh_time=  540; //시작 시간 9 
	int idx= 0;
	int ans_time;
	for(int i=1; i<=n; i++ ,sh_time=sh_time+t){
		int cnt=0;
		for(int j=idx; j<n_time.size(); j++){
			if(n_time[j] <= sh_time){
				idx++;
				cnt++;
				if(cnt==m) break;
			}
		}
		
		if(i==n){
			if(cnt==m) ans_time= n_time[idx]-1;
			else ans_time = sh_time;
		}
		
	}
	
	
	
	int h =ans_time /60;
	int mm = ans_time %60;
	char fh = h/10 +'0';
	char fm = h%10 + '0';
	char sh =mm/10 +'0';
	char sm = mm%10 + '0';
	
	answer +=fh;
	answer +=fm;
	answer+=':';
	answer+=sh;
	answer+=sm;
    return answer;
}
