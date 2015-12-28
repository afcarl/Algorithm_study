class Solution {
public:
  vector<string> generateParenthesis(int n) {
    generate("", n, n);
    return result;
  }

  void generate(string s, int left, int right) {
    if (left == 0 && right == 0) {
      result.push_back(s);
    }
    if (left > 0) {
      generate(s+"(", left-1, right);
    }
    if (right > 0 && left < right) {
      generate(s+")", left, right-1);
    }
  }

private:
  vector<string> result;
};
