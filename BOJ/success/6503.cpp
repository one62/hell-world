/* 백준 6503 망가진 키보드
	최대 m개의 서로 다른 문자로 이루어진 가장 긴 부분 문자열의 길이
	공백 포함
	0이면 종료
*/
#include <iostream>
#include <string>

int main() {
	int m;
	std::cin >> m;
	while (m != 0)
	{
		std::cin.ignore();
		std::string s;
		std::getline(std::cin, s, '\n');

		int start = 0, end = 0;
		int count = 0, answer = 0;

		int arr[256] = {};
		
		while (end < s.length())
		{
			if (count == m) {
				if (arr[s[end]] > 0) {
					arr[s[end]]++;
					end++;
				} else {
					arr[s[start]]--;
					if (arr[s[start]] == 0) {
						count--;
					}
					start++;
				}
			} else {
				if (arr[s[end]] == 0) count++;
				arr[s[end]]++;
				end++;
			}
			answer = std::max(answer, end - start);
		}

		std::cout << answer << '\n';
		std::cin >> m;
	}
}