#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define loop(i, x, n) for (int i = x; i < n; i++)

void helper()
{
    ll n;
    cin >> n;
    ll s;
    cin >> s;
    vector<ll> arr(n);
    loop(i, 0, n) cin >> arr[i];
    ll prefix = 0;
    ll ans = 0;

    //  map<ll, ll> cnt;
    unordered_map<ll, ll> cnt;
    cnt[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        prefix += arr[i - 1]; // lets say we have a sum x; and we want to achive sum s; so total times we can achive
                              //  s is count of (x- s) times;
        ans += cnt[prefix - s];
        cnt[prefix]++;
    }

    cout << ans << endl;
}
// complexity :- O(n logn); because map uses bst;
// O(n) if used on unordered map

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    helper();

    return 0;
}