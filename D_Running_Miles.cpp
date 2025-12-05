#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void helper()
{
    int n;
    cin >> n;
    vector<int> beauty(n);
    for (int i = 0; i < n; i++)
        cin >> beauty[i];

    vector<int> best_left(n), best_right(n);

    // best_left[i] = max(b[j] + j) for j <= i
    for (int i = 0; i < n; i++)
        best_left[i] = beauty[i] + i; // (i1+i2+i3) - (k-l)
    for (int i = 1; i < n; i++)
        best_left[i] = max(best_left[i], best_left[i - 1]);

    // best_right[i] = max(b[j] - j) for j >= i
    for (int i = 0; i < n; i++)
        best_right[i] = beauty[i] - i;
    for (int i = n - 2; i >= 0; i--)
        best_right[i] = max(best_right[i], best_right[i + 1]);

    int ans = 0;
    // Middle sight must be at least 1..n-2
    for (int m = 1; m < n - 1; m++)
    {
        ans = max(ans, beauty[m] + best_left[m - 1] + best_right[m + 1]);
    }

    cout << ans << "\n";
}
// Complexity - O(n);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        helper();
}
