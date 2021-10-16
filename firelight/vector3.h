#pragma once

namespace atom {

template <typename T>
struct Vector3 {
  T x, y, z;

  Vector3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}
  Vector3() : x(0), y(0), z(0) {}

  bool HasNaNs() const {
    return std::isnan(x) || std::isnan(y) || std::isnan(z);
  }
};

}  // namespace atom