#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char target[26];
char ganpan[101];
int ans;
int main()
{
	int n;
	int len1;
	int len2;
	scanf("%d", &n);
	scanf("%s", target);
	len1 = strlen(target);
	for (int i = 0; i < n; i++) {
		scanf("%s", ganpan);
		len2 = strlen(ganpan);
		if (len1 > len2)
			continue;
		for (int first = 0; first < len2; first++) {
			if (target[0] != ganpan[first])
				continue;
			int second;
			for (second = first + 1; second < len2; second++) {
				if (target[1] != ganpan[second])
					continue;
				int interval = second - first;
				int pos2 = second;
				int pos = 2;
				for (; pos < len1; pos++) {
					pos2 += interval;
					if (pos2 >= len2 || target[pos] != ganpan[pos2])
						break;
				}
				if (pos == len1) {
					ans++;
					break;
				}
			}
			if (second < len2)
				break;
		}
	}
	printf("%d", ans);
	return 0;
}
