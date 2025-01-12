class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0)
            return false;

        // Forward and backward balances
        int openPossible = 0, openNeeded = 0;

        // Single pass to handle both forward and backward logic
        for (int i = 0; i < n; ++i) {
            // Forward logic (opening balance)
            if (locked[i] == '0' || s[i] == '(')
                openPossible++;
            else
                openPossible--;

            // Backward logic (closing balance)
            if (locked[n - 1 - i] == '0' || s[n - 1 - i] == ')')
                openNeeded++;
            else
                openNeeded--;

            // If either forward or backward balance is invalid at any point
            if (openPossible < 0 || openNeeded < 0)
                return false;
        }

        return true;
    }
};
