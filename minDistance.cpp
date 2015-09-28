#include "common.h"
//not checked yet
class Solution {
public:
    int minDistance(string word1, string word2) {
        const size_t len1 = word1.length();
        const size_t len2 = word2.length();
        if(len1 == 0)
            return len2;
        vector<vector<int>> distance(len1+1, vector<int>(len2+1, 0));
        for (int i = 0; i <= len1; ++i) {
            distance[i][0] = i;
        }
        for (int j = 0; j <= len2; ++j) {
            distance[0][j] = j;
        }
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                int m = min(distance[i-1][j]+1, distance[i][j-1]+1);
                if(word1[i-1] == word2[j-1]){
                    distance[i][j] =  min(distance[i-1][j-1], m);
                }
                else{
                    distance[i][j] =  min(distance[i-1][j-1]+1, m);
                }
            }
        }
        return distance[len1][len2];
    }
};


int main() {

    return 1;
}