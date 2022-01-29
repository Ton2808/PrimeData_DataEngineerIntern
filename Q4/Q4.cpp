#include<bits/stdc++.h>
using namespace std;

long long n;

int main()
{
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter " << n << " elements of the array: " << endl;
    long long sum = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        long long val;
        cin >> val;
        sum += val;
    }
    cout << "The missing number is: " << n * (n + 1) / 2 - sum << endl;
}
