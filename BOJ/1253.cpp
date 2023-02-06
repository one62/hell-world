#include <iostream>
#include <algorithm>
using namespace std;

int a[2000];
int n;

bool good(int i) {
	int st = 0, en = n - 1;
	while (st < en)
	{
		if (a[st] + a[en] < a[i] || st == i) st++;
		else if (a[st] + a[en] > a[i] || en == i) en--; 
		else if (a[st] + a[en] == a[i]) return true;
	}
	return false;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a+n);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (good(i)) ans++;
	}
	cout << ans;
}

/*
#include <iostream>
#include <algorithm>
using namespace std;

int a[2001];
int n;

bool isgood(int num){
	for (int i = 0; i < n - 1 && a[i] <= a[num]; i++)
	{
		if (i == num) continue;
		int lo = i; int hi = n;
		int mid = (lo + hi) / 2;
		while (mid != i && mid != num)
		{
			mid = (lo + hi) / 2;
			if (a[i] + a[mid] == a[num]) return true;
			if (a[i] + a[mid] < a[num]) {
				lo = mid;
			}
			if (a[i] + a[mid] > a[num]) {
				hi = mid;
			}
		}
	}
	return false;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a+n);
	int good = 0;
	for (int i = 0; i < n; i++)
	{
		if (isgood(i)) {
			good++;
			cout << a[i] << '\n';
		}
	}
	cout << "good: " << good;
}
*/