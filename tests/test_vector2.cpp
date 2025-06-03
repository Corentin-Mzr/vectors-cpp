#include <vector2.hpp>

#include <cassert>
#include <sstream>

[[nodiscard]] bool approx_equal(double a, double b, double e = 1e-10)
{
    return std::fabs(a - b) < e;
}

template <typename T>
[[nodiscard]] bool approx_equal(const Vector2<T> &a, const Vector2<T> &b, double e = 1e-10)
{
    return approx_equal(a.x, b.x, e) && approx_equal(a.y, b.y, e);
}

void test_addition()
{
    /* --------------- Vector - Vector --------------- */

    // Int
    constexpr Vector2i v1_i(2, -3);
    constexpr Vector2i v2_i(-4, 1);
    static_assert(v1_i + v2_i == Vector2i(-2, -2));
    {
        Vector2i v{v1_i};
        v += v2_i;
        assert(v == Vector2i(-2, -2));
    }

    // Float
    constexpr Vector2f v1_f(3.14f, -27.2f);
    constexpr Vector2f v2_f(0.01f, 3.0f);
    static_assert(v1_f + v2_f == Vector2f(3.15f, -24.2f));
    {
        Vector2f v{v1_f};
        v += v2_f;
        assert(v == Vector2f(3.15f, -24.2f));
    }

    // Double
    constexpr Vector2d v1_d(6.0, 0.001);
    constexpr Vector2d v2_d(0.0, 1.0);
    static_assert(v1_d + v2_d == Vector2d(6.0, 1.001));
    {
        Vector2d v{v1_d};
        v += v2_d;
        assert(v == Vector2d(6.0, 1.001));
    }

    /* --------------- Vector - Scalar --------------- */

    // Int
    constexpr Vector2i v3_i(-2, 8);
    constexpr int s1{12};
    static_assert(v3_i + s1 == Vector2i(10, 20));
    {
        Vector2i v{v3_i};
        v += s1;
        assert(v == Vector2i(10, 20));
    }

    // Float
    constexpr Vector2f v3_f(2.0f, -3.0f);
    constexpr float s2{0.5f};
    static_assert(v3_f + s2 == Vector2f(2.5f, -2.5f));
    {
        Vector2f v{v3_f};
        v += s2;
        assert(v == Vector2f(2.5f, -2.5f));
    }

    // Double
    constexpr Vector2d v3_d(1.25, -2.00001);
    constexpr double s3{0.01};
    static_assert(v3_d + s3 == Vector2d(1.26, -1.99001));
    {
        Vector2d v{v3_d};
        v += s3;
        assert(v == Vector2d(1.26, -1.99001));
    }
}

void test_substraction()
{
    /* --------------- Vector - Vector --------------- */

    // Int
    constexpr Vector2i v1_i(5, -2);
    constexpr Vector2i v2_i(3, 1);
    static_assert(v1_i - v2_i == Vector2i(2, -3));
    {
        Vector2i v{v1_i};
        v -= v2_i;
        assert(v == Vector2i(2, -3));
    }

    // Float
    constexpr Vector2f v1_f(3.5f, -1.0f);
    constexpr Vector2f v2_f(1.5f, -2.5f);
    static_assert(v1_f - v2_f == Vector2f(2.0f, 1.5f));
    {
        Vector2f v{v1_f};
        v -= v2_f;
        assert(v == Vector2f(2.0f, 1.5f));
    }

    // Double
    constexpr Vector2d v1_d(10.5, 4.001);
    constexpr Vector2d v2_d(0.5, 0.001);
    static_assert(v1_d - v2_d == Vector2d(10.0, 4.0));
    {
        Vector2d v{v1_d};
        v -= v2_d;
        assert(v == Vector2d(10.0, 4.0));
    }

    /* --------------- Vector - Scalar --------------- */

    // Int
    constexpr Vector2i v3_i(5, -3);
    constexpr int s1{2};
    static_assert(v3_i - s1 == Vector2i(3, -5));
    {
        Vector2i v{v3_i};
        v -= s1;
        assert(v == Vector2i(3, -5));
    }

    // Float
    constexpr Vector2f v3_f(1.0f, 2.0f);
    constexpr float s2{0.5f};
    static_assert(v3_f - s2 == Vector2f(0.5f, 1.5f));
    {
        Vector2f v{v3_f};
        v -= s2;
        assert(v == Vector2f(0.5f, 1.5f));
    }

    // Double
    constexpr Vector2d v3_d(4.25, 1.75);
    constexpr double s3{0.25};
    static_assert(v3_d - s3 == Vector2d(4.0, 1.5));
    {
        Vector2d v{v3_d};
        v -= s3;
        assert(v == Vector2d(4.0, 1.5));
    }
}

