using System;
namespace week_1
{
    public class makefile
    {
        public static void main()
        {
            int n;
            n = Convert.ToInt32(Console.ReadLine());
            int[] list = new int[n];
            for (int i = 0; i < n; i++){
                list[i] = Convert.ToInt32(Console.ReadLine());
            }
            makefile obj = new makefile();
            obj.reversearray(list, n);
        }
        public void reversearray(int [] list, int n){
            for (int i = 0; i < (n - 1) / 2; i++){
                list[i] = list[n - i] + list[i];
                list[n - i] = list[i] - list[n - i];
                list[i] = list[i] - list[n - i];
            }
            Console.WriteLine("Hello");
            for (int i = 0; i < n; i++){
                Console.WriteLine(list[i]);
            }
        }
    }
}
