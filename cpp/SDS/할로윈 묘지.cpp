#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define INF 987654321
using namespace std;

const int MAX = 900;

vector<pii> arr[901];
int dy[] ={-1,0,1,0};
int dx[] ={0,-1,0,1};

int dist[901];
set<int> thomb;



int main(){
	fastio;
	
	
	while(1){
		thomb.clear();
		for(int i=0; i<=MAX; i++){
			dist[i] = INF;
			arr[i].clear();
		}
		
		
		
		int w,h;cin>>w>>h;
		if(w==0&&h==0) break;
		int num=w*h;
		int g;cin>>g;
		for(int i=0; i<g; i++){
			int x,y;cin>>x>>y;
			thomb.insert(y*w+x);
			
		}
		
		int e;cin>>e;
		for(int i=0; i<e; ++i){
        int x1,x2,y1,y2,t;
        cin >> x1 >> y1 >> x2 >> y2 >> t;
        int From = y1*w+x1;
        int To = y2*w+x2;
        arr[From].push_back(pii(To,t));
    }
		
	for(int i=0; i<w; ++i){
        for(int j=0; j<h; ++j){
            int From = j*w+i;
            // ���񿡼� �ٸ�ĭ���� �����̴� ���� ����. 
            if(thomb.count(From)) continue;
            // �ͽ� ���ۿ����� ������� ������. 
            if(!arr[From].empty()) continue;
            // �������� exit �����ϰ�� �ٽ� �������� �ʴ´ٰ� �ϳ׿�. 
            if(From==num-1) continue;
            // �������~ 
            for(int k=0; k<4; ++k){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx<0||nx>=w||ny<0||ny>=h) continue;
                int To = ny*w+nx;
                // ����ĭ���� �� �� ����. 
                if(thomb.count(To)) continue; 
                // ������� �ð� 1��ŭ �ɷ� ����. 
                arr[From].push_back(pii(To,1));
            }       
        }
    }
		
	dist[0] = 0;
    bool minuscycle = false; 
    for(int k=0; k<=num; ++k){
        for(int i=0; i<num; ++i){
            if(dist[i]==INF) continue; 
            for(auto next: arr[i]){
                if(dist[next.first] > dist[i]+next.second){
                    if(k==num) minuscycle = true;                   
                    dist[next.first] = dist[i]+next.second; 
                }
            }   
        }       
    }    
		
		if(minuscycle)cout<<"Never"<<endl;
		else if(dist[num-1] ==INF)cout<<"Impossible"<<endl;
		else cout<<dist[num-1]<<endl;
		
		
		
	}
	
	
	
	
	
	
	
	return 0;
} 
