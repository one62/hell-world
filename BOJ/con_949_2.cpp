#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	vector<vector<string>> vv(9, vector<string>(9));
	string str;
	cin >> vv[1][1] >> vv[1][2] >> vv[1][3] >> vv[2][1] >> vv[2][2] >> vv[2][3] >> vv[3][1] >> vv[3][2] >> vv[3][3];
	cin >> vv[1][4] >> vv[1][0] >> vv[1][5] >> vv[2][4] >> vv[2][0] >> vv[2][5] >> vv[3][4] >> vv[3][0] >> vv[3][5];
	cin >> vv[1][6] >> vv[1][7] >> vv[1][8] >> vv[2][6] >> vv[2][7] >> vv[2][8] >> vv[3][6] >> vv[3][7] >> vv[3][8];
	cin >> vv[4][1] >> vv[4][2] >> vv[4][3] >> str >> str >> str >> vv[5][1] >> vv[5][2] >> vv[5][3];
	cin >> vv[4][4] >> vv[4][0] >> vv[4][5] >> str >> str >> str >> vv[5][4] >> vv[5][0] >> vv[5][5];
	cin >> vv[4][6] >> vv[4][7] >> vv[4][8] >> str >> str >> str >> vv[5][6] >> vv[5][7] >> vv[5][8];
	cin >> vv[6][1] >> vv[6][2] >> vv[6][3] >> vv[7][1] >> vv[7][2] >> vv[7][3] >> vv[8][1] >> vv[8][2] >> vv[8][3];
	cin >> vv[6][4] >> vv[6][0] >> vv[6][5] >> vv[7][4] >> vv[7][0] >> vv[7][5] >> vv[8][4] >> vv[8][0] >> vv[8][5];
	cin >> vv[6][6] >> vv[6][7] >> vv[6][8] >> vv[7][6] >> vv[7][7] >> vv[7][8] >> vv[8][6] >> vv[8][7] >> vv[8][8];
	sort(vv.begin(), vv.end());
	for (int i = 1; i < 9; i++)
	{
		sort(++(vv[i].begin()), vv[i].end());
		cout << '#' << i << ". " << vv[i][0] << '\n';
		for (int j = 1; j < 9; j++)
		{
			cout << '#' << i << '-' << j << ". " << vv[i][j] << '\n';
		}
	}
}