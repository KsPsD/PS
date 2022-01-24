#include<bits/stdc++.h>


using namespace std;




int solution(int n, int a, int b)
{
    int answer = 0;

  //일단 while문 내려 가다가 둘의 차이가 1이 될때
  //예를 들어 n 이 8일때 4 2 1이렇게 감 그럼 둘의 차이를 먼저보고 
  //둘의 차가 1이 되면 answer갱신후  탈출 
    //둘의 위치도 중요
  int cnt=1;
  while(n){
  	if(a %2 ==1 && b==a+1){
  		answer = cnt;
	  	break;
	  }
      else if(a %2 ==0 && b==a-1){
          answer= cnt;
          break;
      }
	  
	  a = a%2==1 ? a/2+1 : a/2;
	  b = b%2 ==1? b/2+1 :b/2;
	cnt++;
  } 
    

    return answer;
}




int main(){
	
	
	solution(8,4,5);
	
	
	return 0;
} 
