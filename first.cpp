#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isPossible(ll ind, ll p, ll s, ll r, vector<ll> &powers, bool isSkipPre, ll initial_power){
    if (ind > 10) return true;
    if (ind == 3 || ind == 7){
        if (!isSkipPre) powers[ind] += powers[ind - 1] / 2;
    }
    if (powers[ind] <= p){
        p -= powers[ind];
        return isPossible(ind + 1, p, s, r, powers, false, initial_power);
    } else {
        bool canSkip = false;
        if (s > 0) canSkip = isPossible(ind + 1, p, s - 1, r, powers, true, initial_power);
        bool canRecharge = false;
        if (r > 0 && initial_power >= powers[ind]) canRecharge = isPossible(ind + 1, initial_power - powers[ind], s, r - 1, powers, false, initial_power);
        return canSkip || canRecharge;
    }
}

int main()
{
    ll t;
    cout << "Enter number of test case: " << endl;
    cin >> t;
    while (t--)
    {
        ll inti_pow, skip, recharge;
        cout << "Enter Abhimanyu Power: " << endl;
        cin >> inti_pow;
        cout<< "Enter Number of Skips: " << endl;
        cin >> skip;
        cout << "Enter Number of Recharge: " << endl;
        cin >> recharge;

        vector<ll> powers(11);
        cout << "Enter the vector of enemy powers: " << endl;
        for (ll &x : powers)
            cin >> x;

        bool can_win = isPossible(0, inti_pow, skip, recharge, powers, false, inti_pow);
        cout << (can_win ? "Abhimanyu cross the Chakrvyuha" : "Abhimanyu cannot cross the Chakrvyuha") << endl;
        cout << endl;
    }
    return 0;
}
