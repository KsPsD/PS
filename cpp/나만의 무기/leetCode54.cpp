#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;

vector<int> spiralOrder(vector<vector<int> > square_matrix){
	const array<array<int,2> ,4> kShift = {{{0,1}, {1,0} , {0,-1}, {-1, 0}}};
	int dir =0, x=0, y=0;
	vector<int> spiral_ordering;
	
	for(int i=0; i<size(square_matrix[0]) *size(square_matrix) ; ++i){
		spiral_ordering.emplace_back(square_matrix[x][y]);
		square_matrix[x][y]=0;
		int next_x =x +kShift[dir][0], next_y = y+kShift[dir][1];
        
		if(next_x <0  || next_x >=size(square_matrix) || next_y<0 || next_y>=size(square_matrix[0]) || square_matrix[next_x][next_y] ==0){
			dir = (dir+1) %4;
			next_x =x+kShift[dir][0] , next_y = y+kShift[dir][1];
		}
		x=next_x, y=next_y;
		
	}
	return spiral_ordering;
}


int main(){
	
	
	
	
	
	
	
	return 0;
}
