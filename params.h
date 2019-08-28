#ifndef LEO_FIRMWARE_PARAMS_H
#define LEO_FIRMWARE_PARAMS_H

#include <cstdint>
#include "hFramework.h"

// Servos
const uint16_t SERVO_PERIOD = 20000;

enum voltage {VOLTAGE_5V, VOLTAGE_6V, VOLTAGE_7V4, VOLTAGE_8V6};
const voltage SERVO_VOLTAGE = VOLTAGE_7V4;

const int16_t SERVO_1_ANGLE_MIN = -90;
const int16_t SERVO_1_ANGLE_MAX = 90;
const uint16_t SERVO_1_WIDTH_MIN = 1000;
const uint16_t SERVO_1_WIDTH_MAX = 2000;

const int16_t SERVO_2_ANGLE_MIN = -90;
const int16_t SERVO_2_ANGLE_MAX = 90;
const uint16_t SERVO_2_WIDTH_MIN = 1000;
const uint16_t SERVO_2_WIDTH_MAX = 2000;

const int16_t SERVO_3_ANGLE_MIN = -90;
const int16_t SERVO_3_ANGLE_MAX = 90;
const uint16_t SERVO_3_WIDTH_MIN = 1000;
const uint16_t SERVO_3_WIDTH_MAX = 2000;

const int16_t SERVO_4_ANGLE_MIN = -90;
const int16_t SERVO_4_ANGLE_MAX = 90;
const uint16_t SERVO_4_WIDTH_MIN = 1000;
const uint16_t SERVO_4_WIDTH_MAX = 2000;

const int16_t SERVO_5_ANGLE_MIN = -90;
const int16_t SERVO_5_ANGLE_MAX = 90;
const uint16_t SERVO_5_WIDTH_MIN = 1000;
const uint16_t SERVO_5_WIDTH_MAX = 2000;

const int16_t SERVO_6_ANGLE_MIN = -90;
const int16_t SERVO_6_ANGLE_MAX = 90;
const uint16_t SERVO_6_WIDTH_MIN = 1000;
const uint16_t SERVO_6_WIDTH_MAX = 2000;


// Uncomment the line according to your wheel motors configuration
#define POLOLU
//#define BUEHLER

#ifdef POLOLU

    const float ENCODER_RESOLUTION = 8256.0; //in ticks per rotation
    const bool ENCODER_PULLUP = false; //set encoder pin A and B as pullups
    const float WHEEL_MAX_SPEED = 6500.0; //in ticks per second

    // PID
    const float PID_P = 0.0;
    const float PID_I = 0.0005;
    const float PID_D = 0.0;

#elif defined BUEHLER

    const float ENCODER_RESOLUTION = 878.4;
    const bool ENCODER_PULLUP = true;
    const float WHEEL_MAX_SPEED = 800.0;

    // PID
    const float PID_P = 0.0;
    const float PID_I = 0.005;
    const float PID_D = 0.0;

#endif


// Wheels
const float WHEEL_RADIUS = 0.0625; //in meters
const float ROBOT_WIDTH = 0.33; //in meters

// Odom
const float ODOM_COVARIANCE_DIAGONAL[6] = {0.001, 0, 0, 0, 0, 0.1};

// Imu
static hFramework::hSensor_i2c& IMU_HSENS = hSens2;
const float IMU_ANGULAR_VELOCITY_COVARIANCE_DIAGONAL[3] = {0.01, 0.01, 0.01};
const float IMU_LINEAR_ACCELERATION_COVARIANCE_DIAGONAL[3] = {0.01, 0.01, 0.01};

// Value between 0 and 1000 describing power limit
// e.g. 1000 means no limit, 800 corresponds to 80%
// Take into account that this value only limits the Voltage (PWM) and not the current.
const uint16_t POWER_LIMIT = 1000;

// Value between 0 and 1000 describing torque limit
// This value limits power depending on actual speed
// e.g. 800 means that power is limited to 80% at 0% speed, 90% at 10% speed etc.
const uint16_t TORQUE_LIMIT = 800;

// Input timeout in ms. 
// The controller will stop the motors if it doesn't receive a command for a specified time. 
// If set to 0, the controller won't check for a timeout
const uint32_t INPUT_TIMEOUT = 500;

// The pin which will be used to drive the informative LED on the power switch
// By default it is set to pin1 on hExt port
static hFramework::hGPIO& LED = hExt.pin1; 

#endif