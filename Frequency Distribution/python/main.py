from FrequencyDistributionMap import FrequencyDistributionMap

if __name__ == '__main__':
    map = FrequencyDistributionMap([
        27, 47, 54, 64, 75,
        35, 47, 56, 64, 75,
        38, 48, 58, 64, 77,
        39, 48, 58, 65, 79,
        40, 49, 59, 65, 81,
        42, 50, 60, 66, 84,
        42, 50, 60, 69, 85,
        43, 52, 62, 69, 89,
        45, 53, 62, 72, 92,
        46, 53, 63, 73, 94
    ])
    print("Count : " + str(map.getSize()))
    print("Min   : " + str(map.getMin()))
    print("Max   : " + str(map.getMax()))
    print("Range : " + str(map.getRange()))
    print("Class Amount  : " + str(map.getClassAmount()))
    print("Class Length : " + str(map.getClassLength()))

    for i in range(0, map.getRow()):
        print(" | " +
              map.getInterval(i, "-") + " | " +
              str(map.getFrequency(i)) + " | " +
              str(map.getClassMark(i)) + " | " +
              map.getClassBoundaries(i, "-") + " | " +
              str(map.getCumulativeFrequencyLessThanType(i)) + " | " +
              str(map.getCumulativeFrequencyGreaterThanType(i)) + " | "
              )

    print("Mean : " + str(map.getMean()))
