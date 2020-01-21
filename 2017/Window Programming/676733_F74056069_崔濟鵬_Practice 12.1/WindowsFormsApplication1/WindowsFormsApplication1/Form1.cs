using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        private string pressx;
        private string pressy;
        private string mousecode;
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            pressx = e.X.ToString();
            pressy = e.Y.ToString();
            mousecode = e.Button.ToString();
        }
        private void label2_MouseDown(object sender, MouseEventArgs e)
        {
            label2.Text = "Press " + mousecode + " at X:" + pressx + ", Y:" + pressy; 
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            label1.Text = "Press " + e.KeyCode.ToString() + ", code:" + e.KeyValue.ToString();
            switch (e.KeyCode)
            {
                case Keys.Left:          
                    label1.Left -= 5;       
                    break;
                case Keys.Right:
                    label1.Left += 5;     
                    break;
                case Keys.Up:
                    label1.Top -= 5;
                    break;
                case Keys.Down:
                    label1.Top += 5;
                    break;
            }
        }
    }
}
