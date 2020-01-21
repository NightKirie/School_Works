using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using System.Data.SqlClient;

namespace NavigatorProduct
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        BindingManagerBase bm;

        private void Form1_Load(object sender, EventArgs e)
        {
            SqlConnection cn = new SqlConnection();
            cn.ConnectionString = @"Data Source=(LocalDB)\MSSQLLocalDB;" +
                "AttachDbFilename=|DataDirectory|Hospital.mdf;" +
                "Integrated Security=True";
            DataSet ds = new DataSet();
            SqlDataAdapter da = new SqlDataAdapter("SELECT * FROM doctor", cn);
            da.Fill(ds, "醫生");
            //https://msdn.microsoft.com/zh-tw/library/system.windows.forms.controlbindingscollection(v=vs.110).aspx
            txtName.DataBindings.Add("Text", ds, "醫生.name");
            txtDepartmentID.DataBindings.Add("Text", ds, "醫生.所屬系別編號");
            txtTitle.DataBindings.Add("Text", ds, "醫生.職稱");
            txtSalary.DataBindings.Add("Text", ds, "醫生.薪水");
            txtID.DataBindings.Add("Text", ds, "醫生.Did");
            bm = this.BindingContext[ds, "醫生"];
            //this 代表 form1 , 使用form1的BindingContext屬性指定bm(BindingManaterBase)物件瀏覽產品資料表
            //https://msdn.microsoft.com/zh-tw/library/system.windows.forms.bindingmanagerbase(v=vs.110).aspx
            CheckButton();
        }

        private void CheckButton()
        {
            if (bm.Position == 0)
            {
                btnFirst.Enabled = false;
                btnPrev.Enabled = false;
                btnNext.Enabled = true;
                btnLast.Enabled = true;
            }
            else if (bm.Position == bm.Count - 1)
            {
                btnFirst.Enabled = true;
                btnPrev.Enabled = true;
                btnNext.Enabled = false;
                btnLast.Enabled = false;
            }
            else
            {
                btnFirst.Enabled = true;
                btnPrev.Enabled = true;
                btnNext.Enabled = true;
                btnLast.Enabled = true;
            }
            lblCount.Text =  (bm.Position + 1).ToString() + " / " + bm.Count.ToString() ;
        }

        private void btnFirst_Click(object sender, EventArgs e)
        {
            bm.Position = 0;
            CheckButton();
        }

        private void btnPrev_Click(object sender, EventArgs e)
        {
            if (bm.Position > 0)
            {
                bm.Position -= 1;
            }
            CheckButton();
        }

        private void btnNext_Click(object sender, EventArgs e)
        {
            if (bm.Position < bm.Count - 1)
            {
                bm.Position += 1;
            }
            CheckButton();
        }

        private void btnLast_Click(object sender, EventArgs e)
        {
            bm.Position = bm.Count - 1;
            CheckButton();
        }
        private void btnAdd_Click(object sender, EventArgs e)
        {
            Edit("INSERT INTO doctor(name,所屬系別編號,職稱,薪水,Did)VALUES(N'" +
                txtName.Text.Replace("'", "''") + "'," +
                txtDepartmentID.Text + ",N'" +
                txtTitle.Text.Replace("'", "''") + "'," +
                txtSalary.Text + "," +
                txtID.Text + ")");
            DataBindingsClear();
            Form1_Load(sender, e);
        }
        void Edit(string sqlstr)
        {
            try
            {
                SqlConnection cn = new SqlConnection();
                cn.ConnectionString = @"Data Source=(LocalDB)\MSSQLLocalDB;" +
                    "AttachDbFilename=|DataDirectory|Hospital.mdf;" +
                    "Integrated Security=True";
                cn.Open();
                SqlCommand cmd = new SqlCommand(sqlstr, cn);
                cmd.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        void DataBindingsClear()
        {
            txtName.DataBindings.Clear();
            txtDepartmentID.DataBindings.Clear();
            txtTitle.DataBindings.Clear();
            txtSalary.DataBindings.Clear();
            txtID.DataBindings.Clear();
        }
    }
}
