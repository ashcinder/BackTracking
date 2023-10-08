#include <vector>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(int n,int k,int curSum,int start) {

        if (curSum > n) {//�ܺͲ��ֵļ�֦
            return;
        }

        if (path.size() == k) {
            if (curSum == n) {
                result.push_back(path);
            }
            return;//ע�⣬��������������������Ҫ����
        }

        for (int i = start;i <= 9-(k-path.size())+1;i++) {//�����ļ�֦

            curSum += i;
            path.push_back(i);//��������

            backtracking(n, k, curSum, i + 1);//�ݹ�

            curSum -= i;
            path.pop_back();//���ݹ���

        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        backtracking(n, k, 0, 0);
        return result;
    }
};