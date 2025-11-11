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
    vector<ll> suffix_sum(n);
    vector<ll> suffix_min(n);

    loop(i, 0, n) cin >> arr[i];

    suffix_sum[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix_sum[i] = suffix_sum[i + 1] + arr[i];
    }
    suffix_min[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        ll k = min(arr[i], suffix_min[i + 1]);
        suffix_min[i] = k;
    }

    ll best_k = -1;
    double best_avg = -1e5;

    for (int k = 1; k < n - 1; k++)
    {
        double avg = -1;

        ll t = (suffix_sum[k] - suffix_min[k]);
        ll d = n - k - 1;
        avg = t / d;
        if (avg > best_avg)
        {
            best_avg = avg;
            best_k = k;
        }
    }
    cout << best_k << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    helper();

    return 0;
}



//