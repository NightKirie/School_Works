using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Please input a decimal number:");
            int num = int.Parse(Console.ReadLine());
            Console.WriteLine("Shift to left or right <Left for 1, Right for 2>:");
            int shift = int.Parse(Console.ReadLine());
            Console.WriteLine("Shift how many digits <Shift in binary way>:");
            int digit = int.Parse(Console.ReadLine());
            Console.WriteLine();
            Console.WriteLine("=========I am the separate line=========");
            Console.WriteLine();
            Console.WriteLine("The number you input is:{0}", num);
            if (shift == 1) 
                Console.WriteLine("The number you input after shifting to left for {0} digits, the answer is {1}", digit, num << digit);
            else if (shift == 2)
                Console.WriteLine("The number you input after shifting to right for {0} digits, the answer is {1}", digit, num >> digit);
            Console.Read();
        }
    }
}
