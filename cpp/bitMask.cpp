#include<bits/stdc++.h>
#include<string>

using namespace std;

const int INF = 987654321;
const int MAX = 12;
int n,k,m,l;
// prerequisite[i] = i��° ������ �������� ����
int prerequisite[MAX];
// classes[i] = i��° �б⿡ �����Ǵ� ���� ����
int classes[10];
int cache[10][1 << MAX];

//���� num�� ������ ǥ������ ���� ��Ʈ�� ���� ��ȯ�Ѵ�.
int bitCount(int num){
    if(num == 0) return 0;
    return num%2 + bitCount(num/2);
}

int graduate(int semester, int taken){
    // k�� �̻��� ������ �̹� ���� ���
    if(bitCount(taken) >= k) return 0;
    // m�бⰡ ���� ���� ���
    if(semester == m) return INF;

    // �޸������̼�
    int& ret = cache[semester][taken];
    if(ret != -1) return ret;
    ret = INF;

    // �̹� �б�(semester)�� ���� �� �ִ� ���� �� ���� ���� ���� ������� ã�´�.
    int canTake = (classes[semester] & ~taken);
    // ���� ������ �� ���� ���� ������� �ɷ�����.
    for(int i=0;i<n;i++)
        if((canTake & (1 << i)) && (taken & prerequisite[i]) != prerequisite[i])
            canTake &= ~(1 << i);
	//�� ������ ��� �κ������� ��ȸ�Ѵ�. 
    for(int take=canTake;take>0;take=((take-1) & canTake)){
        if(bitCount(take) > l) continue;
        ret = min(ret, graduate(semester+1, taken | take) +1);
    }
	//�̹��б� �ƹ� �͵� ���� ���� ��� 
    ret = min(ret, graduate(semester+1, taken));
    return ret;
}

int main(){

    int _;
    cin >> _;
    while(_--){
        memset(prerequisite, 0, sizeof(prerequisite));
        memset(classes, 0, sizeof(classes));
        memset(cache, -1, sizeof(cache));
        cin >> n >> k >> m >> l;

        for(int i=0;i<n;i++){
            // i��° ������ �������� ����
            int preN;
            cin >> preN;
            for(int j=0;j<preN;j++){
                int subN;
                cin >> subN;
                // i��° ������ �������� ��ȣ�� ���� ��Ʈ�� �Ҵ�.
                prerequisite[i] |= (1 << subN);
            }
        }

        for(int i=0;i<m;i++){
            // i��° �б��� ���� ����
            int classN;
            cin >> classN;
            for(int j=0;j<classN;j++){
                int subN;
                cin >> subN;
                // i��° �б��� ���� ��ȣ�� ���� ��Ʈ�� �Ҵ�.
                classes[i] |= (1 << subN);
            }
        }

        int result = graduate(0,0);
        if(result == INF)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << result << endl;
    }

    return 0;
}
