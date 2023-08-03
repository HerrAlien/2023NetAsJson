#pragma once

class NeuralNetwork;

class NeuralNetworkImporter
{
public:
    NeuralNetworkImporter(NeuralNetwork& i);
    ~NeuralNetworkImporter();

    void Read(const char* filePath);

private:
    NeuralNetwork& m_network;
};

