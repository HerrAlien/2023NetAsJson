#include "NeuralNetworkImporter.h"
#include "NeuralNetwork.h"
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

NeuralNetworkImporter::NeuralNetworkImporter(NeuralNetwork& i)
    : m_network(i)
{
}


NeuralNetworkImporter::~NeuralNetworkImporter()
{
}

void NeuralNetworkImporter::Read(const char* filePath)
{
    std::ifstream f(filePath);
    json data = json::parse(f);

    {
        std::vector <Matrix> weightsFromJson = data["weights"];
        m_network.SetWeights(std::move(weightsFromJson));
    }

    {
        std::vector <std::vector <double> > biasesFromJson = data["biases"];
        m_network.SetBiases(std::move(biasesFromJson));
    }
}
