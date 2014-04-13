using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace D.NET
{
    class Sort
    {
        static public void BubbleSort<T>(List<T> datas, Func<T,T,bool> comparer)
        {

	        for (int i = 1; i < datas.Count - 1; i++)
	        {
                for (int j = 0; j < datas.Count - i; j++)
		        {
			        if (comparer(datas[j], datas[j + 1]))
			        {

				        T temp = datas[j];
				        datas[j] = datas[j + 1];
				        datas[j + 1] = temp;
			        }
		        }
	        }
        }
    }
}
