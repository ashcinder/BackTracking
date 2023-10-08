#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target,int sum,int start) {
        if (sum > target) {
            return;
        }
        else if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = start;i < candidates.size();i++) {

            sum += candidates[i];
            path.push_back(candidates[i]);

            backtracking(candidates, target, sum, i);//元素可以重复利用，所以i无需加1

            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

//剪枝操作
class Solution {
private:
    vector<int> path;;
    vector<vector<int>> result;
    void backtracking(vector<int>& candidates, int target, int start) {

        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = start;i < candidates.size()&&target-candidates[i]>=0;i++) {
            path.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], i);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return result;
    }
};