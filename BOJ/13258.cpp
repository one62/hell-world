//백준 13258번 복권 + 은행
#include <iostream>
using namespace std;

int main() {
	int N, credit[2], J, C;
	cin >> N >> credit[0];
	credit[1] = 0; //credit[0] : 강호 잔고, credit[1] : 나머지 사람들 잔고 합
	for (int i = 1; i < N; i++)
	{
		int t;
		cin >> t;
		credit[1] += t;
	}
	cin >> J >> C;
	double a = credit[0], b = credit[1];
	for (int i = 0; i < C; i++)
	{
		a = a + (double)J * a / (a + b);
		b = b + (double)J * b / (a + b);
	}
	cout << a;
}