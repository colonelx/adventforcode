#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main()
{
  int size;
  ifstream iput; 
  iput.open("input.txt");
  int *a = new int[3000];
  a[0] = 0;
  int k = 0;
  int max = 0;
  int max_i = 0;
  string line;
  while (getline(iput, line))
  {
    if (line.empty()) {
        k++;
        a[k] = 0;
    }
    a[k] = a[k] + atoi(line.c_str());
  }
  for (int i = 0; i <= k; i++) {
    if(max < a[i]) {
        max = a[i];
        max_i = i;
    }
    cout << "Elf " << i + 1 << ": " << a[i] << '\n';
  }
  cout << "Max Elf " << max_i + 1 << ": " << max << '\n';
  return 0;
}
