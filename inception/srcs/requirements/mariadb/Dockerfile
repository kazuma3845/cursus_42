FROM debian:buster

# Mettre à jour la liste des paquets et installer les paquets nécessaires
RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y mariadb-server vim zsh wget git mycli

# Copier le script de configuration
COPY ./conf/mdb_conf.sh /mdb_conf.sh

# Rendre le script exécutable
RUN chmod +x /mdb_conf.sh

# Exposer le port MariaDB
EXPOSE 3306

# Définir le point d'entrée
ENTRYPOINT ["./mdb_conf.sh"]