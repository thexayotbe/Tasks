class Solution {
public:
    int compress(vector<char> &chars) {
        int n = chars.size();
        if (n == 0) return 0;

        int write = 0;
        int read = 0;

        while(read < n) {
            char current = chars[read];
            int count = 0;

            while(read < n && current == chars[read]) {
                read++;
                count++;
            }
            chars[write++] = current;

            if(count > 1) {
                for(char digit : to_string(count)) {
                    chars[write++] = digit;
                }
            }
        }
        return write;
    }
};
