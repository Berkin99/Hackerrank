#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'caesarCipher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

string caesarCipher(string s, int k) {
    int len = s.size();
    int l = k % 26;
    string temp;
    for (int i = 0; i < len; i++) {
        int tem = s[i];
        if (64 < tem && tem < 91) {
            tem += l;
            if (tem > 90) tem -= 26;
        }

        if (96 < tem && tem < 123) {
            tem += l;
            if (tem > 122) tem -= 26;
        }
        temp.push_back(tem);
    }

    //[65,90]  = A-Z; 
    //[97,122] = a-z;
    return temp;
}

int main()
{

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = caesarCipher(s, k);

    cout << result << endl;

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
