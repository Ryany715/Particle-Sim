#include <iostream>
#include <vector>
using namespace std;

void intPrint(char *name, int value) {
    printf("name: %s\tvalue: %d\n", name, value);
};

void floatPrint(char *name, float value) {
    printf("%s\t %f\n", name, value);
};

void vecPrint(char *name, vector<double> value) {
     printf("%s\tvalue: ", name);
    for (double i : value) {
        cout << i << " ";
    };
    cout << "\n";
};