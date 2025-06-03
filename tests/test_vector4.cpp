#include <vector4.hpp>

#include <cassert>
#include <sstream>

[[nodiscard]] bool approx_equal(double a, double b, double e = 1e-10)
{
    return std::fabs(a - b) < e;
}

template <typename T>
[[nodiscard]] bool approx_equal(const Vector4<T> &a, const Vector4<T> &b, double e = 1e-10)
{
    return approx_equal(a.x, b.x, e) && approx_equal(a.y, b.y, e) && 
           approx_equal(a.z, b.z, e) && approx_equal(a.w, b.w, e);
}

void test_addition()
{
    /* --------------- Vector - Vector --------------- */

    // Int
    constexpr Vector4i v1_i(2, -3, 1, 5);
    constexpr Vector4i v2_i(-4, 1, 2, -1);
    static_assert(v1_i + v2_i == Vector4i(-2, -2, 3, 4));
    {
        Vector4i v{v1_i};
        v += v2_i;
        assert(v == Vector4i(-2, -2, 3, 4));
    }

    // Float
    constexpr Vector4f v1_f(3.14f, -27.2f, 0.5f, 1.0f);
    constexpr Vector4f v2_f(0.01f, 3.0f, -0.5f, 2.0f);
    static_assert(v1_f + v2_f == Vector4f(3.15f, -24.2f, 0.0f, 3.0f));
    {
        Vector4f v{v1_f};
        v += v2_f;
        assert(v == Vector4f(3.15f, -24.2f, 0.0f, 3.0f));
    }

    // Double
    constexpr Vector4d v1_d(6.0, 0.001, -1.5, 2.5);
    constexpr Vector4d v2_d(0.0, 1.0, 1.5, -0.5);
    static_assert(v1_d + v2_d == Vector4d(6.0, 1.001, 0.0, 2.0));
    {
        Vector4d v{v1_d};
        v += v2_d;
        assert(v == Vector4d(6.0, 1.001, 0.0, 2.0));
    }

    /* --------------- Vector - Scalar --------------- */

    // Int
    constexpr Vector4i v3_i(-2, 8, 3, -1);
    constexpr int s1{12};
    static_assert(v3_i + s1 == Vector4i(10, 20, 15, 11));
    {
        Vector4i v{v3_i};
        v += s1;
        assert(v == Vector4i(10, 20, 15, 11));
    }

    // Float
    constexpr Vector4f v3_f(2.0f, -3.0f, 1.5f, 0.0f);
    constexpr float s2{0.5f};
    static_assert(v3_f + s2 == Vector4f(2.5f, -2.5f, 2.0f, 0.5f));
    {
        Vector4f v{v3_f};
        v += s2;
        assert(v == Vector4f(2.5f, -2.5f, 2.0f, 0.5f));
    }

    // Double
    constexpr Vector4d v3_d(1.25, -2.00001, 3.75, -0.25);
    constexpr double s3{0.01};
    static_assert(v3_d + s3 == Vector4d(1.26, -1.99001, 3.76, -0.24));
    {
        Vector4d v{v3_d};
        v += s3;
        assert(v == Vector4d(1.26, -1.99001, 3.76, -0.24));
    }
}

