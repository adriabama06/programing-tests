using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Text;
using System.Windows.Forms;

namespace testtexteditor
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int size = 0;
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.InitialDirectory = @"C:\"; // or "C:\\"
            openFileDialog.Title = "Select text file";
            openFileDialog.Filter = "All files (*.*)|*.*|All files (*.*)|*.*";
            openFileDialog.FilterIndex = 2;
            openFileDialog.RestoreDirectory = true;
            DialogResult result = openFileDialog.ShowDialog();
            if (result == DialogResult.OK) {
                string file = openFileDialog.FileName;
                this.Text = file;
                try {
                    string text = File.ReadAllText(file);
                    MessageBox.Show(text);
                    size = text.Length;
                } catch (IOException err) {
                    MessageBox.Show("Error insesperado al abrir el archivo:\n\n" + err.ToString());
                    Console.WriteLine(err);
                }
            } else
            {
                MessageBox.Show("Error al abrir el archivo: " + result.ToString());
            }
            Console.WriteLine(size); // <-- Shows file size in debugging mode.
            Console.WriteLine(result); // <-- For debugging use.
        }
    }
}
