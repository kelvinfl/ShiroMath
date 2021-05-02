class ArithmeticSequence:
    def __init__(self, data):
        self.data = data

    def getDifference(self):
        return self.data[1] - self.data[0]

    def getNextTerm(self):
        return self.data[len(self.data) - 1] + self.getDifference()

    # def getNthTerm(self):

    def getValueFromIndex(self, n):
        return self.data[0] + (self.getDifference() * (n - 1))

    def getIndexFromValue(self, value):
        return int((value - self.data[0]) / self.getDifference()) + 1

    def getSum(self):
        i = self.data[0]
        for j in range(1, len(self.data)):
            i += self.data[j]
        return i

    def getSumRange(self, start, end):
        i = 0
        for j in range(start, end + 1):
            i += self.data[j]
        return i