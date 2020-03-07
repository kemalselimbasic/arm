using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp4
{
    public partial class Form1 : Form
    {
        string data;
        int i = 0;
        int polutionData1;
        public Form1()
        {
            InitializeComponent();
        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            data =  serialPort1.ReadExisting() + "\n";
            polutionData1 = Convert.ToInt16( data);
            this.Invoke(new EventHandler (sendData));
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
        private void sendData(object sender, EventArgs e) {
            textBox1.Text = data;
            this.chart1.Series["polutionData"].Points.AddXY(i, polutionData1);
            i++;



        }

        private void Form1_Load(object sender, EventArgs e)
        {
            serialPort1.Open();
        }
    }
}
