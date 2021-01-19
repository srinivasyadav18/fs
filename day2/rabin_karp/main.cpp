// Rabin karp using rolling hash
// pattern matching ~ O(T + P)

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define ull unsigned long long

class Solution{
    private:
        string text, pattern;
        int m, n;
        ull p = 0;
        ull t = 0;
    public:

    Solution(string text, string pattern) {
        this->text = text;
        this->pattern = pattern;
        this->m = text.length();
        this->n = pattern.length();

        int idx = n-1;
        for (char c : pattern) {
            ull temp = (ull)pow(10, idx);
            p += temp * (c - 'a') ;
            idx--;    
        }
        idx = n-1;
        for (int i = 0; i < n; i++) {
            char c = text[i];
            ull temp = (ull)pow(10, idx);
            t += temp * (c-'a');
            idx--;
        }
    }

    ull rolling_hash(int idx, ull curr){
        if (idx == 0) return t;
        ull prev = (ull)pow(10, n-1);
        prev *= (text[idx-1] -'a') ;
        ull offset = text[idx + n-1] - 'a';
        curr = ((curr - prev) * 10) + offset;
        return curr;
    }

    void rabin_karp(){
        ull curr = t;
        for (int i = 0; i < m - n + 1; i++){
            curr = rolling_hash(i, curr);
            if (curr == p){
                if (pattern == text.substr(i, n)) {
                    cout << "true\n";
                    exit(0);
                }
            }
        }
    }
};

int main(){
    string text, pattern;
    Solution s = Solution("abcbcaada", "aad");
    s.rabin_karp();
    cout << "false\n";
}