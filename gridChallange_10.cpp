#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

string gridChallenge(vector<string> grid) {
    int xlen = grid[0].size();
    int ylen = grid.size();

    if (ylen <= 1)return "YES";
    for (int i = 0; i < ylen; i++) {
        sort(grid[i].begin(), grid[i].end());
    }

    for (int i = 0; i < ylen; i++) {
        for (int j = 0; j < xlen - 1; j++) {
            if (grid[j][i] <= grid[j + 1][i]) continue;
            return "NO";
        }
    }
    return "YES";
}

int main()
{
    
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<string> grid;

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(cin, grid_item);

            grid.push_back(grid_item);
        }

        string result = gridChallenge(grid);

        cout << result << "\n";
    }

    
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
