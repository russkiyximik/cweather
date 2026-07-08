typedef enum {
    WEATHER_CLEAR,
    WEATHER_CLOUDY,
    WEATHER_RAINY,
    WEATHER_SNOWY,
    WEATHER_STORM
} WeatherCondition;



void draw_background(); // draws house and such

void draw_weather_frame(WeatherCondition condition, int frame);
