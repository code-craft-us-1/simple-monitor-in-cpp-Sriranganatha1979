#include "./monitor.h"
#include "./temperatureBodylimits.h" 
#include "./pulseratebodylimits.h"
#include "./spo2bodylimits.h"

#include "gtest/gtest.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70));
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));
}

TEST(Monitor, NotOkWhenTemperatureIsMaxValue) {
  ASSERT_FALSE(vitalsOk(MAX_TEMPERATURE + 1, MAX_PULSE_RATE-1, MAX_SPO2-1));
}

TEST(Monitor, NotOkWhenTemperatureIsMinValue) {
  ASSERT_FALSE(vitalsOk(MIN_TEMPERATURE - 1, MAX_PULSE_RATE-1, MAX_SPO2-1));
}

TEST(Monitor, NotOkWhenSpo2IsMaxValue) {
  ASSERT_FALSE(vitalsOk(MAX_TEMPERATURE-1, MAX_PULSE_RATE - 1, MAX_SPO2 + 1));
}

TEST(Monitor, NotOkWhenSpo2IsMinValue) {
  ASSERT_FALSE(vitalsOk(MAX_TEMPERATURE - 1, MAX_PULSE_RATE - 1,  MIN_SPO2 - 1));
}

TEST(Monitor, NotOkWhenPulseRateIsMaxValue) {
  ASSERT_FALSE(vitalsOk(MAX_TEMPERATURE - 1, MAX_PULSE_RATE + 1, MAX_SPO2 - 1));
}

TEST(Monitor, NotOkWhenPulseRateIsMinValue) {
  ASSERT_FALSE(vitalsOk(MAX_TEMPERATURE - 1, MIN_PULSE_RATE - 1, MAX_SPO2 - 1));
}
