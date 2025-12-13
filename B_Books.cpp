#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define loop(i, x, n) for (int i = x; i < n; i++)

void helper()
{
    int n;
    long long target;
    cin >> n >> target;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0;
    long long sum = 0;
    int ans = 0;

    for (int r = 0; r < n; r++)
    {
        sum += a[r];
        while (sum > target && l <= r)
        {
            sum -= a[l];
            l++;
        }
        ans = max(ans, r - l + 1);
    }

    cout << ans << '\n';
}
//Time Complexity :- O(n);
//space complexity :- O(1);

// But I think this problem can be solved using binary search also.


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    helper();

    return 0;
}