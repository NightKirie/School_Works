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
        public Form1()
        {
            InitializeComponent();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: 這行程式碼會將資料載入 'database1DataSet.Student' 資料表。您可以視需要進行移動或移除。
            this.studentTableAdapter.Fill(this.database1DataSet.Student);
            // TODO: 這行程式碼會將資料載入 'database1DataSet.Department' 資料表。您可以視需要進行移動或移除。
            this.departmentTableAdapter.Fill(this.database1DataSet.Department);

        }
    }
}
