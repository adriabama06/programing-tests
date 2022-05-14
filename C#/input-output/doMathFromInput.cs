using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1 {
    class Program {
        static void Main(string[] args) {
            Console.WriteLine("Write number1: ");
            int number1 = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Write number2: ");
            int number2 = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine(number1 + " + " + number2 + " = " + (number1+number2));
        }
    }
}