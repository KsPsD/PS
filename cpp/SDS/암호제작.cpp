#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;
int	ch[1000001];
string p;
bool check(int num){
	int sum = 0;	
	// �־��� �� P �� �� �ڸ�������(ū �ڸ�������) ������ ����
	for(int i=0; p[i];i++) 
		sum = (sum*10+(p[i]-'0'))%num;
	if(sum==0) return true;
	return false;
}


int main(){
	
	 int k;
	cin>>p>>k;

	int ans=0;

	bool flag=true;
	for(int i=2; i<k; ++i){
	if(ch[i]) continue;
	// �Ҽ� i �� P�� ������ ���������� ���� üũ
	if(check(i)){
		flag = false;
		ans = i;
		break;
	}
	// �Ҽ� �ƴѾֵ� ����. �����佺�׳׽��� ü
	for(int j=2*i; j<k; j+=i) ch[j] = true;
	
}
	if(flag){
		cout<<"GOOD"<<endl;
	}
	else{
			cout<<"BAD"<<" "<< ans <<endl;
	}

	
return 0;
	
	
} 
