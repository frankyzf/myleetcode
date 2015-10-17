#include "common.h"
//not checked yet
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {

        auto next = [&wordList](string word){
            deque<string> mwords;
            for (int i = 0; i < word.length(); ++i) {
                char ch = word[i];
                for (int j = 0; j < 26; ++j) {
                    if(ch != 'a'+j){
                        word[i] = 'a'+j;
                        if(wordList.count(word) != 0){
                            mwords.push_back(word);
                            wordList.erase(word);
                        }
                    }
                }
                word[i] = ch;
            }
            return mwords;
        };

        deque<string> con;
        con.push_back(beginWord);
        int step = 0;
        while (!con.empty()){
            deque<string> q;
            ++step;
            while(!con.empty()){
                auto str = con.front();
                con.pop_front();
                if(str == endWord){
                    return step;
                }
                auto t = next(str);
                q.insert(q.end(), t.begin(), t.end());
            }
            con.swap(q);
        }
        return 0;

    }
};

int main() {
    unordered_set<string> wordList {"a", "b","c"};
    string start = "a";
    string end = "c";
    cout << Solution().ladderLength(start, end, wordList);
    return 1;
}