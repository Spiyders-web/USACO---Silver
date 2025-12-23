#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define loop(i, x, n)

void helper()
{
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n;
    long long k;
    cin >> n >> k;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    // len[i] = size of one valid case starting at i
    vector<int> len(n);
    int r = 0;
    for (int l = 0; l < n; l++)
    {
        while (r < n && arr[r] - arr[l] <= k)
            r++;
        len[l] = r - l;
    }

    // time_machine[i] = best single case starting at or after i
    vector<int> time_machine(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
        time_machine[i] = max(time_machine[i + 1], len[i]);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int first = len[i];
        int second = time_machine[i + len[i]];
        ans = max(ans, first + second);
    }

    cout << ans << endl;
}

// Time complexity :- O(nlogn);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    helper();

    return 0;
}