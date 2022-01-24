#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;


void RotateMatrix(vector<vector<int> > * square_matrix_ptr){
	vector<vector<int>>& square_matrix = *square_matrix_ptr;
	const int matrix_size = size(square_matrix) -1;
	for(int i=0 ; i<size(square_matrix) /2 ;++i){
		for(int j=i ;j<matrix_size -i ;j ++){
			int temp1= square_matrix[matrix_size-j][i];
			int temp2= square_matrix[matrix_size-j][matrix_size-i];
			int temp3= square_matrix[j][matrix_size-i];
			int temp4= square_matrix[j][i];
			square_matrix[matrix_size-j][i] =temp2;
			square_matrix[matrix_size-j][matrix_size-i] = temp3;
			square_matrix[j][matrix_size-i] =temp4;
			square_matrix[j][i] = temp1;		
		}	
	}
}



int main() {
	
}
