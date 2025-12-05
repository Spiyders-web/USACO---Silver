#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define loop(i, x, n) for (int i = x; i < n; i++)

void helper()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;

    vector<ll> arr(n);

    loop(i, 0, n)
    {
        arr[i] = (s[i] - '0') - 1; // conversion of string to int and -1 for 0 based indexing.
    }
    // map<ll,ll> cnt;
    unordered_map<ll, ll> cnt; // just for the sake of seeking the runtime difference from naked eye. HAHA!!!
    ll prefix = 0;
    ll ans = 0;

    cnt[0] = 1; // FIX: this must be 1, not 0

    ll target = 0; // target is the sum for which we need to find the value; in this case its zero.

    for (int i = 1; i <= n; i++)
    {
        prefix += arr[i - 1];
        ans += cnt[prefix - target];
        cnt[prefix]++;
    }

    cout << ans << endl;
}

// complexity :- O(nlogn)  ordered map or unordered map can also be used reducing time complexity to O(n).

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        helper();
    }
    return 0;
}

/*
Observarion  and some maths :-
we need to find no of good subarrays.

such that sum of elemets uptil index = no of elemets in the subarray summinng upto n.

Σ(ai) = (r-l+1)

breaking it down  tp every single element
Σ(ai) - Σ(1) from l to r.  basic maths you know.

ans -1 for 0 based indexing ofcourse.
*/
