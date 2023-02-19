#include <iostream>
#include <string>
using namespace std;

bool check(string c){
	int i = 0;
	for (; c[i] && c[i] != '2'; i++);
	if (c[i] == '\0') return 0;
	for (; c[i] && c[i] != '0'; i++);
	if (c[i] == '\0') return 0;
	for (; c[i] && c[i] != '2'; i++);
	if (c[i] == '\0') return 0;
	for (; c[i] && c[i] != '3'; i++);
	if (c[i] != '3') return 0;
	return 1;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	int ans = 0;
	while (N)
	{
		string str = to_string(N);
		if (check(str)) ans++;
		N--;
	}
	cout << ans;
}