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
    vector<ll> b(n);

    loop(i, 0, n) cin >> arr[i];

    stack<ll> s; // store values

    for (int i = 0; i < n; i++)
    {

        while (!s.empty() && s.top() >= arr[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            b[i] = -1; // no smaller element on left
        }
        else
        {
            b[i] = s.top(); // nearest smaller to left
        }

        s.push(arr[i]);
    }

    // print b for verification
    loop(i, 0, n) cout << b[i] << " ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    helper();

    return 0;
}