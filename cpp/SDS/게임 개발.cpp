#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

using namespace std;

const int MAX = 500 + 1;

int N;
int inDegree[MAX];
int duration[MAX];
int result[MAX];
vector<int> graph[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int time;
		cin >> 	duration[i];

		result[i] = duration[i];

		while (1)
		{
			int node;
			cin >> node;
			

			if (node == -1)
			{
				break;
			}

			inDegree[i]++;
			graph[node].push_back(i);
		}
	}
	
	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);
		}
	}

	

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int i = 0; i < graph[node].size(); i++)
		{
			int nextNode = graph[node][i];

			result[nextNode] = max(result[nextNode], result[node] + duration[nextNode]);
			
			if (--inDegree[nextNode] == 0)
			{
				q.push(nextNode);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << result[i]  << "\n";
	}

	return 0;
}
