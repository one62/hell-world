#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

int x[103];
int y[103];

int dis(int a, int b){
    return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        //int* x = new int[n + 2];
        //int* y = new int[n + 2];
        for (int i = 0; i < n + 2; i++) cin >> x[i] >> y[i];
        int pos = 0;
        bool visited[n + 2] = {};
        stack<int> stack;
        stack.push(pos);
        while(!stack.empty())
        {
            pos = stack.top();
            stack.pop();
            if (pos == n + 1) break;
            for (int i = 1; i < n + 2; i++)
            {
                if (!visited[i] && dis(pos, i) <= 1000) {
                    stack.push(i);
                    visited[i] = true;
                }
            }
        }
        if (pos == n + 1) cout << "happy" << '\n';
        else cout << "sad" << '\n';
    }
}