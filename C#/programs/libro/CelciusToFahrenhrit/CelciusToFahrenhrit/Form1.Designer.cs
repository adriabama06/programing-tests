using CelciusToFahrenhrit;
using System;

namespace CelciusToFahrenhrit
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.temperaturas = new temperatures();
            this.celcius = new System.Windows.Forms.Label();
            this.fahrenheit = new System.Windows.Forms.Label();
            this.celciusInput = new System.Windows.Forms.TextBox();
            this.fahrenheitInput = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // celcius
            // 
            this.celcius.AutoSize = true;
            this.celcius.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.celcius.Location = new System.Drawing.Point(103, 95);
            this.celcius.Name = "celcius";
            this.celcius.Size = new System.Drawing.Size(114, 31);
            this.celcius.TabIndex = 0;
            this.celcius.Text = "celcius:";
            // 
            // fahrenheit
            // 
            this.fahrenheit.AutoSize = true;
            this.fahrenheit.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Bold);
            this.fahrenheit.Location = new System.Drawing.Point(531, 95);
            this.fahrenheit.Name = "fahrenheit";
            this.fahrenheit.Size = new System.Drawing.Size(154, 31);
            this.fahrenheit.TabIndex = 1;
            this.fahrenheit.Text = "fahrenheit:";
            // 
            // celciusInput
            // 
            this.celciusInput.Location = new System.Drawing.Point(109, 227);
            this.celciusInput.Name = "celciusInput";
            this.celciusInput.Size = new System.Drawing.Size(100, 20);
            this.celciusInput.TabIndex = 2;
            this.celciusInput.Text = "25";
            this.celciusInput.TextChanged += new System.EventHandler(this.celciusInput_TextChanged);
            // 
            // fahrenheitInput
            // 
            this.fahrenheitInput.Location = new System.Drawing.Point(552, 227);
            this.fahrenheitInput.Name = "fahrenheitInput";
            this.fahrenheitInput.Size = new System.Drawing.Size(100, 20);
            this.fahrenheitInput.TabIndex = 2;
            this.fahrenheitInput.Text = "77";
            this.fahrenheitInput.TextChanged += new System.EventHandler(this.fahrenheitInput_TextChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.fahrenheitInput);
            this.Controls.Add(this.celciusInput);
            this.Controls.Add(this.fahrenheit);
            this.Controls.Add(this.celcius);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "Form1";
            this.Text = "celcius to fahrenheit";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private temperatures temperaturas;
        private System.Windows.Forms.Label celcius;
        private System.Windows.Forms.Label fahrenheit;
        private System.Windows.Forms.TextBox celciusInput;
        private System.Windows.Forms.TextBox fahrenheitInput;
    }
}

