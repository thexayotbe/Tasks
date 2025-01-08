class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i'
        || ch == 'o' || ch == 'u')
            return true;
        if(ch == 'A' || ch == 'E' || ch == 'I'
        || ch == 'O' || ch == 'U')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {

            while(left < right && !isVowel(s[left])) {
                left++;
            }
            while(left< right && !isVowel(s[right])) {
                right--;
            }
            if(left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};

