#include <iostream>
#include <bits/stdc++.h>
#include "Classes/BSTree.cpp"


int main() {
    srand(time(nullptr));
    BSTree<int> bst;
    int value = 102005;
    clock_t start, end;

    for (int i = 0; i < 1000000; ++i) {
        bst.insert(i);
    }

    start = clock();
    bool exist = bst.find(value);
    end = clock();
    if (exist)
        cout << value << " exist" << endl;

    else
        cout << value << " doesn't exist" << endl;

    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;

    cout << endl;


    //bst.showGraphicBSTree();

    //cout << bst.root->left->left->left->height;

    return 0;
}
