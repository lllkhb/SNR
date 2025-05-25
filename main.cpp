#include <iostream>
#include "SNR.h"

using namespace std;

int main()
{
   Signal s1;
   s1.setValue(4.00, 2.00);
   float snr1 = s1.getSNR();
   s1.toString();
   cout << "SNR: " << snr1;
    return 0;
}
