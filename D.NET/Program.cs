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
            Func<int, int> fun = (int i)=>{return 1;};

            var aa = 1;
            List <MountainData> mountains = new List<MountainData>();


            mountains.Add(new MountainData("Dhaulagiri", 8167));
            mountains.Add(new MountainData("Manaslu", 8163));
            mountains.Add(new MountainData("Nanga Parbat", 8125));
            mountains.Add(new MountainData("Gasherbrum II", 8035));
            mountains.Add(new MountainData("Shishapangma", 8012));
            mountains.Add(new MountainData("K2", 8611));
            mountains.Add(new MountainData("Kangchenjunga", 8586));
            mountains.Add(new MountainData("Lhotse", 8516));
            mountains.Add(new MountainData("Makalu", 8463));
            mountains.Add(new MountainData("Everest", 8848));
            mountains.Add(new MountainData("Gasherbrum I", 8068));
            mountains.Add(new MountainData("Broad Peak", 8047));
            mountains.Add(new MountainData("Annapurna", 8091));
            mountains.Add(new MountainData("Cho Oyu", 8201));

            Sort.BubbleSort(mountains, 
                (MountainData a, MountainData b) => 
                    { 
                        return a._elevation > b._elevation;
                    }
                );
        }
    }
}
