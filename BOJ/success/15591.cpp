#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct edge {
	int to;
	int usado;
	edge(int to, int usado) : to(to), usado(usado) {}
};

int bfs(int k, int v, vector<vector<edge>> graph);

int main() {
	int n, q;
	cin >> n >> q;

	vector<vector<edge>> graph(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		int p, q, r;
		cin >> p >> q >> r;
		graph[p].push_back(edge(q, r));
		graph[q].push_back(edge(p, r));
	}

	vector<int> result;
	for (int i = 0; i < q; i++)
	{
		int k, v;
		cin >> k >> v;
		result.push_back(bfs(k, v, graph));
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << '\n';
	}

}

int bfs(int k, int v, vector<vector<edge>> graph)
{
	int count = 0;
	bool visit[5001] = {};
	queue<int> queue;
	queue.push(v);
	// visit[v] = true;

	while(!queue.empty())
	{
		int now = queue.front();
		queue.pop();
		for (int i = 0; i < graph[now].size(); i++)
		{
			if (graph[now][i].usado >= k && !visit[graph[now][i].to]) {
				queue.push(graph[now][i].to);
				visit[graph[now][i].to] = true;
				count++;
			}
		}
	}

	return count;
}