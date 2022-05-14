using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.IO.Compression;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace fnf_installer
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private async void button1_Click(object sender, EventArgs e)
        {
            this.button1.Enabled = false;
            if(File.Exists(@".\tmp.zip"))
            {
                File.Delete(@".\tmp.zip");
            }
            Stream stream = Assembly.GetExecutingAssembly().GetManifestResourceStream("fnf_installer.fnfversions.zip");
            FileStream fileStream = new FileStream("tmp.zip", mode: FileMode.CreateNew);
            this.progressBar1.Maximum = (int) stream.Length;
            int i = 0;
            var ExtraxtTask = Task.Run(() =>
            {
                for (; i < stream.Length; i++)
                {
                    fileStream.WriteByte((byte)stream.ReadByte());
                }
                fileStream.Close();
            });
            while(ExtraxtTask.IsCompleted == false)
            {
                this.progressBar1.Value = i / 2;
                await Task.Delay(1000);
            }
            this.progressBar1.Value = 60;
            this.progressBar1.Maximum = 100;
            ZipFile.ExtractToDirectory(@".\tmp.zip", Environment.GetFolderPath(Environment.SpecialFolder.UserProfile) + @"\Desktop");
            this.progressBar1.Value = 75;
            File.Delete(@".\tmp.zip");
            this.progressBar1.Value = 85;
            Process cmd = new Process();
            cmd.StartInfo.FileName = "cmd.exe";
            cmd.StartInfo.RedirectStandardInput = true;
            cmd.StartInfo.RedirectStandardOutput = true;
            cmd.StartInfo.CreateNoWindow = true;
            cmd.StartInfo.UseShellExecute = false;
            cmd.Start();
            this.progressBar1.Value = 90;
            //"/C mklink \"" + Environment.GetFolderPath(Environment.SpecialFolder.UserProfile) + @"\Desktop\funkin-windows-64bit\Funkin.exe" + "\" \"" + Environment.GetFolderPath(Environment.SpecialFolder.UserProfile) + @"\Desktop\FnF x64" + "\"";
            //"/C mklink \"" + Environment.GetFolderPath(Environment.SpecialFolder.UserProfile) + @"\Desktop\funkin-windows-32bit\Funkin.exe" + "\" \"" + Environment.GetFolderPath(Environment.SpecialFolder.UserProfile) + @"\Desktop\FnF x32" + "\"";
            cmd.StandardInput.WriteLine("mklink \"" + Environment.GetFolderPath(Environment.SpecialFolder.UserProfile) + @"\Desktop\FnF x64" + "\" \"" + Environment.GetFolderPath(Environment.SpecialFolder.UserProfile) + @"\Desktop\funkin-windows-64bit\Funkin.exe" + "\"");
            cmd.StandardInput.WriteLine("mklink \"" + Environment.GetFolderPath(Environment.SpecialFolder.UserProfile) + @"\Desktop\FnF x32" + "\" \"" + Environment.GetFolderPath(Environment.SpecialFolder.UserProfile) + @"\Desktop\funkin-windows-32bit\Funkin.exe" + "\"");
            this.progressBar1.Value = 95;
            cmd.StandardInput.Flush();
            cmd.StandardInput.Close();
            cmd.WaitForExit();
            Console.WriteLine(cmd.StandardOutput.ReadToEnd());
            this.progressBar1.Value = 100;
            DialogResult msgBox = MessageBox.Show("Finalizado dale a acceptar para cerrar");
            if(msgBox.Equals("OK"))
            {
                await Task.Delay(100);
                this.Close();
            }
        }
    }
}
