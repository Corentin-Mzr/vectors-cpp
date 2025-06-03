#pragma once

#include <cmath>
#include <iostream>

/**
 * @brief Simple 4D Vector class template
 *
 * Contains typical vector operations: addition, substraction, scalar
 * multiplication, division, dot, normalization, etc.
 */
template <typename T>
class Vector4
{
public:
    // Constructors
    explicit constexpr Vector4() noexcept = default;
    explicit constexpr Vector4(T x, T y, T z, T w) noexcept : x(x), y(y), z(z), w(w) {}
    Vector4(const Vector4 &other) noexcept = default;
    Vector4(Vector4 &&) noexcept = default;

    // Assignment
    constexpr Vector4 &operator=(const Vector4 &other) noexcept = default;

    // Comparison
    constexpr bool operator==(const Vector4 &other) const noexcept
    {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    // Unary
    constexpr Vector4 operator+() const noexcept { return *this; }
    constexpr Vector4 operator-() const noexcept { return Vector4(-x, -y, -z, -w); }

    // Vector - Vector operations
    constexpr Vector4 operator+(const Vector4 &o) const noexcept { return Vector4(x + o.x, y + o.y, z + o.z, w + o.w); }
    constexpr Vector4 operator-(const Vector4 &o) const noexcept { return Vector4(x - o.x, y - o.y, z - o.z, w - o.w); }
    constexpr Vector4 operator*(const Vector4 &o) const noexcept { return Vector4(x * o.x, y * o.y, z * o.z, w * o.w); }
    constexpr Vector4 operator/(const Vector4 &o) const noexcept { return Vector4(x / o.x, y / o.y, z / o.z, w / o.w); }

    // Vector - Scalar operations
    constexpr Vector4 operator+(T s) const noexcept { return Vector4(x + s, y + s, z + s, w + s); }
    constexpr Vector4 operator-(T s) const noexcept { return Vector4(x - s, y - s, z - s, w - s); }
    constexpr Vector4 operator*(T s) const noexcept { return Vector4(x * s, y * s, z * s, w * s); }
    constexpr Vector4 operator/(T s) const noexcept { return Vector4(x / s, y / s, z / s, w / s); }

    // Compound assignment
    Vector4 &operator+=(const Vector4 &o) noexcept
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
    Vector4 &operator-=(const Vector4 &o) noexcept
    {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        w -= o.w;
        return *this;
    }
    Vector4 &operator*=(const Vector4 &o) noexcept
    {
        x *= o.x;
        y *= o.y;
        z *= o.z;
        w *= o.w;
        return *this;
    }
    Vector4 &operator/=(const Vector4 &o) noexcept
    {
        x /= o.x;
        y /= o.y;
        z /= o.z;
        w /= o.w;
        return *this;
    }

    Vector4 &operator+=(T s) noexcept
    {
        x += s;
        y += s;
        z += s;
        w += s;
        return *this;
    }
    Vector4 &operator-=(T s) noexcept
    {
        x -= s;
        y -= s;
        z -= s;
        w -= s;
        return *this;
    }
    Vector4 &operator*=(T s) noexcept
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }
    Vector4 &operator/=(T s) noexcept
    {
        x /= s;
        y /= s;
        z /= s;
        w /= s;
        return *this;
    }

    // Dot product
    [[nodiscard]] constexpr T dot(const Vector4 &o) const noexcept
    {
        return x * o.x + y * o.y + z * o.z + w * o.w;
    }

    // Norm (length)
    [[nodiscard]] constexpr double norm() const noexcept
    {
        return std::sqrt(static_cast<double>(x) * x + static_cast<double>(y) * y + static_cast<double>(z) * z + static_cast<double>(w) * w);
    }

    [[nodiscard]] constexpr double length() const noexcept
    {
        return norm();
    }

    [[nodiscard]] constexpr double norm_squared() const noexcept
    {
        return static_cast<double>(x) * x + static_cast<double>(y) * y + static_cast<double>(z) * z + static_cast<double>(w) * w;
    }

    [[nodiscard]] constexpr double normSquared() const noexcept
    {
        return norm_squared();
    }

    // Normalized vector
    [[nodiscard]] constexpr Vector4 normalize() const noexcept
    {
        const double n{this->norm()};
        return n != 0 ? *this / static_cast<T>(n) : *this;
    }

    // Sign of components
    [[nodiscard]] constexpr Vector4 sign() const noexcept
    {
        return Vector4(
            x >= 0 ? static_cast<T>(1) : static_cast<T>(-1),
            y >= 0 ? static_cast<T>(1) : static_cast<T>(-1),
            z >= 0 ? static_cast<T>(1) : static_cast<T>(-1),
            w >= 0 ? static_cast<T>(1) : static_cast<T>(-1));
    }

    // Power (component-wise)
    [[nodiscard]] constexpr Vector4 pow(T exp) const noexcept
    {
        return Vector4(
            static_cast<T>(std::pow(x, exp)),
            static_cast<T>(std::pow(y, exp)),
            static_cast<T>(std::pow(z, exp)),
            static_cast<T>(std::pow(w, exp)));
    }

    // Stream output
    friend std::ostream &operator<<(std::ostream &os, const Vector4 &v) noexcept
    {
        os << "Vector4(x=" << v.x << ", y=" << v.y << ", z=" << v.z << ", w=" << v.w << ")";
        return os;
    }

    // Conversion to other Vector4
    template <typename K>
    explicit constexpr operator Vector4<K>() const noexcept
    {
        return Vector4<K>(x, y, z, w);
    }

    T x{};
    T y{};
    T z{};
    T w{};
};

// Scalar * vector
template <typename T>
constexpr Vector4<T> operator*(T s, const Vector4<T> &v) noexcept
{
    return v * s;
}

// Type aliases
using Vector4i = Vector4<int>;
using Vector4f = Vector4<float>;
using Vector4d = Vector4<double>;