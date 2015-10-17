#include "common.h"
//not checked yet

class Solution {
public:
    bool canWinNim(int n) {
        return n%4;
    }
};


int main() {
    cout << Solution().canWinNim(5);

    return 1;
}