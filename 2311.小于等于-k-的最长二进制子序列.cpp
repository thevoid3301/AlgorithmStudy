/*
 * @lc app=leetcode.cn id=2311 lang=cpp
 *
 * [2311] 小于等于 K 的最长二进制子序列
 */

// @lc code=start
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int sm = 0;
        int cnt = 0;
        int bits = 32 - __builtin_clz(k);
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[s.size() - 1 - i];
            if (ch == '1') {
                if (i < bits && sm + (1 << i) <= k) {
                    sm += 1 << i;
                    cnt++;
                }
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end

