class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int maximum = num;
        for (int i = 0; i < numStr.length(); i++) {
            for (int j = numStr.length() - 1; j > i; j--) {
                string tempStr = numStr;
                swap(tempStr[i], tempStr[j]);
                if (stoi(tempStr) > maximum) {
                    maximum = stoi(tempStr);
                }
            }
        }
        return maximum;
    }
};