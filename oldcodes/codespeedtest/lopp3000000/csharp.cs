using System;

namespace main {

    class Program
    {
        static int seconds = 0;
        public static void Main(string[] args)
        {
            Console.WriteLine("inicio");
            System.Timers.Timer aTimer = new System.Timers.Timer();
            aTimer.Elapsed += new System.Timers.ElapsedEventHandler(OnTimedEvent);
            aTimer.Interval = 1;
            aTimer.Enabled = true;
            long number = 3000000;
            for (int i = 0; i < number; i++)
            {
                //Console.WriteLine(i);
            }
            Console.WriteLine(seconds);
            Console.WriteLine("he terminado");
        }
        private static void OnTimedEvent(object source, System.Timers.ElapsedEventArgs e)
        {
            seconds++;
        }
    }

}