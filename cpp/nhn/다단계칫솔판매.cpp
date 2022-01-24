#include<bits/stdc++.h>


using namespace std;

unordered_map<string, string> parent; // Key ���,  Value : �� ����� Ʈ�� �� �θ�(= �� ����� �ٴܰ迡 ������Ų ���)
unordered_map<string, int> profit; // Key ���,  Value : �� ����� ������
void UpdateProfit(string name, int money) {
    if (name == "none") return; // ���� ����

    int notmine = money * 0.1; // �θ𿡰� �Ѱ��� ���� (10 %)
    profit[name] += (money - notmine); // �ڽ��� ���� (90 %)
    if (notmine < 1) return; // �̰� �����ָ� �ð��ʰ� ����! (21.05.21 �׽�Ʈ���̽� �߰�) �׳� �θ𿡰� �Ѱ��� ������ ���ٸ� �� �̻� ��� ȣ��� �ö��� �ʵ��� �Ͽ� �ð��� �����Ѵ�.
    UpdateProfit(parent[name], notmine); // ���ȣ��. �θ� ����� profit ������Ʈ �Ϸ�.
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for (int i = 0; i < enroll.size(); ++i) {
        if (referral[i] == "-") parent[enroll[i]] = "none"; // Ʈ�� �� �θ� none �� ����� �θ� ��尡 ���� ���. (�θ�� �Ƹ� �μ������� �������� �μ��� ������)
        else parent[enroll[i]] = referral[i];
    }
    for (int i = 0; i < seller.size(); ++i)
        UpdateProfit(seller[i], amount[i] * 100);

    for (int i = 0; i < enroll.size(); ++i)
        answer.push_back(profit[enroll[i]]);
    return answer;
}
