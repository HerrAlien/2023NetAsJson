The neural network is described in a JSON with the following meaning:

{
  "n_layers": 3,
  "layer_sizes": [784, 100, 10 ],
  "activation": "logistic",
  "out_activation": "softmax",
  "weights": [
    [ // weights between the input layer and the hidden layer
      [ // weights of input 1 to all 100 hidden neurons
        -0.009230599845819969,
        ...
        -0.021905014335143403 // 100 in an array
      ],
      [ // weights of input 2 to all 100 hidden neurons
        0.004950818655168913,
        ...
        0.04668644343053879 // 100 in an array
      ],
      ...
      [
          ...
      ]  // 784 of such arrays
    ],
    [ // weights between hidden layer and output
      [ // weight of hidden neuron 1 for all 10 output neurons
        -0.008179546022555956,
        ...
        -0.24333291618520705 // 10 in an array
      ],
      ...
      [ // weight of hidden neuron 100 for all 10 output neurons
        ...
      ],
    ]
  ],
  "biases": [
    [ // biases for hidden layer
      -0.012428553745011832,
      ...
      -0.000533145822658016 // the 100th bias
    ],
    [ // biases for the 10 output neurons
      0.05541324068449571,
      ...
      0.016814324833288815 // 10th bias
    ]
  ]
}