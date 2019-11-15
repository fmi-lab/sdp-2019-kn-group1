#include<iostream>
#include"DoubleArray.h"
using namespace std;

void expect(const char* expected_output) {
    cout << "\nExpected:\n" << expected_output << "\n\n";
}

int main() {
    DoubleArray numbers;
    
    numbers.add_element(2.3);
    numbers.add_element(3.45);
    numbers.add_element(5.67);
    
    for(DoubleArray::Iterator it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << ' ';
    }
    
    expect("2.3 3.45 5.67");
}