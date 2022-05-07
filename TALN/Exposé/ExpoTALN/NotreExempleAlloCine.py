# Import des Librairies

import torch
import numpy as np
import pandas as pd
from sklearn.feature_extraction.text import CountVectorizer
from ReseauNeurone import Perceptron
import torch.nn as nn
from torch.utils.data import TensorDataset, DataLoader
import torch.optim as optim
from sklearn.metrics import accuracy_score

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

#################### Chargement des Données ####################

FichierEntrainement = pd.read_csv('data/train.csv', sep=',', header=None,
                                  names=['film-url', 'commentaire', 'sentiment'])

FichierTest = pd.read_csv('data/test.csv', sep=',', header=None,
                                  names=['film-url', 'commentaire', 'sentiment'])

#################### Création des vecteurs  ####################

    # print(FichierEntrainement)

count_vect = CountVectorizer(max_features=1000)
X_train_counts = count_vect.fit_transform(FichierEntrainement.commentaire)

tensorEntrainement = torch.Tensor(X_train_counts.toarray())
tensorSentiment = torch.LongTensor(FichierEntrainement.sentiment)

Y_train_counts = count_vect.fit_transform(FichierTest.commentaire)

tensorTest = torch.Tensor(Y_train_counts.toarray())
tensorSentimentTest = torch.LongTensor(FichierTest.sentiment)

    # print(tensorEntrainement.shape)
    # print(torch.cuda.is_available())

#################### Creation du Modele de Réseau de Neurone ####################

ReseauNeuro = Perceptron().to(device)

    #print(ReseauNeuro)

#################### Definition de la Loss et de l'optimizer ####################

EntrainementDataset = TensorDataset(tensorEntrainement, tensorSentiment)
EntrainementDataLoader = DataLoader(EntrainementDataset, batch_size=32, shuffle=True)

    #batch = next(iter(EntrainementDataLoader))
    #print(batch[0].shape)

criterion = nn.CrossEntropyLoss()
optimizer = optim.Adam(ReseauNeuro.parameters(), lr=0.01)

#################### Boucle d'apprentissage ####################

for epoch in range(10):
    print("Entrainement ", epoch, "...")
    for data in EntrainementDataLoader:
        commentaire, sentiment = data
        resultat = ReseauNeuro(commentaire.to(device))
        loss = criterion(resultat, sentiment.to(device))
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()

#################### Mesure des Performances ####################

TestDataset = TensorDataset(torch.Tensor(Y_train_counts.toarray()), torch.LongTensor(FichierTest.sentiment))
TestDataLoader = DataLoader(TestDataset, batch_size=256, shuffle=False)

AllPrediction = []
AllSentiment = []

print("Test des Prédictions....\n")

i = 0

with torch.no_grad():
    for data in TestDataLoader:
        commentaire, sentiment = data
        resultat = ReseauNeuro(commentaire.to(device))
        _, prediction = torch.max(resultat.data, 1)
        AllPrediction.append(prediction.cpu().numpy())
        AllSentiment.append(sentiment.cpu().numpy())
        if i % 10 == 0:
            pred = accuracy_score(prediction.cpu().numpy(), sentiment.cpu().numpy())
            if pred == 1:
                print("Prediction n°", i, " : ")
                if FichierEntrainement.sentiment[i] == 0:
                    print(FichierEntrainement.commentaire[i], " --> Bon Commentaire")
                else:
                    print(FichierEntrainement.commentaire[i], " --> Mauvais Commentaire")
            else:
                print("Prediction n°", i, " : ")
                if FichierEntrainement.sentiment[i] == 0:
                    print(FichierEntrainement.commentaire[i], " --> Mauvais Commentaire")
                else:
                    print(FichierEntrainement.commentaire[i], " --> Bon Commentaire")
        i = i + 1

AllSentiment = np.concatenate(AllSentiment)
AllPrediction = np.concatenate(AllPrediction)

Performance = accuracy_score(AllSentiment, AllPrediction)
print(Performance)


