/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** define
*/

#ifndef DEFINE_H_
#define DEFINE_H_

#include <SFML/Graphics.h>

// SPACE

const int SIZE_X_SPACE = 10;
const int SIZE_Y_SPACE = 10;
const char *BACKGROUND_SPACE = "templates/env/space_background.jpg";

// ENV

const char *ENV_DISPLAY = "DISPLAY";

// USAGE

const char *USAGE_FLAG = "-h";
const char *USAGE = "DESCRIPTION:\n\t./my_rpg \
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
const char *WINDOW_NAME = "My RPG";
const char *ICON_PATH = "templates/icon.png";

// MAIN MENU

const char *TITLE_PATH = "templates/menu/menu_bg_test_with_text.jpg";

const char *ARROW_RIGHT_PATH = "templates/menu/arrow_right.png";
const char *ARROW_LEFT_PATH = "templates/menu/arrow_left.png";

const char *BACKGROUND_INFO = "templates/menu/in_game_menu_background.jpg";

const char *RETURN_BUTTON_PATH = "templates/menu/return2.png";
const unsigned short RETURN_BUTTON_X = (WINDOW_WIDTH - 280) / 2;
const unsigned short RETURN_BUTTON_Y = 700;
const unsigned short PLAY_BUTTON_X = (WINDOW_WIDTH - 280) / 2;
const unsigned short PLAY_BUTTON_Y = 350;
const char *PLAY_BUTTON_PATH = "templates/menu/play2.png";
const unsigned short OPTION_BUTTON_X = WINDOW_WIDTH - 350;
const unsigned short OPTION_BUTTON_Y = 800;
const char *OPTION_BUTTON_PATH = "templates/menu/option2.png";
const unsigned short INFOS_BUTTON_X = (WINDOW_WIDTH - 280) / 2;
const unsigned short INFOS_BUTTON_Y = 515;
const char *INFOS_BUTTON_PATH = "templates/menu/info2.png";
const unsigned short EXIT_BUTTON_X = (WINDOW_WIDTH - 280) / 2;
const unsigned short EXIT_BUTTON_Y = 690;
const char *EXIT_BUTTON_PATH = "templates/menu/exit2.png";

const char *SHIPS_PATH = "templates/menu/Ships.png";

// IN-GAME MENU

const char *IN_GAME_MENU_BACKGROUND = "templates/menu/\
in_game_menu_background.jpg";

const unsigned short CONTINUE_BUTTON_X = (WINDOW_WIDTH - 280) / 2;
const unsigned short CONTINUE_BUTTON_Y = 350;
const char *CONTINUE_BUTTON_PATH = "templates/menu/continue2.png";
const unsigned short OPTION_BUTTON_X_IN_GAME = (WINDOW_WIDTH - 280) / 2;
const unsigned short OPTION_BUTTON_Y_IN_GAME = 515;
const unsigned short MAIN_MENU_BUTTON_X = (WINDOW_WIDTH - 280) / 2;
const unsigned short MAIN_MENU_BUTTON_Y = 690;
const char *MAIN_MENU_BUTTON_PATH = "templates/menu/main_menu2.png";

// OPTIONS

const char *GLOBAL_VOLUME_TEXT = "Global Volume :";

const char *BAR_PATH = "templates/menu/bar.png";
const char *BAR_BACKGROUND_PATH = "templates/menu/bar_background.png";
const unsigned short BAR_WIDTH = 500;
const unsigned short BAR_HEIGHT = 10;
const unsigned char BAR_BOX_OFFSET = 20;
const unsigned short VOLUME_BAR_X = (WINDOW_WIDTH - BAR_WIDTH) / 2 + 300;
const unsigned short VOLUME_BAR_Y = 400;

const unsigned char VOLUME_UNIT = 10;
const unsigned char MAX_VOLUME = 100;
const unsigned char MIN_VOLUME = 0;

const char *INDICATOR_PATH = "templates/menu/scrollbar_fleur_new.png";
const unsigned short INDICATOR_WIDTH = 107;
const unsigned short INDICATOR_X = VOLUME_BAR_X;
const unsigned short INDICATOR_Y = 400 - 25;

const char *FONT_PATH = "templates/font/space.ttf";

const char *CURSOR_PATH = "templates/menu/Cursor.png";

// INFO

const char *INFOS_TITLE = "templates/menu/infos_title.png";
const unsigned short INFOS_TITLE_X = 852;
const unsigned short INFOS_TITLE_Y = 100;

const unsigned short INFOS_ARROW_Y = 464;
const unsigned short INFOS_ARROW_LEFT_X = 10;
const unsigned short INFOS_ARROW_RIGHT_X = WINDOW_WIDTH - 110;

const char *INFOS_CONTENT_PATH = "templates/menu/infos_content.png";
const sfIntRect *INFOS_CONTENT_FRAME_KEYS[] = {
    &(sfIntRect) {0, 0, 1920, 1080},
    &(sfIntRect) {0, 1080, 1920, 1080},
    &(sfIntRect) {0, 2160, 1920, 1080},
    NULL
};

// GG MENU

const char *RESTART_PATH = "templates/menu/restart.png";
const unsigned short RESTART_X = (WINDOW_WIDTH - 272) / 2;
const unsigned short RESTART_Y = 575;

#endif /* !DEFINE_H_ */
