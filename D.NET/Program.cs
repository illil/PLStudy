using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace D.NET
{
    class Program
    {
        static void Main(string[] args)
        {
            var sum = new List<int> { 1, 2, 3, 4, 5, 6 }.Select(i => i + 1).Sum();
        }
    }
}
