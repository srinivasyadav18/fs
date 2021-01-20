#include <iostream>
#include <string>

using namespace std;

int lcs(const string&a, const string&b, int l, int r){
    if (l == 0 || r == 0) return 0;
    if (a[l] == b[r]) return 1 + lcs(a, b, l-1, r-1);
    return 1 + max(lcs(a, b, l-1, r), lcs(a, b, l, r-1));
}
int main(){
    string a, b;
    cin >> a >> b;
    cout << lcs(a, b, a.length() - 1, b.length() -1);
}