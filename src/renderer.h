/*
Owns a w x h character buffer
Clears the buffer
Draws characters, e.g. from backg.h
*/

#ifndef RENDERER_H
#define RENDERER_H

#include <stddef.h>


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


// Core objects
typedef struct {
    int width;
    int height;
    size_t stride; // bytes between rows
    size_t length;
    char* buffer;
} Renderer;


// Core functionality
int renderer_init(Renderer* renderer, int term_w, int term_h);
void renderer_destroy(Renderer* renderer);

void renderer_clear(Renderer* renderer);
int renderer_write(Renderer* renderer, int x, int y, char symbol);

// just getter functions lol. Encapsulation! Good software design!
const char* renderer_buffer(const Renderer* renderer);
const size_t renderer_length(const Renderer* renderer);


// Random stuff (tbd whether needed or not)
void draw_background(); // draws house and such

void draw_frame(WeatherCondition condition, int frame);


#endif