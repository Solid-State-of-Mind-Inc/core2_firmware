#ifndef LEO_FIRMWARE_INCLUDE_UTILS_H_
#define LEO_FIRMWARE_INCLUDE_UTILS_H_

#include <cstdio>

#include <hFramework.h>

#include <ros.h>
#include <std_msgs/Int16.h>
#include <std_msgs/UInt16MultiArray.h>

#include <leo_firmware/logging.h>

inline float clamp(float value, float limit) {
  if (value > limit)
    return limit;
  else if (value < -limit)
    return -limit;
  else
    return value;
}

template <class T>
class CircularBuffer {
  T *values_;
  size_t size_;
  size_t iter_;

 public:
  explicit CircularBuffer(uint16_t size)
      : size_(size), iter_(0), values_(new T[size]) {}

  T push_back(T val) {
    T tmp = values_[iter_];
    values_[iter_++] = val;
    if (iter_ >= size_) iter_ = 0;
    return tmp;
  }
};

#endif  // LEO_FIRMWARE_INCLUDE_UTILS_H_
