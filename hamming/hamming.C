/* returns the hamming code of a 16-bit hexadecimal value in hexadecimal -- Samir Bekhechi 10-15-2015 */

#include <iostream>
using namespace std;


//most important and only function which takes the input argument val and assigns each element a variable and then calculates the parity bits and returns the hamming code in binary to be changed to hexadecimal in the main funtion

long hamming(long val)
{

  //assigning values from val--pushes this value to the incremented position
  int a = 0,  b = 0, c = (val>>15) &1, d = 0, e = (val>>14) &1, f = (val>>13) &1, g = (val>>12) &1, h = 0, i = (val>>11) &1, j = (val>>10) &1, k = (val>>9) &1, l = (val>>8) &1, m = (val>>7) &1, n = (val>>6) &1, o = (val>>5) &1, p = 0, q = (val>>4) &1, r = (val>>3) &1, s = (val>>2) &1, t = (val>>1) &1, u = (val>>0) &1;

  
  //Calculation of parity bits, checks whether parity bit value is 1 or 0, using mod 2 which will test whether the remainder is a 0 or a 1
  a = (a + c + e + g + i + k + m + o + q + s + u) % 2;
  b = (b + c + f + g + j + k + n + o + r + s) % 2;
  d = (d + e + f + g + l + m + n + o + t + u) % 2;
  h = (h + i + j + k + l + m + n + o) % 2;
  p = (p + q + r + s + t + u) % 2;

  
  //return hamming code by pushing back to its 21 positions and returns the hamming code in binary to be converted into hexadecimal
  return a<<20 | b<<19 | c<<18 | d<<17 | e<<16 | f<<15 | g<<14 | h<<13 | i<<12 | j<<11 |  k<<10 | l<<9 | m<<8 | n<<7 | o<<6 | p<<5 | q<<4 | r<<3 | s<<2 | t<<1 | u<<0;
  
}



int main()
{
  cout<<"Enter a four-digit hexadecimal value: "<<endl;
  cin.setf(ios::hex, ios::basefield);
  cout.setf(ios::hex, ios::basefield);
  long derp;
  cin>>derp;
  cout<<"The hamming code is " << hamming(derp) <<endl;
}
