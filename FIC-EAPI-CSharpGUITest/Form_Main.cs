using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace FIC_EAPI_CSharpGUITest
{
    public partial class Form_Main : Form
    {
        [DllImport("FIC-EAPI.dll", EntryPoint = "fnFICEAPI")]
        public static extern int fnFICEAPI();
        public Form_Main()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int i = fnFICEAPI();
        }
    }
}
