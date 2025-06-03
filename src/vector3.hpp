#pragma once

#include <cmath>
#include <iostream>

/**
 * @brief Simple 3D vector class template
 *
 * Contains typical vector operations: addition, subtraction, scalar
 * multiplication/division, dot and cross products, normalization, etc.
 */
template <typename T>
class Vector3
{
public:
    // Constructors
    explicit constexpr Vector3() noexcept = default;
    explicit constexpr Vector3(T x, T y, T z) noexcept : x(x), y(y), z(z) {}
    Vector3(const Vector3 &other) noexcept = default;
    Vector3(Vector3 &&) noexcept = default;

    // Assignment
    constexpr Vector3 &operator=(const Vector3 &other) noexcept = default;

    // Comparison
    constexpr bool operator==(const Vector3 &other) const noexcept
    {
        return x == other.x && y == other.y && z == other.z;
    }

    // Unary
    constexpr Vector3 operator+() const noexcept { return *this; }
    constexpr Vector3 operator-() const noexcept { return Vector3(-x, -y, -z); }

    // Vector - Vector operations
    constexpr Vector3 operator+(const Vector3 &o) const noexcept { return Vector3(x + o.x, y + o.y, z + o.z); }
    constexpr Vector3 operator-(const Vector3 &o) const noexcept { return Vector3(x - o.x, y - o.y, z - o.z); }
    constexpr Vector3 operator*(const Vector3 &o) const noexcept { return Vector3(x * o.x, y * o.y, z * o.z); }
    constexpr Vector3 operator/(const Vector3 &o) const noexcept { return Vector3(x / o.x, y / o.y, z / o.z); }

    // Vector - Scalar operations
    constexpr Vector3 operator+(T s) const noexcept { return Vector3(x + s, y + s, z + s); }
    constexpr Vector3 operator-(T s) const noexcept { return Vector3(x - s, y - s, z - s); }
    constexpr Vector3 operator*(T s) const noexcept { return Vector3(x * s, y * s, z * s); }
    constexpr Vector3 operator/(T s) const noexcept { return Vector3(x / s, y / s, z / s); }

    // Compound assignment
    Vector3 &operator+=(const Vector3 &o) noexcept
    {
        x += o.x;
        y += o.y;
        z += o.z;
        return *this;
    }
    Vector3 &operator-=(const Vector3 &o) noexcept
    {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        return *this;
    }
    Vector3 &operator*=(const Vector3 &o) noexcept
    {
        x *= o.x;
        y *= o.y;
        z *= o.z;
        return *this;
    }
    Vector3 &operator/=(const Vector3 &o) noexcept
    {
        x /= o.x;
        y /= o.y;
        z /= o.z;
        return *this;
    }

    Vector3 &operator+=(T s) noexcept
    {
        x += s;
        y += s;
        z += s;
        return *this;
    }
    Vector3 &operator-=(T s) noexcept
    {
        x -= s;
        y -= s;
        z -= s;
        return *this;
    }
    Vector3 &operator*=(T s) noexcept
    {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }
    Vector3 &operator/=(T s) noexcept
    {
        x /= s;
        y /= s;
        z /= s;
        return *this;
    }

    // Dot product
    [[nodiscard]] constexpr T dot(const Vector3 &o) const noexcept
    {
        return x * o.x + y * o.y + z * o.z;
    }

    // Cross product
    [[nodiscard]] constexpr Vector3 cross(const Vector3 &o) const noexcept
    {
        return Vector3(
            y * o.z - z * o.y,
            z * o.x - x * o.z,
            x * o.y - y * o.x);
    }

    // Norm (length)
    [[nodiscard]] constexpr double norm() const noexcept
    {
        return std::sqrt(static_cast<double>(x) * x + static_cast<double>(y) * y + static_cast<double>(z) * z);
    }

    [[nodiscard]] constexpr double length() const noexcept
    {
        return norm();
    }

    [[nodiscard]] constexpr double norm_squared() const noexcept
    {
        return static_cast<double>(x) * x + static_cast<double>(y) * y + static_cast<double>(z) * z;
    }

    [[nodiscard]] constexpr double normSquared() const noexcept
    {
        return norm_squared();
    }

    // Normalized vector
    [[nodiscard]] constexpr Vector3 normalize() const noexcept
    {
        const double n{this->norm()};
        return n != 0 ? *this / static_cast<T>(n) : *this;
    }

    // Sign of components
    [[nodiscard]] constexpr Vector3 sign() const noexcept
    {
        return Vector3(
            x >= 0 ? static_cast<T>(1) : static_cast<T>(-1),
            y >= 0 ? static_cast<T>(1) : static_cast<T>(-1),
            z >= 0 ? static_cast<T>(1) : static_cast<T>(-1));
    }

    // Power (component-wise)
    [[nodiscard]] constexpr Vector3 pow(T exp) const noexcept
    {
        return Vector3(
            static_cast<T>(std::pow(x, exp)),
            static_cast<T>(std::pow(y, exp)),
            static_cast<T>(std::pow(z, exp)));
    }

    // Stream output
    friend std::ostream &operator<<(std::ostream &os, const Vector3 &v) noexcept
    {
        os << "Vector3(x=" << v.x << ", y=" << v.y << ", z=" << v.z << ")";
        return os;
    }

    // Conversion to other Vector3
    template <typename K>
    explicit constexpr operator Vector3<K>() const noexcept
    {
        return Vector3<K>(x, y, z);
    }

    T x{};
    T y{};
    T z{};
};

// Scalar * vector
template <typename T>
constexpr Vector3<T> operator*(T s, const Vector3<T> &v) noexcept
{
    return v * s;
}

// Type aliases
using Vector3i = Vector3<int>;
using Vector3f = Vector3<float>;
using Vector3d = Vector3<double>;