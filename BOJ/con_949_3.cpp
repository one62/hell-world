#include <iostream>
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int N, L;
	cin >> N >> L;
	int* a = new int[N + 1];
	a[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		int tmp = a[i];
		if (i > L) tmp -= a[i - L];
		if (tmp >= 129 && tmp <= 138) ans++;
	}
	cout << ans;
}