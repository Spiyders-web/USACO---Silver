#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define loop(i, x, n) for (int i = x; i < n; i++)

void helper()
{
    string s;
    cin >> s;
    ll n = s.size();

    vector<vector<ll>> prefix(n + 1, vector<ll>(26, 0)); // Prefix for count of each occurance

    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i];

        int c = s[i] - 'a'; // converting string to its ascaii value;
        prefix[i + 1][c]++; // frequency of each element;
    }

    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;

        ll length = r - l + 1;

        if (length == 1) // if length == 1 that means its an irreducible anagram.
        {
            cout << "Yes" << endl;
            continue;
        }
        else if (length == 2)
        {
            if (s[l - 1] == s[r - 1]) // if first element is equal to last element it can be further reduced if l ==2
            {
                cout << "No" << endl;
                continue;
            }
            else
            {
                cout << "Yes" << endl;
            }
        }

        ll distinct = 0;
        for (int c = 0; c < 26; c++)
        {
            ll cnt = prefix[r][c] - prefix[l - 1][c];
            if (cnt > 0)
                distinct++; // count of disticnt elements;
        }
        if (s[l - 1] != s[r - 1] || distinct >= 3) // of first and last are different || count of distinct is >3 meaning
                                                   // atleast one combination can be formed that doesnt match the requirement.

        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}

// Complexity :- O(q*n);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //  int t;
    //  cin >> t;
    //  while (t--) {
    helper();
    //}
    return 0;
}