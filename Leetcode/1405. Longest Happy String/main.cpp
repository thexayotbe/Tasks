#include <string>

using namespace std;

class Solution {
public:
    std::string longestDiverseString(int a, int b, int c) {
        priority_queue<std::pair<int, char>> maxHeap;
        if(a>0) maxHeap.push({a,'a'});
        if(b>0) maxHeap.push({b,'b'});
        if(c>0) maxHeap.push({c,'c'});


        string result = "";
        while(!maxHeap.empty()) {
            auto [count1,char1] = maxHeap.top();
            maxHeap.pop();

            if(result.size()>=2 && result.back() == char1 && result[result.size()-2]==char1) {
                if(maxHeap.empty()) break;

                auto [count2,char2] = maxHeap.top();
                maxHeap.pop();

                result += char2;
                count2--;

                if(count2>0) maxHeap.push({count2,char2});

                maxHeap.push({count1,char1});

            }
            else {
                result += char1;
                count1--;
                if(count1>0) maxHeap.push({count1,char1});
            }
        }
        return result;    }
};
