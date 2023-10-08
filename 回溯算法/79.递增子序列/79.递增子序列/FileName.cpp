#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int>& nums, int start) {
        if (path.size() > 1) {
            result.push_back(path);
        }

        if (start == nums.size()) {
            return;
        }

        unordered_set<int> used;//用来记录同一层的元素，如果找到了，说明在同一层，必须被跳过
        for (int i = start;i < nums.size();i++) {
            if ((!path.empty() && path.back() > nums[i]) || used.count(nums[i])) {
                continue;
            }
            else {
                used.insert(nums[i]);
                path.push_back(nums[i]);

                backtracking(nums, i + 1);

                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {//不能直接排序，排序会改变答案
        backtracking(nums, 0);
        return result;
    }
};