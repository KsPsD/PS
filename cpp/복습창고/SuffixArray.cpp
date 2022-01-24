#include <cstdio>
#include <algorithm>
#include <cstring>
#include<bits/stdc++.h>
#define MAX_N 600000
using namespace std;
 
/*
str :: ���ڿ��� �� �迭
t :: �ܾ��� ��ġ�� ���� ����
n :: str�� ����
g :: �׷�
tg :: �� �׷�
SA :: Suffix Array
*/
 
char str[MAX_N];
int t, n, g[MAX_N], tg[MAX_N], SA[MAX_N];
 
bool cmp(int x, int y)
{
    // �׷� ��ȣ�� ������
    if (g[x] == g[y])
        return g[x + t] < g[y + t];
 
    // �׷� ��ȣ�� �ٸ���
    return g[x] < g[y];
}
 
void getSA(const char* str)
{
    t = 1;
    n = (int)strlen(str);    //������ �� ����
 
    //ù ���ڿ� ���� �׷��� �����ִ� ��ó��
    for (int i = 0; i < n; i++)
    {
        SA[i] = i;
        g[i] = str[i] - 'a';
    }
 
    //1,2,4,8... �� �ܾ��� ���̺��� ���� ��츦 Ž��
    while (t <= n)
    {
        g[n] = -1;
        sort(SA, SA + n, cmp);    //�׷쿡 ���� ����
        tg[SA[0]] = 0;    //���� �׷��� �Ҵ��ϱ� ���Ͽ� tempgroup�� ù��° ��ȣ ����
 
        //���� �׷� ���� 
        for (int i = 1; i < n; i++)
        {
            //�׷��� �ٸ� ��� ���� �׷� ��ȣ �Ҵ�
            if (cmp(SA[i - 1], SA[i])){
                tg[SA[i]] = tg[SA[i - 1]] + 1;
			}
            
 
            //�׷��� ���� ��� ���� �׷� ��ȣ �Ҵ�
            else
                tg[SA[i]] = tg[SA[i - 1]];
        }
 
        //���ο� �׷� �Ҵ�
        for (int i = 0; i < n; i++)
            g[i] = tg[i];
 
        t <<= 1; // t *= 2;
    }
}
 
int main()
{
    scanf("%s", &str);
    getSA(str);
 
    printf("\n[Suffix Array]\n");
    for (int i = 0; i < n; i++){
    	 printf("%s\n", str + SA[i]);
	}
       
   
    	
//    printf("\n[Suffix Array Order]\n");
//    for (int i = 0; i < n; i++)
//        printf("%d ", SA[i] + 1);
// 
//    printf("\n\n");
 
 
    return 0;
}


