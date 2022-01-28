#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
bool cnt[N];

void input()
{
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter " << n << " elements of the array: " << endl;
    for(int i = 1 ; i <= n ; i++) {
        int val;
        cin >> val;
        cnt[val] = true; // mark that this value has appeared
    }
}

void solve()
{
    for(int i = 0 ; i <= n ; i++)
        if(!cnt[i]){
            cout << "The missing number is " << i << endl;;
            break;
        }
}

int main()
{
    input();
    solve();
}
