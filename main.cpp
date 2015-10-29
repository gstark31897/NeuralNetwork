#include "neuron.h"
#include <iostream>

int main()
{
   SNeuron* neuron = new SNeuron(50);
   for(int i = 0; i < 50; ++i)
      std::cout << neuron->m_inputWeights.at(i) << std::endl;

   delete neuron;
}
