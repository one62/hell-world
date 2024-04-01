// 가장 먼 노드
// 가장 먼 노드의 개수 구하기

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	int tmp = 0;
	
	// 그래프 만들기
	vector<vector<int>> g(n + 1);
	for (vector<int> e : edge)
	{
		g[e[0]].push_back(e[1]);
		g[e[1]].push_back(e[0]);
	}
	
	queue<int> q;
	q.push(1);
	q.push(0);
	bool* check = new bool[n + 1]{true, true,};

	while (!q.empty())
	{
		int front = q.front();
		q.pop();

		for (int i : g[front])
		{
			if (check[i] == false)
			{
				q.push(i);
				check[i] = true;
				tmp++;
			}
		}

		if (q.front() == 0)
		{
			q.pop();
			if (q.empty()) break;
			if (tmp) answer = tmp;
			tmp = 0;
			q.push(0);
		}
	}

	return answer;
}


#include <iostream>

int main() {
	vector<vector<int>> v = { {3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2} };

	cout << solution(6, v);
}