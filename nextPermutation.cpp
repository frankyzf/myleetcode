#include "common.h"
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        std::next_permutation(num.begin(), num.end());
    }
};


int main() {

    return 1;
}