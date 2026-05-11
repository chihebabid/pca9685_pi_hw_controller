//
// Created by chiheb on 11/05/2026.
//

#ifndef WS_ROS_PI_PCA9685_DRIVER_H
#define WS_ROS_PI_PCA9685_DRIVER_H
#include "i2c_driver.h"
#include <memory>
namespace rpi_pca9685_hw_controller {
    constexpr uint8_t PCA9685_MODE1  {0x0};
    constexpr uint8_t  PCA9685_PRESCALE {0xFE};
    struct Pca9685Driver {
        Pca9685Driver(uint8_t i2c_bus, uint8_t i2c_address,uint8_t freq=50);
        void set_servo_degree(uint8_t channel, uint8_t degree);
        void set_pulsewidth_min_max(uint16_t min, uint16_t max);
    private:
        void set_pwm_frequency(uint8_t freq);
        std::unique_ptr<I2cDriver> i2c_driver_;
        uint16_t pulse_width_min_ {500};
        uint16_t pulse_width_max_ {2500};
    };
}


#endif //WS_ROS_PI_PCA9685_DRIVER_H
