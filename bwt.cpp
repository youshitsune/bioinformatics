#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string bwt(string x){
    vector<char> a;
    vector<string> b;

    for (int i = 0; i < x.length(); i++){
        a.push_back((char)x[i]);
    }
    a.push_back('$');

    for (int i = 0; i <= x.length(); i++){
        a.push_back(a[0]);
        a.erase(a.begin());
        string tmp;
        for (int i = 0; i < a.size(); i++){
            tmp += a[i];
        }
        b.push_back(tmp);
    }
    sort(b.begin(), b.end());
    string tmp;
    for (int i = 0; i < b.size(); i++){
        tmp+=b[i][x.length()];
    }
    return tmp;
}

string debwt(string x){
    map<char, int> d;
    vector<int> ranks;
    for (int i = 0; i < x.length(); i++){
        ranks.push_back(d[x[i]]);
        d[x[i]] += 1;
    }

    map<char, pair<int, int>> e;
    int t = 0;
    map<char, int>::iterator it = d.begin();
    while (it != d.end()){
        e[it->first] = {t, t + it->second};
        t+=it->second;
        ++it;
    }

    int i = 0;
    string te = "$";
    while (x[i] != '$'){
        te = x[i] + te;
        i = e[x[i]].first + ranks[i];
    }
    return te;


}

int main(){
    string x;
    cout << ">>> ";
    cin >> x;
    string y = bwt(x);
    cout << debwt(y);
}
