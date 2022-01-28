#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n , m;
int arrF[N] , arrS[N] , arrM[2 * N];

void input()
{
    // input first array
    cout << "Enter the size of the first sorted array: ";
    cin >> m;
    cout << "Enter the " << m << " elements of the first array in sorted order: " << endl;
    for(int i = 1 ; i <= m ; i++)
        cin >> arrF[i];

    // input second array
    cout << "Enter the size of the second sorted array: ";
    cin >> n;
    cout << "Enter the " << n << " elements of the second array in sorted order: " << endl;
    for(int i = 1 ; i <= n ; i++)
        cin >> arrS[i];

}

void solve()
{
    // solve by two pointer
    int cnt = 0;
    for(int i = 1 , j = 1 ; i <= m || j <= n ; i++){
        while(j <= n && (i > m || arrF[i] > arrS[j])){ // if the next element of the second array is smaller than the first array
            arrM[++cnt] = arrS[j]; // take j as the next element in the sorted array
            j++;
        }
        arrM[++cnt] = arrF[i]; // take i as the next element in the sorted array
    }

    // print result
    int sz = n + m;
    if(sz % 2 == 0)
        cout << (double)(arrM[sz / 2] + arrM[sz / 2 + 1]) / 2;
    else
        cout << arrM[sz / 2 + 1];
}

int main()
{
    input();
    solve();
}
