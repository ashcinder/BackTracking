#include <vector>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(int n, int k, int start) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        for (int i = start;i <= n-(k-path.size())+1;i++) {//此处使用到了剪枝的操作
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};