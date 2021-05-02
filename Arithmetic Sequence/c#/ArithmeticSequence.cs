public class ArithmeticSequence
{

    internal int[] idata = null;
    internal double[] ddata = null;

    public ArithmeticSequence(int[] idata)
    {
        this.idata = idata;
    }

    public ArithmeticSequence(double[] ddata)
    {
        this.ddata = ddata;
    }

    public virtual object Difference
    {
        get
        {
            object r = "";
            if (idata == null)
            {
                r = ddata[1] - ddata[0];
            }
            else
            {
                r = idata[1] - idata[0];
            }
            return r;
        }
    }

    public virtual object NextTerm
    {
        get
        {
            object r = "";
            if (idata == null)
            {
                r = ddata[ddata.Length - 1] + (double)Difference;
            }
            else
            {
                r = idata[idata.Length - 1] + (int)Difference;
            }
            return r;
        }
    }

    // public virtual string getNthTerm(){}

    public virtual object getValueFromIndex(int n)
    {
        object r = "";
        if (idata == null)
        {
            r = ddata[0] + ((double)Difference * (n - 1));
        }
        else
        {
            r = idata[0] + ((int)Difference * (n - 1));
        }
        return r;
    }

    public virtual object getIndexFromValue(object value)
    {
        object r = "";
        if (idata == null)
        {
            r = (((double)value - ddata[0]) / (double)Difference) + 1;
        }
        else
        {
            r = (((int)value - idata[0]) / (int)Difference) + 1;
        }
        return r;
    }

    public virtual object Sum
    {
        get
        {
            object r = "";
            if (idata == null)
            {
                double? i = ddata[0];
                for (int j = 1; j < ddata.Length; j++)
                {
                    i += ddata[j];
                }
                r = i;
            }
            else
            {
                int i = idata[0];
                for (int j = 1; j < idata.Length; j++)
                {
                    i += idata[j];
                }
                r = i;
            }
            return r;
        }
    }

    public virtual object getSum(int start, int end)
    {
        object r = "";
        if (idata == null)
        {
            double? i = 0.0;
            for (int j = start; j <= end; j++)
            {
                i += ddata[j];
            }
            r = i;
        }
        else
        {
            int i = 0;
            for (int j = start; j <= end; j++)
            {
                i += idata[j];
            }
            r = i;
        }
        return r;
    }

}