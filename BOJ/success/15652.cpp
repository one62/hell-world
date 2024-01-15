// 백준 15652 N과 M (4)

#include <iostream>
using namespace std;

void printarr(int* arr, int m) {
	for (int i = 0; i < m; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

int main() {
	int n, m;
	cin >> n >> m;

	int* arr = new int[m];

	for (int i = 0; i < m; i++) 
	{
		arr[i] = 1;
	}

	for (int i = m - 1; i >= 0;)
	{
		if (arr[i] <= n) {
			printarr(arr, m);
			arr[i]++;
		} else {
			i--;
			if (i < 0) continue;
			arr[i]++;
			if (arr[i] > n) continue;
			for (int j = i + 1; j < m; j++)
			{
				arr[j] = arr[i];
			}
			i = m - 1;
		}
	}
}