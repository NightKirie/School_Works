using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Q1_F74056069
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] hand = new string[] {"Stone", "Scissor", "Paper"};
            int win = 0, lose = 0, tie = 0;
            Console.Write("How many rounds will you play?\n> ");
            int N = int.Parse(Console.ReadLine());
            for(int i = 0; i < N; i++)
            {
                Console.Write("make your choice!(0:Stone, 1:Scissor, 2:Paper)\n> ");
                int choose = int.Parse(Console.ReadLine());
                Random rand = new Random();
                int com_choose = rand.Next(3); 
                switch (choose)
                {
                    case 0:
                        switch (com_choose)
                        {
                            case 0:
                                Console.Write("You chose {0}, and computer chose {1}\nTie!\n\n", hand[choose], hand[com_choose]);
                                ++tie;
                                break;
                            case 1:
                                Console.Write("You chose {0}, and computer chose {1}\nYou win!\n\n", hand[choose], hand[com_choose]);
                                ++win;
                                break;
                            case 2:
                                Console.Write("You chose {0}, and computer chose {1}\nYou lose!\n\n", hand[choose], hand[com_choose]);
                                ++lose;
                                break;
                        }
                        break;
                    case 1:                       
                        switch (com_choose)
                        {
                            case 0:
                                Console.Write("You chose {0}, and computer chose {1}\nYou lose!\n\n", hand[choose], hand[com_choose]);
                                ++lose;
                                break;
                            case 1:
                                Console.Write("You chose {0}, and computer chose {1}\nTie!\n\n", hand[choose], hand[com_choose]);
                                ++tie;
                                break;
                            case 2:
                                Console.Write("You chose {0}, and computer chose {1}\nYou win!\n\n", hand[choose], hand[com_choose]);
                                ++win;
                                break;
                        }
                        break;
                    case 2:
                        switch (com_choose)
                        {
                            case 0:
                                Console.Write("You chose {0}, and computer chose {1}\nYou win!\n\n", hand[choose], hand[com_choose]);
                                ++win;
                                break;
                            case 1:
                                Console.Write("You chose {0}, and computer chose {1}\nYou lose!\n\n", hand[choose], hand[com_choose]);
                                ++lose;
                                break;
                            case 2:
                                Console.Write("You chose {0}, and computer chose {1}\nTie!\n\n", hand[choose], hand[com_choose]);
                                ++tie;
                                break;
                        }
                        break;
                }
            }
            Console.WriteLine("Total Result");
            Console.WriteLine("Win:{0}, Lose:{1}, Tie:{2}", win, lose, tie);
            Console.WriteLine("Press any key to continue!");    
            Console.Read();
        }
    }
}
