/*
** EPITECH PROJECT, 2019
** defender
** File description:
** const
*/

#include <SFML/Graphics.h>

#ifndef CONST_H
#define CONST_H

// SPACE

extern const int SIZE_Y_SPACE;
extern const int SIZE_X_SPACE;
extern const char *BACKGROUND_SPACE;

// ENV

extern const char *ENV_DISPLAY;

// USAGE

extern const char *USAGE_FLAG;
extern const char *USAGE;

// WINDOW

extern const unsigned short int WINDOW_WIDTH;
extern const unsigned short int WINDOW_HEIGHT;
extern const unsigned char WINDOW_BITS_PER_PIXEL;
extern const unsigned char WINDOW_FRAMERATE;
extern const char *WINDOW_NAME;
extern const char *ICON_PATH;

// MAIN MENU

extern const char *TITLE_PATH;

extern const char *ARROW_RIGHT_PATH;
extern const char *ARROW_LEFT_PATH;

extern const char *BACKGROUND_INFO;

extern const char *RETURN_BUTTON_PATH;
extern const unsigned short RETURN_BUTTON_X;
extern const unsigned short RETURN_BUTTON_Y;
extern const unsigned short PLAY_BUTTON_X;
extern const unsigned short PLAY_BUTTON_Y;
extern const char *PLAY_BUTTON_PATH;
extern const unsigned short OPTION_BUTTON_X;
extern const unsigned short OPTION_BUTTON_Y;
extern const char *OPTION_BUTTON_PATH;
extern const unsigned short INFOS_BUTTON_X;
extern const unsigned short INFOS_BUTTON_Y;
extern const char *INFOS_BUTTON_PATH;
extern const unsigned short EXIT_BUTTON_X;
extern const unsigned short EXIT_BUTTON_Y;
extern const char *EXIT_BUTTON_PATH;

extern const char *SHIPS_PATH;

// IN-GAME_MENU

extern const char *IN_GAME_MENU_BACKGROUND;

extern const unsigned short CONTINUE_BUTTON_X;
extern const unsigned short CONTINUE_BUTTON_Y;
extern const char *CONTINUE_BUTTON_PATH;
extern const unsigned short OPTION_BUTTON_X_IN_GAME;
extern const unsigned short OPTION_BUTTON_Y_IN_GAME;
extern const unsigned short MAIN_MENU_BUTTON_X;
extern const unsigned short MAIN_MENU_BUTTON_Y;
extern const char *MAIN_MENU_BUTTON_PATH;

// OPTIONS

extern const char *GLOBAL_VOLUME_TEXT;

extern const char *BAR_PATH;
extern const char *BAR_BACKGROUND_PATH;
extern const unsigned short BAR_WIDTH;
extern const unsigned short BAR_HEIGHT;
extern const unsigned char BAR_BOX_OFFSET;
extern const unsigned short VOLUME_BAR_X;
extern const unsigned short VOLUME_BAR_Y;

extern const unsigned char VOLUME_UNIT;
extern const unsigned char MAX_VOLUME;
extern const unsigned char MIN_VOLUME;

extern const char *INDICATOR_PATH;
extern const unsigned short INDICATOR_WIDTH;
extern const unsigned short INDICATOR_X;
extern const unsigned short INDICATOR_Y;

extern const char *FONT_PATH;
extern const char *CURSOR_PATH;

// INFOS

extern const char *INFOS_TITLE;
extern const unsigned short INFOS_TITLE_X;
extern const unsigned short INFOS_TITLE_Y;

extern const unsigned short INFOS_ARROW_Y;
extern const unsigned short INFOS_ARROW_LEFT_X;
extern const unsigned short INFOS_ARROW_RIGHT_X;

extern const char *INFOS_CONTENT_PATH;
extern const sfIntRect *INFOS_CONTENT_FRAME_KEYS[];

// GG MENU

extern const char *RESTART_PATH;
extern const unsigned short RESTART_X;
extern const unsigned short RESTART_Y;
#endif
