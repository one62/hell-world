//백준 27313번: 효율적인 애니메이션 감상
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int* watching = new int[k];
	for (int i = 0; i < k; i++)
	{
		watching[i] = m;
	}
	priority_queue<int, vector<int>, greater<int>> l;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		l.push(t);
	}
	int count = 0;
	while (!l.empty())
	{
		int t = l.size();
		for (int i = 0; i < k; i++)
		{
			if (watching[i] >= l.top()) {
				watching[i] -= l.top();
				l.pop();
				count++;
			}
		}
		if (t == l.size()) break;
	}
	cout << count;
}