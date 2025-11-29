#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
        prefix_sum[i] = (prefix_sum[i - 1] + arr[i - 1]) % 7; // Storing the prefix_sum % 7.

    vector<ll> first_index(7, -1), last_index(7, -1); // element 'x' first seen at index 'i' and last seen at lets say 'j'
    for (int i = 0; i <= n; i++)
    /*
    Mathematically :-
    lets say sum of elements from i to k gives you a reminder 3 and from i to f also gives you are reminder '3'.
    What it means?
    It means that elements from index (k+1) to (f-k) is divisible by 7.

    */
    {
        if (first_index[prefix_sum[i]] == -1)
            first_index[prefix_sum[i]] = i;
        last_index[prefix_sum[i]] = i;
    }

    ll maxm = 0;
    for (int i = 0; i < 7; i++)
        if (first_index[i] != -1)
            maxm = max(maxm, last_index[i] - first_index[i]);

    cout << maxm << endl;
}
