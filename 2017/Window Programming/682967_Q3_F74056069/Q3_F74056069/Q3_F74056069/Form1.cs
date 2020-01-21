using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Q3_F74056069
{
    public partial class Form1 : Form
    {
        OpenFileDialog ofd = new OpenFileDialog();
        SaveFileDialog sfd = new SaveFileDialog();
        public Form1()
        {
            InitializeComponent();
            ofd.InitialDirectory = Path.GetFullPath("../Debug");
            ofd.RestoreDirectory = true;
            ofd.Filter = "Text Files(*.txt)|*.txt|All Files(*.*)|*.*";
            sfd.InitialDirectory = Path.GetFullPath("../Debug");
            sfd.RestoreDirectory = true;
            sfd.Filter = "Text Files(*.txt)|*.txt|All Files(*.*)|*.*"; 
        }

        private void Browse_Click(object sender, EventArgs e)
        {
            if (ofd.ShowDialog() == DialogResult.OK)
            {
                checkedListBox1.Items.Clear();
                FileStream fs = new FileStream(ofd.FileName, FileMode.Open);
                StreamReader sr = new StreamReader(fs);
                for(string line = sr.ReadLine(); line != null; line = sr.ReadLine())
                {
                    checkedListBox1.Items.Add(line);
                }
                sr.Close();
                fs.Close();
            }                             
        }

        private void Next_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
            string[] temp = new string[1000] ;
            for (int i = 0; i < checkedListBox1.CheckedItems.Count; i++)
            {
                temp[i] = checkedListBox1.CheckedItems[i].ToString();
            }
            textBox1.Lines = temp;
            tabControl1.SelectedTab = tabControl1.TabPages[1];
        }

        private void RedColor_CheckedChanged(object sender, EventArgs e)
        {
            if (RedColor.Checked)
                textBox1.ForeColor = Color.Red;
        }

        private void BlueColor_CheckedChanged(object sender, EventArgs e)
        {
            if (BlueColor.Checked)
                textBox1.ForeColor = Color.Blue;
        }

        private void FontSize_Scroll(object sender, EventArgs e)
        {
            textBox1.Font = new Font(textBox1.Font.Name, 10+FontSize.Value);           
        }

        private void Save_Click(object sender, EventArgs e)
        {
            if(sfd.ShowDialog() == DialogResult.OK)
            {
                FileStream fs = new FileStream(sfd.FileName, FileMode.OpenOrCreate);
                StreamWriter sw = new StreamWriter(fs);
                sw.Write(textBox1.Text);
                sw.Flush();
                sw.Close();
                fs.Close();
            }
        }
    }
}