void test_multiplication()
{
    /* --------------- Vector - Vector --------------- */

    // Int
    constexpr Vector2i v1_i(2, -3);
    constexpr Vector2i v2_i(4, 5);
    static_assert(v1_i * v2_i == Vector2i(8, -15));

    // Float
    constexpr Vector2f v1_f(1.5f, -2.0f);
    constexpr Vector2f v2_f(2.0f, 3.0f);
    static_assert(v1_f * v2_f == Vector2f(3.0f, -6.0f));

    // Double
    constexpr Vector2d v1_d(1.1, 2.2);
    constexpr Vector2d v2_d(2.0, 0.5);
    static_assert(v1_d * v2_d == Vector2d(2.2, 1.1));

    /* --------------- Vector - Scalar --------------- */

    // Int
    constexpr Vector2i v3_i(3, -2);
    constexpr int s1{4};
    static_assert(v3_i * s1 == s1 * v3_i && s1 * v3_i == Vector2i(12, -8));
    {
        Vector2i v{v3_i};
        v *= s1;
        assert(v == Vector2i(12, -8));
    }

    // Float
    constexpr Vector2f v3_f(1.0f, -1.0f);
    constexpr float s2{2.5f};
    static_assert(v3_f * s2 == s2 * v3_f && s2 * v3_f == Vector2f(2.5f, -2.5f));
    {
        Vector2f v{v3_f};
        v *= s2;
        assert(v == Vector2f(2.5f, -2.5f));
    }

    // Double
    constexpr Vector2d v3_d(1.5, 2.0);
    constexpr double s3{0.5};
    static_assert(v3_d * s3 == s3 * v3_d && s3 * v3_d == Vector2d(0.75, 1.0));
    {
        Vector2d v{v3_d};
        v *= s3;
        assert(v == Vector2d(0.75, 1.0));
    }
}

void test_division()
{
    /* --------------- Vector - Vector --------------- */

    // Int
    constexpr Vector2i v1_i(8, -6);
    constexpr Vector2i v2_i(2, 3);
    static_assert(v1_i / v2_i == Vector2i(4, -2));
    {
        Vector2i v{v1_i};
        v /= v2_i;
        assert(v == Vector2i(4, -2));
    }

    // Float
    constexpr Vector2f v1_f(4.5f, -9.0f);
    constexpr Vector2f v2_f(1.5f, 3.0f);
    static_assert(v1_f / v2_f == Vector2f(3.0f, -3.0f));
    {
        Vector2f v{v1_f};
        v /= v2_f;
        assert(v == Vector2f(3.0f, -3.0f));
    }

    // Double
    constexpr Vector2d v1_d(6.0, 2.0);
    constexpr Vector2d v2_d(3.0, 0.5);
    static_assert(v1_d / v2_d == Vector2d(2.0, 4.0));
    {
        Vector2d v{v1_d};
        v /= v2_d;
        assert(v == Vector2d(2.0, 4.0));
    }

    /* --------------- Vector - Scalar --------------- */

    // Int
    constexpr Vector2i v3_i(12, -4);
    constexpr int s1{4};
    static_assert(v3_i / s1 == Vector2i(3, -1));
    {
        Vector2i v{v3_i};
        v /= s1;
        assert(v == Vector2i(3, -1));
    }

    // Float
    constexpr Vector2f v3_f(2.0f, -5.0f);
    constexpr float s2{0.5f};
    static_assert(v3_f / s2 == Vector2f(4.0f, -10.0f));
    {
        Vector2f v{v3_f};
        v /= s2;
        assert(v == Vector2f(4.0f, -10.0f));
    }

    // Double
    constexpr Vector2d v3_d(3.0, 0.75);
    constexpr double s3{0.25};
    static_assert(v3_d / s3 == Vector2d(12.0, 3.0));
    {
        Vector2d v{v3_d};
        v /= s3;
        assert(v == Vector2d(12.0, 3.0));
    }
}

