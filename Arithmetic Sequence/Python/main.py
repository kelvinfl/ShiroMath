from ArithmeticSequence import ArithmeticSequence

if __name__ == '__main__':
    map = ArithmeticSequence([
        6, 9, 12, 15, 18, 21
    ])
    print("Difference : " + str(map.getDifference()))
    print("Next Term : " + str(map.getNextTerm()))
    print("Value From Index(n) : " + str(map.getValueFromIndex(10)))
    print("Index From Value(value) : " + str(map.getIndexFromValue(30)))
    print("Sum : " + str(map.getSum()))
    print("Sum in Range(start,end) : " + str(map.getSumRange(0, 1)))