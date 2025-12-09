#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define loop(i, x, n) for (int i = x; i < n; i++)

void helper()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    loop(i, 0, n)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    ll x = arr[0];

    vector<ll> reminders(n);
    for (int i = 0; i < n; i++)
    {
        reminders[i] = (arr[i] - x) % m;
    }
    ll ops = 0;
    for (int i = 0; i < n; i++)
    {

        ll reminder = reminders[i];
        ops += min(reminder, m - reminder);
    }

    cout << ops << endl;
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