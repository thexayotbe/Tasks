class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0)
            return false;

        int forwardBalance = 0, backwardBalance = 0;

        for (int i = 0; i < n; ++i) {
            // Forward pass
            if (locked[i] == '0' || s[i] == '(')
                forwardBalance++;
            else
                forwardBalance--;

            // Backward pass
            int j = n - 1 - i;
            if (locked[j] == '0' || s[j] == ')')
                backwardBalance++;
            else
                backwardBalance--;

            // Check for invalid balance
            if (forwardBalance < 0 || backwardBalance < 0)
                return false;
        }

        return true;
    }
};