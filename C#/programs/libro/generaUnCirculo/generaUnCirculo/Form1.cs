using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace generaUnCirculo
{
    public partial class Form1 : Form
    {
        private Graphics Papel;

        public Form1()
        {
            InitializeComponent();
            Papel = pictureBox1.CreateGraphics();
            trackBar1.Minimum = 0;
            trackBar1.Maximum = pictureBox1.Width;

            trackBar2.Minimum = 0;
            trackBar2.Maximum = pictureBox1.Height;

            setImage(1, 1);
            setImage(0, 0);
        }

        private void setImage(int x, int y)
        {
            Papel.Clear(Color.White);
            label1.Text = Convert.ToString(y);
            label2.Text = Convert.ToString(x);
            SolidBrush Lapiz = new SolidBrush(Color.LightBlue);
            Papel.FillEllipse(Lapiz, 0, 0, x, y);
            return;
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            setImage(trackBar1.Value, trackBar2.Value);
        }

        private void trackBar2_Scroll(object sender, EventArgs e)
        {
            setImage(trackBar1.Value, trackBar2.Value);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Papel.Clear(Color.White);
        }
    }
}