void test_substraction()
{
    /* --------------- Vector - Vector --------------- */

    // Int
    constexpr Vector4i v1_i(5, -2, 8, 3);
    constexpr Vector4i v2_i(3, 1, 2, -1);
    static_assert(v1_i - v2_i == Vector4i(2, -3, 6, 4));
    {
        Vector4i v{v1_i};
        v -= v2_i;
        assert(v == Vector4i(2, -3, 6, 4));
    }

    // Float
    constexpr Vector4f v1_f(3.5f, -1.0f, 2.5f, 4.0f);
    constexpr Vector4f v2_f(1.5f, -2.5f, 0.5f, 1.0f);
    static_assert(v1_f - v2_f == Vector4f(2.0f, 1.5f, 2.0f, 3.0f));
    {
        Vector4f v{v1_f};
        v -= v2_f;
        assert(v == Vector4f(2.0f, 1.5f, 2.0f, 3.0f));
    }

    // Double
    constexpr Vector4d v1_d(10.5, 4.001, -1.5, 6.0);
    constexpr Vector4d v2_d(0.5, 0.001, -2.5, 2.0);
    static_assert(v1_d - v2_d == Vector4d(10.0, 4.0, 1.0, 4.0));
    {
        Vector4d v{v1_d};
        v -= v2_d;
        assert(v == Vector4d(10.0, 4.0, 1.0, 4.0));
    }

    /* --------------- Vector - Scalar --------------- */

    // Int
    constexpr Vector4i v3_i(5, -3, 7, 1);
    constexpr int s1{2};
    static_assert(v3_i - s1 == Vector4i(3, -5, 5, -1));
    {
        Vector4i v{v3_i};
        v -= s1;
        assert(v == Vector4i(3, -5, 5, -1));
    }

    // Float
    constexpr Vector4f v3_f(1.0f, 2.0f, -0.5f, 3.5f);
    constexpr float s2{0.5f};
    static_assert(v3_f - s2 == Vector4f(0.5f, 1.5f, -1.0f, 3.0f));
    {
        Vector4f v{v3_f};
        v -= s2;
        assert(v == Vector4f(0.5f, 1.5f, -1.0f, 3.0f));
    }

    // Double
    constexpr Vector4d v3_d(4.25, 1.75, 2.5, 0.75);
    constexpr double s3{0.25};
    static_assert(v3_d - s3 == Vector4d(4.0, 1.5, 2.25, 0.5));
    {
        Vector4d v{v3_d};
        v -= s3;
        assert(v == Vector4d(4.0, 1.5, 2.25, 0.5));
    }
}

void test_multiplication()
{
    /* --------------- Vector - Vector --------------- */

    // Int
    constexpr Vector4i v1_i(2, -3, 4, 1);
    constexpr Vector4i v2_i(4, 5, -2, 3);
    static_assert(v1_i * v2_i == Vector4i(8, -15, -8, 3));

    // Float
    constexpr Vector4f v1_f(1.5f, -2.0f, 0.5f, 4.0f);
    constexpr Vector4f v2_f(2.0f, 3.0f, -4.0f, 0.25f);
    static_assert(v1_f * v2_f == Vector4f(3.0f, -6.0f, -2.0f, 1.0f));

    // Double
    constexpr Vector4d v1_d(1.1, 2.2, -1.5, 0.8);
    constexpr Vector4d v2_d(2.0, 0.5, 2.0, 1.25);
    static_assert(v1_d * v2_d == Vector4d(2.2, 1.1, -3.0, 1.0));

    /* --------------- Vector - Scalar --------------- */

    // Int
    constexpr Vector4i v3_i(3, -2, 1, 5);
    constexpr int s1{4};
    static_assert(v3_i * s1 == s1 * v3_i && s1 * v3_i == Vector4i(12, -8, 4, 20));
    {
        Vector4i v{v3_i};
        v *= s1;
        assert(v == Vector4i(12, -8, 4, 20));
    }

    // Float
    constexpr Vector4f v3_f(1.0f, -1.0f, 2.0f, 0.5f);
    constexpr float s2{2.5f};
    static_assert(v3_f * s2 == s2 * v3_f && s2 * v3_f == Vector4f(2.5f, -2.5f, 5.0f, 1.25f));
    {
        Vector4f v{v3_f};
        v *= s2;
        assert(v == Vector4f(2.5f, -2.5f, 5.0f, 1.25f));
    }

    // Double
    constexpr Vector4d v3_d(1.5, 2.0, -4.0, 0.8);
    constexpr double s3{0.5};
    static_assert(v3_d * s3 == s3 * v3_d && s3 * v3_d == Vector4d(0.75, 1.0, -2.0, 0.4));
    {
        Vector4d v{v3_d};
        v *= s3;
        assert(v == Vector4d(0.75, 1.0, -2.0, 0.4));
    }
}

