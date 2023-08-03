#pragma once

#include "Image.h"
#include <vector>

using Matrix=std::vector<std::vector<double> >;

class NeuralNetwork
{
public:
    NeuralNetwork();
    ~NeuralNetwork();

    int Predict(const Image& i);

    void SetWeights(std::vector<Matrix>&& w);
    void SetBiases(std::vector<std::vector<double> >&& b);

private:
    std::vector<Matrix> m_weights;
    std::vector<std::vector<double> > m_biases;
};

