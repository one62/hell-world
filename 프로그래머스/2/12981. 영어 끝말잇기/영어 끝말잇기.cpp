#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    int i;
    for (i = 1; i < words.size(); i++)
    {
        string now = words[i];
        string before = words[i - 1];
        
        if (now[0] != before[before.length() - 1]) break;
        
        int flag = 0;
        for (int j = 0; j < i; j++)
        {
            if (!now.compare(words[j])) {
                cout << "p1" << endl;
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    
    cout << i << endl;
    
    if (i == words.size()) answer = {0, 0};
    else {
        i++;
        if (i % n == 0) {
            answer.push_back(n);
            answer.push_back(i / n);
        }
        else {
            answer.push_back(i % n);
            answer.push_back(i / n + 1);
        }
    }
    
    return answer;
}