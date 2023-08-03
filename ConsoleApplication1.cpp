// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Image.h"
#include "json.hpp"
#include <fstream>
#include "NeuralNetwork.h"
#include "NeuralNetworkImporter.h"

using json = nlohmann::json;

int main()
{
    std::cout << "Hello World!\n"; 

    Image i;
    // 1. Read image from JSON file
    std::ifstream imageInput("D:\\workdir\\digitRecognition2023\\ConsoleApplication1\\image.json");
    json data = json::parse(imageInput);

    int height = data["height"];
    int width = data["width"];
    int label = data["label"];

    //i.pixels = data["pixels"];
    {
        std::vector<uint8_t> pixels = data["pixels"];
        i.pixels = std::move(pixels);
    }

    // 2. Instantiate the NN
    NeuralNetwork n;
    // 3. Import the NN from JSON
    NeuralNetworkImporter nImporter(n);
    nImporter.Read("D:\\workdir\\digitRecognition2023\\ConsoleApplication1\\neural_net.json");
    // 4. Classify!!!

    int digit = n.Predict(i);

    return 0; // HA!
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
