#include <bits/stdc++.h>
using namespace std;



string reverse(string::iterator& it){
	char head = *it;
	++it;
	if(head == 'b' || head =='w'){
		return string(1,head);
	}
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);
	
	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}


int main(){
	int c;cin>>c;
	string s;
	for(int i=0 ;i<c ;i++){
		cin>>s;
		string::iterator it = s.begin();
		string ans = reverse(it);
		cout<<ans<<endl;
	}
}
