#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if (n > s)
        answer = { -1 };
    else {
        for (int i = 0; i < n; i++)
            answer.push_back(s / n);
        if (s % n != 0) {
            for (int i = s % n; i; i--)
            {
                answer[answer.size() - i]++;
            }
        }
    }
    
    return answer;
}