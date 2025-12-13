#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define loop(i, x, n) for (int i = x; i < n; i++)

void helper()
{
    ll n, target;
    cin >> n >> target;

    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i + 1;
    }

    sort(v.begin(), v.end());

    for (ll i = 0; i < n; i++)
    {
        ll start = i + 1;
        ll end = n - 1;

        while (start < end)
        {
            ll sum = v[i].first + v[start].first + v[end].first;

            if (sum == target)
            {
                cout << v[i].second << " "
                     << v[start].second << " "
                     << v[end].second << endl;
                return;
            }
            else if (sum < target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}
// Time complexity :- O(n^2);
// Space complexity: - O(n);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    helper();

    return 0;
}