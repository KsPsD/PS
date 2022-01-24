#include<bits/stdc++.h>



using namespace std;

int N,M,K;

struct DIR{
	int y,x;
};

DIR dir[] ={{-1,0}, {-1,1}, {0,1}, {1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

struct fb{
	int r,c,m,s,d;
	fb(int q,int w,int e,int r,int t){
		
		r=q;
		c=w;
		m=e;
		s=r;
		d=t;
		
	}
};


vector<fb> arr[51][51];
vector<fb>  v;


void moveFb(){
	while(K--){
		for(int i =0; i<v.size(); i++){
			int yy= (v[i].r+dir[v[i].d].y * v[i].s) %N;
			int xx= (v[i].c+dir[v[i].d].x * v[i].s) %N;
			
			if (yy<0) yy+=N;
			if(xx<0) xx+=N;
			
			v[i].r= yy;
			v[i].c= xx;
			
		}
		
		for(int i=1;i<=N; i++){
			for(int j=1; j<=N; j++){
				arr[i][j].clear();
			}
		}
		
		for(int i=0; i<v.size(); i++){
			arr[v[i].r][v[i].c].push_back(v[i]);
		}
		v.clear();
		
		for(int i=0; i<N;i++){
			for(int j=0; j<N; j++){
				if(arr[i][j].size()==1){ 
					v.push_back(arr[i][j][0]);
				}
				
				else if(arr[i][j].size()>=2){
					int m_sum=0,s_sum=0;
					bool even=true, odd=true;
					for(auto e:arr[i][j]){
						m_sum+=e.m;
						s_sum+=e.s;
						
						if(e.d %2==0) odd=false;
						else even=false;
					}
					
					int n_m=  M/5;
					int n_s= s_sum/ arr[i][j].size();
					
					if(n_m==0) continue;
					
				
				if(even||odd){
					v.push_back(fb(i,j,n_m,n_s,0));
					v.push_back(fb(i,j,n_m,n_s,2));
					v.push_back(fb(i,j,n_m,n_s,4));
					v.push_back(fb(i,j,n_m,n_s,6));
				}
				else{
					v.push_back(fb(i,j,n_m,n_s,1));
					v.push_back(fb(i,j,n_m,n_s,3));
					v.push_back(fb(i,j,n_m,n_s,5));
					v.push_back(fb(i,j,n_m,n_s,7));
				}			
					
				}
				
				
				
			}
		}
		
	}
	
}



int main(){
	
	cin>>N>>M>>K;
	
	
	for(int i=0; i<M; i++){
		int r,c,m,s,d;
		cin>>r>>c>>m>>s>>d;
		v.push_back({r-1,c-1,m,s,d});
	}
	
	int ans=0;
	
	moveFb();
	
	for(auto e:v){
		ans+=e.m;
	}
	
	cout<<ans<<endl;
	
	
	
	
	
	
	return 0;
}
