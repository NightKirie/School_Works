using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        private static void Hanoi(int plates, char A, char B, char C)
        {
            if (plates == 1)
                Console.WriteLine("Move sheet from {0} ro {1}", A, C);
            else
            {
                Hanoi(plates - 1, A, C, B);
                Hanoi(1, A, B, C);
                Hanoi(plates - 1, B, A, C);
            }
        }
        static void Main(string[] args)
        {
            Console.Write("Please input the number of plates:");
            int plates = int.Parse(Console.ReadLine());
            Hanoi(plates, 'A', 'B', 'C');
            Console.ReadLine();
        }
    }
}
