##
## EPITECH PROJECT, 2020
## minishell1
## File description:
## deploy
##

NAME=$TRAVIS_REPO_SLUG
echo $TRAVIS_REPO_SLUG
REPO_NAME=echo $NAME | awk -F'/' '{print $2}'
echo $REPO_NAME

ssh-keyscan -H git.epitech.eu >> ~/.ssh/known_hosts
git push git@git.epitech.eu:/guillaume.mailhol@epitech.eu/$REPO_NAME master