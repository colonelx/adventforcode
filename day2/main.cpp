#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int compare(char a, char b) {
    int op_1, op_2;
    switch (a) {
        case 'A': op_1 = 1; break; // Rock
        case 'B': op_1 = 2; break; // Paper
        case 'C': op_1 = 3; break; // Scissors
    }
    switch (b) {
        case 'X': op_2 = 1; break; // Rock
        case 'Y': op_2 = 2; break; // Paper
        case 'Z': op_2 = 3; break; // Scissors
    }

    if (op_1 == 1 && op_2 == 3) { // A: Rock / B: Scissors = winner A
        return 3;
    } else if (op_2 == 1 && op_1 == 3) { // A: Scissors / B: Rock = winner B
        return 7;
    } else if (op_1 < op_2) {
        return op_2 + 6;
    } else if (op_1 > op_2) {
        return op_2;
    } else {
        return op_2 + 3;
    }
    
}
int decode(char a, char b) {
    int op_1, op_2;
    switch (a) {
        case 'A': op_1 = 1; break; // Rock
        case 'B': op_1 = 2; break; // Paper
        case 'C': op_1 = 3; break; // Scissors
    }
    
    switch (b) {
        case 'X':
            if (op_1 == 3) op_2 = 2;
            if (op_1 == 2) op_2 = 1;
            if (op_1 == 1) op_2 = 3; 
            break; // Lose
        case 'Y': op_2 = op_1 + 3; break; // Draw
        case 'Z': 
            if (op_1 == 3) op_2 = 1 + 6;
            if (op_1 == 2) op_2 = 3 + 6;
            if (op_1 == 1) op_2 = 2 + 6;  
            break; // Win
    }
    return op_2;
}

int main()
{
  int size;
  ifstream iput; 
  iput.open("input.txt");
  int *a = new int[3000];
  a[0] = 0;
  string line;
  int total = 0;
  while (getline(iput, line))
  {
    string delimiter = " ";
    const char* str = line.c_str();
    char a = str[0];
    char b = str[line.find(delimiter) + 1];
    int ret = decode(a, b);
    cout << a << ' ' << b << " = " << ret << '\n';

    total = total + ret;

  }
  cout << "total "  << ": " << total << '\n';
  return 0;
}
