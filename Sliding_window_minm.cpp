#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define loop(i, x, n) for (int i = x; i < n; i++)
void helper()
{
    ll n;
    cin >> n;

    ll k;
    cin >> k;

    vector<ll> arr(n);
    loop(i, 0, n) cin >> arr[i];

    deque<ll> q; // store indices
    vector<ll> ans;

    for (int i = 0; i < n; i++)
    {

        // Remove all bigger elements from the back
        while (!q.empty() && arr[q.back()] >= arr[i])
        {
            q.pop_back();
        }

        // Push current index
        q.push_back(i);

        // Remove elements that are outside the window
        int L = i - k + 1; // left boundary of current window
        if (!q.empty() && q.front() < L)
        {
            q.pop_front();
        }

        // Record answer once window is of size k
        if (i >= k - 1)
        {
            ans.push_back(arr[q.front()]);
        }
    }

    // print results
    for (auto x : ans)
        cout << x << " ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    helper();

    return 0;
}