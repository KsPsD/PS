#include<bits/stdc++.h>


using namespace std;




int solution(int n, int a, int b)
{
    int answer = 0;

  //�ϴ� while�� ���� ���ٰ� ���� ���̰� 1�� �ɶ�
  //���� ��� n �� 8�϶� 4 2 1�̷��� �� �׷� ���� ���̸� �������� 
  //���� ���� 1�� �Ǹ� answer������  Ż�� 
    //���� ��ġ�� �߿�
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
