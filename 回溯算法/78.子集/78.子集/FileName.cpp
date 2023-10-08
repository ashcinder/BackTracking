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
            if (i>0&&nums[i] == nums[i - 1] && used[i-1] == true)//���Ϊtrue˵������֦�ϣ�����ѡȡ 
            {
                continue;
            }
            else {
                path.push_back(nums[i]);
                used[i] = true;

                backtracking(nums, i+1, used);
                //����ط��Ƿ��һȡ�����Ƿ����ظ�ȡĳһ��Ԫ��

                path.pop_back();
                used[i] = false;
            }
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());//ע��nums���鲢û����ǰ�ź���

        used.resize(nums.size(), false);
        backtracking(nums, 0, used);
        return result;
    }
};