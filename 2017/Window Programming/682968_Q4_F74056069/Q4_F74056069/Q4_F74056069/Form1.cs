using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace Q4_F74056069
{
    public partial class Form1 : Form
    {
        static int life = 10;
        string[] keys = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        List<Button> blocks = new List<Button>();
        Random rand = new Random();
        public Form1()
        {
            InitializeComponent();
            timer1.Stop();
        }

        private void Start_Click(object sender, EventArgs e)
        {
            timer1.Start();
            life = 10;
            Focus();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Life.Text = "Life:" + life;
            if (life == 0)
            {
                timer1.Stop();
                MessageBox.Show("Game Over");
                Controls.Clear();
                blocks.Clear();
                Controls.Add(Start);
                Controls.Add(Grade);
                Controls.Add(Life);
            }
            else
            {
                int key = rand.Next(26);
                Button temp = new Button();
                temp.Size = new Size(80,80);
                temp.Location = new Point(rand.Next(640), 0);
                temp.Enabled = false;
                temp.Text = keys[key];
                blocks.Add(temp);
                Controls.Add(temp);
                for (int i = 0; i < blocks.Count(); i++)
                {
                    
                    if (blocks[i].Location.Y+80 >= textBox1.Top)
                    {
                        Controls.Remove(blocks[i]);
                        blocks.RemoveAt(i);
                        --life;
                    }
                    blocks[i].Location = new Point(blocks[i].Location.X, blocks[i].Location.Y + 80);
                }
            }    
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            for(int i = 0; i < blocks.Count(); i++)
            {
                Console.Write(e.KeyData);
                if (blocks[i].Text == e.KeyData.ToString())
                    Console.Write("lol");
            }
        }
    }
}
