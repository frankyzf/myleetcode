//
// Created by feng on 8/10/15.
//

#include"common.h"


class Solution {
public:
    void reverseWords(string &s) {
        while(s.begin() != s.end() && *s.begin() == ' ')
            s.erase(s.begin());
        while(s.rbegin() != s.rend() && *s.rbegin() == ' ')
            s.erase((++s.rbegin()).base() );

        size_t start = 0;
        size_t end = s.find(' ');
        while(end != string::npos){
            string::iterator b = s.begin() + start;
            string::iterator e = s.begin()+end;
            reverse(s.begin()+start, s.begin()+end);
            start = end + 1 ;
            while(start <= s.length() -1 && s[start] == ' '){
                s.erase(start, 1);
            }
            end = s.find(' ', start);
        }
        reverse(s.begin() + start, s.end());
        reverse(s.begin(), s.end());

    }
};



int main(){
    string s("   a   b ");
     Solution().reverseWords(s);
    cout << s;
    return 1;
}