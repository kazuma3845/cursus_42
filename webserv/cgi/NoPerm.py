#!/usr/bin/python3
from datetime import datetime

# Obtenir l'heure actuelle
now = datetime.now()

# Formater l'heure au format HH:MM:SS
current_time = now.strftime("%H:%M:%S")

print("L'heure actuelle est :", current_time)