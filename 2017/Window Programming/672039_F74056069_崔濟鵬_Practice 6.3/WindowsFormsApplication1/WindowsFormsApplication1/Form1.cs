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

        List<Data> store = new List<Data>();
        private const string username = "0000";
        private const string password = "0000";
        private const string empty = "";

        private void button1_Click(object sender, EventArgs e)
        {
            if (string.Equals(textBox1.Text, username) && string.Equals(textBox2.Text, password))
            {
                textBox1.Visible = false;
                textBox2.Visible = false;
                label1.Visible = false;
                label2.Visible = false;
                button1.Visible = false;
                button2.Visible = true;
                button3.Visible = true;
                button4.Visible = true;
                button5.Visible = true;
            }
            else
            {
                System.Windows.Forms.MessageBox.Show("Invalid usermname or passworld");
            }
        }

        private void button2_Click(object sender, EventArgs e)  //for add button
        {
            label3.Visible = true;
            label4.Visible = true;
            label5.Visible = true;
            label6.Visible = true;
            label7.Visible = false;
            label8.Visible = false;
            textBox3.Visible = true;
            textBox4.Visible = true;
            textBox5.Visible = true;
            textBox6.Visible = true;
            button6.Visible = false;
            button7.Visible = true;
            button8.Visible = false;
            label7.Text = "";
            label8.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
            textBox5.Text = "";
            textBox6.Text = "";
        }

        private void button3_Click(object sender, EventArgs e)  //for inquire button
        {
            label3.Visible = true;
            label4.Visible = false;
            label5.Visible = false;
            label6.Visible = false;
            label7.Visible = false;
            label8.Visible = false;
            textBox3.Visible = true;
            textBox4.Visible = false;
            textBox5.Visible = false;
            textBox6.Visible = false;
            button6.Visible = true;
            button7.Visible = false;
            button8.Visible = false;
            label7.Text = "";
            label8.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
            textBox5.Text = "";
            textBox6.Text = "";
        }

        private void button4_Click(object sender, EventArgs e)  //for delete button
        {
            label3.Visible = true;
            label4.Visible = false;
            label5.Visible = false;
            label6.Visible = false;
            label7.Visible = false;
            label8.Visible = false;
            textBox3.Visible = true;
            textBox4.Visible = false;
            textBox5.Visible = false;
            textBox6.Visible = false;
            button6.Visible = false;
            button7.Visible = false;
            button8.Visible = true;
            label7.Text = "";
            label8.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
            textBox5.Text = "";
            textBox6.Text = "";
        }

        private void button5_Click(object sender, EventArgs e)  //for logout button
        {
            label1.Visible = true;
            label2.Visible = true;
            label3.Visible = false;
            label4.Visible = false;
            label5.Visible = false;
            label6.Visible = false;
            label7.Visible = false;
            label8.Visible = false;
            textBox1.Visible = true;
            textBox2.Visible = true;
            textBox3.Visible = false;
            textBox4.Visible = false;
            textBox5.Visible = false;
            textBox6.Visible = false;
            button1.Visible = true;
            button2.Visible = false;
            button3.Visible = false;
            button4.Visible = false;
            button5.Visible = false;
            button6.Visible = false;
            button7.Visible = false;
            button8.Visible = false;
            label7.Text = "";
            label8.Text = "";
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
            textBox5.Text = "";
            textBox6.Text = "";
        }

        private void button6_Click(object sender, EventArgs e)  //for search button
        {
            textBox4.Visible = false;
            textBox5.Visible = false;
            textBox6.Visible = false;
            label4.Visible = false;
            label5.Visible = false;
            label6.Visible = false;
            label8.Visible = false;
            if (string.Equals(textBox3.Text, empty))
            {
                label8.Text = "The field can't be empty";
                label8.Visible = true;
            }
            else
            {
                bool found = false;
                foreach(var i in store)
                {
                    if (string.Equals(textBox3.Text, i.GetID()))
                    {
                        found = true;
                        textBox4.Text = i.GetGender();
                        textBox5.Text = i.GetTel();
                        textBox6.Text = i.GetAddress();
                    }
                        
                }
                if (found)
                {
                    textBox4.Visible = true;
                    textBox5.Visible = true;
                    textBox6.Visible = true;
                    label4.Visible = true;
                    label5.Visible = true;
                    label6.Visible = true;
                }
                else
                {
                    label8.Text = "Data is not found";
                    label8.Visible = true;
                }

            }
        }

        private void button7_Click(object sender, EventArgs e)  //for confirm button
        {
            if (string.Equals(textBox3.Text, empty) || string.Equals(textBox4.Text, empty) || string.Equals(textBox5.Text, empty) || string.Equals(textBox6.Text, empty))
            {
                label7.Text = "Every field should be filled, \nplease enter again.";
                label7.Visible = true;
            }
            else
            {
                bool exist = false;
                foreach (var i in store)
                {
                    if (string.Equals(textBox3.Text, i.GetID()) && string.Equals(textBox4.Text, i.GetGender()) && string.Equals(textBox5.Text, i.GetTel()) && string.Equals(textBox6.Text, i.GetAddress()))
                    {
                        exist = true;
                        textBox3.Text = "";
                        textBox4.Text = "";
                        textBox5.Text = "";
                        textBox6.Text = "";
                        label7.Text = "This data has been stored before!";
                        label7.Visible = true;
                    }
                    else if (string.Equals(textBox3.Text, i.GetID()))
                    {
                        exist = true;
                        label7.Text = "Reset the data of ID = " + textBox3.Text;
                        label7.Visible = true;
                        i.ResetGender(textBox4.Text);
                        i.ResetTel(textBox5.Text);
                        i.ResetAddress(textBox6.Text);
                    }

                }
                if (!exist)
                {
                    store.Add(new Data(textBox3.Text, textBox4.Text, textBox5.Text, textBox6.Text));
                    textBox3.Text = "";
                    textBox4.Text = "";
                    textBox5.Text = "";
                    textBox6.Text = "";
                    label7.Text = "Data has been stored, \nnow have " + store.Count + " data";
                    label7.Visible = true;
                }
                
            }                
        }

        private void button8_Click(object sender, EventArgs e)  //for detele it button
        {
            label8.Visible = false;
            Data removeone = null;
            removeone = store.Find(x => x.GetID() == textBox3.Text);
            if (removeone != null)
            {
                store.Remove(removeone);
                label8.Text = "delete successful!!";
                label8.Visible = true;
            }
            else
            {
                if (string.Equals(textBox3.Text, empty))
                { 
                    label8.Text = "The field can't be empty";
                    label8.Visible = true;
                }
                else
                {
                    label8.Text = "This ID isn't in the data";
                    label8.Visible = true;
                }
            }
        }
    }
    public class Data
    {
        private string ID, gender, tel, address;
        public Data(string ID, string gender, string tel, string address)
        {
            this.ID = ID;
            this.gender = gender;
            this.tel = tel;
            this.address = address;
        }

        public void ResetGender(string gender)
        {
            this.gender = gender;
        }

        public void ResetTel(string tel)
        {
            this.tel = tel;
        }

        public void ResetAddress(string address)
        {
            this.address = address;
        }

        public string GetID()
        {
            return ID;
        }

        public string GetGender()
        {
            return gender;
        }

        public string GetTel()
        {
            return tel;
        }

        public string GetAddress()
        {
            return address;
        }
    }
}
