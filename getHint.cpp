#include "common.h"
//not checked yet

class Solution {
public:
    string getHint(string secret, string guess) {
        int len = secret.length();
        if(len > 0){
            vector<bool> used(len, false);
            int a = 0, b = 0;
            for (int i = 0; i < guess.length(); ++i) {
                if(guess[i] == secret[i]){
                    ++a;
                    if(used[i] == false){
                        used[i] = true;
                    }
                    else{
                        --b;
                        for (int j = 0; j < len; ++j) {
                            if(!used[j] && secret[j] == guess[i]){
                                 ++b;
                                used[j] = true;
                                break;
                            }
                        }
                    }
                }
                else{
                    for (int j = 0; j < len; ++j) {
                        if(!used[j] && secret[j] == guess[i]){
                            ++b;
                            used[j] = true;
                            break;
                        }
                    }
                }
            }
            stringstream ss;
            ss << a << "A"<<b << "B";
            return ss.str();
        }
        else{
            return "0A0B";
        }
    }
};

int main() {
    cout << Solution().getHint("1122",  "2211");
    return 1;
}