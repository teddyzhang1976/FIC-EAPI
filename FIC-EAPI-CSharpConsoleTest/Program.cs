using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
namespace FIC_EAPI_CSharpConsoleTest
{
    class Program
    {
        [DllImport("FIC-EAPI.dll", EntryPoint = "Add", ExactSpelling = false, CallingConvention = CallingConvention.Cdecl)]
        public static extern int Add(int a, int b); //DllImport请参照MSDN

        static void Main(string[] args)
        {
            Console.WriteLine(Add(1,2));
            Console.Read();
        }
    }
}
