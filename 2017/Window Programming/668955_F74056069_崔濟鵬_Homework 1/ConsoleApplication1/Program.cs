using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    public class student{
        public int num, ch, eng, math;
        public student()
        {
            num = 0;
            ch = 0;
            eng = 0;
            math = 0;
        }
        public void setChinese(int ch)
        {
            this.ch = ch;
        }
        public void setEnglish(int eng)
        {
            this.eng = eng;
        }
        public void setMath(int math)
        {
            this.math = math;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Please select the activity: 1)Input data  2)Print out data  3)Sort  0)Exit> ");
            int selection = int.Parse(Console.ReadLine());
            student[] score = null;
            while (selection != 0)
            {   
                switch (selection)
                {
                    case 1:
                        Console.Write("\nPlease input the number of students in class> ");
                        int studentnum = int.Parse(Console.ReadLine());                        
                        score = new student[studentnum];
                        for(int i = 0; i < studentnum; i++)
                        {
                            score[i] = new student();
                            score[i].num = i + 1;
                            Console.WriteLine("\nPlease input the score of No.{0} student:", i+1);
                            Console.Write("Chinese score> ");
                            score[i].setChinese(int.Parse(Console.ReadLine()));
                            Console.Write("English score> ");
                            score[i].setEnglish(int.Parse(Console.ReadLine()));
                            Console.Write("Math score> ");
                            score[i].setMath(int.Parse(Console.ReadLine()));
                        }
                        break;
                    case 2:
                        if (score == null)
                            Console.WriteLine("There is no data!");
                        else
                        {
                            Console.WriteLine("\n\nSeatnumber  Chinese  English  Math");
                            Console.WriteLine("==================================");
                            for(int i = 0; i < score.Length; i++)
                                Console.WriteLine("{0}           {1}        {2}        {3}", score[i].num, score[i].ch, score[i].eng, score[i].math);
                        }
                        break;
                    case 3:
                        if (score == null)
                            Console.WriteLine("There is no data!");
                        else
                        {
                            Console.Write("Please select the method of sorting: 1)Seatnumber  2)Chinese  3)English  4)Math> ");
                            int sorting = int.Parse(Console.ReadLine());
                            switch (sorting)
                            {
                                case 1:
                                    Array.Sort(score, delegate (student x, student y) { return x.num.CompareTo(y.num); });
                                    break;
                                case 2:
                                    Array.Sort(score, delegate (student x, student y) { return x.ch.CompareTo(y.ch); });
                                    break;
                                case 3:
                                    Array.Sort(score, delegate (student x, student y) { return x.eng.CompareTo(y.eng); });
                                    break;
                                case 4:
                                    Array.Sort(score, delegate (student x, student y) { return x.math.CompareTo(y.math); });
                                    break;
                                default:
                                    Console.WriteLine("ERROR INPUT!");
                                    break;
                            }
                        }
                        break;
                    default:
                        Console.WriteLine("ERROR INPUT!");
                        break;
                }
                Console.Write("\nPlease select the activity: 1)Input data  2)Print out data  3)Sort  0)Exit> ");
                selection = int.Parse(Console.ReadLine());
            }
        }
    }
}
