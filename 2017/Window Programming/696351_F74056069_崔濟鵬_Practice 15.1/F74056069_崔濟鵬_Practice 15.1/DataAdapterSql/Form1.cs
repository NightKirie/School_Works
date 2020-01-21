using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
namespace DataAdapterSql
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string cn = @"Data Source=(LocalDB)\MSSQLLocalDB;" +
                 "AttachDbFilename=|DataDirectory|Hospital.mdf;" +
                "Integrated Security=True"; //設為True 指定使用Windows 帳號認證連接資料庫
            SqlConnection db = new SqlConnection(cn);
            db.Open();
            SqlDataAdapter ap1 = new SqlDataAdapter
                ("SELECT * FROM 系科別", db);
            SqlDataAdapter ap2 = new SqlDataAdapter
                ("SELECT * FROM doctor", db);
            DataSet ds = new DataSet();
            ap1.Fill(ds, "系科別");
            ap2.Fill(ds, "doctor");
            ds.Relations.Add("FK_系科別_doctor", ds.Tables["系科別"].Columns["Pid"], ds.Tables["doctor"].Columns["所屬系別編號"]);
            if(ds.Relations.Contains("FK_系科別_doctor"))
            {
                MessageBox.Show("資料連結成功!");
            }
            dataGridView1.DataSource = ds;
            dataGridView1.DataMember = "系科別";
            dataGridView2.DataSource = ds;
            dataGridView2.DataMember = "系科別.FK_系科別_doctor";
            db.Close();
        }
    }
}
