#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    int* m = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> m[i];
    }
    int ans = 0;
    int t = 0;
    for (int i = 1; i < N; i++)
    {
        if (m[t] < m[i]) {
            t = i;
        }
        else {
            ans = max(ans, i - t);
        }
    }
    cout << ans;
}