//백준 1782번: 거울 숫자
#include <iostream>
#include <cmath>
using namespace std;

//l과 r 사이의 거울 숫자 개수를 리턴하는 함수. l과 r은 같은 자릿수.
int f(long long l, long long r) {
	
}

int main() {
	long long a, b;
	cin >> a >> b;
	/*
	반만 검사하면 된다
	짝수 자릿수면 그 절반만큼의 자릿수에 01258 아무거나
	홀수 자릿수면 그 절반만큼의 자릿수에 01258 아무거나
	+ 가운데엔 018
	맨 앞, 뒤엔 0 안 됨
	*/

	string strA = to_string(a);
	string strB = to_string(b);
	int count = 0;
	if (strA.length() != strB.length()) {
		count += f(a, pow(10, strA.length()) - 1);
		count += f(pow(10, strB.length() - 1), b);
	}
	else {
		count += f(a, b);
	}
	for (int i = strA.length() + 1; i < strB.length(); i++)
	{
		int t = 4;
		for (int j = 1; j < i / 2; j++)
		{
			t *= 5;
		}
		if (i % 2 != 0) {
			t *= 3;
		}
		count += t;
	}
	cout << count;
}