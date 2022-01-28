#include<bits/stdc++.h>
using namespace std;

int f[13][3]; //f[i][j] is the number of way to make the j dice score i point
int prefixSum[13][3]; // prefixSum[i][j] is the number of way to make j dice score from [0,i] point

void naive_sol() //O(N^3)
{
    /* The naive solution O(N^3) with N = 6*/
    int res = 0;
    for(int x = 1 ; x <= 6 ; x++) // first dice
        for(int y = 1 ; y <= 6 ; y++) // second dice
            for(int z = 1 ; z <= 6 ; z++) // third dice
                if(x > y + z) // if first dice greater than the sum of the remaining dice
                    res += 1;
    cout << "The naive solution result: " << res << "/" << 6 * 6 * 6  << "=" << (double)res / (6 * 6 * 6) << endl;
}

void optimize_sol() //O(N)
{
    /* The complexity O(N) using dynamic programming instead O(N^3)
    because the next dice could be from 1 -> 6 so f[i][j] = f[i - 1][j - 1] + f[i - 2][j - 1] + ... + f[i - 6][j - 1]
    if we just loop to find the sum the complexity will be O(N^2)
    to optimize it we will have use prefix sum:
    1) prefixSum[i][j] = f[1][j] + f[2][j] + ... + f[i][j]
    = prefixSum[i - 1][j] + f[i][j]
    2) f[i][j] = f[i - 1][j - 1] + f[i - 2][j - 1] + ... + f[i - 6][j - 1]
    = (f[i - 1][j - 1] + f[i - 2][j - 1] + ... + f[1][j - 1]) - (f[i - 7][j - 1] + f[i - 8][j - 1] + ... + f[1][j - 1])
    = prefixSum[i - 1][j - 1] - prefixSum[i - 7][j - 1]*/
    f[0][0] = 1; // 0 dice so 0 score
    prefixSum[0][0] = 1;
    for(int i = 1 ; i <= 6 ; i++)
         prefixSum[i][0] = prefixSum[i - 1][0] + f[i][0];


    for(int j = 1 ; j <= 2 ; j++){
        for(int i = 1 ; i <= 6 ; i++){
            f[i][j] = prefixSum[i - 1][j - 1];
            if(i >= 7)
                f[i][j] -= prefixSum[i - 7][j - 1];
            prefixSum[i][j] = prefixSum[i - 1][j] + f[i][j];
        }
    }

    // calculate the result
    int res = 0;
    for(int i = 1 ; i <= 6 ; i++)
        res += prefixSum[i - 1][2]; // result plus the number of way to make two dice score point greater than i

    cout << "The optimize result: " << res << "/" << 6 * 6 * 6  << "="  << (double)res / (6 * 6 * 6) << endl;
}

int main()
{
    naive_sol();
    optimize_sol();
}
