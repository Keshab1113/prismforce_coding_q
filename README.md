# Abhimanyu's Chakravyuha Challenge

## Overview

This program is designed to simulate a scenario where Abhimanyu must cross a series of enemies, each with a specified power level. Abhimanyu has limited initial power but can skip a certain number of enemies or recharge his power a few times to aid his journey. The program determines whether Abhimanyu can successfully cross all enemies based on these constraints.

## How It Works

### Problem Description

- **Initial Power**: Abhimanyu starts with a specific amount of power.
- **Enemy Powers**: There are 11 enemies, each with a certain power level that Abhimanyu must overcome to proceed.
- **Skips**: Abhimanyu can skip a limited number of enemies without battling them.
- **Recharges**: Abhimanyu can recharge his power to the initial value, but only a limited number of times.
- At certain points in the sequence (specifically indices 3 and 7), if Abhimanyu hasn't skipped the previous enemy, the current enemy's power increases by half the previous enemy's power.

The program recursively determines whether Abhimanyu can make it through all 11 enemies using his power, skips, and recharges.

### Inputs

The program takes the following inputs for each test case:

1. **Initial Power**: The starting power of Abhimanyu.
2. **Number of Skips**: The number of enemies Abhimanyu can skip.
3. **Number of Recharges**: The number of times Abhimanyu can recharge his power.
4. **Enemy Powers**: A vector of 11 integers representing the power of each enemy.

### Outputs

For each test case, the program outputs whether Abhimanyu can cross the Chakravyuha:

- **"Abhimanyu cross the Chakrvyuha"**: If he can successfully cross all 11 enemies.
- **"Abhimanyu cannot cross the Chakrvyuha"**: If he cannot cross all 11 enemies.

## Code Example

```cpp
#include <bits/stdc++.h>
#define long long int
using namespace std;

// Function to determine if Abhimanyu can cross the Chakravyuha
bool isPossible(int ind, int p, int s, int r, vector<int> &powers, bool isSkipPre, int initial_power){
    if (ind > 10) return true;  // Base case: If all enemies are crossed
    if (ind == 3 or ind == 7){
        if (!isSkipPre) powers[ind] += powers[ind - 1] / 2; // Increase current enemy's power based on the previous one
    }
    if (powers[ind] <= p){
        p -= powers[ind]; // Deduct enemy's power from Abhimanyu's power
        return isPossible(ind + 1, p, s, r, powers, false, initial_power); // Recurse to the next enemy
    } else {
        bool canSkip = false;
        if (s > 0) canSkip = isPossible(ind + 1, p, s - 1, r, powers, true, initial_power); // Attempt to skip the enemy
        bool canRecharge = false;
        if (r > 0 && initial_power >= powers[ind]) canRecharge = isPossible(ind + 1, initial_power - powers[ind], s, r - 1, powers, false, initial_power); // Attempt to recharge and cross the enemy
        return canSkip or canRecharge; // Return true if either skipping or recharging allows to proceed
    }
}

int main()
{
    int t;
    cout << "Enter number of test case: " << endl;
    cin >> t;
    while (t--)
    {
        int inti_pow, skip, recharge;
        cout << "Enter Abhimanyu Power: " << endl;
        cin >> inti_pow;
        cout<< "Enter Number of Skips: " << endl;
        cin >> skip;
        cout << "Enter Number of Recharge: " << endl;
        cin >> recharge;

        vector<int> powers(11);
        cout << "Enter the vector of enemy powers: " << endl;
        for (int &x : powers)
            cin >> x;

        bool can_win = isPossible(0, inti_pow, skip, recharge, powers, false, inti_pow);
        cout << (can_win ? "Abhimanyu cross the Chakrvyuha" : "Abhimanyu cannot cross the Chakrvyuha") << endl;
        cout << endl;
    }
    return 0;
}
