#include<bits/stdc++.h>

using namespace std;

int ch[10000];

int d(int num){
	return num + (num / 1000 )+ ((num % 1000) /100 ) + (((num % 1000) %100) /10)  +  (((num % 1000) %100) % 10);
}



int main(){
	
	ch[1]= 0;
	for(int i=0; i< 10000; i++){
		int tmp = d(i);
		if(tmp <10000){
			ch[tmp] =1;
		}
	}	
	
	
	for(int i=0; i<10000; i++){
		if(!ch[i])
			cout<<i<<endl;
	}
	
	
	return 0;
}
