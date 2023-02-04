#include <iostream>
#include <cmath>
using namespace std;

/*
CAZ GENERAL D=1,NR_Z=1
123 -> * 10
1230 -> 1230 - (230 - 23)  = 1230 - 207 = 1023
1023 -> * 10
10230 -> 10230 - (30 - 3)  = 10230 - 27 = 10203

CAZ UNDE D=1,NR_Z=2
123 -> * 100
12300 -> 12300 - (2300 - 23) = 12300 - 2277 = 10023
10023 -> * 100
10023 -> 1002300 - (300 - 3) = 1002300 - 297 = 1002003

  // 12300 - (12300 % 10000 - (12300 % 10000 / 100))
  // 12300 - (2300 - 2300 / 100 -> 23)
  // 12300 - 2277 = 10023

  // 1002300 - (1002300 % 1000 - (1002300 % 1000 / 100))
  // 1002300 - (300 - (300 / 100)
  // 1002300 - (300 - 3)
  // 1002300 - 297 =  1002003

CAZ UNDE D=2,NR_Z=1;
123 -> * 10
1230 -> 1230 - (30 - 3) = 1230 - 27 = 1203

CAZ UNDE D=2,NR_Z=2;
123 -> * 100
12300 -> 12300 - (300 - 3) = 12300 - 297 = 12003

*/

short int aflaLungimeNumar(unsigned long int N)
{
  short int nr_cif = 0;

  while (N)
  {
    nr_cif++;
    N /= 10;
  }

  return nr_cif;
}

unsigned long int samanare(unsigned long int N, short int nrZerouri, short int d, short int repetari, short int nrPasi)
{
  if (repetari == 0)
  {
    return N;
  }
  unsigned long int numarFinal = N * pow(10, nrZerouri);
  short int nrCif = aflaLungimeNumar(numarFinal);
  unsigned long int numarRest = pow(10, nrCif - d);

  numarFinal = numarFinal - (numarFinal % numarRest - (numarFinal % numarRest / pow(10, nrZerouri)));
  d = d + nrZerouri + nrPasi;
  samanare(numarFinal, nrZerouri, d, repetari - 1, nrPasi);
}

int main()
{
  unsigned long int N;
  short int d, nrZerouri, repetari;

  cout << "N: " << endl;
  cin >> N;
  cout << "distanta dintre zerouri: " << endl;
  cin >> d;
  cout << "numarul de zerouri de inserat: " << endl;
  cin >> nrZerouri;

  repetari = aflaLungimeNumar(N) - d - 1;

  cout << samanare(N, nrZerouri, d, repetari, d) << endl;

  return 0;
}