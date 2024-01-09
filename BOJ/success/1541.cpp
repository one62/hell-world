// 백준 1541 잃어버린 괄호
#include <iostream>
using namespace std;

int main() {
	string input;
	cin >> input;

	int t = 0;
	int result = 0;
	int flag = 0;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] >= '0' && input[i] <= '9') {
			t *= 10;
			t += input[i] - '0';
		} else if (input[i] == '-') {
			if (flag == 1)
				result -= t;
			else
				result += t;
			t = 0;
			flag = 1;
		} else if (input[i] == '+') {
			if (flag == 1)
				result -= t;
			else
				result += t;
			t = 0;
		}
	}

	if (flag == 1)
		result -= t;
	else
		result += t;

	cout << result;
}