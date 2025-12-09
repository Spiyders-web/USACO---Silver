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

    ll start = 0;
    ll end = 0;
    ll sum = arr[0];

    while (start < n && end < n)
    {

        if (sum == target) // if the sum is equal to target; cout<<elements[l,r];
        {
            for (int i = start; i <= end; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            return;
        }

        if (sum < target) // if sum if smaller,expand the window.
        {
            end++;
            if (end < n)
                sum += arr[end]; // add the element
        }
        else
        {
            sum -= arr[start]; // if bigger shrink the window.
            start++;           // subtract the element
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    helper();

    return 0;
}