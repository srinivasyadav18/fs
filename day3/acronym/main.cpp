#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

std::vector<std::string> split(const std::string &str, const std::string &delim)
{
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos)
            pos = str.length();
        std::string token = str.substr(prev, pos - prev);
        if (!token.empty())
            tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}

string hash2(string s){
    int n = s.length();
    if (n <= 2) return s;
    string res;
    res += s[0];
    res += to_string(n-2);
    res += s.back();
    return res;
}

int main(){
    string first, second;
    getline(cin, first);
    getline(cin, second);
    cout << first << endl << second << endl;;

    vector<string> vocab = split(first, " ");
    vector<string> words = split(second, " ");

    unordered_map<string, set<string>> hash_map;
    for (string v : vocab){
        hash_map[hash2(v)].insert(v);
    }
    cout << endl;
    for (auto i : hash_map){
        cout << i.first << " ";
        for (auto j : i.second)
            cout << j << " ";
        cout << endl;
    }
    for (string w : words){
        string h = hash2(w);
        if (hash_map.find(h) == hash_map.end()) {
            cout << "false ";
        }else if (hash_map[h].find(w) == hash_map[h].end()){
            cout << "false ";
        }else cout << "true ";
    }
}