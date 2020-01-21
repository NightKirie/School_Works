using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace hit
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        Button[] btn = new Button[9];   //宣告按鈕物件陣列
        private string player = "X";

        private void Form1_Load(object sender, EventArgs e)
        {
            btn[0] = btn1; btn[1] = btn2; btn[2] = btn3;//指定按鈕物件陣列元素
            btn[3] = btn4; btn[4] = btn5; btn[5] = btn6;
            btn[6] = btn7; btn[7] = btn8; btn[8] = btn9;
            btn2.Click += btn1_Click; btn3.Click += btn1_Click;//訂閱共享事件
            btn4.Click += btn1_Click; btn5.Click += btn1_Click;
            btn6.Click += btn1_Click; btn7.Click += btn1_Click;
            btn8.Click += btn1_Click; btn9.Click += btn1_Click;
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < 9; i++)
                btn[i].Text = "";   //空白字元
            player = "X";
        }


        private void btn1_Click(object sender, EventArgs e)
        {
            Button btnClick = (Button)sender;   //將sender轉型為按鈕物件btnClick
            if (btnClick.Text == "")
            {
                btnClick.Text = player;
                if (player == "X")
                    player = "O";
                else
                    player = "X";
            }
            for (int i = 0; i < 3; i++)
            {
                if (btn[3 * i].Text == btn[3 * i + 1].Text && btn[3 * i + 1].Text == btn[3 * i + 2].Text && btn[3 * i].Text != "")
                {
                    MessageBox.Show(btn[3 * i].Text + " wins!", "OK!");
                    btnStart_Click(sender, e);
                }
                else if (btn[i].Text == btn[i + 3].Text && btn[i + 3].Text == btn[i + 6].Text && btn[i].Text != "")
                {
                    MessageBox.Show(btn[i].Text + " wins!", "OK!");
                    btnStart_Click(sender, e);
                }
                else if (btn[0].Text == btn[4].Text && btn[4].Text == btn[8].Text && btn[0].Text != "")
                {
                    MessageBox.Show(btn[0].Text + " wins!", "OK!");
                    btnStart_Click(sender, e);
                }
                else if (btn[2].Text == btn[4].Text && btn[4].Text == btn[6].Text && btn[2].Text != "")
                {
                    MessageBox.Show(btn[2].Text + " wins!", "OK!");
                    btnStart_Click(sender, e);
                }
                else if (btn[0].Text != "" && btn[1].Text != "" && btn[2].Text != "" &&
                         btn[3].Text != "" && btn[4].Text != "" && btn[5].Text != "" &&
                         btn[6].Text != "" && btn[7].Text != "" && btn[8].Text != "")
                {
                    MessageBox.Show("Duce", "OK!");
                    btnStart_Click(sender, e);
                }
            }

        }
    }
}
