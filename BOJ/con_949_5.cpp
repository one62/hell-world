#include <iostream>
using namespace std;
#include <vector>
#include <list>

vector<list<int>> vec;

int findcycle(int i, int j, int** ab) {
	for (int k = )
	if (findcycle(i, j+1, ab)) {

	}
} 

int main() {
	int N, M;
	cin >> N >> M;
	int** ab = new int*[N];
	for (int i = 0; i < N; i++) ab[i] = new int[N];
	int a, b, c, d;
	for (int i = 0; i < M; i++) 
	{
		cin >> a >> b >> c >> d;
		if (d) ab[a][b] = 10001;
		else ab[a][b] = c;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (ab[i][j]) {
				findcycle(i, j, ab);
			}
		}
	}
}