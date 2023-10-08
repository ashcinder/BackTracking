#include <vector>
#include <algorithm>
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
            if (used[i]) {
                continue;
            }

            used[i] = true;
            path.push_back(nums[i]);

            backtracking(nums);

            used[i] = false;
            path.pop_back();
        } 
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(), false);
        backtracking(nums);
        return result;
    }
};