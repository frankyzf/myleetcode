#include "common.h"
class Solution {
public:
    string simplifyPath(string path) {
        if (path.length() == 0) {
            return "";
        }
        deque<string> d;
        int i =0;
        bool rootstart = false;
        if(path[0] == '/') {
            rootstart = true;
            ++i;
        }
        int j = i;
        i = path.find('/', j);
        while(i != string::npos && i < path.length()){
            if(path[j] == '/'){
                //do nothing
            }
            else{
                string part = path.substr(j, i-j);
                if(part == ".." ) {
                    if(d.size())
                        d.pop_back();
                }
                else if (part == ".") {
                    //do nothing
                }
                else {
                    d.push_back(part);
                }
            }
            j = ++i;
            if(j < path.length()) {
                i = path.find('/', j);
            }
            else {
                i = string::npos;
            }
        }
        if(j < path.length() ) {
            string part = path.substr(j, string::npos);
            if(part == ".." ) {
                if(d.size())
                    d.pop_back();
            }
            else if (part == ".") {
                //do nothing
            }
            else {
                d.push_back(part);
            }
        }

        string res;
        if (rootstart) {
            res += "/";
        }
        if(d.size()) {
            for (auto v: d) {
                res += (v+"/");
            }
            res = res.substr(0, res.length()-1);
        }
        return res;
    }
};


int main() {

    return 1;
}