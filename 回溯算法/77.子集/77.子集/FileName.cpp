#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int>& nums, int start) {

        result.push_back(path);//这里不过是否终止，每一次都会push元素
        if (start >= nums.size()) {

            return;
        }

        for (int i = start;i < nums.size();i++) {
            path.push_back(nums[i]);

            backtracking(nums, i + 1);

            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        result.push_back(vector<int>());
        return result;
    }
};