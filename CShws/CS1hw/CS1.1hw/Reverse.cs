using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//2.Выполнить реверс введенного пользователем числа:

namespace CS1._1hw
{
    internal class ReverseInt
    {
        private int number;

        public ReverseInt()
        {
            Console.WriteLine("Введите число:\n");
            string input = Console.ReadLine(); Console.WriteLine();

            for (int i = 0; i < input.Length; i++)
            {
                if (!char.IsDigit(input[i]))
                {
                    Console.WriteLine("\nОшибка: введенное значение не является числом...\n");
                    number = 0;
                    return;
                }
            }
            number = Convert.ToInt32(input);
        }
        public int Reverse()
        {
            string s = number.ToString();
            char[] chars = s.ToCharArray();
            Array.Reverse(chars);
            s = new string(chars);
            return Convert.ToInt32(s);
        }
        public void Print()
        {
            Console.WriteLine($"\nИзначальное число:\n\n {number} \n\nРеверсированное число:\n\n {Reverse()}\n");
        }
    }
}
