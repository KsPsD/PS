#include <string>
#include <vector>
#include<algorithm>
using namespace std;



long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long  i, lt=0,rt,mid;
    int maxx= -9999;
    sort(times.begin(), times.end());
    rt=times[times.size() - 1];
    rt= n*rt;
    answer = rt;
    while(lt<=rt){
        long curr=0;
        mid = (lt+rt)/2;
       for(int time :times){
           curr +=(mid/time);
       }
        if(curr<n) lt= mid+1;
        else{
            if(mid<=answer) answer=mid;
            rt = mid-1;
            
        }
    
}
    return answer;
}
