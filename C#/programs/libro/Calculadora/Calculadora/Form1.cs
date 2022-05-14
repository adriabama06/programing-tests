using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace Calculadora
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        public string GenerarCalculo(string texto)
        {
            string[] letras = texto.Split('+', '-');
            if(!(letras.Length == 2))
            {
                return "0.0";
            }
            if(texto.IndexOf('+') > 0)
            {
                return Convert.ToString(Convert.ToDouble(letras[0]) + Convert.ToDouble(letras[1]));
            }
            if (texto.IndexOf('-') > 0)
            {
                return Convert.ToString(Convert.ToDouble(letras[0]) - Convert.ToDouble(letras[1]));
            }
            return "0.0";
        }

        private void resultado_Click(object sender, EventArgs e)
        {
            this.output.Text = GenerarCalculo(this.input.Text);
        }

        private void num1_Click(object sender, EventArgs e)
        {
            this.input.Text += "1";
        }

        private void num2_Click(object sender, EventArgs e)
        {
            this.input.Text += "2";
        }

        private void num3_Click(object sender, EventArgs e)
        {
            this.input.Text += "3";
        }

        private void num4_Click(object sender, EventArgs e)
        {
            this.input.Text += "4";
        }

        private void num5_Click(object sender, EventArgs e)
        {
            this.input.Text += "5";
        }

        private void num6_Click(object sender, EventArgs e)
        {
            this.input.Text += "6";
        }

        private void num7_Click(object sender, EventArgs e)
        {
            this.input.Text += "7";
        }

        private void num8_Click(object sender, EventArgs e)
        {
            this.input.Text += "8";
        }

        private void num9_Click(object sender, EventArgs e)
        {
            this.input.Text += "9";
        }

        private void num0_Click(object sender, EventArgs e)
        {
            this.input.Text += "0";
        }

        private void sumar_Click(object sender, EventArgs e)
        {
            this.input.Text += "+";
        }

        private void restar_Click(object sender, EventArgs e)
        {
            this.input.Text += "-";
        }
    }
}
