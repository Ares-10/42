NAME = inception

DOCKER_COMPOSE_FILE = ./srcs/docker-compose.yml


all : $(NAME)

$(NAME) :
	mkdir -p /Users/johyeongeun/42/inception/srcs/wordpress
	mkdir -p /Users/johyeongeun/42/inception/srcs/mariadb
	docker-compose -f $(DOCKER_COMPOSE_FILE) up -d

clean :
	docker-compose -f $(DOCKER_COMPOSE_FILE) down

fclean :
	docker-compose -f $(DOCKER_COMPOSE_FILE) down --rmi all -v

ffclean : fclean
	rm -r /Users/johyeongeun/42/inception/srcs/wordpress
	rm -r /Users/johyeongeun/42/inception/srcs/mariadb
	docker system prune -a -f

re : fclean all

logs :
	docker-compose -f $(DOCKER_COMPOSE_FILE) logs

ps :
	docker-compose -f $(DOCKER_COMPOSE_FILE) ps

mariadb :
	docker-compose -f $(DOCKER_COMPOSE_FILE) exec mariadb bash

nginx :
	docker-compose -f $(DOCKER_COMPOSE_FILE) exec nginx bash

wordpress :
	docker-compose -f $(DOCKER_COMPOSE_FILE) exec wordpress bash

.PHONY : all clean fclean re ffclean logs ps mariadb nginx wordpress
