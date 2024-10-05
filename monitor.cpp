#include "./monitor.h"
#include <thread>
#include <chrono>
#include <iostream>
#include "./temperatureBodylimits.h"  // Include the header file for temperature body limits
#include "./pulseratebodylimits.h"  // Include the header file for pulse rate body limits
#include "./spo2bodylimits.h"  // Include the header file for spo2 body limits
using std::cout;
using std::flush;
using std::this_thread::sleep_for;
using std::chrono::seconds;

static void measureVitals() {
    for (int i = 0; i < 1; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}

static bool checkVital(const char* vitalName, float value, float min, float max) {
    if (value < min || value > max) {
        measureVitals();
        cout << vitalName << " is out of range!\n";
        return false;
    }
    return true;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
    bool temperatureOk = checkVital("Temperature", temperature, MIN_TEMPERATURE, MAX_TEMPERATURE);
    bool pulseRateOk = checkVital("Pulse Rate", pulseRate, MIN_PULSE_RATE, MAX_PULSE_RATE);
    bool spo2Ok = checkVital("Oxygen Saturation", spo2, MIN_SPO2, MAX_SPO2);

    return temperatureOk && pulseRateOk && spo2Ok;
}
