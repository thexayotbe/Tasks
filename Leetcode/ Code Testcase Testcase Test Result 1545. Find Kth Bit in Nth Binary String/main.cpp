class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';

        // Calculate the length of Sn. The length of Sn is 2^n - 1.
        int length = (1 << n) - 1;  // Equivalent to 2^n - 1

        // Middle bit of Sn is at position length / 2 + 1 (1-indexed)
        int middle = length / 2 + 1;

        if (k == middle) {
            // If k is the middle bit, it's always '1'
            return '1';
        } else if (k < middle) {
            // If k is in the first part, it's the same as in Sn-1
            return findKthBit(n - 1, k);
        } else {
            // If k is in the third part, find the corresponding position in the first part
            // The corresponding position is (length - k + 1), and invert the bit
            char bit = findKthBit(n - 1, length - k + 1);
            return (bit == '0') ? '1' : '0';  // Invert the bit
        }
    }
};