using System;
using System.Collections.Generic;

namespace CelciusToFahrenhrit
{
    class temperatures
    {
        public List<double> history = new List<double>();
        private List<double> SureHistory = new List<double>();
        public double CelciusToFahrenheit(double celcius)
        {
            double calc = (celcius * 9.0 / 5.0) + 32.0;
            history.Add(calc);
            return calc;
        }
        public double FahrenheitToCelcius(double fahrenheit)
        {
            double calc = (fahrenheit - 32.0) * 5.0 / 9.0;
            history.Add(calc);
            return calc;
        }
        public double lastCalc() => history[0];
    }
}
