#include<bits/stdc++.h>
#define MAX_N 200020
using namespace std;
char str[2 * MAX_N], str2[MAX_N], res[MAX_N];
int t, n, m, g[MAX_N], tg[MAX_N], SA[MAX_N], r[MAX_N], LCP[MAX_N];
bool cmp(int x, int y) {
    if (g[x] == g[y]) {
        return g[x + t] < g[y + t];
    }
    return g[x] < g[y];
}
int main() {
    t = 1;
    cin>>str>>str2;
    //합치기 전 문자열 길이 
    m = strlen(str);
    str[m] = '$';
    strcat(str, str2);
    //합친 후 문자열 길이 
    n = strlen(str);
    for (int i = 0; i < n; i++) {
        SA[i] = i;
        g[i] = str[i] - 'a';
    }
	        
    while (t <= n) {    
        g[n] = -1;
        sort(SA, SA + n, cmp);    
        tg[SA[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (cmp(SA[i - 1], SA[i]))
                tg[SA[i]] = tg[SA[i - 1]] + 1;
            else
                tg[SA[i]] = tg[SA[i - 1]];
        }
        for (int i = 0; i < n; i++)
            g[i] = tg[i];    
        t <<= 1;
    }
    
    
    
    for (int i = 0; i < n; i++)
        r[SA[i]] = i;
    int len = 0;
    for (int i = 0; i < n; i++) {
        int k = r[i];
        if (k) {
            int j = SA[k - 1];
            while (str[j + len] == str[i + len])
                len++;
            LCP[k] = len;
            if (len)
                len--;
        }
    }
    
    
    
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if ((SA[i - 1]>m && SA[i] < m) || (SA[i - 1]<m && SA[i]>m)) {
            if (ans < LCP[i]) {
                ans = LCP[i];
                for (int j = 0; j < ans; j++)
                    res[j] = str[j + SA[i]];
            }
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < ans; i++)
        printf("%c", res[i]);
    return 0;
}




