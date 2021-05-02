import java.util.ArrayList
import java.util.Arrays
import kotlin.math.log10
import kotlin.math.roundToInt

class FrequencyDistributionMap(private val data: IntArray) {
    val size: Int = data.size
    val min: Int
    val max: Int
    val range: Int
    val classAmount: Long
    val classLength: Int
    private val _intervalBottom: MutableList<Int> = ArrayList()
    private val _intervalTop: MutableList<Int> = ArrayList()
    private val frequency: MutableList<Int> = ArrayList()
    private val classMark: MutableList<Double> = ArrayList()
    private val trueLowerLimit: MutableList<Double> = ArrayList()
    private val trueUpperLimit: MutableList<Double> = ArrayList()
    private val cumulativeFrequencyLessThanType: MutableList<Int> = ArrayList()
    private val cumulativeFrequencyGreaterThanType: MutableList<Int> = ArrayList()
    fun getInterval(index: Int, splitter: String): String {
        return _intervalBottom[index].toString() + splitter + _intervalTop[index]
    }

    fun getIntervalBottom(index: Int): Int {
        return _intervalBottom[index]
    }

    fun getIntervalTop(index: Int): Int {
        return _intervalTop[index]
    }

    fun getFrequency(index: Int): Int {
        return frequency[index]
    }

    fun getClassMark(index: Int): Double {
        return classMark[index]
    }

    fun getClassBoundaries(index: Int, splitter: String): String {
        return trueLowerLimit[index].toString() + splitter + trueUpperLimit[index]
    }

    fun getTrueLowerLimit(index: Int): Double {
        return trueLowerLimit[index]
    }

    fun getTrueUpperLimit(index: Int): Double {
        return trueUpperLimit[index]
    }

    fun getCumulativeFrequencyLessThanType(index: Int): Int {
        return cumulativeFrequencyLessThanType[index]
    }

    fun getCumulativeFrequencyGreaterThanType(index: Int): Int {
        return cumulativeFrequencyGreaterThanType[index]
    }

    val row: Int
        get() = _intervalBottom.size
    val mean: Double
        get() {
            var total = 0.0
            for (i in 0 until classAmount) {
                total += frequency[i.toInt()] * classMark[i.toInt()]
            }
            return total / size
        }

    private fun setupInterval() {
        for (i in 0 until classAmount) {
            addInterval((min + (classLength + 1) * i).toInt(), (min + classLength + (classLength + 1) * i).toInt())
        }
    }

    private fun setupFrequency() {
        for (i in 0 until size) {
            for (j in 0 until classAmount) {
                if (data[i] >= _intervalBottom[j.toInt()] && data[i] <= _intervalTop[j.toInt()]) {
                    var count = frequency[j.toInt()]
                    count++
                    frequency[j.toInt()] = count
                }
            }
        }
    }

    private fun setupLessAndGreater() {
        var countLess = 0
        var countGreater = size
        for (i in 0 until classAmount) {
            countLess += frequency[i.toInt()]
            cumulativeFrequencyLessThanType.add(countLess)
            countGreater -= frequency[i.toInt()]
            cumulativeFrequencyGreaterThanType.add(countGreater)
        }
    }

    private fun addInterval(intervalBottom: Int, intervalTop: Int) {
        _intervalBottom.add(intervalBottom)
        _intervalTop.add(intervalTop)
        frequency.add(0)
        classMark.add(intervalBottom.toDouble() + (intervalTop.toDouble() - intervalBottom.toDouble()) / 2)
        trueLowerLimit.add(intervalBottom.toDouble() - 0.5)
        trueUpperLimit.add(intervalTop.toDouble() + 0.5)
    }

    init {
        val stat = Arrays.stream(data).summaryStatistics()
        min = stat.min
        max = stat.max
        range = max - min
        classAmount = (1 + 3.3 * log10(data.size.toDouble())).roundToInt().toLong()
        classLength = range / classAmount.toFloat().roundToInt()
        setupInterval()
        setupFrequency()
        setupLessAndGreater()
    }
}