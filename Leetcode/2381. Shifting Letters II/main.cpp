#include <iostream>
#include <numeric>

using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int> > &shifts) {
        unordered_map<int, vector<int> > positions;
        for (int i = 0; i < shifts.size(); i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            for (int j = start; j <= end; j++) {
                positions[j].push_back(shifts[i][2] == 1 ? +1 : -1);
            }
        }
        unordered_map<int, int> sumss;

        for (const auto &pair: positions) {
            int key = pair.first;
            const vector<int> &vec = pair.second;
            int sum = accumulate(vec.begin(), vec.end(), 0);
            sumss[key] = sum;
        }
        for (const auto &pair: sumss) {
            int key = pair.first;
            int sum = pair.second;
            char ch = s[key];

            s[key] = (ch - 'a' + sum + 26) % 26 + 'a';
        }
        return s;
    }
};


int main() {
    Solution solution;
    string s = "abc";
    vector<vector<int> > shifts = {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};
    cout << solution.shiftingLetters(s, shifts) << endl;
    return 0;
}
