using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace FileOperate
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // 設定第一個操作畫面
            txtInput.Text = "";
        }

        private void btnCreate_Click(object sender, EventArgs e)
        {
            FileInfo fInfo = new FileInfo("myfile.txt");
            if (fInfo.Exists)                   // 若來源檔案存在，顯示訊息
                MessageBox.Show("檔案已存在");
            else                               // 若來源檔案不存在，建立檔案
            {
                FileStream fs = fInfo.Create();                   
                MessageBox.Show("創建成功");
                fs.Close();                    
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            FileInfo fInfo = new FileInfo("myfile.txt");
            if (fInfo.Exists)
            {
                StreamWriter sw = fInfo.CreateText();
                sw.WriteLine(txtInput.Text);
                sw.Flush();
                sw.Close();
            }
            else
                MessageBox.Show("沒有該檔案 請先創建");
        }

        private void btnMove_Click(object sender, EventArgs e)
        {
            string movepath = txtSource.Text + "myfile.txt";
            if (Directory.Exists(txtSource.Text))
            {
                FileInfo fInfo = new FileInfo("myfile.txt");
                if (!File.Exists(movepath))
                {
                    fInfo.MoveTo(movepath);
                    MessageBox.Show("移動成功");
                }
                else
                    MessageBox.Show("該路徑已有此檔案");
            }
            else
            {
                MessageBox.Show("沒有該資料夾");
            }
        }
    }
}
