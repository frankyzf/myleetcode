//
// Created by feng on 9/3/15.
//

class Solution {
public:
    bool isMatch(string s, string p) {
        function<bool(int, int)> f = [&s, &p, &f](int si, int pi  ){
            if(pi == p.length() ){
                if (si  == s.length())
                    return true;
                else
                    return false;
            }
            else if (si == s.length()){
                return false;
            }
            if (p[pi] == '.'){
                return f(++si, ++pi);
            }
            else if (p[pi] == '*'){
                if(pi > 0 && (p[pi-1] == '.' || p[pi-1] == s[si]) ){
                    return f(++si, ++pi) || f(si, ++pi);
                }
                else{
                    return false;
                }
            }
            else{
                if(p[pi] != s[si])
                    return false;
                else
                    return f(++si, ++pi);
            }
        };
        return f(0, 0);
    }
};

int main(){
    cout << Solution().isMatch("aa", "a");
    return 1;
}