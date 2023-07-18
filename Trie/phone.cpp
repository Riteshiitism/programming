#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    TrieNode *child[26];
    bool isLeaf;
    int noOfChild;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            this->child[i] = NULL;
        }
        this->isLeaf = false;
        this->noOfChild = 0;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }
    void insertUtil(TrieNode *root, string str)
    {
        if (str.length() == 0)
        {
            root->isLeaf = true;
            return;
        }
        int idx = str[0] - 'a';
        if (root->child[idx] != NULL)
        {
            insertUtil(root->child[idx], str.substr(1));
        }
        else
        {
            TrieNode *newNode = new TrieNode();
            root->child[idx] = newNode;
            root->noOfChild++;
            insertUtil(root->child[idx], str.substr(1));
        }
    }

    void insert(string str)
    {
        insertUtil(root, str);
    }
    void printSuggestion(TrieNode *cur, vector<string> &vec, string prefixStr)
    {
        if (cur->isLeaf)
        {
            vec.push_back(prefixStr);
        }

        for (int i = 0; i < 26; i++)
        {
            if (cur->child[i] != NULL)
            {
                char ch = i + 'a';
                prefixStr.push_back(ch);
                printSuggestion(cur->child[i], vec, prefixStr);
                prefixStr.pop_back();
            }
        }
    }
    vector<vector<string>> suggestions(string query)
    {
        vector<vector<string>> ans;
        TrieNode *prev = root;
        // TrieNode *cur;
        string prefixStr = "";
        // char lastChar ;
        for (int i = 0; i < query.length(); i++)
        {
            char lastChar = query[i];

            prefixStr.push_back(lastChar);
            TrieNode *cur = prev->child[lastChar - 'a'];
            if (cur != NULL)
            {
                vector<string> vec;
                printSuggestion(cur, vec, prefixStr);
                ans.push_back(vec);
                prev = cur;
                vec.clear();
            }
            else
            {
                for (int j = i; j < query.length(); j++)
                {
                    vector<string> v;
                    v.push_back("0");

                    ans.push_back(v);
                }
                break;
            }
        }
        return ans;
    }
};
class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie t;
        for (int i = 0; i < n; i++)
        {
            t.insert(contact[i]);
        }
        vector<vector<string>> ans = t.suggestions(s);
        // solve(t,n,s,ans);

        return ans;
    }
};
int main()
{
    string contact[] = {"geeikistest", "geeksforgeeks", "geeksfortest"};
    // string contact[]  = {"code", "coding","codeforces","coder","codechef","coly"};
    int n = sizeof(contact) / sizeof(contact[0]);
    string s = "geeips";

    Solution ob;
    vector<vector<string>> ans = ob.displayContacts(n, contact, s);
    for (int i = 0; i < s.length(); i++)
    {
        for (auto u : ans[i])
        {
            cout << u << " ";
        }
        cout << endl;
    }
}

/*


    bool searchUtil(TrieNode* root,string str){
        if(str.length()==0){
            return root->isLeaf;
        }
        int idx = str[0]-'a';
        if(root->child[idx]!=NULL){
            return searchUtil(root->child[idx],str.substr(1));
        }
        else{
            return false;
        }

    }
    bool search(string str){
        return searchUtil(root,str);
    }

    bool prefixUtil(TrieNode* root,string str){
        if(str.length()==0){
            return true;
        }
        int idx = str[0]-'a';
        if(root->child[idx]!=NULL){
            return prefixUtil(root->child[idx],str.substr(1));
        }
        else{
            return false;
        }
    }
    bool prefix(string s){
        return prefixUtil(root,s);


    void printUtil(TrieNode* root,string str){

        if(root->noOfChild == 0){
            cout<<str<<endl;
            return;
        }

        if(root->isLeaf){
            cout<<str<<endl;
        }
        for(int i = 0; i< 26; i++){
            if(root->child[i]!=NULL){
                char ch = i+'a';
                printUtil(root->child[i],str+ch);
            }
        }

        return ;
    }

    void printreletedToS(string s){
        string str = s;
        int l = 0;
        while (l<str.length())
        {
            int idx = str[l]-'a';
            root=root->child[idx];
            l++;
        }

        printUtil(root,str);
    }
    }*/