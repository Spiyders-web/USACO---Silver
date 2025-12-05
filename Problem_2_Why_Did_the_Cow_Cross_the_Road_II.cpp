#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define loop(i, x, n) for (int i = x; i < n; i++)

void helper()
{
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    ll n, k, b;
    cin >> n >> k >> b;

    vector<ll> arr(n, 0);
    ll current = 0;
    ll ans = 0;

    loop(i, 0, b)
    {
        ll x;
        cin >> x;
        arr[x - 1] = 1;
    }
    loop(i, 0, k)
    {
        current += arr[i];
    }

    ans = current;

    for (int i = k; i < n; i++)
    {
        current += arr[i];
        current -= arr[i - k];
        ans = min(ans, current);
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    helper();

    return 0;
}