//아니메컵 1쿨_치노의 라떼 아트 (Easy)
#include <iostream>
#include <string>
using namespace std;

string str[11];

bool isH(int r, int c){
    string dot;
    for(int i = 0; i < c; i++)
    {
        dot.append(".");
    }
    int i = 0;
    if (str[0] == dot) {
        for (;str[i] == dot; i++);
        if (i >= r) return false;
    }
    int i1 = i;//첫번째 .이아닌 문자열 시작
    for (;str[i] == str[i+1]; i++); i++;
    int i2 = i;//두번째 .이아닌 문자열 시작
    for (;str[i] == str[i+1]; i++); i++;
    int i3 = i;//세번째 .이아닌 문자열 or r
    if (i < r) {
        for (; i < r; i++)
        {
            if (str[i] != dot) return false;
        }
    }
    int n = i3 - i1;
    int i1c = 0, i2c = 0;
    for (i = 0; i < c; i++)
    {
        if (str[i1][i] == '#') {
            i1c++;
        } else if (i < c - 1 && str[i1][i+1] == '#' && i1c) return false;
        if (str[i2][i] == '#') {
            i2c++;
        } else if (i < c - 1 && str[i2][i+1] == '#' && i2c) return false;
    }
    int m;
    if (i1c == n) {
        m = i1c - i2c; if (i3 - i2 != m) return false;
    }
    else if (i2c == n) {
        m = i2c - i1c; if (i2 - i1 != m) return false;
    }
    else return false;
    for (i = 0; i < c && str[i1][i] == '.' && str[i2][i] == '.'; i++);
    if (i >= c) return false;
    if (str[i1][i] == '#' && str[i2][i] == '#') return true;
    for (; i < c && (str[i1][i] == '#' || str[i2][i] == '#'); i++);
    if (str[i1][i-1] == '#' && str[i2][i-1] == '#') return true;
    else return false;
}

int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int r, c;
        cin >> r >> c;
        for (int i = 0; i < r; i++)
        {
            cin >> str[i];
        }
        cout << isH(r, c) << '\n';
    }
}