class ArithmeticSequence {
    private var idata: IntArray? = null
    private var ddata: DoubleArray? = null

    constructor(idata: IntArray?) {
        this.idata = idata
    }

    constructor(ddata: DoubleArray?) {
        this.ddata = ddata
    }

    val difference: Any
        get() {
            var r: Any = ""
            r = if (idata == null) {
                ddata!![1] - ddata!![0]
            } else {
                idata!![1] - idata!![0]
            }
            return r
        }
    val nextTerm: Any
        get() {
            var r: Any = ""
            r = if (idata == null) {
                ddata!![ddata!!.size - 1] + difference as Double
            } else {
                idata!![idata!!.size - 1] + difference as Int
            }
            return r
        }

    // public String getNthTerm(){return "";}
    fun getValueFromIndex(n: Int): Any {
        var r: Any = ""
        r = if (idata == null) {
            ddata!![0] + difference as Double * (n - 1)
        } else {
            idata!![0] + difference as Int * (n - 1)
        }
        return r
    }

    fun getIndexFromValue(value: Any): Any {
        var r: Any = ""
        r = if (idata == null) {
            (value as Double - ddata!![0]) / difference as Double + 1
        } else {
            (value as Int - idata!![0]) / difference as Int + 1
        }
        return r
    }

    val sum: Any?
        get() {
            var r: Any? = ""
            if (idata == null) {
                var i = ddata!![0]
                for (j in 1 until ddata!!.size) {
                    i += ddata!![j]
                }
                r = i
            } else {
                var i = idata!![0]
                for (j in 1 until idata!!.size) {
                    i += idata!![j]
                }
                r = i
            }
            return r
        }

    fun getSum(start: Int, end: Int): Any? {
        var r: Any? = ""
        if (idata == null) {
            var i = 0.0
            for (j in start..end) {
                i += ddata!![j]
            }
            r = i
        } else {
            var i = 0
            for (j in start..end) {
                i += idata!![j]
            }
            r = i
        }
        return r
    }
}