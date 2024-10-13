#include <iostream>
#include <vector>

using namespace std;

void intPrint(char *name, int value) {
    printf("name: %s\tvalue: %d\n", name, value);
};

void vecPrint(char *name, vector<double> value) {
    for (int i : value) {
        cout << i << " ";
    };
};