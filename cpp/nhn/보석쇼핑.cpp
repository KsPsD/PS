#include<bits/stdc++.h>

using namespace std;


using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {1, (int)gems.size()}; // �ε����� ���� �����Ͽ� ���� �����ϱ� ���� �ʱⰪ�� ����  
    int s = 0; //start 
    int e = 0; //end
    int distance = gems.size()-1; // end-start�� ������ ���� ���� ������ ���ϱ� ���� ����
    map<string, int> m;
    int total;
    for(string i : gems) {
        m[i] += 1;
    }
    
    total = m.size(); // ������ ������ ���� ��
    m.clear(); // �� �ʱ�ȭ
    
    while(true) {
        if(m.size() == total) { // ��� ������ �� ���� ���
            if(e-s<distance) { // end-start(���籸��)�� distance(�̸� ���س��� �ִܱ���)�� ��
                distance = e-s;
                answer[0] = s+1;
                answer[1] = e;
            }
            
            if(m[gems[s]] == 1) { // ������ ������ 1�� �� ��
                m.erase(gems[s]);
                s++; // m[gems[s]]�� 1�϶� --�� �ϸ� �ʿ��� ������� �ʰ� value�� 0�� �Ǳ� ����
            }
            else { // ������ ������ 1�� �̻��� ��
                m[gems[s]]--;
                s++;
            }
        }
        else if(e == gems.size()) // ������ Ž���� ��������
            break;
        
        else { // ��� ������ ���� ã�� ������ ���
                m[gems[e]]++;
                e++; // end���� ������Ű�鼭 gems[e]�� �ش��ϴ� ������ ���� ����
        }
        
    }
    
    return answer;
}
