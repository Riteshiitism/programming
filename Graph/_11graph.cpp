#include <bits/stdc++.h>
using namespace std;
int ladderLength(string b, string e, vector<string> &wordList)
{
    int n = wordList.size();
    unordered_set<string>word;
    for (int i = 0; i < n; i++)
    {
        word.insert(wordList[i]);
    }
    if(word.find(e)==word.end()) {
        return 0;
    } 
    queue<string> q;
    int ans = 1;
    q.push(b);
    
    while (q.size())
    {
        int k = q.size();
        while (k--)
        {
            string str = q.front();
            q.pop();
            if (str == e)
                return ans;
            for(int i = 0; i < b.length();i++){
                string copy = str;
                for(char ch = 'a'; ch<='z';ch++){
                    copy[i] = ch;
                    if(word.find(copy)==word.end()) continue;

                    q.push(copy);
                    word.erase(copy);
                }
            }
        }
        ans++;
    }
    return 0;
}
int main()
{
    // cout<<"HellO";
    string beginWord = "hit";
    string endWord =  "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    // string beginWord = "hit";
    // string endWord =  "cog";
    // vector<string> wordList = {"hot","dot","dog","lot","log"};
    // cout<<beginWord<<" "<<endWord<<endl;
    // string beginWord = "hot";
    // string endWord =  "dog";
    // vector<string> wordList = {"hot","dog"};

    // string beginWord = "a";
    // string endWord = "z";
    // vector<string> wordList = {"b"};

    // string beginWord = "hot";
    // string endWord =  "dog";
    // vector<string> wordList = {"hot","dog","dot"};
    cout << ladderLength(beginWord, endWord, wordList);


    // string str = "apple";
    // string copy = str;
    // copy[0]='b';
    // cout<<str;
}