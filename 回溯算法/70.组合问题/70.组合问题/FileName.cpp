#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(int n, int k, int startindex) {
        if (path.size() == k) {//������ĿҪ��Ĵ�Сʱ
            result.push_back(path);
            return;
        }

        for (int i = startindex; i <= n;i++) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();//����
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};