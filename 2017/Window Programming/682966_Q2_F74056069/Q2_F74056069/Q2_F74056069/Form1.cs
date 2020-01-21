using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Q2_F74056069
{
    public partial class Form1 : Form
    {
        Image[] img = new Image[4] { Properties.Resources.down, Properties.Resources.left, Properties.Resources.right, Properties.Resources.up };
        static int start = 0;
        static int[] x = new int[2] {0, 0};
        static int[] y = new int[2] {0, 0};

        public Form1()
        {
            InitializeComponent();
            pictureBox1.Image = img[start];
        }

        private void Pre_Click(object sender, EventArgs e)
        {
            if (pictureBox1.Image.Equals(img[0]))
            {
                start = 3;
                pictureBox1.Image = img[3];
            }
            else
                pictureBox1.Image = img[--start];
             
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (pictureBox1.Image.Equals(img[3]))
            {
                start = 0;
                pictureBox1.Image = img[0];
            }
            else
                pictureBox1.Image = img[++start];

        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            x[0] = e.X;
            y[0] = e.Y;
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            x[1] = e.X;
            y[1] = e.Y;
            int dirX = x[1] - x[0];
            int dirY = y[1] - y[0];
            if (dirY > 0 && Math.Abs(dirY) > Math.Abs(dirX))    //Down
            { 
                if (start == 0)
                    MessageBox.Show("You are Right");
                else
                    MessageBox.Show("Wrong!!");
            }
            else if (dirX < 0 && Math.Abs(dirX) > Math.Abs(dirY))    //Left
            {
                if (start == 1)
                    MessageBox.Show("You are Right");
                else
                    MessageBox.Show("Wrong!!");
            }
            else if (dirX > 0 && Math.Abs(dirX) > Math.Abs(dirY))    //Right
            {
                if (start == 2)
                    MessageBox.Show("You are Right");
                else
                    MessageBox.Show("Wrong!!");
            }
            else if (dirY < 0 && Math.Abs(dirY) > Math.Abs(dirX))    //Up
            {
                if (start == 3)
                    MessageBox.Show("You are Right");
                else
                    MessageBox.Show("Wrong!!");
            }
            


        }
    }
}
