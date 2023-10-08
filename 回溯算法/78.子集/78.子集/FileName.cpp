#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<bool> used;
    vector<int> path;
    vector<vector<int>> result;
    
    void backtracking(vector<int>& nums, int start, vector<bool> used) {
        result.push_back(path);
        if (start == nums.size()) {
            return;
        }

        for (int i = start;i < nums.size();i++) {
            if (i>0&&nums[i] == nums[i - 1] && used[i-1] == true)//如果为true说明在树枝上，可以选取 
            {
                continue;
            }
            else {
                path.push_back(nums[i]);
                used[i] = true;

                backtracking(nums, i+1, used);
                //这个地方是否加一取决于是否能重复取某一个元素

                path.pop_back();
                used[i] = false;
            }
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());//注意nums数组并没有提前排好序

        used.resize(nums.size(), false);
        backtracking(nums, 0, used);
        return result;
    }
};