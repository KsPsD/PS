#include<bits/stdc++.h>

 
#define endl "\n"
using namespace std;
 
const int MAX = 40000 + 1;
const int MOD = 123456789;

int N;
int cache[MAX];
bool notPrime[MAX];
vector<int> prime;



 
 
 void eratosthenes(void)

{
        notPrime[0] = notPrime[1] = true;


        for(int i=2; i<MAX; i++)
                 if (!notPrime[i])
                 {
                      for (int j = i * i; j < MAX; j += i)
							notPrime[j] =true;

                 }

        for (int i = 2; i < MAX; i++)

                 if (!notPrime[i])

                         prime.push_back(i);

}



 
 int main(){
 	ios::sync_with_stdio(false);
 	cin.tie(NULL);
 	cout.tie(NULL);
 	cin>>N;
 	cache[0]=1;
 	eratosthenes();
 	for(int i= 0 ;i<prime.size(); i++){
 		for(int j=prime[i]; j<=N; j++){
 			cache[j] = (cache[j] +cache[j-prime[i]]) %MOD;
 			cache[j] %MOD;
		 }
	 }
	 
	 cout<<cache[N]<<endl;
 	
 	return 0;
 	
 }
