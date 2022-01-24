#include<bits/stdc++.h>


using namespace std;

unordered_map<string, string> parent; // Key 사람,  Value : 이 사람의 트리 상 부모(= 이 사람을 다단계에 참여시킨 사람)
unordered_map<string, int> profit; // Key 사람,  Value : 이 사람의 순이익
void UpdateProfit(string name, int money) {
    if (name == "none") return; // 종료 조건

    int notmine = money * 0.1; // 부모에게 넘겨줄 이익 (10 %)
    profit[name] += (money - notmine); // 자신의 이익 (90 %)
    if (notmine < 1) return; // 이거 안해주면 시간초과 난다! (21.05.21 테스트케이스 추가) 그냥 부모에게 넘겨줄 이익이 없다면 더 이상 재귀 호출로 올라가지 않도록 하여 시간을 절약한다.
    UpdateProfit(parent[name], notmine); // 재귀호출. 부모 노드의 profit 업데이트 하러.
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for (int i = 0; i < enroll.size(); ++i) {
        if (referral[i] == "-") parent[enroll[i]] = "none"; // 트리 상 부모가 none 인 사람은 부모 노드가 없는 사람. (부모는 아마 민수겠지만 문제에선 민수를 제외함)
        else parent[enroll[i]] = referral[i];
    }
    for (int i = 0; i < seller.size(); ++i)
        UpdateProfit(seller[i], amount[i] * 100);

    for (int i = 0; i < enroll.size(); ++i)
        answer.push_back(profit[enroll[i]]);
    return answer;
}
