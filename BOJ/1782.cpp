#include <iostream>
using namespace std;

bool IsMirrorNum(long long num)
{
	string str = to_string(num);
	for (int i = 0; i < str.length() / 2; i++)
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == '8')
		{
			if (str[str.length() - i - 1] != str[i])
				return false;
		}
		else if (str[i] == '2')
		{
			if (str[str.length() - i - 1] != '5')
				return false;
		}
		else if (str[i] == '5')
		{
			if (str[str.length() - i - 1] != '2')
				return false;
		}
		else
			return false;
	}
	if (str.length() % 2 == 1) {
		int mid = str.length() / 2;
		if (str[mid] != '0' && str[mid] != '1' && str[mid] != '8') return false;
	}
	return true;
}

int main()
{
	long long A, B;
	cin >> A >> B;

	long long count = 0;
	for (long long i = A; i <= B; i++)
	{
		if (IsMirrorNum(i)) count++;
	}
	cout << count;
}