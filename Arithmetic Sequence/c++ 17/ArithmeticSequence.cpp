#include "ArithmeticSequence.h"

ArithmeticSequence::ArithmeticSequence(vector<int> *idata)
{
    this->idata = *idata;
}

ArithmeticSequence::ArithmeticSequence(vector<double> *ddata)
{
    this->ddata = *ddata;
}

any ArithmeticSequence::getDifference()
{
    any r = L"";
    if (idata.empty())
    {
        r = ddata[1] - ddata[0];
    }
    else
    {
        r = idata[1] - idata[0];
    }
    return r;
}

any ArithmeticSequence::getNextTerm()
{
    any r = L"";
    if (idata.empty())
    {
        r = ddata[ddata.size() - 1] + any_cast<double>(getDifference());
    }
    else
    {
        r = idata[idata.size() - 1] + any_cast<int>(getDifference());
    }
    return r;
}

any ArithmeticSequence::getValueFromIndex(int n)
{
    any r = L"";
    if (idata.empty())
    {
        r = ddata[0] + (any_cast<double>(getDifference()) * (n - 1));
    }
    else
    {
        r = idata[0] + (any_cast<int>(getDifference()) * (n - 1));
    }
    return r;
}

any ArithmeticSequence::getIndexFromValue(any value)
{
    any r = L"";
    if (idata.empty())
    {
        r = ((any_cast<double>(value) - ddata[0]) / any_cast<double>(getDifference())) + 1;
    }
    else
    {
        r = ((any_cast<int>(value) - idata[0]) / any_cast<int>(getDifference())) + 1;
    }
    return r;
}

any ArithmeticSequence::getSum()
{
    any r = L"";
    if (idata.empty())
    {
        double i = ddata[0];
        for (int j = 1; j < ddata.size(); j++)
        {
            i += ddata[j];
        }
        r = i;
    }
    else
    {
        int i = idata[0];
        for (int j = 1; j < idata.size(); j++)
        {
            i += idata[j];
        }
        r = i;
    }
    return r;
}

any ArithmeticSequence::getSum(int start, int end)
{
    any r = L"";
    if (idata.empty())
    {
        double i = 0.0;
        for (int j = start; j <= end; j++)
        {
            i += ddata[j];
        }
        r = i;
    }
    else
    {
        int i = 0;
        for (int j = start; j <= end; j++)
        {
            i += idata[j];
        }
        r = i;
    }
    return r;
}