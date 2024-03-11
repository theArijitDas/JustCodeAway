#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int deletions = 0;
        for (int i = 0; i < n; ++i) {
            if (i + 2 < n && (s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e')) {
                deletions++;
                i += 2;
            } else if (i + 2 < n && (s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p')) {
                deletions++;
                i += 2;
            }
        }

        cout << deletions << endl;
    }

    return 0;
}