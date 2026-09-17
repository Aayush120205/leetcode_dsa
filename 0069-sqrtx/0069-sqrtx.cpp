#include "../utils/binary_search.hpp"

class Solution {
public:
    int mySqrt(int x) {
        return (int)dsa::lastTrue(0, x, [&](long long root) {
            return root * root <= (long long)x;
        });
    }
};
