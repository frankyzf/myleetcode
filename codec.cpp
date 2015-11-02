#include "common.h"
//not checked yet

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        function<void(TreeNode*, stringstream&)> f = [&f](TreeNode* p, stringstream& ss){
             if(p == nullptr){
                 if(ss.str().length() != 0)
                     ss << ",";
                 ss << "#";
                 return ;
             }
             if(ss.str().length() !=0)
                 ss << ",";
            ss << p->val;
            f(p->left, ss);
            f(p->right, ss);
            return ;
        };
        stringstream ss;
        f(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        if(i == data.length() || data[0] == '#')
            return nullptr;
        stack<pair<TreeNode*, bool> > st;
        TreeNode* p = nullptr;
        TreeNode* tmp = nullptr;
        int j = data.find(',', i);
        p = new TreeNode(atoi(data.substr(i, j-i).c_str()));
        auto head = p;
        st.push(make_pair(p, false));
        i = ++j;
        while(i < data.length()){
            auto pr = st.top();
            st.pop();
            p = pr.first;
            bool b  = pr.second;
            j = data.find(',', i);
            if(data[i] != '#'){
                tmp = new TreeNode(atoi(data.substr(i, j-i).c_str()));
            }
            else{
                tmp = nullptr;
            }

            if(b){
                p->right = tmp;
            }else{
                p->left = tmp;
                st.push(make_pair(p, true));
            }

            if(tmp)
                st.push(make_pair(tmp, false));
            if(j != string::npos)
                i = ++j;
            else
                i = data.length();

        }
        return head;
    }
};


int main() {
    vector<string> data{"1","2","3","#","#","4","5"};
    auto root = constructTree(data);
    Codec cd;
    auto s = cd.serialize(root);
    auto proot = cd.deserialize(s);
    return 1;
}