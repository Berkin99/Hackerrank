#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//cases int first line

// for cases:
// n,m : for n
//          for m
//             num
// her n = 0 m =0,1,2,3,4,5
//     n = 1 m =0,1,2,3,4,5
 
struct Matrix {
    vector<vector<int>> a;

    Matrix operator+(const Matrix mx) {
        Matrix result;
        int i, j;
        i = this->a.size();
        j = this->a[0].size();

        // if (mx.a.size()<i) i = mx.a.size();
        // if (mx.a[0].size()<j) j= mx.a[0].size();

        for (int k = 0; k < i; k++) {
            vector <int> v;
            int num;

            for (int l = 0; l < j; l++) {
                num = a[k][l] + mx.a[k][l];
                v.push_back(num);
            }
            result.a.push_back(v);
        }
        return result;
    }
};



int main() {
    int cases, k;
    cin >> cases;
    for (k = 0; k < cases; k++) {
        Matrix x;
        Matrix y;
        Matrix result;
        int n, m, i, j;
        cin >> n >> m;
        for (i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);
        }
        for (i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);
        }
        result = x + y;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cout << result.a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}


