#include <vector>

struct SNeuron
{
   int m_numInputs;
   std::vector<double> m_inputWeights;

   SNeuron(int numInputs);
};

struct SNeuronLayer
{
   int m_numNeurons;
   std::vector<SNeuron> m_vecNeurons;

   SNeuronLayer(int numNeurons, int numInputsPerNeuron);
};

class CNeuralNet
{
private:
   int m_numInputs;
   int m_numOutputs;
   int m_numHiddenLayers;
   int m_neuronsPerHiddenLayer;

   std::vector<SNeuronLayer> m_vecLayers;

public:
   CNerualNet(int numInputs, int numOutputs, int numHiddenLayers, int neruonsPerHiddenlayer);

   std::vector<double> GetWeights() const;
   int GetNumberOfWeights() const;
   void PutWeights(std::vector<double> &weights);
   std::vector<double> Update(std::vector<double> &inputs);
};
