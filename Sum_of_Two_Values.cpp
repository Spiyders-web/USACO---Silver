#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define loop(i, x, n) for (int i = x; i < n; i++)

/* void helper()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> sum;
    ll target;
    cin >> target;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        sum.push_back({temp, i});
    }
    sort(sum.begin(), sum.end());
    ll start = 0;
    ll end = n - 1;

    while (end > start)
    {
        ll temp = sum[start].first + sum[end].first;
        if (temp == target)
        {
            cout << sum[start].second + 1 << " " << sum[end].second + 1 << endl;
            return;
        }
        else if (temp < target)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
*/
// Time Complexity :- O(nlogn);
// Space Complexity :- O(n);
/*

ll binary_search(ll e, ll n, vector<ll> &arr)
{

    ll start = 0;
    ll end = n - 1;

    while (start <= end)
    {
        ll mid = start + (end - start) / 2;
        if (e == arr[mid])
        {
            return mid;
        }
        else if (arr[mid] < e)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // helper();

    ll n;
    ll target;
    cin >> n >> target;

    vector<ll> arr(n);
    loop(i, 0, n)
    {
        cin >> arr[i];
    }


    loop(i, 0, n)
    {
        ll element = target - arr[i];

        ll r = binary_search(element, n, arr);

        if (r != -1 && r != i)
        {
            // if (r != -1)
            {
                cout << r + 1 << " " << i + 1 << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}

// Time complexity - O(n(logn));
// SPace Complexity :- O(n);



  But this solution wont work because for one to apply for binary search the array that we are working on must be sorted
  and thinking of sorting the array then the original structure of the array is void. SO NO!!!!!!

*/

// Lets try hash map

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll target;
    cin >> target;

    unordered_map<ll, ll> mp;

    loop(i, 0, n)
    {
        ll x;
        cin >> x;
        ll remaining = target - x;

        if (mp.count(remaining))
        {
            cout << mp[remaining] + 1 << " " << i + 1 << endl;
            return 0;
        }

        if (!mp.count(x))
        {
            mp[x] = i;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

// Time complexity :- O(n);
// Space Complexity :- o(n);

/*
 In this approach we are creating a map where we store the value with it index.
 lets say we have element x and we have a target t
 so the remaining value we need to search for is t-x;

 now we check that is the remaining value is present in the map or not if present the count will be one else the count
 will be zero because duplicates are not allowed in map.
 If present return the index of the remaining from map and the index of current element.

 if not present the store the x with its index in map and check futher until pair found.

 if not found till n print impossible.

Why un-ordered map?
Because uses hash map so less time in finding and order here is not necessary as the problem suggests there can be multiple pair.
had i used ordered map the search time would have been O(n(logn)) because uses bst to be precise self balancing bst,
Also known as red black tree if am not mistaken!!


*/