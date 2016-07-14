using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace FIC_EAPI_CSharpGUITest
{
    class TestBackLight
    {
        
        [DllImport("FIC-EAPI.dll", EntryPoint = "EApiVgaGetBacklightEnable")]
        unsafe public static extern int EApiVgaGetBacklightEnable(int Id, /* Backlight Id */
         IntPtr pEnable);
    
        //[DllImport("FIC-EAPI.dll", EntryPoint = "EApiVgaGetBacklightEnable")]
        //public static extern int EApiVgaGetBacklightEnable(int Id, /* Backlight Id */
        // int* pEnable);
    }
}
