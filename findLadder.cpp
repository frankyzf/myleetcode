#include "common.h"
//not checked yet
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        unordered_multimap<string, string> upstream;
        vector<string> level;
        level.push_back(beginWord);
        bool bFound = false;
        string upword = "";
        upstream.insert(make_pair(beginWord, upword));

        while(!bFound && !level.empty()){
            vector<string> l2;
            std::set< pair<string, string> > up2;
            for(auto word: level){
                auto oword = word;
                for(int i = 0; i < word.length(); ++i){
                    unsigned char oc = word[i];
                    unsigned char c = 'a';
                    for(int j = 0 ; j < 26; ++j){
                        if(c != oc){
                            word[i] = c;
                            if(word == endWord)
                                bFound = true;
                            if(wordList.count(word) && upstream.count(word) == 0){
                                l2.push_back(word);
                                up2.insert(make_pair(word, oword));
                            }
                        }
                        ++c;
                    }
                    word[i] = oc;
                }
            }

            level.swap(l2);
            for(auto& item: up2){
                upstream.insert(item);
            }
        }
		
		/*for (auto item : upstream)
			cout << item.first << " : " << item.second << endl ;*/
		
        vector<vector<string>> res;
        if(bFound){
			res.emplace_back(vector<string>{ endWord });
            bool bend = false;
            while(!bend){
                vector<vector<string>> res2;
                for(auto path: res){
                    auto word = *path.rbegin();
                    if(word == beginWord)
                        bend = true;
                    auto range = upstream.equal_range(word);
                    for(auto it = range.first; it != range.second; ++it){
                        auto path2 = path;
                        path2.push_back(it->second);
                        res2.push_back(move(path2));
                    }
                }
                res.swap(res2);
            }
        }
		for (auto& path : res) {
			path.pop_back();
			reverse(path.begin(), path.end());
		}
        return res;
    }
};

int main() {
    unordered_set<string> wordList {"hot","dot","dog","lot","log"};
    string start = "hit";
    string end = "cog";
    auto res = Solution().findLadders(start, end, wordList);
    for(auto& ws: res){
        for(auto&w: ws){
            cout << w << ",";
        }
        cout << endl;
    }

    return 1;
}
