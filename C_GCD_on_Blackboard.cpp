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

    vector<ll> prefix(n);       // prefix arr of size(n);
    vector<ll> suffix(n);       // suffix arr of size(n);
    prefix[0] = arr[0];         //
    suffix[n - 1] = arr[n - 1]; // suffix of last element is the last element itself.

    for (int i = 1; i < n; i++)
    {
        prefix[i] = __gcd(prefix[i - 1], arr[i]); // taking the gcd elements as gcd(gcd(a1,a2,a3,......,an));
    }
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = __gcd(suffix[i + 1], arr[i]);
    }

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        ll g;
        if (i == 0)
        {
            g = suffix[1]; // if i==0 we want gcd of all except first element so suffix[1].
        }
        else if (i == n - 1)
        {
            g = prefix[n - 2]; // if i== n-1 we want gcd of all except last element of prefix[n-2].
        }
        else
        {
            g = __gcd(prefix[i - 1], suffix[i + 1]); // else check gcd of all elements before and after that particular element.
        }
        ans = max(ans, g);
    }

    cout << ans << endl;
}

/*                 ************
//check indexing before submission
// complexity :- O(n);
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    helper();
    return 0;
}
