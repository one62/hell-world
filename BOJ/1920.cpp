#include <iostream>
#include <algorithm>
using namespace std;

int biSearch(int N, int* nA, int m){
    int start = 0;
    int end = N;
    int mid;
    while(start <= end)
    {
        mid = (start + end) / 2;
        if (nA[mid] == m) return 1;
        if (nA[mid] < m) start = mid + 1;
        else end = mid - 1;
    }
    return 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    int* nA = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> nA[i];
    }
    sort(nA, nA + N);
    int M;
    cin >> M;
    int* mA = new int[M];
    for (int i = 0; i < M; i++)
    {
        cin >> mA[i];
    }
    //입력 완료
    for (int i = 0; i < M; i++)
    {
        cout << biSearch(N, nA, mA[i]) << '\n';
    }
}