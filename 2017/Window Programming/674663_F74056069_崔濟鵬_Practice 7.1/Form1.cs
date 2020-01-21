using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PictureBox
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        int current = 1;              // 目前顯示的圖像檔順序
        int change = 0;
        private void FigShow()
        {
            pic.Image = Image.FromFile(@"..\..\7_pics\p" + current + ".png");
            pic.Size = new Size(pic.Width, pic.Height);      // 設定圖片方塊的大小
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            FigShow();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (radioButton1.Checked)
            {
                if (current < 6)
                    change = 1;
                else
                    change = 0;
            }
            else if (radioButton2.Checked)
            {
                if (current > 1)
                    change = -1;
                else
                    change = 0;               
            }
            current += change;
            FigShow();
        }
    }
}
