#include<bits/stdc++.h>


using namespace std;

int arr[202][202];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
struct Virus{
	int virus;
	int x;
	int y;
};
bool cmp(const Virus& v1, const Virus& v2){
	return v1.virus < v2.virus;
}
int main(){
	vector<Virus> vec;
	int N, K, S, X, Y;
	scanf("%d %d", &N, &K);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &arr[i][j]);
			if(arr[i][j] >= 1 && arr[i][j] <= K){
				vec.push_back({arr[i][j], i, j});
			}
		}
	}
	scanf("%d %d %d", &S, &X, &Y);
	int s = 0;
    sort(vec.begin(), vec.end(), cmp);
	while(s < S){
		int len = vec.size();
		for(int j=0; j<len; j++){
			Virus v = vec[j];
			for(int i=0; i<4; i++){
				int nx = v.x + dx[i];
				int ny = v.y + dy[i];
				if(nx <= 0 || ny <= 0 || nx > N || ny > N)	continue;
				if(!arr[nx][ny]){
					arr[nx][ny] = v.virus;
					vec.push_back({arr[nx][ny], nx, ny});
					
				}
			}
		}
		if(arr[X][Y] > 0)	break;
		s++;
	}
	printf("%d", arr[X][Y]);
	return 0;
}