void test_division()
{
    /* --------------- Vector - Vector --------------- */

    // Int
    constexpr Vector4i v1_i(8, -6, 12, 20);
    constexpr Vector4i v2_i(2, 3, 4, 5);
    static_assert(v1_i / v2_i == Vector4i(4, -2, 3, 4));
    {
        Vector4i v{v1_i};
        v /= v2_i;
        assert(v == Vector4i(4, -2, 3, 4));
    }

    // Float
    constexpr Vector4f v1_f(4.5f, -9.0f, 6.0f, 2.0f);
    constexpr Vector4f v2_f(1.5f, 3.0f, 2.0f, 0.5f);
    static_assert(v1_f / v2_f == Vector4f(3.0f, -3.0f, 3.0f, 4.0f));
    {
        Vector4f v{v1_f};
        v /= v2_f;
        assert(v == Vector4f(3.0f, -3.0f, 3.0f, 4.0f));
    }

    // Double
    constexpr Vector4d v1_d(6.0, 2.0, -4.0, 1.0);
    constexpr Vector4d v2_d(3.0, 0.5, 2.0, 0.25);
    static_assert(v1_d / v2_d == Vector4d(2.0, 4.0, -2.0, 4.0));
    {
        Vector4d v{v1_d};
        v /= v2_d;
        assert(v == Vector4d(2.0, 4.0, -2.0, 4.0));
    }

    /* --------------- Vector - Scalar --------------- */

    // Int
    constexpr Vector4i v3_i(12, -4, 8, 16);
    constexpr int s1{4};
    static_assert(v3_i / s1 == Vector4i(3, -1, 2, 4));
    {
        Vector4i v{v3_i};
        v /= s1;
        assert(v == Vector4i(3, -1, 2, 4));
    }

    // Float
    constexpr Vector4f v3_f(2.0f, -5.0f, 1.0f, 3.0f);
    constexpr float s2{0.5f};
    static_assert(v3_f / s2 == Vector4f(4.0f, -10.0f, 2.0f, 6.0f));
    {
        Vector4f v{v3_f};
        v /= s2;
        assert(v == Vector4f(4.0f, -10.0f, 2.0f, 6.0f));
    }

    // Double
    constexpr Vector4d v3_d(3.0, 0.75, -1.0, 2.5);
    constexpr double s3{0.25};
    static_assert(v3_d / s3 == Vector4d(12.0, 3.0, -4.0, 10.0));
    {
        Vector4d v{v3_d};
        v /= s3;
        assert(v == Vector4d(12.0, 3.0, -4.0, 10.0));
    }
}

void test_dot()
{
    // Int
    constexpr Vector4i v1_i(1, 2, 3, 4);
    constexpr Vector4i v2_i(2, -1, 0, 1);
    static_assert(v1_i.dot(v2_i) == 4); // 1*2 + 2*(-1) + 3*0 + 4*1 = 2 - 2 + 0 + 4 = 4

    // Float
    constexpr Vector4f v1_f(1.0f, 0.0f, -1.0f, 2.0f);
    constexpr Vector4f v2_f(2.0f, 3.0f, 1.0f, 0.5f);
    static_assert(v1_f.dot(v2_f) == 2.0f); // 1*2 + 0*3 + (-1)*1 + 2*0.5 = 2 + 0 - 1 + 1 = 2

    // Double
    constexpr Vector4d v1_d(1.5, -2.0, 0.5, 1.0);
    constexpr Vector4d v2_d(2.0, 1.0, -1.0, 3.0);
    static_assert(v1_d.dot(v2_d) == 3.5); // 1.5*2 + (-2)*1 + 0.5*(-1) + 1*3 = 3 - 2 - 0.5 + 3 = 3.5
}

void test_norm()
{
    // Int
    constexpr Vector4i vi(1, 2, 2, 4);
    assert(vi.norm() == vi.length() && vi.length() == 5); // sqrt(1 + 4 + 4 + 16) = sqrt(25) = 5

    // Float
    constexpr Vector4f vf(0.5f, 0.5f, 0.5f, 0.5f);
    assert(vf.norm() == vf.length() && approx_equal(vf.norm(), 1.0)); // sqrt(0.25 * 4) = sqrt(1) = 1

    // Double
    constexpr Vector4d vd(1.0, 1.0, 1.0, 1.0);
    assert(vd.norm() == vd.length() && approx_equal(vd.norm(), 2.0)); // sqrt(4) = 2
}

void test_norm_squared()
{
    // Int
    constexpr Vector4i vi(1, 2, 2, 4);
    assert(vi.norm_squared() == vi.normSquared() && vi.normSquared() == 25);

    // Float
    constexpr Vector4f vf(0.5f, 0.5f, 0.5f, 0.5f);
    assert(vf.norm_squared() == vf.normSquared() && vf.normSquared() == 1.0f);

    // Double
    constexpr Vector4d vd(1.0, 1.0, 1.0, 1.0);
    assert(vd.norm_squared() == vd.normSquared() && vd.normSquared() == 4.0);
}

