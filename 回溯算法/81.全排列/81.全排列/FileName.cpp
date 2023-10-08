#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    vector<bool> used;

    void backtracking(vector<int>& nums) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0;i < nums.size();i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {//数层去重
                continue;
            }
            else if (used[i] == true) {//树枝去重
                continue;
            }
            else {
                path.push_back(nums[i]);
                used[i] = true;

                backtracking(nums);

                path.pop_back();
                used[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used.resize(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums);
        return result;
    }
};