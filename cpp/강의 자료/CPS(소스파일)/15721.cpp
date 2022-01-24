#include<bits/stdc++.h>

using namespace std;



int a,t, cmd;

int main(){
	
	cin>>a>>t>>cmd;
	
	int b=0;
	int d=0;
	int cnt=2;
	
	
	while(1){
		
		for(int i=0; i<4; i++){
			if(i %2 ==0)
				b++;
			else
				d++;
			
			if(b==t && cmd==0){
				cout<<(b+d -1 )  % a<<endl;
				return 0;
			}
			if(d==t && cmd==1){
				cout<<(b+d -1) %a <<endl;
				return 0;
			}
		}
		
		
		for (int i = 0; i < cnt; i++)

                 {
                         b++;

                         if (b == t && cmd == 0)
								{   cout<< (b + d - 1) % a<<endl;
                                 return 0;
								}
                              
                 }

                 for (int i = 0; i < cnt; i++)

                 {
                         d++;

                         if (d == t && cmd == 1){
                         	 cout<< (b + d - 1) % a<<endl;
								return 0;
						 }
                                
                 }

                 cnt++; 
		
		
	}	
	
	
	
	return 0;
}
