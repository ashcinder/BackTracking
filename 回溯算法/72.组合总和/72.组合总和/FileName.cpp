#include <vector>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(int n,int k,int curSum,int start) {

        if (curSum > n) {//总和部分的剪枝
            return;
        }

        if (path.size() == k) {
            if (curSum == n) {
                result.push_back(path);
            }
            return;//注意，无论满不满足条件，都要返回
        }

        for (int i = start;i <= 9-(k-path.size())+1;i++) {//个数的剪枝

            curSum += i;
            path.push_back(i);//插入数据

            backtracking(n, k, curSum, i + 1);//递归

            curSum -= i;
            path.pop_back();//回溯过程

        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        backtracking(n, k, 0, 0);
        return result;
    }
};