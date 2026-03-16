#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int N, sixnine, mx = -1;
    int arr[10] = {};
    
    cin >> N;
    while (N > 0) {
        arr[N % 10]++;
        N /= 10;
    }
    sixnine = (arr[6] + arr[9] + 1) / 2;
    arr[6] = sixnine;
    arr[9] = sixnine;
    
    for (int i=0; i<10; i++)
        if (arr[i] > mx) mx = arr[i];
    cout << mx << '\n';
    
    return 0;
}