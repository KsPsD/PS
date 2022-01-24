#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1<<19;
 
char S[MAX];
int N, d, sa[MAX], pos[MAX]; // pos: �׷� ��ȣ
 
// ���̻� �񱳿� ����� �� �Լ�
bool cmp(int i, int j){
    // ���� �ڽ��� ��ġ�� ���ڸ� ��
    if(pos[i] != pos[j]) return pos[i] < pos[j];
    // ���ڰ� ������ dĭ ���� ���ڳ��� ��
    i += d;
    j += d;
    return (i < N && j < N) ? (pos[i] < pos[j]) : (i > j);
}
 
// S�� ����� sa �迭�� ����� �Լ�
void constructSA(){
    N = strlen(S);
    // ��ó��
    for(int i=0; i<N; i++){
        sa[i] = i;
        pos[i] = S[i]; // ���� ù ��° ���������� ���ڸ� ���ڷ� ��
    }
    // d�� 2�辿 �÷����鼭 �Ź� �տ������� d*2���ڸ� ���� ���̻� ����
    for(d=1; ; d*=2){
        sort(sa, sa+N, cmp);
 
        // temp: ���ο� �׷� ��ȣ
        int temp[MAX] = {0};
        // �տ������� �����鼭 �� ���̻簡 ���� �ٸ� �׷쿡 ���� ������ �׷� ��ȣ ������Ŵ
        for(int i=0; i<N-1; i++)
            temp[i+1] = temp[i] + cmp(sa[i], sa[i+1]);
        // pos �迭�� temp �迭�� ��ü
        for(int i=0; i<N; i++)
            pos[sa[i]] = temp[i];
 
        // ��� ���̻簡 �ٸ� �׷����� ���������ٸ� ����
        if(temp[N-1] == N-1) break;
    }
}
 
int main(){
    scanf("%s", S);
    constructSA();
    for(int i=0; i<N; i++)
        printf("%d ", sa[i]+1);
}


