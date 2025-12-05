#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define loop(i, x, n) for (int i = x; i < n; i++)

int win(char fj_moves, int g)
{
    if (g == 0 && fj_moves == 'S')
        return 1;
    if (g == 1 && fj_moves == 'H')
        return 1;
    if (g == 2 && fj_moves == 'P')
        return 1;
    return 0;
}
void helper()
{
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    ll n;
    cin >> n;
    vector<char> fj_moves(n);
    loop(i, 0, n) cin >> fj_moves[i];

    vector<vector<ll>> prefix(n + 1, vector<ll>(3, 0));
    // vector<vector<> prefix(with 3 possibilites);

    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1];

        for (int g = 0; g < 3; g++)
        {
            prefix[i][g] += win(fj_moves[i - 1], g);
        }
    }

    vector<vector<ll>> suffix(n + 2, vector<ll>(3, 0)); // suffix[n] is linked to suffix[n+1], so size (n+2);

    for (int i = n; i >= 1; i--)
    {
        suffix[i] = suffix[i + 1];
        for (int g = 0; g < 3; g++)
        {
            suffix[i][g] += win(fj_moves[i - 1], g);
        }
    }

    ll best = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int g1 = 0; g1 < 3; g1++)
        {
            for (int g2 = 0; g2 < 3; g2++)
            {
                best = max(best, (prefix[i][g1] + suffix[i + 1][g2]));
            }
        }
    }

    cout << best << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    helper();

    return 0;
}