void test_norm()
{
    // Int
    constexpr Vector2i vi(3, 4);
    assert(vi.norm() == vi.length() && vi.length() == 5);

    // Float
    constexpr Vector2f vf(-0.5f, 0.5f);
    assert(vf.norm() == vf.length() && approx_equal(vf.norm(), std::sqrt(0.5)));

    // Double
    constexpr Vector2d vd(1.234, 5.678);
    assert(vd.norm() == vd.length() && approx_equal(vd.norm(), std::sqrt(33.76244)));
}

void test_norm_squared()
{
    // Int
    constexpr Vector2i vi(3, 4);
    assert(vi.norm_squared() == vi.normSquared() && vi.normSquared() == 25);

    // Float
    constexpr Vector2f vf(-0.5f, 0.5f);
    assert(vf.norm_squared() == vf.normSquared() && vf.normSquared() == 0.5);

    // Double
    constexpr Vector2d vd(1.234, 5.678);
    assert(vd.norm_squared() == vd.normSquared() && vd.normSquared() == 33.76244);
}

void test_normalize()
{
    // Int
    constexpr Vector2i vi(10, 0);
    assert(vi.normalize() == Vector2i(1, 0));

    // Float
    constexpr Vector2f vf(-0.0f, 0.0f);
    assert(vf.normalize() == Vector2f(0.0f, 0.0f));

    // Double
    constexpr Vector2d vd(-4, 3);
    assert(vd.normalize() == Vector2d(-4.0 / 5.0, 3.0 / 5.0));
}

void test_sign()
{
    // Int
    constexpr Vector2i vi(10, 0);
    static_assert(vi.sign() == Vector2i(1, 1));

    // Float
    constexpr Vector2f vf(-4.0f, 17.0f);
    static_assert(vf.sign() == Vector2f(-1.0f, 1.0f));

    // Double
    constexpr Vector2d vd(-4, -3);
    static_assert(vd.sign() == Vector2d(-1.0, -1.0));
}

void test_pow()
{
    // Int
    constexpr Vector2i vi(10, 0);
    assert(vi.pow(2) == Vector2i(100, 0));

    // Float
    constexpr Vector2f vf(4.0f, 4.0f);
    assert(approx_equal(vf.pow(1.5f), Vector2f(8, 8)));

    // Double
    constexpr Vector2d vd(2.2, 1.2);
    assert(approx_equal(vd.pow(3.0), Vector2d(10.648, 1.728)));
}

void test_convert()
{
    constexpr Vector2i vi(10, 5);
    constexpr Vector2f vf(1.1234567f, -1.1234567f);
    constexpr Vector2d vd(1.1234567891234567, -1.1234567891234567);

    // Int -> Float
    static_assert(static_cast<Vector2f>(vi).x == 10.0f &&static_cast<Vector2f>(vi).y == 5.0f);

    // Int -> Double
    static_assert(static_cast<Vector2d>(vi).x == 10.0 && static_cast<Vector2d>(vi).y == 5.0);

    // Float -> Int
    static_assert(static_cast<Vector2i>(vf).x == 1 && static_cast<Vector2i>(vf).y == -1);

    // Float -> Double
    static_assert(static_cast<Vector2d>(vf).x == 1.1234567165374756 && static_cast<Vector2d>(vf).y == -1.1234567165374756);

    // Double -> Int
    static_assert(static_cast<Vector2i>(vd).x == 1 && static_cast<Vector2i>(vd).y == -1);

    // Double -> Float
    static_assert(static_cast<Vector2f>(vd).x == 1.1234568f && static_cast<Vector2f>(vd).y == -1.1234568f);
}

void test_stream_output()
{
    Vector2f v(1.124f, 2.0f);
    std::ostringstream oss{};
    oss << v;
    assert(oss.str() == "Vector2(x=1.124, y=2)");
}

int main()
{
    test_addition();
    test_substraction();
    test_multiplication();
    test_division();
    test_norm();
    test_norm_squared();
    test_normalize();
    test_sign();
    test_pow();
    test_convert();
    test_stream_output();
    return 0;
}