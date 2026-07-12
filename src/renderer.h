/*
Owns a w x h character buffer
Clears the buffer
Draws characters, e.g. from backg.h
*/

#ifndef RENDERER_H
#define RENDERER_H



// Data
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



// Random stuff
void draw_background(); // draws house and such

void draw_frame(WeatherCondition condition, int frame);


#endif