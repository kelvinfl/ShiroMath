#include <iostream>
#include "FrequencyDistributionMap.h"

using namespace std;

int main() {

    FrequencyDistributionMap *map = new FrequencyDistributionMap(new vector<int>{
            27,47,54,64,75,
            35,47,56,64,75,
            38,48,58,64,77,
            39,48,58,65,79,
            40,49,59,65,81,
            42,50,60,66,84,
            42,50,60,69,85,
            43,52,62,69,89,
            45,53,62,72,92,
            46,53,63,73,94
    });

    cout << "Count : " << map->getSize() << endl;
    cout << "Min   : " << map->getMin() << endl;
    cout << "Max   : " << map->getMax() << endl;
    cout << "Range : " << map->getRange() << endl;
    cout << "Class Amount : " << map->getClassAmount() << endl;
    cout << "Class Length : " << map->getClassLength() << endl;

    for (int i = 0; i < map->getRow(); i++){
        wcout << " | " <<
              map->getInterval(i, L"-") << " | " <<
              map->getFrequency(i) << " | " <<
              map->getClassMark(i) << " | " <<
              map->getClassBoundaries(i, L"-") << " | " <<
              map->getCumulativeFrequencyLessThanType(i) << " | " <<
              map->getCumulativeFrequencyGreaterThanType(i) << " | " << endl;
        ;
    }

    cout << "Mean : " << map->getMean();

    return 0;
}
