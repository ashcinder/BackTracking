#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<bool> used;
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int> candidates, int target, int start, vector<bool> used) {
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = start;i < candidates.size() && target - candidates[i] >= 0;i++) {

            if (i > 0 && candidates[i - 1] == candidates[i] && used[i] == false) {
                continue;
            }
            // used[i - 1] == true��˵��ͬһ��֦candidates[i - 1]ʹ�ù�����֦�Ͽ����ظ�����
            // used[i - 1] == false��˵��ͬһ����candidates[i - 1]ʹ�ù��������ϲ����ظ�����

            path.push_back(candidates[i]);
            target -= candidates[i];
            used[i] = true;

            backtracking(candidates, target, i + 1, used);

            path.pop_back();
            target += candidates[i];
            used[i] = false;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        used.resize(candidates.size(), false);
        backtracking(candidates, target, 0, used);
        return result;
    }
};