using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace multiple
{
    public partial class Form1 : Form
    {
        private System.Collections.ArrayList arrayRand = new System.Collections.ArrayList();
        public Form1()
        {
            InitializeComponent();
            Random random = new Random();
            int rand;
            while(arrayRand.Count < 6)
            {
                rand = random.Next(1,49);
                if (!arrayRand.Contains(rand))
                    arrayRand.Add(rand);
            }
            arrayRand.Sort();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            for (int x = 1; x < 50; x++)
            {
                clstTest.Items.Add(x, false);//產生1~99亂數並新增成項目
            }
            lblMsg.Text = "Please select six numbers!";
        }

        private void btnCheck_Click(object sender, EventArgs e)
        {
            if (clstTest.CheckedItems.Count != 6)
                MessageBox.Show("Please select six numbers!");
            else
            {
                bool check = true;
                lblMsg.Text = "The current Lotto numbers are as follow\n";
                for (int i = 0; i < 6; i++)
                {
                    lblMsg.Text += clstTest.CheckedItems[i].ToString() + ",";
                    if (!arrayRand.Contains(int.Parse(clstTest.CheckedItems[i].ToString())))
                    {
                        check = false;
                    }
                }
                if (check)
                {
                    lblMsg.Text += "\nCongratulations on winning your big prize...";
                    Random random = new Random();
                    arrayRand.Clear();
                    int rand;
                    while (arrayRand.Count < 6)
                    {
                        rand = random.Next(1, 49);
                        if (!arrayRand.Contains(rand))
                            arrayRand.Add(rand);
                    }
                    arrayRand.Sort();
                }
                else
                    lblMsg.Text += "\nTough luck!Please keep it up...";
                
                //CHECK THE ANSWER
                //for(int i = 0; i < arrayRand.Count; i++)
                 //   lblMsg.Text += arrayRand[i].ToString() + ",";

            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            for (int x = 0; x < 49; x++)
            {
                clstTest.SetItemChecked(x, false);
            }
            lblMsg.Text = "Please select six numbers!";
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
