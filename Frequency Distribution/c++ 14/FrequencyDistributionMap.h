#ifndef CLION_PROJECT_FREQUENCYDISTRIBUTIONMAP_H
#define CLION_PROJECT_FREQUENCYDISTRIBUTIONMAP_H

#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

class FrequencyDistributionMap
{

private:
    vector<int> data;
    int size = 0;
    int min = 0;
    int max = 0;
    int range = 0;
    long classAmount;
    int classLength = 0;

    vector<int> _intervalBottom = vector<int>();
    vector<int> _intervalTop = vector<int>();
    vector<int> frequency = vector<int>();
    vector<double> classMark = vector<double>();
    vector<double> trueLowerLimit = vector<double>();
    vector<double> trueUpperLimit = vector<double>();
    vector<int> cumulativeFrequencyLessThanType = vector<int>();
    vector<int> cumulativeFrequencyGreaterThanType = vector<int>();

public:
    FrequencyDistributionMap(vector<int> *data);

    virtual wstring getInterval(int index, const wstring &splitter);

    virtual int getIntervalBottom(int index);

    virtual int getIntervalTop(int index);

    virtual int getFrequency(int index);

    virtual double getClassMark(int index);

    virtual wstring getClassBoundaries(int index, const wstring &splitter);

    virtual double getTrueLowerLimit(int index);

    virtual double getTrueUpperLimit(int index);

    virtual int getCumulativeFrequencyLessThanType(int index);

    virtual int getCumulativeFrequencyGreaterThanType(int index);

    virtual int getRow();

    virtual int getSize();

    virtual int getMin();

    virtual int getMax();

    virtual double getMean();

    virtual int getRange();

    virtual long getClassAmount();

    virtual int getClassLength();

private:
    void setupInterval();

    void setupFrequency();

    void setupLessAndGreater();

    void addInterval(int intervalBottom, int intervalTop);

};

#endif
