#include <iostream>
using namespace std;
#include <deque>

int main() {
	int N;
	cin >> N;
	deque<pair<int, char>> dq;
	while (N--)
	{
		int b; cin >> b;
		switch (b)
		{
			char c;
		case 1:
			cin >> c;
			dq.push_back(make_pair(N, c));
			break;
		case 2:
			cin >> c;
			dq.push_front(make_pair(N, c));
			break;
		case 3:
			if (dq.empty()) break;
			if (dq.front().first > dq.back().first) {
				dq.pop_back();
			}
			else {
				dq.pop_front();
			}
		default:
			break;
		}
	}
	if (dq.empty()) {
		cout << '0';
	}
	else for (deque<pair<int, char>>::iterator iter = dq.begin(); iter != dq.end(); iter++)
	{
		cout << (*iter).second;
	}
}