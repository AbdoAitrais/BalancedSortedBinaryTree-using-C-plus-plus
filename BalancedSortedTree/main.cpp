#include <iostream>
#include "Classes/BSTree.cpp"

int main() {
    srand(time(nullptr));
    BSTree<int> bst;
    int value = 10005;

    for (int i = 0; i < 100000000; ++i) {
        bst.insert(i);
    }
    float start = clock();
    bool exist = bst.find(value);
    float end = clock();

    if (exist)
        cout << value << " exist" << endl;

    else
        cout << value << " doesn't exist" << endl;

    cout << "Search time : " << (end - start)/CLOCKS_PER_SEC << endl;

    cout << endl;


    //bst.showGraphicBSTree();

    //cout << bst.root->left->left->left->height;

    return 0;
}
