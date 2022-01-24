#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;
int total; 
bool areFriends[10][10];


int count(bool taken[10]){
	int first =-1;
	for(int i=0 ;i<total;i++){
		if(!taken[i]){
			first= i;
			break;
		}
	}
	
	if(first == -1)return 1;
	int res =0;
	
	for(int i=first+1; i<total; i++){
		if(!taken[i] && areFriends[first][i]){
			taken[first] = taken[i] = true; 
            res += count(taken); //재귀
            taken[first] = taken[i] = false; //다른 경우의 수 찾기 위해 짝 해제



		}
	}

	
	return res;
}


int main() {
	fastio;

	int t;cin>>t;
	bool taken[10];
	for(int i=0 ;i<t; i++){
		 int pair;
		cin>>total>>pair;
		if(total<2 || total>10 || pair<0 || pair>((total*(total-1)) /2)) exit(-1);
		
		memset(areFriends, false, sizeof(areFriends));
        memset(taken, false, sizeof(taken));

	for (int j = 0; j < pair; j++)
    {

    int student1, student2;
    cin >> student1 >> student2;
	areFriends[student1][student2] = areFriends[student2][student1] = true;

    }
	   cout << count(taken) << endl;

        }




	

    return 0;
}

