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
            Console.WriteLine("Please select 1> Sqaure 2> Triangle:");
            int choose = int.Parse(Console.ReadLine());
            if (choose == 1)
            {
                Console.WriteLine("Please input the size you want to draw");
                int size = int.Parse(Console.ReadLine());
                for (int i = 1; i <= size; i++)
                {
                    for (int j = 1; j <= size; j++) 
                        Console.Write("*");
                    Console.WriteLine("");
                }
                Console.WriteLine("Total using {0} '*'", size*size);
            }
            else if (choose == 2)
            {
                Console.WriteLine("Please input the size you want to draw");
                int size = int.Parse(Console.ReadLine());
                for (int i = 1; i <= size; i++)
                {
                    for(int j = 1; j <= size - i; j++)
                        Console.Write(" ");
                    for (int j = 1; j <= i*2 - 1; j++)
                        Console.Write("{0}", i);
                    Console.WriteLine("");
                }
                Console.WriteLine("Total using {0} groups of numbers and {1} numbers", size, size * size);
            }
            else
                Console.WriteLine("Please restart!\nPress any key to continue...");
            Console.Read();

        }
    }
}
