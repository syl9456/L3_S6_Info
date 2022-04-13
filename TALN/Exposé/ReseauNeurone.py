import torch.nn as nn


class Perceptron(nn.Module):

    def __init__(self):
        super(Perceptron, self).__init__()
        self.fcl = nn.Linear(1000, 2)

    def forward(self, x):
        return self.fcl(x)
