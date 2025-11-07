#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> arr(n, vector<ll>(m, 0));
    vector<vector<ll>> prefix_sum(n + 1, vector<ll>(m + 1, 0));

    // input matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    // Complexity :- O(n*m);

    //  prefix sum matrix
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            prefix_sum[i][j] = arr[i - 1][j - 1] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
        }
    }

    // Complexity :- O(n*m);

    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    // l and r are 1-based and inclusive
    ll result1 = prefix_sum[l1][r1] - prefix_sum[l1 - 1][r1] - prefix_sum[l1][r1 - 1] + prefix_sum[l1 - 1][r1 - 1];

    ll result2 = prefix_sum[l2][r2] - prefix_sum[l2 - 1][r2] - prefix_sum[l2][r2 - 1] + prefix_sum[l2 - 1][r2 - 1];

    ll total = result1 + result2;
    // Compexity = o(1);
    cout << result2 << endl;
}

// Overall complexity :- O(n*m);
