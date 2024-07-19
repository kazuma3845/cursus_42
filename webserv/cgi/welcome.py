#!/usr/bin/python3
import cgi

def main():
    form = cgi.FieldStorage()
    prenom = form.getvalue('prenom', 'Visiteur')
    couleur = form.getvalue('couleur', 'white')  # Couleur de fond par défaut

    print("Content-Type: text/html; charset=UTF-8")
    print("")  # Fin des en-têtes

    # Contenu HTML avec CSS pour un meilleur design
    print(f"""
          <!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Bienvenue</title>
    <style>
        body {{
            font-family: 'Arial', sans-serif;
            margin: 40px;
            transition: background-color 0.5s ease;
        }}
        h1 {{
            color: #333;
        }}
        form {{
            margin-top: 20px;
        }}
        input[type="text"], input[type="color"] {{
            padding: 10px;
            margin: 10px 0;
            border: 2px solid #ddd;
            border-radius: 4px;
            display: block;
        }}
        button {{
            padding: 10px 20px;
            background-color: #5C85D6;
            color: white;
            border: none;
            border-radius: 4px;
            cursor: pointer;
            font-size: 16px;
        }}
        button:hover {{
            background-color: #3A66CC;
        }}
        label {{
            margin-top: 20px;
        }}
    </style>
</head>
<body style="background-color: {couleur};">
    <h1>Bienvenue {prenom} !</h1>
    <p>Changez la couleur de fond de cette page en ajoutant <code>?prenom=VotreNom&couleur=Couleur</code> à l'URL.</p>
    <form action="" method="get">
        <label for="prenom">Votre prénom:</label>
        <input type="text" id="prenom" name="prenom" value="{prenom}">
        <label for="couleur">Choisissez une couleur:</label>
        <input type="color" id="couleur" name="couleur" value="{couleur}">
        <button type="submit">Appliquer</button>
    </form>
</body>
</html>""")

if __name__ == "__main__":
    main()
