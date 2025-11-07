#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<ll> prefix_sum(n);
    prefix_sum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        ll result;
        if (l > 0)
        {
            result = prefix_sum[r - 1] - prefix_sum[l - 1];
        }
        else
        {
            result = prefix_sum[r - 1];
        }
        cout << result << endl;
    }
    return 0;
}