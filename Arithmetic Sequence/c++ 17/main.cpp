#include <vector>
#include <iostream>
#include <any>
#include "ArithmeticSequence.h"

using namespace std;

void printAny(char * text, any value){
    if (value.type() == typeid(int)){
        cout << text << any_cast<int>(value) << endl;
    }
    if (value.type() == typeid(double)){
        cout << text << any_cast<double>(value) << endl;
    }
}

int main() {

    ArithmeticSequence *data = new ArithmeticSequence(new vector<int>{
            6, 9, 12, 15, 18, 21
    });

    printAny("Difference : ",data->getDifference());
    printAny("Next Term : ",data->getNextTerm());
    printAny("Value From Index(n) : ",data->getValueFromIndex(10));
    printAny("Index From Value(value) : ",data->getIndexFromValue(30));
    printAny("Sum : ",data->getSum());
    printAny("Sum in Range(start,end) : ",data->getSum(0,1));

    return 0;
}