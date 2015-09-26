#include "common.h"
//not checked yet
class Solution {
public:
    inline char n2c(int i) {
        if(i >= 1000) {
            return 'M';
        }
        else if (i >= 500) {
            return 'D';
        }
        else if (i >= 100) {
            return 'C';
        }
        else if (i >= 50) {
            return 'L';
        }
        else if (i >= 10) {
            return 'X';
        }
        else if (i >= 5) {
            return 'V';
        }
        else if(i >=1) {
            return 'I';
        }
        else
            return ' ';
    }

    string intToRoman(int num) {

        char symbol[7] = { 'I','V','X', 'L','C', 'D','M'};
        string roman;
        int scale = 1000;
        for(int i =6; i>=0; i-=2)
        {
            int digit = num/scale;
            if(digit != 0)
            {
                if(digit <= 3)
                {
                    roman.append(digit, symbol[i]);
                }
                else if(digit ==4)
                {
                    roman.append(1, symbol[i]);
                    roman.append(1, symbol[i+1]);
                }
                else if(digit ==5)
                {
                    roman.append(1, symbol[i+1]);
                }
                else if(digit <=8)
                {
                    roman.append(1, symbol[i+1]);
                    roman.append(digit-5, symbol[i]);
                }
                else if(digit ==9)
                {
                    roman.append(1, symbol[i]);
                    roman.append(1, symbol[i+2]);
                }
            }
            num = num%scale;
            scale/=10;
        }
        return roman;
    }
};


int main() {

    return 1;
}