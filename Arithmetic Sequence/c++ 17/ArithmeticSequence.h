#ifndef UNTITLED_ARITHMETICSEQUENCE_H
#define UNTITLED_ARITHMETICSEQUENCE_H

#include <vector>
#include <any>
#include <optional>

using namespace std;

class ArithmeticSequence
{

public:
    vector<int> idata;
    vector<double> ddata;

    explicit ArithmeticSequence(vector<int> *idata);

    explicit ArithmeticSequence(vector<double> *ddata);

    virtual any getDifference();

    virtual any getNextTerm();

    // virtual any getNthTerm();

    virtual any getValueFromIndex(int n);

    virtual any getIndexFromValue(any value);

    virtual any getSum();

    virtual any getSum(int start, int end);

};

#endif
