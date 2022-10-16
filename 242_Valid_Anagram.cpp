#include "LCUtils/Includes/LCIncludes.h"
#include "LCUtils/Includes/LCUtils.h"

#define RUN_SOLUTION 0

/**
 * Solution 0 - Letter Count
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
#if RUN_SOLUTION == 0

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        array<int, 26> letterCount{};

        for (const char &c: s) {
            ++letterCount[c - 'a'];
        }

        for (const char &c: t) {
            if (letterCount[c - 'a'] > 0) --letterCount[c - 'a'];
            else return false;
        }
        return true;
    }
};

#endif

int main() {
    Solution sol;
    string s, t;

    s = "anagram";
    t = "nagaram";
    LC::print("s: ", s, "t: ", t);
    LC::print("Solution", sol.isAnagram(s, t));

    s = "rat";
    t = "car";
    LC::print("s: ", s, "t: ", t);
    LC::print("Solution", sol.isAnagram(s, t));

    s = "ab";
    t = "a";
    LC::print("s: ", s, "t: ", t);
    LC::print("Solution", sol.isAnagram(s, t));

    return 0;
}
