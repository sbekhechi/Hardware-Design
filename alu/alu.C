/* This program computes and prints out the simulation of a 1-bit ALU circuit Samir Bekhechi 11-2-2015 */

#include <iostream>
#include "blogic.H"
using namespace std;


/* This is the most important function for performing basic circuit gate operations of an ALU based on the 8 input values */
int alu(int f_0, int f_1, int inva, int ena, int enb, int c_i, int a, int b)
{
  return  (bor(
      band(
	   band(bnot(f_0),bnot(f_1)),
	   band(bxor(inva, band(a, ena)),band(b, enb))
      ),
      band(
	   band(bnot(f_0),f_1),
	   bor(
	       bxor(inva, band(a,ena)),
	       band(b, enb)
	       )
     ),
      band(
	   band(bnot(f_0),f_1),
	   bnot(
		band(b,enb))
     ),
      band(
	   bxor(c_i,
		bxor(band(b,enb), bxor(inva,band(a,ena)))
		),
	   band(f_0,f_1)
	   )
	               )*2)+
    bor(
      band(c_i, band(f_1,f_0), bxor(band(b,enb),bxor(inva,band(a,ena)))),
      band(band(f_0,f_1), band(b, enb), bxor(inva, band(a, ena)))
	 );
}


// This function calls the ALU function and formats the output
void print_call(int f_0, int f_1, int inva, int ena, int enb, int c_i, int a, int b)
{
  cout << "(alu " << f_0<<" "<<f_1<<" "<<inva<<" "<<ena<<" "<<enb<<" "<<c_i<<" "<<a<<" "<<b<<") --> "<< alu(f_0, f_1, inva, ena, enb, c_i, a, b)<<endl;
  return;
}


// This function formats and increments the last 3 values of the 8 inputs namely c_i, a, b
void print_section(int f_0, int f_1, int inva, int ena, int enb)
{
  cout << "F0 = "<< f_0 << " F1 = "<< f_1 << " INVA = "<< inva << " ENA = " << ena << " ENB = " << enb<<endl;   
  // These for loops are to increment the last 3 values
  for(int i=0; i<2; i++)
    for(int j=0; j<2; j++)
      for(int k=0; k<2; k++)
	print_call(f_0, f_1, inva, ena, enb, i, j, k);
}



/* This main function simply increments the input of the first 5 values of the 8 inputs for the alu starting at (0,0,0,0,0) aka f_0, f_1, inva, ena, enb. And then calls the function print_section each time it is incremented */
int main()
{
  for(int i=0; i<2; i++)
    for(int j=0; j<2; j++)
      for(int k=0; k<2; k++)
	for(int l=0; l<2; l++)
	  for(int m=0; m<2; m++)
	    print_section(i, j, k, l, m);

}
