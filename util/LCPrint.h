#ifndef LCPRINT
#define LCPRINT

#include "LeetCodeIncludes.h"

template<typename T>
void LCPrint(const vector<vector<T>> &v) {
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << "\t";
        }
        cout << endl;
    }
}

#endif //LCPRINT
