#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define loop(i, x, n) for (int i = x; i < n; i++)

void helper()
{
    ll n;
    cin >> n;
    ll target;
    cin >> target;
    vector<ll> arr(n);
    loop(i, 0, n)
    {
        cin >> arr[i];
    }

    ll start = 0, sum = 0, count = 0;
    for (ll end = 0; end < n; end++)
    {
        sum += arr[end]; // sliding window
        while (sum > target && start <= end)
        {
            sum -= arr[start];
            start++;
        }
        if (sum == target)
            count++;
    }
    cout << count << endl;
}

// Time complexity :- O(n);
// Space Complexity - O(n);
// the array is non-negative so was able to use two pinter sliding window else would have used hash map as value might decrease also with
// slide of window.
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    helper();

    return 0;
}