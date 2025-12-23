#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define loop(i, x, n) for (int i = x; i < n; i++)
/*
void helper()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> city(n);
    vector<ll> tower(m);
    loop(i, 0, n) cin >> city[i];
    loop(j, 0, m) cin >> tower[j];
    sort(city.begin(), city.end());
    sort(tower.begin(), tower.end());
    ll j = 0;
    ll ans = 0;
    loop(i, 0, n)
    {
        while (j + 1 < m && ((abs(tower[j + 1] - city[i]) <= abs(tower[j] - city[i]))))
        {        // distance of next tower from city <=
            j++; // distance of current tower from city;
        }

        ll d = abs(tower[j] - city[i]);

        ans = max(d, ans);
    }
    cout << ans << endl;
}
*/

int nearest_tower(ll t, vector<ll> &tower, vector<ll> &city)
{
    ll start = 0;
    ll end = tower.size() - 1;

    ll ans = tower.size(); // no tower found  (means: no tower >= city[t])

    while (start <= end)
    {
        // mid of the current search range
        ll mid = start + (end - start) / 2;

        if (tower[mid] >= city[t])
        {
            // tower is after (or exactly at) the city
            ans = mid;
            end = mid - 1; // search further left for a closer valid tower
        }
        else
        {
            // tower is before the city, so discard left half
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<ll> city(n);
    vector<ll> tower(m);

    for (int i = 0; i < n; i++)
    {
        cin >> city[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> tower[i];
    }

    // binary search needs sorted towers
    sort(tower.begin(), tower.end());

    ll ans = 0;

    for (int t = 0; t < n; t++)
    {
        // index of first tower >= city[t]
        ll k = nearest_tower(t, tower, city);

        ll nearest = LLONG_MAX;

        if (k < m)
        {
            // distance from the tower on the right
            nearest = abs(tower[k] - city[t]);
        }

        if (k > 0)
        {
            // distance from the tower on the left
            ll z = abs(tower[k - 1] - city[t]);
            nearest = min(z, nearest);
        }

        // we want the maximum among all minimum distances
        ans = max(ans, nearest);
    }
    // Complexity :- O(nlogm + mlogm )

    cout << ans << endl;
    return 0;
}
