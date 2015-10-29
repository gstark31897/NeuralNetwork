#include "neuron.h"
#include <stdlib.h>
#include <time.h>

#include <iostream>

SNeuron::SNeuron(int numInputs): m_numInputs(numInputs+1)
{
   srand(time(NULL));
   for(int i = 0; i < m_numInputs; ++i)
   {
      double value = rand()%1000;
      value /= 1000.0;
      m_inputWeights.push_back(value);
   }
}

SNeuronLayer::SNeuronLayer(int numNeurons, int numInputsPerNeuron):
      m_numNeurons(numNeurons)
{
   for(int i = 0; i < m_numNeurons; ++i)
      m_vecNeurons.push_back(SNeuron(numInputsPerNeuron));
}

CNeuralNet::CNeuralNet(int numInputs, int numOutputs, int numHiddenLayers, int neuronsPerHiddenLayer):
      m_numInputs(numInputs), 
      m_numOutputs(numOutputs),
      m_numHiddenLayers(numHiddenLayers),
      m_neuronsPerHiddenLayer(neuronsPerHiddenLayer)
{
   for(int i = 0; i < numHiddenLayers; ++i)
   {
      m_vecLayers.push_back(SNeuronLayer(neuronsPerHiddenLayer,
            i > 0 ? neuronsPerHiddenLayer : numInputs));
   }
}
