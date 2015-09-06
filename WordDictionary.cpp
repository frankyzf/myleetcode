//
// Created by feng on 8/10/15.
//

#include "common.h"

class WordDictionary {
private:
    struct charnode {
        bool leaf;
        vector<charnode*> links;
        charnode(): leaf(false), links(26, nullptr){}
    };
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        const int size = word.length();
        charnode* node = &root;
        for(int i = 0; i < size; ++i){
            int index = word[i] - 'a';
            if(node->links[index] == nullptr){
                charnode* p = new charnode();
                node->links[index] = p;
                node = p;
            }
            else{
                node = node->links[index];
            }
        }
        node->leaf = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        stack<pair<charnode*, int >> st;
        st.push(make_pair(&root, 0));
        charnode* p = &root;
        int index = 0;
        bool valid = false;
        while(!st.empty() ){
            tie(p, index) = st.top();
            st.pop();
            if(index > word.length()-1){
                if(p->leaf == true){
                    valid = true;
                    break;
                }
                else
                    continue;
            }
            char ch = word[index];
            if(ch == '.'){
                for(auto n: p->links){
                    if(n != nullptr){
                        st.push(make_pair(n, index+1));
                    }
                }
            }
            else{
                if(p->links[ch-'a'] != nullptr){
                    st.push(make_pair(p->links[ch-'a'], index+1));
                }
            }
        }
        return valid;

    }

    charnode root;

};

int main(){
    WordDictionary wd;
    wd.addWord("ran");
    wd.addWord("rune");
    wd.addWord("runner");
    wd.addWord("runs");
    wd.addWord("add");
    wd.addWord("adds");
    wd.addWord("adder");
    wd.addWord("addee");
    cout << boolalpha<< wd.search("r.n") << endl;
    cout << boolalpha<< wd.search("ru.n.e") << endl;
    cout << boolalpha<< wd.search("add") << endl;
    cout << boolalpha<< wd.search("add.") << endl;
    cout << boolalpha<< wd.search("adde.") << endl;
    cout << boolalpha<< wd.search(".an.") << endl;
    cout << boolalpha<< wd.search("...s") << endl;
    cout << boolalpha<< wd.search("....e.") << endl;
    cout << boolalpha<< wd.search(".......") << endl;
    cout << boolalpha<< wd.search("..n.r") << endl;

    return 1;
}

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");