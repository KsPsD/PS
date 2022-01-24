#include <iostream>
#include <fstream>
#include<limits>
#include<string.h>
#include<string>
#include<vector>
#include<cstdlib>
#pragma warning(disable: 4996)
#include<stdio.h>
#include<stack>
#include<algorithm>
#include<queue>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std;




int map[10][10];
int row[10][10];
int col[10][10];
int b[10][10];
struct pos {
	int y, x;
	pos(int a, int b) {
		y = a;
		x = b;

	}
};
queue<pos> q;




void dfs(int c) {
	

	if (c == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << map[i][j] << ' ';
			cout << '\n';
		}
		exit(0);
	}


	int y = c / 9;
	int x = c % 9;

	if (map[y][x]) 
		dfs(c + 1);
	else {
		for (int i = 1; i <= 9; i++) {
			if (!col[x][i] && !row[y][i] && !b[(y / 3) * 3 + (x / 3)][i])
			{

				map[y][x] = i;

				col[x][i] = true;

				row[y][i] = true;

				b[(y / 3) * 3 + (x / 3)][i] = true;

				dfs(c + 1);

				map[y][x] = 0;

				col[x][i] = false;

				row[y][i] = false;

				b[(y / 3) * 3 + (x / 3)][i] = false;

			}



		}
	}

}

int main()
{

	fastio;


	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin>>map[i][j];
			if(map[i][j]){
				row[i][map[i][j]] =1;
				col[i][map[i][j]]=1;
				b[(i/3)*3+(j/3)][map[i][j]] =1;
			}
			}
		

		}
	}




	dfs(0);
	
	return 0;
}



