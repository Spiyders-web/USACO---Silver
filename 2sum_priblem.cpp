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

    ll target;
    cin >> target;

    sort(arr.begin(), arr.end());

    ll start = 0;
    ll end = n - 1;

    while (start < end)
    {

        ll sum = arr[start] + arr[end];

        if (sum == target)
        {
            cout << arr[start] << " " << arr[end] << endl;
            return;
        }

        if (sum < target)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    cout << "No SOlution" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    helper();

    return 0;
}