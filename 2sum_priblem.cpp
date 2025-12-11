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

    sort(arr.begin(), arr.end()); // sorting takes O(nlogn) time;

    ll start = 0;
    ll end = n - 1;

    while (start < end)
    {

        ll sum = arr[start] + arr[end];   // calculate sum;

        if (sum == target)   // if equal cout elements.
        {
            cout << arr[start] << " " << arr[end] << endl;
            return;
        }

        if (sum < target)   // if target is greater than the sum increment start;
        {
            start++;
        }
        else       // sum if greater decrement end;
        {
            end--; 
        }
    }
    cout << "No SOlution" << endl;
}

  //Time complexity :- O(nlogn);



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    helper();

    return 0;
}


/* void helper2() {
    ll n;
    cin >> n;

    vector<ll> arr(n);
    loop(i, 0, n) cin >> arr[i];

    ll target;
    cin >> target;

    sort(arr.begin(), arr.end());

    for (ll i = 0; i < n; i++) {

        ll need = target - arr[i];

        // binary search for need in arr[i+1 ... n-1]
        ll low = i + 1;
        ll high = n - 1;

        while (low <= high) {
            ll mid = (low + high) / 2;

            if (arr[mid] == need) {
                cout << arr[i] << " " << arr[mid] << endl;
                return;
            }
            else if (arr[mid] < need) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }

    cout << "no solution" << endl;
}
*/

//Complexity :- O(nlogn);
//Approach :- Binary Search;