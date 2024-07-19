#!/usr/bin/env python3

import cgi
import cgitb
import html

cgitb.enable()  # Pour aider à déboguer

print("Content-Type: text/html")
print()  # Ligne vide nécessaire pour terminer les en-têtes HTTP

form = cgi.FieldStorage()

# Récupération des données du formulaire
name = form.getvalue('name')
email = form.getvalue('email')
password = form.getvalue('password')

# Échappement des données pour éviter les failles XSS
name = html.escape(name) if name else "Inconnu"
email = html.escape(email) if email else "Inconnu"
password = html.escape(password) if password else "Inconnu"

# Traitement des données (exemple : affichage des données)
print(f"""
	  
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Inscription Réussie</title>
</head>
<body>
    <h2>Merci pour votre inscription, {name}!</h2>
    <p>Email: {email}</p>
    <p>Mot de passe: {password}</p>
</body>
</html>
""")
