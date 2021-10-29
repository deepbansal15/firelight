// Copyright 2021 Deep Bansal
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <assert.h>
#include <stdio.h>

namespace firelight {

template <typename T>
struct Vector3 {
  T x, y, z;

  T operator[](int i) const {
    assert(i >= 0 && i <= 2);
    if (i == 0) return x;
    if (i == 1) return y;
    return z;
  }
  T& operator[](int i) {
    assert(i >= 0 && i <= 2);
    if (i == 0) return x;
    if (i == 1) return y;
    return z;
  }

  Vector3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) { assert(!HasNaNs()); }
  Vector3() : x(0), y(0), z(0) {}

  bool HasNaNs() const {
    return std::isnan(x) || std::isnan(y) || std::isnan(z);
  }

  Vector3(const Vector3<T>& v) {
    assert(!v.HasNaNs());
    x = v.x;
    y = v.y;
    z = v.z;
  }
  Vector3(Vector3<T>&& v) {
    assert(v.HasNaNs());
    x = v.x;
    y = v.y;
    z = v.z;
  }

  // Journal this
  friend std::ostream& operator<<(std::ostream& os, const Vector3<T>& v) {
    os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
    return os;
  }

  Vector3<T> operator+(const Vector3<T>& v) const {
    return Vector3(x + v.x, y + v.y, z + v.z);
  }

  Vector3<T>& operator+=(const Vector3<T>& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  }

  Vector3<T> operator-(const Vector3<T>& v) const {
    return Vector3(x - v.x, y - v.y, z - v.z);
  }

  Vector3<T>& operator+=(const Vector3<T>& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
  }

  bool operator==(const Vector3<T>& v) const {
    return x == v.x && y == v.y && z == v.z;
  }

  bool operator!=(const Vector3<T>& v) const {
    return x != v.x || y != v.y || z != v.z;
  }

  Vector3<T> operator*(T s) const { return Vector3<T>(s * x, s * y, s * z); }
  Vector3<T>& operator*=(T s) {
    x *= s;
    y *= s;
    z *= s;
    return *this;
  }

  Vector3<T> operator/(T f) const {
    Assert(f != 0);
    float inv = (Float)1 / f;
    return Vector3<T>(x * inv, y * inv, z * inv);
  }

  Vector3<T>& operator/=(T f) {
    Assert(f != 0);
    // TODO(db): Check this conversion
    float inv = static_cast<float>(1 / f);
    x *= inv;
    y *= inv;
    z *= inv;
    return *this;
  }

  Vector3<T> operator-() const { return Vector3<T>(-x, -y, -z); }
  // TODO(db): Write custom value types, for easy replacement with double or low
  // precision values
  float LengthSquared() const { return x * x + y * y + z * z; }
  float Length() const { return std::sqrt(LengthSquared()); }
};

typedef Vector3<double> Vector3d;
typedef Vector3<float> Vector3f;
typedef Vector3<int> Vector3i;

}  // namespace firelight
