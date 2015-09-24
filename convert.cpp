#include "common.h"
//not checked yet

class Solution {
public:
    string convert(string s, int numRows) {
        const int size = s.length();
        if(numRows <= 1)
            return s;
        int i = 0;
        string res;
        int gap = numRows*2 -2;
        while(i < size){
            res.push_back(s[i]);
            i += gap;
        }
        int first  = gap -2;
        int second = gap -first;
        for(int j = 1; j < numRows -1; ++j ){
            i = j;
            while(i < size){
                res.push_back(s[i]);
                i+= first;
                if(i < size){
                    res.push_back(s[i]);
                    i+= second;
                }
            }
            first -=2 ;
            second = gap - first;
        }
        i = numRows -1;
        while(i < size) {
            res.push_back(s[i]);
            i+= gap;
        }
        return res;
    }
};


int main() {
    cout << Solution().convert("ABC", 3);

    return 1;
}