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
    public partial class Form2 : Form
    {
        Form1 form1;
        public string text;
        public Form2(Form1 form1)
        {
            InitializeComponent();
            this.form1 = form1;
            pageSetupDialog1.Document = printDocument1;
            printPreviewDialog1.Document = printDocument1;
        }

        public void addText(string text, int from)
        {
            if (from == 1)
                textBox3.AppendText("我說:" + text + Environment.NewLine);
            else if (from == 2)
                textBox3.AppendText("他說:" + text + Environment.NewLine);
        }


        private void button2_Click(object sender, EventArgs e)
        {
            if (textBox4.Text != "")
            {
                text = textBox4.Text;
                addText(text, 1);
                form1.addText(text, 2);
                textBox4.Clear();
            }
        }

        private void 字型ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (fontDialog1.ShowDialog() == DialogResult.OK)
            {
                textBox3.Font = fontDialog1.Font;
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
