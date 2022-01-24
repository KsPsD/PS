#include<bits/stdc++.h>
using namespace std;
bool dfs(string departure, vector<vector<string>> &tickets, vector<string> &answer, vector<bool> &visited, vector<string> &temp, int finishCnt) {
    temp.push_back(departure);

    if(finishCnt == tickets.size()) {
        answer = temp;
        return true;
    }

    for(int i = 0; i < tickets.size(); i++) {
        if(tickets[i][0] == departure && !visited[i]) {
            visited[i] = true;
            bool success = dfs(tickets[i][1], tickets, answer, visited, temp, finishCnt+1);
            if(success)
                return true;
            visited[i] = false;
        }
    }
    temp.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visited(tickets.size());
    vector<string> temp;

    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, answer, visited, temp, 0);

    return answer;
}
