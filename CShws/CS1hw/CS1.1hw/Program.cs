using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace CS1._1hw
{
    internal class Program
    {
        static void Main(string[] args)
        {
            bool isExit = false;
            while (!isExit)
            {
                Console.WriteLine("С# 1: СПИСОК КОМАНД\n");
                Console.WriteLine("/register - изменение регистра;");
                Console.WriteLine("/reverse - реверс числа;");
                Console.WriteLine("/range - вывод всех чисел от А до B;");
                Console.WriteLine("/exit - выход.\n");

                Console.WriteLine("Введите команду:\n");

                string input = Console.ReadLine(); Console.WriteLine();

                if(input == "/register")
                {
                    //1.Изменить введенную строку пользователем на противоположный регистр (реализовано в Register.cs):

                    Register register = new Register(); register.Print();
                    Console.ReadKey(); Console.Clear();
                }
                else if(input == "/reverse")
                {
                    //2.Выполнить реверс введенного пользователем числа (реализовано в Reverse.cs):

                    ReverseInt reverseInt = new ReverseInt(); reverseInt.Print();
                    Console.ReadKey(); Console.Clear();
                }
                else if(input == "/range")
                {
                    //3. Вывести все числа в диапазоне от А до В (реализовано в Range.cs):

                    Range range = new Range(); range.Print();
                    Console.ReadKey(); Console.Clear();
                }
                else if(input == "/exit")
                {
                    isExit = true;
                }
                else
                {
                    Console.WriteLine("Ошибка: введена неизвестная команда..."); 
                    Thread.Sleep(1000); Console.Clear();
                }
            }

            Console.WriteLine("Выход из программы..."); Thread.Sleep(1000);
        }
        
    }
}
