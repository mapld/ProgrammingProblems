class Solution {
public:
    int divide(int dividend, int divisor) {
      while(divisor > 1){
        dividend = dividend >> 1;
        divisor = divisor >> 1;
        cout << "dividend: " << dividend;
      }
      return dividend;
    }
};
