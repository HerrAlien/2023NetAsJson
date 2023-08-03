#include "NeuralNetwork.h"
#include <numeric>
#include <vector>
#include <algorithm>

namespace
{
    std::vector<double> GetColumn(const Matrix& m, int columnIndex)
    {
        std::vector<double> column(m.size());
        for (unsigned int i = 0; i < column.size(); i++)
        {
            column[i] = m[i][columnIndex];
        }

        return column;
    }
}

NeuralNetwork::NeuralNetwork()
{
}


NeuralNetwork::~NeuralNetwork()
{

}

int NeuralNetwork::Predict(const Image& i)
{
    // get the vector of pixels from image
    // I will resize it to the number of pixels - first
    std::vector<double> input(i.pixels.size());
    std::copy(i.pixels.begin(), i.pixels.end(), input.begin());

    std::vector<double> outputs;
    // for each layer:
    for (size_t layerIndex = 0; layerIndex < m_weights.size(); layerIndex++)
    {
        const Matrix& currentWeights = m_weights[layerIndex];
        const std::vector<double>& currentBiases = m_biases[layerIndex];

        outputs.resize(currentWeights[0].size());
        
        for (size_t columnIndex = 0; columnIndex < outputs.size(); columnIndex++)
        {
            std::vector <double> column = GetColumn(currentWeights, columnIndex);
            double weightedSumForOneColumn = std::inner_product(input.begin(), input.end(), column.begin(), 0.0);
            double withBias = weightedSumForOneColumn + currentBiases[columnIndex];

            double outputForColumn = 1.0 / (1.0 + exp(-withBias)); // sigmoid
            outputs[columnIndex] = outputForColumn;
                // the outcome is the input for the next layer - repeat the same steps again for the next layer
        }

        input = outputs;
    }

    // after all layers done, get the one with the maximum value => its index is our predicted value.

    // for softrarg
    // ---------------------------------------------------------
    std::transform(outputs.begin(), outputs.end(),
        outputs.begin(),
        [](double i) { return exp(i); });

    double sumOfExp = std::accumulate(outputs.begin(), outputs.end(), 0.0);

    std::transform(outputs.begin(), outputs.end(),
        outputs.begin(),
        [sumOfExp](double i) { return i / sumOfExp; }
    );
    // --------------------------------------------------------------

    // very, very simple:
    auto foundMaxAt = std::max_element(outputs.begin(), outputs.end());
    int digit = foundMaxAt - outputs.begin();
    return digit;
}

void NeuralNetwork::SetWeights(std::vector<Matrix>&& w)
{
    m_weights = std::move(w);
}
void NeuralNetwork::SetBiases(std::vector<std::vector<double> >&& b)
{
    m_biases = std::move(b);
}
