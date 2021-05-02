using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class FrequencyDistributionMap
{
    private int[] data;
    private int size;
    private int min;
    private int max;
    private int range;
    private long classAmount;
    private int classLength;

    private IList<int> _intervalBottom = new List<int>();
    private IList<int> _intervalTop = new List<int>();
    private IList<int> frequency = new List<int>();
    private IList<double> classMark = new List<double>();
    private IList<double> trueLowerLimit = new List<double>();
    private IList<double> trueUpperLimit = new List<double>();
    private IList<int> cumulativeFrequencyLessThanType = new List<int>();
    private IList<int> cumulativeFrequencyGreaterThanType = new List<int>();

    public FrequencyDistributionMap(int[] data)
    {
        this.data = data;
        size = data.Length;
        min = data.Min();
        max = data.Max();
        range = max - min;
        classAmount = (long)Math.Round(1 + ((3.3) * Math.Log10(data.Length)), MidpointRounding.AwayFromZero);
        classLength = range / (int)Math.Round(Convert.ToDouble(classAmount));
        setupInterval();
        setupFrequency();
        setupLessAndGreater();
    }

    public virtual string getInterval(int index, string splitter)
    {
        return _intervalBottom[index] + splitter + _intervalTop[index];
    }

    public virtual int getIntervalBottom(int index)
    {
        return _intervalBottom[index];
    }

    public virtual int getIntervalTop(int index)
    {
        return _intervalTop[index];
    }

    public virtual int getFrequency(int index)
    {
        return frequency[index];
    }

    public virtual double getClassMark(int index)
    {
        return classMark[index];
    }

    public virtual string getClassBoundaries(int index, string splitter)
    {
        return trueLowerLimit[index] + splitter + trueUpperLimit[index];
    }

    public virtual double getTrueLowerLimit(int index)
    {
        return trueLowerLimit[index];
    }

    public virtual double getTrueUpperLimit(int index)
    {
        return trueUpperLimit[index];
    }

    public virtual int getCumulativeFrequencyLessThanType(int index)
    {
        return cumulativeFrequencyLessThanType[index];
    }

    public virtual int getCumulativeFrequencyGreaterThanType(int index)
    {
        return cumulativeFrequencyGreaterThanType[index];
    }

    public virtual int Row
    {
        get
        {
            return _intervalBottom.Count;
        }
    }

    public virtual int Size
    {
        get
        {
            return size;
        }
    }

    public virtual int Min
    {
        get
        {
            return min;
        }
    }

    public virtual int Max
    {
        get
        {
            return max;
        }
    }

    public virtual double? Mean
    {
        get
        {
            double? total = 0.0;
            for (int i = 0; i < classAmount; i++)
            {
                total = total.Value + (frequency[i] * classMark[i]);
            }
            return total.Value / Size;
        }
    }

    public virtual int Range
    {
        get
        {
            return range;
        }
    }

    public virtual long? ClassAmount
    {
        get
        {
            return classAmount;
        }
    }

    public virtual int ClassLength
    {
        get
        {
            return classLength;
        }
    }

    private void setupInterval()
    {
        for (int i = 0; i < classAmount; i++)
        {
            addInterval((int)(Min + ((ClassLength + 1) * i)), (int)((Min + ClassLength) + ((ClassLength + 1) * i)));
        }
    }

    private void setupFrequency()
    {
        for (int i = 0; i < Size; i++)
        {
            for (int j = 0; j < classAmount; j++)
            {
                if (data[i] >= _intervalBottom[j] && data[i] <= _intervalTop[j])
                {
                    int count = frequency[j];
                    count++;
                    frequency[j] = count;
                }
            }
        }
    }

    private void setupLessAndGreater()
    {
        int countLess = 0;
        int countGreater = Size;
        for (int i = 0; i < classAmount; i++)
        {
            countLess += frequency[i];
            cumulativeFrequencyLessThanType.Add(countLess);
            countGreater -= frequency[i];
            cumulativeFrequencyGreaterThanType.Add(countGreater);
        }
    }

    private void addInterval(int intervalBottom, int intervalTop)
    {
        _intervalBottom.Add(intervalBottom);
        _intervalTop.Add(intervalTop);
        frequency.Add(0);
        classMark.Add((double)intervalBottom + (((double)intervalTop - (double)intervalBottom) / 2));
        trueLowerLimit.Add((double)intervalBottom - 0.5);
        trueUpperLimit.Add((double)intervalTop + 0.5);
    }
}
