object main {
    private fun print(data: Any?) {
        println(data)
    }

    @JvmStatic
    fun main(args: Array<String>) {
        val map = FrequencyDistributionMap(intArrayOf(
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
        ))
        print("Count : " + map.size)
        print("Min   : " + map.min)
        print("Max   : " + map.max)
        print("Range : " + map.range)
        print("Class Amount : " + map.classAmount)
        print("Class Length : " + map.classLength)
        for (i in 0 until map.row) {
            print(" | " +
                    map.getInterval(i, "-") + " | " +
                    map.getFrequency(i) + " | " +
                    map.getClassMark(i) + " | " +
                    map.getClassBoundaries(i, "-") + " | " +
                    map.getCumulativeFrequencyLessThanType(i) + " | " +
                    map.getCumulativeFrequencyGreaterThanType(i) + " | "
            )
        }
        print("Mean : " + map.mean)
    }
}