#include <iostream>
#include<vector>
using namespace std;

int main()
{
   int n;
   cin >> n;
   vector<vector<int>> arr(n, vector<int>(n, 0));
   int count = 1;
   int i = 0, j = 0;
   int k = i + j;
   int ss = n - 1;
   while (count <= n * n)
   {
       if (k < n)
       {

           if (k % 2 == 0)
           {
               i = k;
               j = 0;
               for (int s = 0; s < k + 1; s++)
               {
                   arr[i][j] = count;
                   count++;
                   i--;
                   j++;
               }
               k++;
           }
           else if (k % 2 == 1)
           {
               i = 0;
               j = k;
               for (int s = 0; s < k + 1; s++)
               {
                   arr[i][j] = count;
                   count++;
                   i++;
                   j--;
               }
               k++;
           }
       }
       if (k >= n)
       {
           if (k % 2 == 0)
           {
               j = k - (n - 1);
               i = k - j;
               for (int t = 0; t < ss; t++)
               {
                   arr[i][j] = count;
                   count++;
                   i--;
                   j++;
               }
               ss--;
               k++;
           }
           else if (k % 2 == 1)
           {
               i = k - (n - 1);
               j = k - i;
               for (int t = 0; t < ss; t++)
               {
                   arr[i][j] = count;
                   count++;
                   i++;
                   j--;
               }
               ss--;
               k++;
           }
       }
   }
   for (auto& t : arr)
   {
       for (auto& r : t)
       {
           cout << r << "\t";
       }
       cout << endl;
   }
}
