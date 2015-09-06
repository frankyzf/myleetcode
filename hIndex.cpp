#include "common.h"
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        const int size = citations.size();
        int low = 0, high = size;
        while (low < high) {
            int mid = low + ( (high - low) >> 1 );
            if (citations[mid] < size - mid) {
                low = mid +1;
            }
            else {
                high = mid;
            }
        }
        return size - low;
    }
};
int main() {
    vector<int> cit ={3, 0, 6, 1, 5};
    cout << Solution().hIndex(cit);
    return 1;
}