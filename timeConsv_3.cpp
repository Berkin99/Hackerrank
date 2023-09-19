#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

typedef struct time_r {
    int t[4];
    string get_stim() {
        return get_2dig(t[0]) + ":" + get_2dig(t[1]) + ":" + get_2dig(t[2]);
    }
    string get_2dig(int dig) {
        string s = to_string(dig);
        return ((dig < 10) ? "0" : "") + s;
    }
}time_s;

time_s stotime(string s) {
    time_s tim;
    int len = s.size();
    for (int i = 0; i < 3; i++) {
        tim.t[i] = stoi(s.substr(3 * i, 3 * i + 2));
    }
    if (len < 8) tim.t[3] = 0;
    else if (s[8] == 'A') tim.t[3] = 1;
    else if (s[8] == 'P') tim.t[3] = 2;

    return tim;
}

string timetos(time_s tim, bool ampm = false) {
    if (ampm) {
        return tim.get_stim();
    }
    else {
        if (tim.t[3] == 0) return tim.get_stim();

        int hr = tim.t[0];
        if (tim.t[3] == 1) { if (hr == 12) hr = 0; }
        else if (hr != 12) hr += 12;

        string s = tim.get_stim();
        return tim.get_2dig(hr) + s.substr(2, 6);
    }
}

string timeConversion(string s) {
    time_s tim;
    tim = stotime(s);
    return timetos(tim, false);
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
