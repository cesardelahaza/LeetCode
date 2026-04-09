# General information

## Importation

```
#include <bits/stdc++.h>
using namespace std;
```

This imports everything, but we need to change the compiler, which says `usr/bin/clang` to the one that gives us `which g++` in the terminal.

However, what we will do is:

```
#include <iostream>
#include <specific includings>
using namespace std;
```

## How to run the code

To run the code we use a function outside the class like

```
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // my solution...
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    vector<int> result = sol.twoSum(nums, 9);
    cout << result[0] << ", " << result[1] << endl;
    return 0;
}
```

Then in terminal:

```
g++ -o two_sum 001_two_sum.cpp
./two_sum
```

In addition, in `C/C++: Edit Configurations (UI)` in `C++ Standard` change to `C++17`. Then create a `.sh` file with:

```
#!/bin/bash
g++ -std=c++17 -o $1 $1.cpp
./$1
```

Then, to execute: `./compile.sh 001_two_sum`, for example.

