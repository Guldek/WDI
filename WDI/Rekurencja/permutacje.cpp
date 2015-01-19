#include <iostream>
#include <string>
using namespace std;
void permutacje(string s, int i, int n)
{
   if (i == n)
   {
      std::cout << s << std::endl;
   }
   else
   {
      for (int j = i; j <= n; j++)
      {
         swap(s[i], s[j]);
         permutacje(s, i + 1, n);
         swap(s[i], s[j]);
      }

   }

}
int main()
{
   string s;
   cin >> s;
   cout<<s.length();
   permutacje(s, 0, s.length()-1);

}
