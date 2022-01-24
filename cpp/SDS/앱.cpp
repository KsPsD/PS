#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
using namespace std;
//



int n, m;
int memory[MAX];
int cost[MAX];
int dp[10001];
int sum;
int main(void) {

	sum = 0;
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0, a; i < n; i++) {
		cin >> memory[i]; 

	}

	for (int i = 0, b; i < n; i++) {
		cin >> cost[i];
		sum += cost[i];
	}

	//cost
	for (int i = 0; i < n; i++) {
		for (int j = sum; j >= cost[i]; j--) {
			dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]); //���� cost���� �ִ�� Ȯ���Ҽ��ִ� �޸�
		}
	}

	int i = 0;
	for (i = 0; i < sum, dp[i] < m; i++);
	cout << i << endl;
	return 0;
}


//ž�ٿ� ��� 


int N,M;

int memory[100];
int cost[100];
//cache[i][j]�� i��ġ���� j������� ����� �ִ� �ִ� �޸� ũ��
int cache[100][10001];
 
int calc_memory(const int& here, const int& total_cost) {
    if (here >= N)
        return 0;
    
    //�޸������̼� Ȱ��
    int& ret = cache[here][total_cost];
 
    //���� ��� : �̹� Ž���� �Ϸ�� ���
    if (ret != -1)
        return ret;
 
    //���� ���� ��Ȱ��ȭ ��Ű�� ���� ���
    ret = calc_memory(here + 1, total_cost);    
 
    //���� ���� ��Ȱ��ȭ ��Ű�� ���
    if (cost[here] <= total_cost)
        //���� ���� ��Ȱ��ȭ ��Ű�� ���� ���� ���Ͽ� �� ū �޸𸮸� ����
        ret = max(ret, memory[here] + calc_memory(here + 1, total_cost - cost[here]));
    
    return ret;
}
 
int main() {
    cin >> N >> M;
 
    for (int i = 0; i < N; i++)
        cin >> memory[i];
    for (int i = 0; i < N; i++)
        cin >> cost[i];
 
    //�޸������̼��� Ȱ���ϱ� ���� �ʱ�ȭ
    memset(cache, -1, sizeof(cache));
 
    int ret = 0;
 
    //������ �ִ� �ڽ�Ʈ�� 10000���� Ž���� �����ϵ��� ����.
    for (int i = 0; i < 10001; i++) {
        ret = calc_memory(0, i);
        if (ret >= M) {
            cout << i;
            break;
        }
    }
 
    return 0;
}
