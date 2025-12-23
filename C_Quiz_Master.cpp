#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define loop(i, x, n) for (int i = x; i < n; i++)

void add_element(ll x, ll m, ll &divisors, vector<ll> &cnt)
{
    for (ll i = 1; i * i <= x; i++) //         
    {
        if (x % i == 0)
        {
            ll div1 = i;
            ll div2 = x / i;

            if (div1 <= m)
            {
                if (cnt[div1] == 0)
                    divisors++;
                cnt[div1]++;
            }

            if (div1 != div2 && div2 <= m)
            {
                if (cnt[div2] == 0)
                    divisors++;
                cnt[div2]++;
            }
        }
    }
}
// O(N)
void remove_element(ll x, ll m, ll &divisors, vector<ll> &cnt)
{
    for (ll i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            ll div1 = i;
            ll div2 = x / i;

            if (div1 <= m)
            {
                cnt[div1]--;
                if (cnt[div1] == 0)
                    divisors--;
            }

            if (div1 != div2 && div2 <= m)
            {
                cnt[div2]--;
                if (cnt[div2] == 0)
                    divisors--;
            }
        }
    }
}

/*void helper()
{
    ll n;
    cin >> n;
    ll m;
    cin >> m;

    vector<ll> smartness(n);
    loop(i, 0, n) cin >> smartness[i];

    sort(smartness.begin(), smartness.end());

    ll divisors = 0;
    vector<ll> cnt(m + 1, 0);

    ll start = 0;
    ll ans = 1e9 + 18;

    for (ll end = 0; end < n; end++)
    {
        add_element(smartness[end], m, divisors, cnt);

        while (divisors == m && start <= end)
        {
            ll difference = smartness[end] - smartness[start];
            ans = min(ans, difference);

            remove_element(smartness[start], m, divisors, cnt);
            start++;
        }
    }

    if (ans == 1e9 + 18)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
*/
// TIme complexity :- O(n(logn)Sqrt(max(A)));
bool possible(vector<ll> &smartness, ll mid, ll m)
{
    ll n = smartness.size();
    ll start = 0;

    vector<ll> cnt(m + 1, 0);
    ll divisors = 0;

    for (ll end = 0; end < n; end++)
    {
        add_element(smartness[end], m, divisors, cnt);

        while (smartness[end] - smartness[start] > mid)
        {
            remove_element(smartness[start], m, divisors, cnt);
            start++;
        }

        if (divisors == m)
            return true;
    }

    return false;
}

void helper()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> smartness(n);
    loop(i, 0, n)
            cin >>
        smartness[i];

    sort(smartness.begin(), smartness.end());

    ll ans = -1;
    ll start = 0;
    ll end = smartness[n - 1] - smartness[0];

    while (start <= end)
    {
        ll mid = start + (end - start) / 2;

        if (possible(smartness, mid, m))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << ans << endl;
}

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