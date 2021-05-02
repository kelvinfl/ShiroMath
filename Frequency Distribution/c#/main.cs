using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program
{
    static void Main(string[] args)
    {
        FrequencyDistributionMap map = new FrequencyDistributionMap(new int[] {
            27,47,54,64,75,
            35,47,56,64,75,
            38,48,58,64,77,
            39,48,58,65,79,
            40,49,59,65,81,
            42,50,60,66,84,
            42,50,60,69,85,
            43,52,62,69,89,
            45,53,62,72,92,
            46,53,63,73,94
        });

        Console.WriteLine("Count : " + map.Size);
        Console.WriteLine("Min   : " + map.Min);
        Console.WriteLine("Max   : " + map.Max);
        Console.WriteLine("Range : " + map.Range);
        Console.WriteLine("Class Amount : " + map.ClassAmount);
        Console.WriteLine("Class Length : " + map.ClassLength);

        for (int i = 0; i < map.Row; i++)
        {
            Console.WriteLine(" | " + map.getInterval(i, "-") + " | " + map.getFrequency(i) + " | " + map.getClassMark(i) + " | " + map.getClassBoundaries(i, "-") + " | " + map.getCumulativeFrequencyLessThanType(i) + " | " + map.getCumulativeFrequencyGreaterThanType(i) + " | ");
        }

        Console.WriteLine("Mean : " + map.Mean);
        Console.ReadKey();
    }
}
