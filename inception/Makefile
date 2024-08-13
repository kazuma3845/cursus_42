NAME = inception
PATH_DOCKER_COMPOSE = srcs/docker-compose.yml
PATH_V_WORDPRESS = /home/tomuller/data/wordpress
PATH_V_MARIADB = /home/tomuller/data/mariadb
PATH_TO_ENV_FILE = /home/tomuller/.env

all : prepare up start

up :
	@sudo docker-compose -f ./srcs/docker-compose.yml up -d

down : 
	@sudo docker-compose -f ./srcs/docker-compose.yml down

stop : 
	@sudo docker-compose -f ./srcs/docker-compose.yml stop

start : 
	@sudo docker-compose -f ./srcs/docker-compose.yml start

status : 
	@sudo docker image ls
	@sudo docker volume ls
	@sudo docker network ls

prepare:
		cp ${PATH_TO_ENV_FILE} srcs/.env;
		mkdir -p ${PATH_V_WORDPRESS};
		mkdir -p ${PATH_V_MARIADB};

clean: down
	sudo docker system prune -a

fclean: down
	sudo docker system prune -a --volumes
	sudo docker volume rm mariadb
	sudo docker volume rm wordpress
	sudo rm -rf ~/data
	sudo rm -rf srcs/.env

re: fclean all
