#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SensorReadings {
    int temperatureInC;
    int precipitation;
    int humidity;
    int windSpeedKMPH;
};

// This is a stub for a weather sensor. For the sake of testing 
// we create a stub that generates weather data and allows us to
// test the other parts of this application in isolation
// without needing the actual Sensor during development

struct SensorReadings sensorStub() {
    struct SensorReadings readings;
    readings.temperatureInC = 50;
    readings.precipitation = 70;
    readings.humidity = 26;
    readings.windSpeedKMPH = 52;
    return readings;
}

char* report(struct SensorReadings (*sensorReader)()) {
    size_t bufsize = 50;
    char* weather = (char*)malloc(bufsize);
    if (!weather) return NULL;
    struct SensorReadings readings = sensorReader();
    const char* weatherStr = "Sunny Day";
    if (readings.temperatureInC > 25) {
        if (readings.precipitation >= 20 && readings.precipitation < 60) {
            weatherStr = "Partly Cloudy";
        } else if (readings.windSpeedKMPH > 50) {
            weatherStr = "Alert, Stormy with heavy rain";
        }
    }
    snprintf(weather, bufsize, "%s", weatherStr);
    return weather;
}

void testRainy() {
    char* weather = report(sensorStub);
    printf("%s\n", weather);
    assert(weather && strstr(weather, "rain") != NULL);
    free(weather);
}

struct SensorReadings sensorHighPrecipitationStub() {
    struct SensorReadings readings;
    readings.temperatureInC = 50;
    readings.precipitation = 70;
    readings.humidity = 26;
    readings.windSpeedKMPH = 40;
    return readings;
}
void testHighPrecipitation() {
    // This instance of stub needs to be different-
    // to give high precipitation (>60) and low wind-speed (<50)
    char* weather = report(sensorHighPrecipitationStub);

    assert(weather && strlen(weather) > 0);
    assert(strstr(weather, "rain") != NULL);
    free(weather);
}

int testWeatherReport() {
    printf("\nWeather report test\n");
    testRainy();
    testHighPrecipitation();
    printf("All is well (maybe!)\n");
    return 0;
}
