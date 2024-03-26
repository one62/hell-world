#include <iostream>
#include <algorithm>
using namespace std;

int main () {
	int q;
	cin >> q;
	int* answer = new int[q];

	for (int i = 0; i < q; i++)
	{
		int ta, tb, va, vb;
		cin >> ta >> tb >> va >> vb;

		int dohoon = 0, sanghyeok = 0;
		while (va > 0 || vb > 0)
		{
			if (vb > 0) {
				vb--;
				dohoon += tb;
			} else if (va > 0) {
				va--;
				if (dohoon > sanghyeok) {
					sanghyeok += ta;
				} else {
					dohoon += ta;
				}
			}
		}

		answer[i] = max(dohoon, sanghyeok);
	}

	for (int i = 0; i < q; i++)
	{
		cout << answer[i] << '\n';
	}
}