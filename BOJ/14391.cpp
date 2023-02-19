#include <iostream>
using namespace std;

int n, m;
int paper[4][4];
int ans;
bool rc[4][4];

void dfs(int r, int c){
	if (r == n) {
		int sum = 0;
		int tmp = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				while(rc[i][j] && j < m)
				{
					tmp *= 10;
					tmp += paper[i][j];
					j++;
				}
				sum += tmp;
				tmp = 0;
			}
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				while(!rc[j][i] && j < n)
				{
					tmp *= 10;
					tmp += paper[j][i];
					j++;
				}
				sum += tmp;
				tmp = 0;
			}
		}
		ans = max(ans, sum);
		return;
	}
	if (c == m) {
		dfs(r + 1, 0);
		return;
	}
	rc[r][c] = true;
	dfs(r, c + 1);
	rc[r][c] = false;
	dfs(r, c + 1);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		for (int j = 0; j < m; j++)
		{
			paper[i][m - j - 1] = a % 10;
			a /= 10;
		}
	}//입력 받기
	dfs(0,0);
	cout << ans;
}