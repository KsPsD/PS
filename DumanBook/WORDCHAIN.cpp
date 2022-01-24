#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000007
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;


vector<vector<int> > adj;
vector<string> graph[26][26];

vector<int> indgree, outdgree;

void makeGraph(const vector<string> & words){
	adj = vector<vector<int> > (26, vector<int> (26));
	
	for(int i= 0 ;i<26; i++){
		for(int j= 0; j<26; j++){
			graph[i][j].clear();
		}
	}
	indgree = outdgree =vector<int>(26);
	
	
	for(auto & w: words){
		int a= w.front()- 'a';
		int b = w.back() - 'a';
		graph[a][b].push_back(w);
		++adj[a][b];
		++indgree[b];
		++outdgree[a];
		
	}
}




void getEulerCircuit(int curr, vector<int>  & circuit){
	for(int next= 0;next< adj.size() ;++next){
		while(adj[curr][next] > 0){
			--adj[curr][next];
			getEulerCircuit(next,circuit);
		}
	}
	circuit.push_back(curr);	
}

vector<int> getEulerTrailOrCircuit() {
	vector<int> circuit;

	//1. Ʈ���� -> ������ ã�Ƽ� ����
	for (int i=0; i<26; ++i)
		if (outdegree[i] == indegree[i] + 1) {
			getEulerCircuit(i, circuit);
			return circuit;
		}

	//2. ��Ŷ -> �ƹ�������
	for (int i=0; i<26; ++i)
		if (outdegree[i]) {
			getEulerCircuit(i, circuit);
			return circuit;
		}

	// ���� -> �׷����� ���� ������Ʈ�� �и��� ��� ���������� ��ȯ�ϴµ�
	//         ��ü �׷����� ���Ϸ� Ʈ����, ��Ŷ�� �ƴ� �� ����

	return circuit;	// ������ �� �迭 ��ȯ
}

bool checkEuler() {
	int plus1 = 0, minus1 = 0;	// ���� ������, ������ ��
	for (int i = 0; i < 26; ++i) {
		int delta = outdegree[i] - indegree[i];

		//������ -1, 1, 0 �̾�� ��
		if (delta < -1 || 1 < delta) return false;
		if (delta == 1) ++plus1;
		else if (delta == -1) ++minus1;
	}
	
	// ������,������ �ѽ־� �ְų�(Ʈ����), �ƴϸ� �ϳ��� ���ų�(��Ŷ)
	return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}


string solve(const vector<string>& words) {
	makeGraph(words);

	if (!checkEuler()) return "IMPOSSIBLE";

	vector<int> circuit = getEulerTrailOrCircuit();

	// ��� ������ �湮���� ���� ���
	if (circuit.size() != words.size() + 1) return "IMPOSSIBLE";
	//��Ŷ�� �ܾ ���°� �ƴ϶� ù���� �����ڴϱ�. 
	// �湮 ������ ������, ������ ��� ���ڿ��� ��ȯ
	reverse(circuit.begin(), circuit.end());
	string ret;
	for (int i = 1; i < circuit.size(); ++i) {
		int a = circuit[i - 1], b = circuit[i];
		if (ret.size()) ret += " ";

		ret += graph[a][b].back();
		graph[a][b].pop_back();
	}
	return ret;
}


int main(){
	fastio;
	
	int c;cin>>c;
	while(c--){
		int n;cin>>n;
		vector<string> words(n);
		for(auto & w :words){
			cin>>w;
		}
		cout<<solve(words)<<endl;
	}
}
