#include <iostream>
#include <string>

using namespace std;


// (100+1+ | 01)
//  123456   78
//        9
bool isPattern(string str) {
	int flag = 0;

	for (int i = 0; i < str.length(); i++)
	{
		switch(flag) {
		case 0:
			if (str[i] == '0') flag = 7;
			else flag = 1;
			break;
		case 1:
			if (str[i] == '0') flag = 2;
			else return false;
			break;
		case 2:
			if (str[i] == '0') flag = 3;
			else return false;
			break;
		case 3:
			if (str[i] == '0') flag = 4;
			else flag = 5;
			break;
		case 4:
			if (str[i] == '0') flag = 4;
			else flag = 5;
			break;
		case 5:
			if (str[i] == '0') flag = 7;
			else flag = 6;
			break;
		case 6:
			if (str[i] == '0') flag = 9;
			else flag = 6;
			break;
		case 7:
			if (str[i] == '0') return false;
			else flag = 0;
			break;
		case 9:
			if (str[i] == '0') flag = 3;
			else flag = 0;
			break;
		}
	}

	if (flag == 5 || flag == 6 || flag == 0) return true;
	else return false;
}


int main() {
	string str;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> str;
		if (isPattern(str)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}