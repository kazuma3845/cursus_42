#!/bin/bash

# Nombre de répétitions
repetitions=1

# URL à tester avec Siege
url="http://127.0.0.1:8002/siege.html"

# Lancer Siege avec les options nécessaires, rediriger la sortie vers un fichier temporaire
siege -b -r $repetitions -v $url > siege_output.txt

# Afficher uniquement le résumé des statistiques
cat siege_output.txt | grep -A 10 'Transactions'

# Supprimer le fichier temporaire
rm siege_output.txt
