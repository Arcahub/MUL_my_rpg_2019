/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** define
*/

#ifndef DEFINE_H_
#define DEFINE_H_

#include <SFML/Graphics.h>

// BASE

const char *BASE_PATH = "templates/tower/base.png";

// ENV

const char *ENV_DISPLAY = "DISPLAY";

// USAGE

const char *USAGE_FLAG = "-h";
const char *USAGE = "DESCRIPTION:\n\t./my_defender \
\n\nUSAGE:\n\tLaunch the game and head to the how to play section to see \
the different contents.\n \
\nCREATE MAP AND TOWER:\n\tRefer to the legend.md file\n\nDOCUMENTATION:\n\t\
Head to the doc.md file\n\nINFORMATION ABOUT COMPIL AND LAUNCH THE GAME:\n\t\
Head to the Readme.md";

// WINDOW

const unsigned short int WINDOW_WIDTH = 1920;
const unsigned short int WINDOW_HEIGHT = 1000;
const unsigned char WINDOW_BITS_PER_PIXEL = 32;
const unsigned char WINDOW_FRAMERATE = 60;
const char *WINDOW_NAME = "My Defender";
const char *ICON_PATH = "templates/icon.png";

const sfColor GAME_BACKGROUND_COLOR = {66, 98, 116, 0};
#endif /* !DEFINE_H_ */
