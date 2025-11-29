#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define loop(i, x, n) for (int i = x; i < n; i++)

void helper()
{

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n);
    loop(i, 0, n) cin >> arr[i];

    vector<ll> pref_1(n + 1, 0);
    vector<ll> pref_2(n + 1, 0);
    vector<ll> pref_3(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        pref_1[i] = pref_1[i - 1];
        pref_2[i] = pref_2[i - 1];
        pref_3[i] = pref_3[i - 1];

        if (arr[i - 1] == 1)
            pref_1[i]++;
        if (arr[i - 1] == 2)
            pref_2[i]++;
        if (arr[i - 1] == 3)
            pref_3[i]++;
    }

    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        ll x = pref_1[r] - pref_1[l - 1];
        ll y = pref_2[r] - pref_2[l - 1];
        ll z = pref_3[r] - pref_3[l - 1];

        cout << x << " " << y << " " << z << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    helper();

    return 0;
}