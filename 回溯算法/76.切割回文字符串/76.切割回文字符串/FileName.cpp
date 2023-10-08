#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    bool isPalindrome(string s,int start,int end) {//判断是否回文
        int left = 0;
        int right = end;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    vector<string> path;
    vector<vector<string>> result;

    void backtracking(string s, int start) {//start表示分割点
        if (start == s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = start;i < s.size();i++) {
            if (isPalindrome(s, start, i)) {
                string temp(s.begin() + start, s.begin() + i + 1);//回文传插入到path中，左闭右开
                path.push_back(temp);
            }
            else {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }
};