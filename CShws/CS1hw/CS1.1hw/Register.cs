using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//1.Изменить введенную строку пользователем на противоположный регистр:

namespace CS1._1hw
{
    internal class Register
    {
        private string text;

        public Register() 
        {
            Console.WriteLine("Введите текст:\n");
            string input = Console.ReadLine();
            text = input;
        }
        public string Change()
        {
            StringBuilder sb = new StringBuilder(text);
            for (int i = 0; i < text.Length; i++)
            {
                if(char.IsUpper(text[i]))
                {
                    sb[i] = char.ToLower(text[i]);
                }
                if(char.IsLower(text[i]))
                {
                    sb[i] = char.ToUpper(text[i]);
                }
            }
            return sb.ToString();
        }
        public void Print()
        {
            Console.WriteLine($"\nИзначальная строка:\n\n {text} \n\nИзмененная строка:\n\n {Change()}\n");}
        }
}
