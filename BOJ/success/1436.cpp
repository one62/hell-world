#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int i;
	for (i = 665; N > 0; i++)
	{
		int j = i;
		int c = 3;
		while (j > 0)
		{
			if (j % 10 == 6) c--;
			else c = 3;
			if (c == 0) break;
			else j /= 10;
		}
		if (c == 0) N--;
		if (N == 0) break;
	}
	cout << i;
}
