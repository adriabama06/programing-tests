using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.File;

namespace ConsoleApp1 {
    class Program {
        static void Main(string[] args) {
            string[] lines = {
                "Hello form line 0"//, "Second line", "Third line" 
            };

            await File.WriteAllLinesAsync("sometext.txt", lines);

            Console.WriteLine("Writted sometext.txt!");
        }
    }
}