// C++ Program to illustrate use of std::lower_bound()
// and std::upper_bound() for vector
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {11, 34, 56, 67, 89};

      // Finding lower bound of 56
    cout << *lower_bound(v.begin(), v.end(), 56)
      << endl;
    
      // Finding upper bound of 56
    cout << *upper_bound(v.begin(), v.end(), 56);
    return 0;
}

/*output:
56
67
*/