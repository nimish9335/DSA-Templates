#include <bits/stdc++.h>
using namespace std;

vector<long long> buildPrefixSum0Indexed(const vector<long long>& arr)
{
    int n = arr.size();
    vector<long long> prefix(n);

    prefix[0] = arr[0];

    for(int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i-1] + arr[i];
    }

    return prefix;
}

long long rangeSum0Indexed(const vector<long long>& prefix, int L, int R)
{
    if(L == 0)
        return prefix[R];

    return prefix[R] - prefix[L-1];
}

vector<long long> buildPrefixSum1Indexed(const vector<long long>& arr)
{
    int n = arr.size();
    vector<long long> prefix(n + 1, 0);

    for(int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i-1] + arr[i-1];
    }

    return prefix;
}

long long rangeSum1Indexed(const vector<long long>& prefix, int L, int R)
{
    return prefix[R + 1] - prefix[L];
}

vector<long long> buildArrayFromDifference(const vector<long long>& diff)
{
    int n = diff.size();
    vector<long long> arr(n);

    arr[0] = diff[0];

    for(int i = 1; i < n; i++)
    {
        arr[i] = arr[i-1] + diff[i];
    }

    return arr;
}

vector<vector<long long>> build2DPrefixSum(const vector<vector<long long>>& matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<long long>> prefix(n, vector<long long>(m, 0));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            long long top = (i > 0) ? prefix[i-1][j] : 0;
            long long left = (j > 0) ? prefix[i][j-1] : 0;
            long long diag = (i > 0 && j > 0) ? prefix[i-1][j-1] : 0;

            prefix[i][j] = matrix[i][j] + top + left - diag;
        }
    }

    return prefix;
}

long long rangeSum2D(
    const vector<vector<long long>>& prefix,
    int r1, int c1,
    int r2, int c2)
{
    long long total = prefix[r2][c2];
    long long up = (r1 > 0) ? prefix[r1-1][c2] : 0;
    long long left = (c1 > 0) ? prefix[r2][c1-1] : 0;
    long long diag = (r1 > 0 && c1 > 0) ? prefix[r1-1][c1-1] : 0;

    return total - up - left + diag;
}

int main()
{

}
