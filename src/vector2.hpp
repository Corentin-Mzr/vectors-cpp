#pragma once

#include <cmath>
#include <iostream>

/**
 * @brief Simple 2D Vector class template
 *
 * Contains both classic and unusual operations on vectors (i.e multiplication of vectors, powers etc.)
 */
template <typename T>
class Vector2
{
public:
    // Constructors
    explicit constexpr Vector2() noexcept = default;
    explicit constexpr Vector2(T x, T y) noexcept : x(x), y(y) {};
    Vector2(const Vector2 &v) noexcept = default;
    Vector2(Vector2 &&) noexcept = default;

    // Assignment
    constexpr Vector2 &operator=(const Vector2 &o) noexcept = default;

    // Comparison
    constexpr bool operator==(const Vector2 &o) const noexcept
    {
        return x == o.x && y == o.y;
    }

    // Unary
    constexpr Vector2 operator+() const noexcept { return *this; }
    constexpr Vector2 operator-() const noexcept { return Vector2(-x, -y); }

    // Vector - Vector operations
    constexpr Vector2 operator+(const Vector2 &o) const noexcept { return Vector2(x + o.x, y + o.y); }
    constexpr Vector2 operator-(const Vector2 &o) const noexcept { return Vector2(x - o.x, y - o.y); }
    constexpr Vector2 operator*(const Vector2 &o) const noexcept { return Vector2(x * o.x, y * o.y); }
    constexpr Vector2 operator/(const Vector2 &o) const noexcept { return Vector2(x / o.x, y / o.y); }

    // Vector - Scalar operations
    constexpr Vector2 operator+(T s) const noexcept { return Vector2(x + s, y + s); }
    constexpr Vector2 operator-(T s) const noexcept { return Vector2(x - s, y - s); }
    constexpr Vector2 operator*(T s) const noexcept { return Vector2(x * s, y * s); }
    constexpr Vector2 operator/(T s) const noexcept { return Vector2(x / s, y / s); }

    // Compound assignment
    Vector2 &operator+=(const Vector2 &o) noexcept
    {
        x += o.x;
        y += o.y;
        return *this;
    }

    Vector2 &operator-=(const Vector2 &o) noexcept
    {
        x -= o.x;
        y -= o.y;
        return *this;
    }

    Vector2 &operator*=(const Vector2 &o) noexcept
    {
        x *= o.x;
        y *= o.y;
        return *this;
    }

    Vector2 &operator/=(const Vector2 &o) noexcept
    {
        x /= o.x;
        y /= o.y;
        return *this;
    }

    Vector2 &operator+=(T s) noexcept
    {
        x += s;
        y += s;
        return *this;
    }

    Vector2 &operator-=(T s) noexcept
    {
        x -= s;
        y -= s;
        return *this;
    }

    Vector2 &operator*=(T s) noexcept
    {
        x *= s;
        y *= s;
        return *this;
    }

    Vector2 &operator/=(T s) noexcept
    {
        x /= s;
        y /= s;

        return *this;
    }

    // Dot product
    [[nodiscard]] constexpr T dot(const Vector2 &o) const noexcept
    {
        return x * o.x + y * o.y;
    }

    // Norm (length)
    [[nodiscard]] constexpr double norm() const noexcept
    {
        return std::sqrt(static_cast<double>(x) * x + static_cast<double>(y) * y);
    }

    [[nodiscard]] constexpr double length() const noexcept
    {
        return norm();
    }

    [[nodiscard]] constexpr double norm_squared() const noexcept
    {
        return static_cast<double>(x) * x + static_cast<double>(y) * y;
    }

    [[nodiscard]] constexpr double normSquared() const noexcept
    {
        return norm_squared();
    }

    // Normalized vector
    [[nodiscard]] constexpr Vector2 normalize() const noexcept
    {
        const double n{this->norm()};
        return n != 0 ? *this / static_cast<T>(n) : *this;
    }

    // Sign of components
    [[nodiscard]] constexpr Vector2 sign() const noexcept
    {
        return Vector2(
            x >= 0 ? static_cast<T>(1) : static_cast<T>(-1),
            y >= 0 ? static_cast<T>(1) : static_cast<T>(-1));
    }

    // Power (component-wise)
    [[nodiscard]] constexpr Vector2 pow(T exp) const noexcept
    {
        return Vector2(
            static_cast<T>(std::pow(x, exp)),
            static_cast<T>(std::pow(y, exp)));
    }

    // Stream output
    friend std::ostream &operator<<(std::ostream &os, const Vector2 &vec) noexcept
    {
        os << "Vector2(x=" << vec.x << ", y=" << vec.y << ")";
        return os;
    }

    // Conversion to other Vector2
    template <typename K>
    explicit constexpr operator Vector2<K>() const noexcept
    {
        return Vector2<K>(x, y);
    }

    T x{};
    T y{};
};

// Scalar * vector
template <typename T>
constexpr Vector2<T> operator*(T s, const Vector2<T> &v) noexcept
{
    return v * s;
}

// Type aliases
using Vector2i = Vector2<int>;
using Vector2f = Vector2<float>;
using Vector2d = Vector2<double>;
