#include "FrequencyDistributionMap.h"

FrequencyDistributionMap::FrequencyDistributionMap(vector<int> *data)
{
    this->data = *data;
    size = data->size();
    min = *min_element(data->begin(),data->end());
    max = *max_element(data->begin(),data->end());
    range = max - min;
    classAmount = static_cast<long long>(round(1 + ((3.3) * log10(data->size()))));
    classLength = range / static_cast<long long>(round(classAmount));
    setupInterval();
    setupFrequency();
    setupLessAndGreater();
}

wstring FrequencyDistributionMap::getInterval(int index, const wstring &splitter)
{
    return to_wstring(_intervalBottom[index]) + splitter + to_wstring(_intervalTop[index]);
}

int FrequencyDistributionMap::getIntervalBottom(int index)
{
    return _intervalBottom[index];
}

int FrequencyDistributionMap::getIntervalTop(int index)
{
    return _intervalTop[index];
}

int FrequencyDistributionMap::getFrequency(int index)
{
    return frequency[index];
}

double FrequencyDistributionMap::getClassMark(int index)
{
    return classMark[index];
}

wstring FrequencyDistributionMap::getClassBoundaries(int index, const wstring &splitter)
{
    wstring str1 = to_wstring(trueLowerLimit[index]);
    wstring str2 = to_wstring(trueUpperLimit[index]);
    size_t found1 = str1.find('.');
    size_t found2 = str2.find('.');
    return str1.substr(0,found1+2) + splitter + str2.substr(0,found2+2);
}

double FrequencyDistributionMap::getTrueLowerLimit(int index)
{
    return trueLowerLimit[index];
}

double FrequencyDistributionMap::getTrueUpperLimit(int index)
{
    return trueUpperLimit[index];
}

int FrequencyDistributionMap::getCumulativeFrequencyLessThanType(int index)
{
    return cumulativeFrequencyLessThanType[index];
}

int FrequencyDistributionMap::getCumulativeFrequencyGreaterThanType(int index)
{
    return cumulativeFrequencyGreaterThanType[index];
}

int FrequencyDistributionMap::getRow()
{
    return _intervalBottom.size();
}

int FrequencyDistributionMap::getSize()
{
    return size;
}

int FrequencyDistributionMap::getMin()
{
    return min;
}

int FrequencyDistributionMap::getMax()
{
    return max;
}

double FrequencyDistributionMap::getMean()
{
    double total = 0.0;
    for (int i = 0; i < classAmount; i++)
    {
        total = total + (frequency[i] * classMark[i]);
    }
    return total / getSize();
}

int FrequencyDistributionMap::getRange()
{
    return range;
}

long FrequencyDistributionMap::getClassAmount()
{
    return classAmount;
}

int FrequencyDistributionMap::getClassLength()
{
    return classLength;
}

void FrequencyDistributionMap::setupInterval()
{
    for (int i = 0; i < classAmount; i++)
    {
        addInterval(static_cast<int>(getMin() + ((getClassLength() + 1) * i)), static_cast<int>((getMin() + getClassLength()) + ((getClassLength() + 1) * i)));
    }
}

void FrequencyDistributionMap::setupFrequency()
{
    for (int i = 0; i < getSize(); i++)
    {
        for (int j = 0; j < classAmount; j++)
        {
            if (data[i] >= _intervalBottom[j] && data[i] <= _intervalTop[j])
            {
                int count = frequency[j];
                count++;
                frequency[j] = count;
            }
        }
    }
}

void FrequencyDistributionMap::setupLessAndGreater()
{
    int countLess = 0;
    int countGreater = getSize();
    for (int i = 0; i < classAmount; i++)
    {
        countLess += frequency[i];
        cumulativeFrequencyLessThanType.push_back(countLess);
        countGreater -= frequency[i];
        cumulativeFrequencyGreaterThanType.push_back(countGreater);
    }
}

void FrequencyDistributionMap::addInterval(int intervalBottom, int intervalTop)
{
    _intervalBottom.push_back(intervalBottom);
    _intervalTop.push_back(intervalTop);
    frequency.push_back(0);
    classMark.push_back(static_cast<double>(intervalBottom) + ((static_cast<double>(intervalTop) - static_cast<double>(intervalBottom)) / 2));
    trueLowerLimit.push_back(static_cast<double>(intervalBottom) - 0.5);
    trueUpperLimit.push_back(static_cast<double>(intervalTop) + 0.5);
}
