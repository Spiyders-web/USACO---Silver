#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll x, y;
    cin >> x >> y;

    ll total = 0;
    ll steps = 1;
    ll direction = 1; // 1 = right, -1 = left
    ll current = x;

    while (true)
    {
        ll next = x + direction * steps;

        // Check if this move will pass the cow
        if ((direction == 1 && next >= y) || (direction == -1 && next <= y))
        {
            total += abs(y - current);
            break;
        }
        else
        {
            total += abs(next - current);
            current = next;
            direction *= -1;
            steps *= 2;
        }
    }

    cout << total << endl;
    return 0;
}
