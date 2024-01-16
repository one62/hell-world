// 백준 1782 거울 숫자 (난이도 P5)

#include <iostream>
#include <stack>
using namespace std;

int main () {
	/* 0, 1, 8은 서로 대칭. 2, 5는 서로 반대.
	두 수 사이(포함)의 거울 숫자의 개수 출력.*/
	long long a, b;
	cin >> a >> b;

	int count = 0;

	for (long long i = a; i <= b; i++)
	{
		long long t = i;
		stack<long long> stack;
		while (t)
		{
			stack.push(t % 10);
			t /= 10;
		}
		t = i;
		while (t)
		{
			long long top = stack.top();
			if (top == 0 || top == 1 || top == 8) {
				if (top == t % 10) {
					stack.pop();
					t /= 10;
				} else break;
			} else if (top == 2) {
				if (5 == t % 10) {
					stack.pop();
					t /= 10;
				} else break;
			} else if (top == 5) {
				if (2 == t % 10) {
					stack.pop();
					t /= 10;
				} else break;
			} else break;
		}
		if (stack.empty()) count++;
	}

	cout << count;
}