#ifndef TERMINAL_H
#define TERMINAL_H


#define SCENE_WIDTH 100
#define SCENE_HEIGHT 20
#define FRAME_COUNT 150
#define FRAME_DELAY_MS 100


// basic terminal utils
void clear_screen(void);
void hide_cursor(void);
void show_cursor(void);
void sleep_ms(long ms);


// stuff related to weather
typedef enum {
    WEATHER_CLEAR,
    WEATHER_CLOUDY,
    WEATHER_RAINY,
    WEATHER_SNOWY,
    WEATHER_STORM
} WeatherCondition;

typedef struct {
    WeatherCondition condition;
    double temp; // in C
    double wind_speed;
    double precipitation;
} WeatherData;



void draw_background(); // draws house and such

void draw_frame(WeatherCondition condition, int frame);


#endif