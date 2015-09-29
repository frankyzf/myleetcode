#include "common.h"
//not checked yet
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s.length() == 0)
            return res;
        auto isPalindrome = [&s](int start, int end){
          if(start > end)
              return true;
            string str = s.substr(start, end-start+1);
            string str2(str);
            reverse(str2.begin(), str2.end());
            return str == str2;
        };

        function<void(int, vector<string>&)> dfs = [&res, &s, &dfs, &isPalindrome](int start, vector<string>& path){
            if(start == s.length()){
                res.push_back(path);
                return ;
            }
            for(int i = start; i < s.length(); ++i){
                if(isPalindrome(start,i)){
                    path.push_back(s.substr(start, i-start+1));
                    dfs(i+1, path);
                    path.pop_back();
                }
            }

        };

        vector<string> path {};
        dfs(0, path);
        return res;
    }
};

int main() {
    auto r = Solution().partition("aab");
    for(auto& p: r){
        for(auto s: p)
            cout << s << "-->";
        cout << endl;
    }
    return 1;
}