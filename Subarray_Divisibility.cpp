#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define loop(i, x, n) for (int i = x; i < n; i++)

void helper()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    loop(i, 0, n) cin >> arr[i];

    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = (prefix[i - 1] + arr[i - 1]) % n;
        if (prefix[i] < 0)
            prefix[i] += n; // if the prefix_sum is <0 to get it back on track we simply add n to it
    }
    vector<ll> frequency(n, 0);
    for (int i = 0; i <= n; i++)
    {
        frequency[prefix[i]]++;
    }
    ll ans = 0;
    loop(r, 0, n)
    {
        ll f = frequency[r]; // say some frequency appears x times so we have to chose any two out of x frequencies of prefix;

        ans += f * (f - 1) / 2; // so n C r;
    }
    cout << ans << endl;
}

// complexity :- O(n);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    helper();

    return 0;
}