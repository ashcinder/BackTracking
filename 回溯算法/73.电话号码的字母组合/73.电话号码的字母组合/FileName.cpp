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
        if (index == digits.size()) {//��ִ�е����һ����ĸʱ����Ȼ��Ҫ���еݹ����
            result.push_back(path);
            return;
        }

        int num = digits[index] - '0';//�õ�����
        string alphabet = map[num];//�õ���ǰ���ַ���

        for (int i = 0;i < alphabet.size();i++) {

            path.push_back(alphabet[i]);
            index += 1;

            backtracking(digits, index);//�ݹ�

            path.pop_back();
            index -= 1;//�����㷨
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