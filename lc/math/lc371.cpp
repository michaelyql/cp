class Solution {
  public:
      int getSum(int a, int b) {
          bitset<10> out;
          bitset<10> a_bits {(unsigned long long) a};
          bitset<10> b_bits {(unsigned long long) b};
          
          bool carry = false;
          bool neg = false;
  
          for (int i = 0; i < 10; i++) {
              if (a_bits[i] && b_bits[i]) {
                  if (carry) {
                      out[i] = true;
                  } 
                  carry = true;
              } else if (a_bits[i] || b_bits[i]) {
                  if (!carry) {
                      out[i] = true;
                  }
              } else {
                  if (carry) {
                      out[i] = true;
                  }
                  carry = false;
              }
          }
  
          bitset<32> res;
  
          if (a < 0 && b < 0) {
              for (int i = 0; i < 32; i++) res[i] = true;
              neg = true;
          } else if (a < 0 || b < 0) {
              if (a < b) swap(a, b);
              if (abs(a) < abs(b)) for (int i = 0; i < 32; i++) {
                  res[i] = true;
                  neg = true;
              }
          }
          for (int i = 0; i < 10; i++) {
              res[i] = out[i];
          }
  
          if (carry && a > 0 && b > 0) res[10] = true;
  
          return (int) (res.to_ulong());
      }
  };
