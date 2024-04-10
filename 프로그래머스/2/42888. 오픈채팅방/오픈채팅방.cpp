#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    map<string, string> uid_table;
    
    for (int i = 0; i < record.size(); i++)
    {
        istringstream iss(record[i]);
        string type, uid, nickname; 
        getline(iss, type, ' ');
        if (type == "Leave") continue;
        getline(iss, uid, ' ');
        getline(iss, nickname, ' ');
        
        uid_table[uid] = nickname;
    }
    
    for (int i = 0; i < record.size(); i++)
    {
        string str;
        istringstream iss(record[i]);
        string type, uid, nickname; 
        getline(iss, type, ' ');
        getline(iss, uid, ' ');
        nickname = uid_table[uid];
        if (type == "Change") continue;
        else if (type == "Enter")
            str = nickname + "님이 들어왔습니다.";
        else if (type == "Leave")
            str = nickname + "님이 나갔습니다.";
        answer.push_back(str);
    }
    
    return answer;
}