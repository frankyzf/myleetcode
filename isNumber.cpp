#include "common.h"
//not checked yet
class Solution {
public:
    bool isNumber(string s) {
        if(s.length() == 0)
            return false;
        int pos = 0;
        while(pos < s.length() && s[pos] == ' ')
            ++pos;
        if(pos == s.length())
            return false;

        auto judge= [&](bool checkpoint, int startpos, int endpos, bool& bpoint, bool& bnum){
            bool bsign = false;
            for(int i = startpos; i <endpos; ++i ){
                if(s[i] == '+' || s[i] == '-'){
                    if(bsign || bnum || bpoint )
                        return false;
                    bsign = true;
                }
                else if (s[i] == '.'){
                    if(checkpoint == false || bpoint)
                        return false;
                    bpoint = true;
                }
                else if (isdigit(s[i])){
                    bnum = true;
                }
                else{
                    return false;
                }
            }
            return true;
        };


        bool bsign =false, bpoint = false, bnum = false;
        auto epos = s.find('e', pos);
        if(epos == string::npos){
            epos = s.find_first_not_of("0123456789.+-", pos);
            if(epos == string::npos)
                epos = s.length();
            auto b = judge(true, pos, epos, bpoint, bnum);
            if(b && (bnum ) ){
                while(epos < s.length()){
                    if(s[epos] != ' ')
                        return false;
                    ++epos;
                }
                return true;
            }
            return false;
        }
        else{
            auto b = judge(true, pos, epos, bpoint, bnum);
            if(b && bnum){
                bpoint = bnum = false;
                auto end2 = s.find_first_not_of("0123456789+-", epos+1);
                if(end2 == string::npos)
                    end2 = s.length();
                b = judge(false, epos+1, end2, bpoint, bnum);
                if(b && bnum){
                    while(end2 < s.length()){
                        if(s[end2] != ' ')
                            return false;
                        ++end2;
                    }
                    return true;
                }
            }
            return false;
        }

    }
};


int main() {
    cout << Solution().isNumber(" 2e0") << endl;

    return 1;
}