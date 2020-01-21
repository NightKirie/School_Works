using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ProgressBar
{
    public partial class Form1 : Form
    {
        private int countdowntime;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            progressBar1.Step = 1;       // 設定進度列每次的增量為1
            progressBar1.Maximum = 100;
            progressBar1.Minimum = 0;
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            OneSec.Stop();
            Progressing.Stop();
            countdowntime = int.Parse(textBox1.Text);
            if (countdowntime != 0)
            {
                progressBar1.Value = progressBar1.Minimum;
                Progressing.Interval = 10 * countdowntime;
                OneSec.Start();
                Progressing.Start();
            }
        }
        private void OneSec_Tick(object sender, EventArgs e)
        {
            countdownlabel.Text = countdowntime + " s";
            --countdowntime;
        }

        private void Progressing_Tick(object sender, EventArgs e)
        {
            progressBar1.PerformStep();
            if (progressBar1.Value == progressBar1.Maximum)
            {
                countdownlabel.Text = "Time's up!";
                OneSec.Stop();
                Progressing.Stop();	// 計時器停止
            }
        }
    }
}
