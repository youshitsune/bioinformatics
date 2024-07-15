#include <iostream>
#include <string>

using namespace std;

int main(){
    int match, mismatch, gap;
    string a, b;
    cout << "Match: ";
    cin >> match;
    cout << "Mismatch: ";
    cin >> mismatch;
    cout << "Gap: ";
    cin >> gap;
    cout << "First sequence: ";
    cin >> a;
    cout << "Second sequence: ";
    cin >> b;
    a = "-" + a;
    b = "-" + b;
    int m[a.length()][b.length()];
    int x, y, z;
    for (int i = 0; i < a.length(); i++){
        for (int j = 0; j < b.length(); j++){
            if (i == 0 && j == 0) m[i][j] = 0;   
            else if (i == 0) m[i][j] = m[i][j-1] + gap;
            else if (j == 0) m[i][j] = m[i-1][j] + gap;
            else{
                if (a[i] == b[j]) x = m[i-1][j-1] + match;
                else x = m[i-1][j-1] + mismatch;
                y = m[i-1][j] + gap;
                z = m[i][j-1] + gap;
                m[i][j] = max(max(x, y), z);
            }
        }
    }
    cout << "Alignment score: " << m[a.length()-1][b.length()-1] << '\n';

    return 0;
}
