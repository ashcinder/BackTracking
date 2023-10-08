#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    string map[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    string path;
    vector<string> result;
    void backtracking(string digits,int index) {
        if (index == digits.size()) {//当执行到最后一个字母时，仍然需要进行递归操作
            result.push_back(path);
            return;
        }

        int num = digits[index] - '0';//得到数字
        string alphabet = map[num];//得到当前的字符串

        for (int i = 0;i < alphabet.size();i++) {

            path.push_back(alphabet[i]);
            index += 1;

            backtracking(digits, index);//递归

            path.pop_back();
            index -= 1;//回溯算法
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return vector<string>();
        }
        backtracking(digits, 0);

        return result;
    }
};