#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define loop(i, x, n) for (int i = x; i < n; i++)
/*
void helper()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> characters(256, 0); // 256 because input has both capital and small characterrs so to counter that.
    ll noc = 0;                    // no_of_characters
    for (char c : s)               // firstly count the no of unique characters in the string.
    {
        if (characters[c] == 0)
        {
            characters[c]++;
            noc++;
        }
    }

    unordered_map<char, ll> frequency;
    ll l = 0;
    ll available = 0; // no of unique_available_characters [l,r].
    ll ans = n;       // for say we need to go into every flat.

    for (int r = 0; r < n; r++)
    {
        frequency[s[r]]++; // count the frequency  of every character

        if (frequency[s[r]] == 1) // if frequency ==1 means character is unique.
        {
            available++;
        }
        while (available == noc) // if no of availabble and unique characters are found doesnt mean that the
                                 // window is smallest so take minimum of them.
        {
            ans = min(ans, r - l + 1);

            frequency[s[l]]--;        // shrink from the left
            if (frequency[s[l]] == 0) // means that the character has been lost.
            {
                available--; // so this
            }
            l++; // shrink the window and check.
        }
    }
    cout << ans << endl;
}

// time Complexity :- O(n)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    helper();

    return 0;
}

*/
// function to count no of unique characters in the string;
int unique_characters(const string &s)
{
    vector<ll> frequency(256, 0);
    ll count = 0;
    for (char c : s)
    {
        if (frequency[c] == 0)
        {
            frequency[c]++;
            count++;
        }
    }
    return count;
}

bool valid_substring(const string &s, ll noc, ll mid)
{
    vector<ll> frequency(256, 0);
    ll available = 0;

    // First window of size mid
    for (int i = 0; i < mid; i++)
    {
        if (frequency[s[i]] == 0)
            available++;
        frequency[s[i]]++;
    }

    if (available == noc)
        return true;

    // Slide the window
    for (int i = mid; i < s.size(); i++)
    {
        // add right character
        if (frequency[s[i]] == 0)
            available++;
        frequency[s[i]]++;

        // remove left character
        frequency[s[i - mid]]--;
        if (frequency[s[i - mid]] == 0)
            available--;

        if (available == noc)
            return true;
    }

    return false;
}
// Time Complexity :- O(n(logn));

int main()
{

    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll noc = unique_characters(s);
    ll minm = noc; // minimum no of flats to visit;
    ll maxm = n;

    ll ans = n;

    while (minm <= maxm)
    {
        ll mid = (minm + (maxm - minm));

        if (valid_substring(s, noc, mid))
        {
            ans = mid;      // if found
            maxm = mid - 1; // search in the smaller window
        }
        else
        {
            minm = mid + 1; // if not found expand the window
        }
    }
    cout << ans << endl;
}