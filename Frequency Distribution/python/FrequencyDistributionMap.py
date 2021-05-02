import math


class FrequencyDistributionMap:
    def __init__(self, data):
        self.data = data
        self.size = len(data)
        self.min = min(data)
        self.max = max(data)
        self.range = self.max - self.min
        self.classAmount = round(1 + (3.3 * math.log10(self.size)))
        self.classLength = round(self.range / round(self.classAmount)) - 1
        self._intervalBottom = []
        self._intervalTop = []
        self.frequency = []
        self.classMark = []
        self.trueLowerLimit = []
        self.trueUpperLimit = []
        self.cumulativeFrequencyLessThanType = []
        self.cumulativeFrequencyGreaterThanType = []
        self.setupInterval()
        self.setupFrequency()
        self.setupLessAndGreater()

    def getInterval(self, index, splitter):
        return str(self._intervalBottom[index]) + splitter + str(self._intervalTop[index])

    def getIntervalBottom(self, index):
        return self._intervalBottom[index]

    def getIntervalTop(self, index):
        return self._intervalTop[index]

    def getFrequency(self, index):
        return self.frequency[index]

    def getClassMark(self, index):
        return self.classMark[index]

    def getClassBoundaries(self, index, splitter):
        return str(self.trueLowerLimit[index]) + splitter + str(self.trueUpperLimit[index])

    def getTrueLowerLimit(self, index):
        return self.trueLowerLimit[index]

    def getTrueUpperLimit(self, index):
        return self.trueUpperLimit[index]

    def getCumulativeFrequencyLessThanType(self, index):
        return self.cumulativeFrequencyLessThanType[index]

    def getCumulativeFrequencyGreaterThanType(self, index):
        return self.cumulativeFrequencyGreaterThanType[index]

    def getRow(self):
        return len(self._intervalBottom)

    def getSize(self):
        return self.size

    def getMin(self):
        return self.min

    def getMax(self):
        return self.max

    def getMean(self):
        total = 0.0
        for i in range(0, self.classAmount):
            total += (self.frequency[i] * self.classMark[i])
        return total / self.getSize()

    def getRange(self):
        return self.range

    def getClassAmount(self):
        return self.classAmount

    def getClassLength(self):
        return self.classLength

    def setupInterval(self):
        for i in range(0, self.classAmount):
            self.addInterval(self.getMin() + ((self.getClassLength() + 1) * i),
                             (self.getMin() + self.getClassLength()) + ((self.getClassLength() + 1) * i))

    def setupFrequency(self):
        for i in range(0, self.getSize()):
            for j in range(0, self.classAmount):
                if self._intervalBottom[j] <= self.data[i] <= self._intervalTop[j]:
                    count = self.frequency[j] + 1
                    self.frequency[j] = count

    def setupLessAndGreater(self):
        countLess = 0
        countGreater = self.getSize()
        for i in range(0, self.classAmount):
            countLess += self.frequency[i]
            self.cumulativeFrequencyLessThanType.append(countLess)
            countGreater -= self.frequency[i]
            self.cumulativeFrequencyGreaterThanType.append(countGreater)

    def addInterval(self, intervalBottom, intervalTop):
        self._intervalBottom.append(intervalBottom)
        self._intervalTop.append(intervalTop)
        self.frequency.append(0)
        self.classMark.append(intervalBottom + ((intervalTop - intervalBottom) / 2))
        self.trueLowerLimit.append(intervalBottom - 0.5)
        self.trueUpperLimit.append(intervalTop + 0.5)
