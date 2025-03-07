/*
 * @lc app=leetcode.cn id=2080 lang=cpp
 *
 * [2080] 区间内查询数字的频率
 */

// @lc code=start
class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> res;
public:
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            res[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        vector<int> &pos = res[value];
        auto l = lower_bound(pos.begin(), pos.end(), left);
        auto r = upper_bound(pos.begin(), pos.end(), right);
        return r - l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
// @lc code=end

