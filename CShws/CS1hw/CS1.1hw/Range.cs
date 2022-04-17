using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//3.Вывести все числа в диапазоне от А до В:

namespace CS1._1hw
{
    internal class Range
    {
        private int begin, end;

        public Range()
        {
            Console.WriteLine("Введите начало диапазона:\n");
            string input = Console.ReadLine(); Console.WriteLine();
            for (int i = 0; i < input.Length; i++)
            {
                if (!char.IsDigit(input[i]))
                {
                    Console.WriteLine("\nОшибка: введенное значение не является числом...\n");
                    input = "1";
                    break;
                }
            }
            begin = Convert.ToInt32(input);

            Console.WriteLine("Введите конец диапазона:\n");
            input = Console.ReadLine(); Console.WriteLine();
            for (int i = 0; i < input.Length; i++)
            {
                if (!char.IsDigit(input[i]))
                {
                    Console.WriteLine("\nОшибка: введенное значение не является числом...\n");
                    input = "2";
                    break;
                }
            }
            end = Convert.ToInt32(input);
            Console.WriteLine($"Начало диапазона: {begin} \n\nКонец диапазона: {end}\n");
            Console.ReadKey();
        }
        public void Print()
        {
            Console.WriteLine("Результат:\n");
            if(begin > end)
            {
                for (int i = begin; i >= end; i--)
                {
                    for (int j = 0; j < i; j++)
                    {
                        Console.Write(i + " ");
                    }
                    Console.WriteLine();
                }
            }
            for (int i = begin; i <= end; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    Console.Write(i + " ");
                }
                Console.WriteLine();
            }
            
        }
    }
}
