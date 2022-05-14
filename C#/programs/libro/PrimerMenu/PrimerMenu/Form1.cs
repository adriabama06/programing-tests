using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PrimerMenu
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {
            label1.Text = "Ves cambie";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Menu de prueba");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Graphics Grafico = pictureBox1.CreateGraphics();
            Pen Lapiz = new Pen(Color.Red);
            //                          Posicion - Tamaño
            //                    Pen     x   y    x   y
            Grafico.DrawRectangle(Lapiz, 10, 10, 100, 50);
            Grafico.DrawRectangle(Lapiz, 10, 75, 100, 100);
            //                      El @ es para quitar lo del \\
            Bitmap imagen = new Bitmap(@"D:\Users\adria\Documents\learncsharp\libro\PrimerMenu\PrimerMenu\image1.png");
            Grafico.DrawImage(imagen, 0, 0, 150, 100);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string input = textBox1.Text;
            string toset = string.Empty;
            char[] inputAsArray = input.ToCharArray();
            for (int i = inputAsArray.Length - 1; i > -1; i--)
            {
                toset += inputAsArray[i];
            }
            textBox2.Text = toset;
            textBox1.Clear();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            //textBox2.Clear();
        }

        private void textBox2_Click(object sender, EventArgs e)
        {
            textBox2.SelectAll();
        }
    }
}
