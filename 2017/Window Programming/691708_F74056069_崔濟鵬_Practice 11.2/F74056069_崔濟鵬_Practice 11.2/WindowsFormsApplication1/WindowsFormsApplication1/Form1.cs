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
        Form2 form2;

        public string text;
        public Form1()
        {
            InitializeComponent();
            form2 = new Form2(this);
            form2.Show();
            pageSetupDialog1.Document = printDocument1;
            printPreviewDialog1.Document = printDocument1;
        }

        public void addText(string text, int from) {
            if(from == 1)
                textBox1.AppendText("我說:" + text + Environment.NewLine);
            else if(from == 2)
                textBox1.AppendText("他說:" + text + Environment.NewLine);
        }


        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox2.Text != "")
            {
                text = textBox2.Text;
                addText(text, 1);
                form2.addText(text, 2);
                textBox2.Clear();
            }
        }

        private void 字型ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (fontDialog1.ShowDialog() == DialogResult.OK)
            {
                textBox1.Font = fontDialog1.Font;
            }
        }


        private void 結束ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void 列印格式ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            pageSetupDialog1.ShowDialog();
        }

        private void 預覽列印ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            printPreviewDialog1.ShowDialog();
        }

        private void 列印ToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            printDialog1.ShowDialog();
        }
    }
}
