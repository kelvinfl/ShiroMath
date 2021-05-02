import kotlin.jvm.JvmStatic

object main {
    @JvmStatic
    fun main(args: Array<String>){
        val map = ArithmeticSequence(intArrayOf(
                6, 9, 12, 15, 18, 21
        ))
        println("Difference : " + map.difference)
        println("Next Term : " + map.nextTerm)
        println("Value From Index(n) : " + map.getValueFromIndex(10))
        println("Index From Value(value) : " + map.getIndexFromValue(30))
        println("Sum : " + map.sum)
        println("Sum in Range(start,end) : " + map.getSum(0, 1))
    }
}