#include <vector>
#include <iostream>
#include <cmath>
using namespace std;


int solution(vector<int> nums) {
    int answer = 0;

    int len = nums.size();
    int i1 = 0, i2 = 1, i3 = 2;
    while (true)
    {
        int sum = nums[i1] + nums[i2] + nums[i3];
        
        // 소수인지 판별
        bool isPrime = true;
        for (int i = 2; i <= sqrt(sum); i++)
            if (sum % i == 0) {
                isPrime = false;
                break;
            }
        
        // 소수일 경우
        if (isPrime == true) {
            answer++;
            cout << '[' << nums[i1] << ',' << nums[i2] << ',' << nums[i3] << "]를 사용해서 " << sum << "을 만들 수 있습니다." << endl;
        }
        
        // 다음으로
        i3++;
        if (i3 == len) {
            i2++;
            i3 = i2 + 1;
            if (i3 == len) {
                i1++;
                i2 = i1 + 1;
                i3 = i2 + 1;
                if (i3 == len) break;
            }
        }
    }

    return answer;
}