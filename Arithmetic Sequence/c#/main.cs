using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class main
{
    static void Main(string[] args)
    {
        ArithmeticSequence map = new ArithmeticSequence(new int[] {
            6, 9, 12, 15, 18, 21
        });
        Console.WriteLine("Difference : " + map.Difference);
        Console.WriteLine("Next Term : " + map.NextTerm);
        Console.WriteLine("Value From Index(n) : " + map.getValueFromIndex(10));
        Console.WriteLine("Index From Value(value) : " + map.getIndexFromValue(30));
        Console.WriteLine("Sum : " + map.Sum);
        Console.WriteLine("Sum in Range(start,end) : " + map.getSum(0, 1));
        Console.ReadKey();
    }
}
