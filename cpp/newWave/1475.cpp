#include<bits/stdc++.h>


using namespace std;

int ch[10];

int main(){
	
string N; cin >> N;
	int len = N.length();
	for (int i = 0; i < len; i++) {
		ch[N[i] - '0']++;
	}
	
	//6과 9처리 (반절씩)
	int six_nine = (ch[6] + ch[9] + 1) / 2;
	ch[6] = six_nine; ch[9] = six_nine;

	int M = 0;
	for (int i = 0; i < 10; i++) {
		if (ch[M] < ch[i]) M = i;
	}
	
	cout << ch[M] << endl;
	return 0;
	
	
	
	return 0;
}
