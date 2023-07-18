#include <bits/stdc++.h>
using namespace std;
string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a1[i]]++;
    }
    /*unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[a1[i]]++;
    }*/
    string str = "yes";
    for(int i = 0; i < m; i++){
        if(mp[a2[i]]==0){
            str = "No";
            return str;
        }
    }
    return str;
}
int main(){
    
}