void test_normalize()
{
    // Int
    constexpr Vector4i vi(10, 0, 0, 0);
    assert(vi.normalize() == Vector4i(1, 0, 0, 0));

    // Float
    constexpr Vector4f vf(0.0f, 0.0f, 0.0f, 0.0f);
    assert(vf.normalize() == Vector4f(0.0f, 0.0f, 0.0f, 0.0f));

    // Double
    constexpr Vector4d vd(2.0, 0.0, 0.0, 0.0);
    assert(vd.normalize() == Vector4d(1.0, 0.0, 0.0, 0.0));
}

void test_sign()
{
    // Int
    constexpr Vector4i vi(10, 0, -5, 3);
    static_assert(vi.sign() == Vector4i(1, 1, -1, 1));

    // Float
    constexpr Vector4f vf(-4.0f, 17.0f, 0.0f, -1.5f);
    static_assert(vf.sign() == Vector4f(-1.0f, 1.0f, 1.0f, -1.0f));

    // Double
    constexpr Vector4d vd(-4.0, -3.0, 2.5, 0.0);
    static_assert(vd.sign() == Vector4d(-1.0, -1.0, 1.0, 1.0));
}

void test_pow()
{
    // Int
    constexpr Vector4i vi(2, 3, 1, 4);
    assert(vi.pow(2) == Vector4i(4, 9, 1, 16));

    // Float
    constexpr Vector4f vf(2.0f, 4.0f, 1.0f, 8.0f);
    assert(approx_equal(vf.pow(0.5f), Vector4f(std::sqrt(2.0f), 2.0f, 1.0f, std::sqrt(8.0f))));

    // Double
    constexpr Vector4d vd(2.0, 3.0, 1.0, 4.0);
    assert(approx_equal(vd.pow(3.0), Vector4d(8.0, 27.0, 1.0, 64.0)));
}

void test_convert()
{
    constexpr Vector4i vi(10, 5, -2, 8);
    constexpr Vector4f vf(1.1234567f, -1.1234567f, 2.5f, -0.75f);
    constexpr Vector4d vd(1.1234567891234567, -1.1234567891234567, 3.5, -1.25);

    // Int -> Float
    static_assert(static_cast<Vector4f>(vi).x == 10.0f && static_cast<Vector4f>(vi).y == 5.0f && 
                  static_cast<Vector4f>(vi).z == -2.0f && static_cast<Vector4f>(vi).w == 8.0f);

    // Int -> Double
    static_assert(static_cast<Vector4d>(vi).x == 10.0 && static_cast<Vector4d>(vi).y == 5.0 && 
                  static_cast<Vector4d>(vi).z == -2.0 && static_cast<Vector4d>(vi).w == 8.0);

    // Float -> Int
    static_assert(static_cast<Vector4i>(vf).x == 1 && static_cast<Vector4i>(vf).y == -1 && 
                  static_cast<Vector4i>(vf).z == 2 && static_cast<Vector4i>(vf).w == 0);

    // Float -> Double
    static_assert(static_cast<Vector4d>(vf).x == 1.1234567165374756 && static_cast<Vector4d>(vf).y == -1.1234567165374756);

    // Double -> Int
    static_assert(static_cast<Vector4i>(vd).x == 1 && static_cast<Vector4i>(vd).y == -1 && 
                  static_cast<Vector4i>(vd).z == 3 && static_cast<Vector4i>(vd).w == -1);

    // Double -> Float
    static_assert(static_cast<Vector4f>(vd).x == 1.1234568f && static_cast<Vector4f>(vd).y == -1.1234568f);
}

void test_stream_output()
{
    Vector4f v(1.124f, 2.0f, -1.45f, 0.0f);
    std::ostringstream oss{};
    oss << v;
    assert(oss.str() == "Vector4(x=1.124, y=2, z=-1.45, w=0)");
}

int main()
{
    test_addition();
    test_substraction();
    test_multiplication();
    test_division();
    test_dot();
    test_norm();
    test_norm_squared();
    test_normalize();
    test_sign();
    test_pow();
    test_convert();
    test_stream_output();
    return 0;
}
