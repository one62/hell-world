// 백준 9934 : 완전 이진 트리
#include <iostream>
#include <cmath>
using namespace std;


int main() {
	int k;
	cin >> k;

	int p = pow(2, k) - 1;
	int* list = new int[p];
	for (int i = 0; i < p; i++)
	{
		cin >> list[i];
	}

	for (int i = 0; i < k; i++)
	{
		int p1 = pow(2, k - i - 1) - 1;
		int p2 = pow(2, k - i);
		for (int j = p1; j < p;)
		{
			if (j != p1) cout << ' ';
			cout << list[j];
			j += p2;
		}
		cout << '\n';
	}

	return 0;
}