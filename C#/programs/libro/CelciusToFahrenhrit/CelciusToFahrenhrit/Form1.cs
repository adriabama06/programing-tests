using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace CelciusToFahrenhrit
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void celciusInput_TextChanged(object sender, EventArgs e)
        {
            string input = this.celciusInput.Text;
            double todoule = Convert.ToDouble(input);
            double converted = this.temperaturas.CelciusToFahrenheit(todoule);
            this.fahrenheitInput.Text = Convert.ToString(converted);
        }

        private void fahrenheitInput_TextChanged(object sender, EventArgs e)
        {
            string input = this.fahrenheitInput.Text;
            double todoule = Convert.ToDouble(input);
            double converted = this.temperaturas.FahrenheitToCelcius(todoule);
            this.celciusInput.Text = Convert.ToString(converted);
        }
    }
}
