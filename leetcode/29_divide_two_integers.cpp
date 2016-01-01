class Solution {
public:
  int divide(int dividend, int divisor) {

    bool is_neg = (divisor^dividend) < 0;
    int res = 0;
    int num_digit = 31;

    if (divisor == 0) return INT_MAX;

    if (divisor == INT_MIN) {
      return dividend == INT_MIN ? 1 : 0;
    }

    if (dividend == INT_MIN) {
      if (divisor == -1) return INT_MAX;

      if (divisor > 0) {
	dividend += divisor;
      } else {
	dividend -= divisor;
      }
      res += 1;
    }

    divisor = divisor < 0 ? -divisor : divisor;
    dividend = dividend < 0 ? -dividend : dividend;

    for (int i=num_digit;i>=0;--i) {
      if ((dividend>>i) >= divisor) {
	dividend -= (divisor << i);
	res += (1 << i);
      }
    }
    return is_neg ? -res : res;
  }
};
