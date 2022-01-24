#include<bits/stdc++.h>

#define MAX 360000
using namespace std;



int convert_time_to_int(string S){
	string sh = S.substr(0,2);
	int h = stoi(sh) * 3600;
    string sm = S.substr(3, 2);
    int m = stoi(sm) * 60;
    string ss = S.substr(6, 2);
    int s = stoi(ss);
 
    int Total = h + m + s;
    return Total; 
}

string Convert_Time_To_String(int T)
{
    string S = "";
    int Hour = T / 3600;
    int Minute = (T % 3600) / 60;
    int Second = T % 60;
 
    if (Hour <= 9) S += '0';
    S += to_string(Hour);
    S += ':';
    if (Minute <= 9) S += '0';
    S += to_string(Minute);
    S += ':';
    if (Second <= 9) S += '0';
    S += to_string(Second);
    return S;
}


string solution(string play_time, string adv_time, vector<string> logs) 
{
	string ans= "";
	int Play_Time = Convert_Time_To_Int(play_time);
    int Adv_Time = Convert_Time_To_Int(adv_time);
	
 	vector<int> Total_Play_Time(MAX, 0);	
	
	 for (int i = 0; i < logs.size(); i++)
    {
        int Start = Convert_Time_To_Int(logs[i].substr(0, 8));
        int End = Convert_Time_To_Int(logs[i].substr(9, 8));
        for (int j = Start + 1; j <= End; j++) Total_Play_Time[j]++;
    }
	
	long long Cur_Play_Time= 0;
	long long Max_Play_Time= 0;
	int Time =1;
	for (int i = 1; i <= Adv_Time; i++)
    {
        Cur_Play_Time += Total_Play_Time[i];
        Max_Play_Time += Total_Play_Time[i];
    }
    for(int i= 2; i<= (Play_Time +Adv_Time -1) ;i++){
    	Cur_Play_Time += (long long)(Total_Play_Time[Adv_Time+i-1] - Total_Play_Time[i-1]);
    	if(Cur_Play_Time >= Max_Play_Time ){
    		Max_Play_Time = Cur_Play_Time;
    		Time= i;
		}
	}
	
	answer = Convert_Time_To_String(Time - 1);
    return answer;
}
