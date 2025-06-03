#include <vector3.hpp>

#include <cassert>
#include <sstream>

[[nodiscard]] bool approx_equal(double a, double b, double e = 1e-10)
{
    return std::fabs(a - b) < e;
}

template <typename T>
[[nodiscard]] bool approx_equal(const Vector3<T> &a, const Vector3<T> &b, double e = 1e-10)
{
    return approx_equal(a.x, b.x, e) && approx_equal(a.y, b.y, e) && approx_equal(a.z, b.z, e);
}

void test_addition()
{
    /* --------------- Vector - Vector --------------- */

    // Int
    constexpr Vector3i v1_i(2, -3, 1);
    constexpr Vector3i v2_i(-4, 1, 5);
    static_assert(v1_i + v2_i == Vector3i(-2, -2, 6));
    {
        Vector3i v{v1_i};
        v += v2_i;
        assert(v == Vector3i(-2, -2, 6));
    }

    // Float
    constexpr Vector3f v1_f(3.14f, -27.2f, 0.5f);
    constexpr Vector3f v2_f(0.01f, 3.0f, -1.5f);
    static_assert(v1_f + v2_f == Vector3f(3.15f, -24.2f, -1.0f));
    {
        Vector3f v{v1_f};
        v += v2_f;
        assert(v == Vector3f(3.15f, -24.2f, -1.0f));
    }

    // Double
    constexpr Vector3d v1_d(6.0, 0.001, 2.5);
    constexpr Vector3d v2_d(0.0, 1.0, -0.5);
    static_assert(v1_d + v2_d == Vector3d(6.0, 1.001, 2.0));
    {
        Vector3d v{v1_d};
        v += v2_d;
        assert(v == Vector3d(6.0, 1.001, 2.0));
    }

    /* --------------- Vector - Scalar --------------- */

    // Int
    constexpr Vector3i v3_i(-2, 8, 3);
    constexpr int s1{12};
    static_assert(v3_i + s1 == Vector3i(10, 20, 15));
    {
        Vector3i v{v3_i};
        v += s1;
        assert(v == Vector3i(10, 20, 15));
    }

    // Float
    constexpr Vector3f v3_f(2.0f, -3.0f, 1.0f);
    constexpr float s2{0.5f};
    static_assert(v3_f + s2 == Vector3f(2.5f, -2.5f, 1.5f));
    {
        Vector3f v{v3_f};
        v += s2;
        assert(v == Vector3f(2.5f, -2.5f, 1.5f));
    }

    // Double
    constexpr Vector3d v3_d(1.25, -2.00001, 0.75);
    constexpr double s3{0.01};
    static_assert(v3_d + s3 == Vector3d(1.26, -1.99001, 0.76));
    {
        Vector3d v{v3_d};
        v += s3;
        assert(v == Vector3d(1.26, -1.99001, 0.76));
    }
}

void test_substraction()
{
    /* --------------- Vector - Vector --------------- */

    // Int
    constexpr Vector3i v1_i(5, -2, 8);
    constexpr Vector3i v2_i(3, 1, 2);
    static_assert(v1_i - v2_i == Vector3i(2, -3, 6));
    {
        Vector3i v{v1_i};
        v -= v2_i;
        assert(v == Vector3i(2, -3, 6));
    }

    // Float
    constexpr Vector3f v1_f(3.5f, -1.0f, 4.5f);
    constexpr Vector3f v2_f(1.5f, -2.5f, 0.5f);
    static_assert(v1_f - v2_f == Vector3f(2.0f, 1.5f, 4.0f));
    {
        Vector3f v{v1_f};
        v -= v2_f;
        assert(v == Vector3f(2.0f, 1.5f, 4.0f));
    }

    // Double
    constexpr Vector3d v1_d(10.5, 4.001, 7.5);
    constexpr Vector3d v2_d(0.5, 0.001, 2.5);
    static_assert(v1_d - v2_d == Vector3d(10.0, 4.0, 5.0));
    {
        Vector3d v{v1_d};
        v -= v2_d;
        assert(v == Vector3d(10.0, 4.0, 5.0));
    }

    /* --------------- Vector - Scalar --------------- */

    // Int
    constexpr Vector3i v3_i(5, -3, 7);
    constexpr int s1{2};
    static_assert(v3_i - s1 == Vector3i(3, -5, 5));
    {
        Vector3i v{v3_i};
        v -= s1;
        assert(v == Vector3i(3, -5, 5));
    }

    // Float
    constexpr Vector3f v3_f(1.0f, 2.0f, 3.0f);
    constexpr float s2{0.5f};
    static_assert(v3_f - s2 == Vector3f(0.5f, 1.5f, 2.5f));
    {
        Vector3f v{v3_f};
        v -= s2;
        assert(v == Vector3f(0.5f, 1.5f, 2.5f));
    }

    // Double
    constexpr Vector3d v3_d(4.25, 1.75, 3.25);
    constexpr double s3{0.25};
    static_assert(v3_d - s3 == Vector3d(4.0, 1.5, 3.0));
    {
        Vector3d v{v3_d};
        v -= s3;
        assert(v == Vector3d(4.0, 1.5, 3.0));
    }
}

void test_multiplication()
{
    /* --------------- Vector - Vector --------------- */

    // Int
    constexpr Vector3i v1_i(2, -3, 4);
    constexpr Vector3i v2_i(4, 5, -2);
    static_assert(v1_i * v2_i == Vector3i(8, -15, -8));

    // Float
    constexpr Vector3f v1_f(1.5f, -2.0f, 3.0f);
    constexpr Vector3f v2_f(2.0f, 3.0f, 0.5f);
    static_assert(v1_f * v2_f == Vector3f(3.0f, -6.0f, 1.5f));

    // Double
    constexpr Vector3d v1_d(1.1, 2.2, 0.5);
    constexpr Vector3d v2_d(2.0, 0.5, 4.0);
    static_assert(v1_d * v2_d == Vector3d(2.2, 1.1, 2.0));

    /* --------------- Vector - Scalar --------------- */

    // Int
    constexpr Vector3i v3_i(3, -2, 5);
    constexpr int s1{4};
    static_assert(v3_i * s1 == s1 * v3_i && s1 * v3_i == Vector3i(12, -8, 20));
    {
        Vector3i v{v3_i};
        v *= s1;
        assert(v == Vector3i(12, -8, 20));
    }

    // Float
    constexpr Vector3f v3_f(1.0f, -1.0f, 2.0f);
    constexpr float s2{2.5f};
    static_assert(v3_f * s2 == s2 * v3_f && s2 * v3_f == Vector3f(2.5f, -2.5f, 5.0f));
    {
        Vector3f v{v3_f};
        v *= s2;
        assert(v == Vector3f(2.5f, -2.5f, 5.0f));
    }

    // Double
    constexpr Vector3d v3_d(1.5, 2.0, 4.0);
    constexpr double s3{0.5};
    static_assert(v3_d * s3 == s3 * v3_d && s3 * v3_d == Vector3d(0.75, 1.0, 2.0));
    {
        Vector3d v{v3_d};
        v *= s3;
        assert(v == Vector3d(0.75, 1.0, 2.0));
    }
}

void test_division()
{
    /* --------------- Vector - Vector --------------- */

    // Int
    constexpr Vector3i v1_i(8, -6, 12);
    constexpr Vector3i v2_i(2, 3, 4);
    static_assert(v1_i / v2_i == Vector3i(4, -2, 3));
    {
        Vector3i v{v1_i};
        v /= v2_i;
        assert(v == Vector3i(4, -2, 3));
    }

    // Float
    constexpr Vector3f v1_f(4.5f, -9.0f, 6.0f);
    constexpr Vector3f v2_f(1.5f, 3.0f, 2.0f);
    static_assert(v1_f / v2_f == Vector3f(3.0f, -3.0f, 3.0f));
    {
        Vector3f v{v1_f};
        v /= v2_f;
        assert(v == Vector3f(3.0f, -3.0f, 3.0f));
    }

    // Double
    constexpr Vector3d v1_d(6.0, 2.0, 8.0);
    constexpr Vector3d v2_d(3.0, 0.5, 4.0);
    static_assert(v1_d / v2_d == Vector3d(2.0, 4.0, 2.0));
    {
        Vector3d v{v1_d};
        v /= v2_d;
        assert(v == Vector3d(2.0, 4.0, 2.0));
    }

    /* --------------- Vector - Scalar --------------- */

    // Int
    constexpr Vector3i v3_i(12, -4, 16);
    constexpr int s1{4};
    static_assert(v3_i / s1 == Vector3i(3, -1, 4));
    {
        Vector3i v{v3_i};
        v /= s1;
        assert(v == Vector3i(3, -1, 4));
    }

    // Float
    constexpr Vector3f v3_f(2.0f, -5.0f, 4.0f);
    constexpr float s2{0.5f};
    static_assert(v3_f / s2 == Vector3f(4.0f, -10.0f, 8.0f));
    {
        Vector3f v{v3_f};
        v /= s2;
        assert(v == Vector3f(4.0f, -10.0f, 8.0f));
    }

    // Double
    constexpr Vector3d v3_d(3.0, 0.75, 1.5);
    constexpr double s3{0.25};
    static_assert(v3_d / s3 == Vector3d(12.0, 3.0, 6.0));
    {
        Vector3d v{v3_d};
        v /= s3;
        assert(v == Vector3d(12.0, 3.0, 6.0));
    }
}

void test_dot()
{
    // Int
    constexpr Vector3i v1_i(1, 2, 3);
    constexpr Vector3i v2_i(4, 5, 6);
    static_assert(v1_i.dot(v2_i) == 32);

    // Float
    constexpr Vector3f v1_f(1.0f, 0.0f, -1.0f);
    constexpr Vector3f v2_f(2.0f, 3.0f, 1.0f);
    static_assert(v1_f.dot(v2_f) == 1.0f);

    // Double
    constexpr Vector3d v1_d(1.5, 2.5, 0.5);
    constexpr Vector3d v2_d(2.0, 1.0, 4.0);
    static_assert(v1_d.dot(v2_d) == 7.5);
}

void test_cross()
{
    // Int
    constexpr Vector3i v1_i(1, 0, 0);
    constexpr Vector3i v2_i(0, 1, 0);
    static_assert(v1_i.cross(v2_i) == Vector3i(0, 0, 1));

    // Float
    constexpr Vector3f v1_f(1.0f, 2.0f, 3.0f);
    constexpr Vector3f v2_f(4.0f, 5.0f, 6.0f);
    static_assert(v1_f.cross(v2_f) == Vector3f(-3.0f, 6.0f, -3.0f));

    // Double
    constexpr Vector3d v1_d(2.0, 1.0, 0.0);
    constexpr Vector3d v2_d(1.0, 2.0, 3.0);
    static_assert(v1_d.cross(v2_d) == Vector3d(3.0, -6.0, 3.0));
}

void test_norm()
{
    // Int
    constexpr Vector3i vi(3, 4, 0);
    assert(vi.norm() == vi.length() && vi.length() == 5);

    // Float
    constexpr Vector3f vf(1.0f, 0.0f, 0.0f);
    assert(vf.norm() == vf.length() && approx_equal(vf.norm(), 1.0));

    // Double
    constexpr Vector3d vd(1.0, 1.0, 1.0);
    assert(vd.norm() == vd.length() && approx_equal(vd.norm(), std::sqrt(3.0)));
}

void test_norm_squared()
{
    // Int
    constexpr Vector3i vi(3, 4, 0);
    assert(vi.norm_squared() == vi.normSquared() && vi.normSquared() == 25);

    // Float
    constexpr Vector3f vf(1.0f, 2.0f, 3.0f);
    assert(vf.norm_squared() == vf.normSquared() && vf.normSquared() == 14.0f);

    // Double
    constexpr Vector3d vd(1.0, 1.0, 1.0);
    assert(vd.norm_squared() == vd.normSquared() && vd.normSquared() == 3.0);
}

void test_normalize()
{
    // Int
    constexpr Vector3i vi(10, 0, 0);
    assert(vi.normalize() == Vector3i(1, 0, 0));

    // Float
    constexpr Vector3f vf(0.0f, 0.0f, 0.0f);
    assert(vf.normalize() == Vector3f(0.0f, 0.0f, 0.0f));

    // Double
    constexpr Vector3d vd(3.0, 4.0, 0.0);
    assert(approx_equal(vd.normalize(), Vector3d(0.6, 0.8, 0.0)));
}

void test_sign()
{
    // Int
    constexpr Vector3i vi(10, 0, -5);
    static_assert(vi.sign() == Vector3i(1, 1, -1));

    // Float
    constexpr Vector3f vf(-4.0f, 17.0f, 0.0f);
    static_assert(vf.sign() == Vector3f(-1.0f, 1.0f, 1.0f));

    // Double
    constexpr Vector3d vd(-4.0, -3.0, 2.0);
    static_assert(vd.sign() == Vector3d(-1.0, -1.0, 1.0));
}

void test_pow()
{
    // Int
    constexpr Vector3i vi(2, 3, 1);
    assert(vi.pow(2) == Vector3i(4, 9, 1));

    // Float
    constexpr Vector3f vf(4.0f, 9.0f, 1.0f);
    assert(approx_equal(vf.pow(0.5f), Vector3f(2.0f, 3.0f, 1.0f)));

    // Double
    constexpr Vector3d vd(2.0, 1.0, 3.0);
    assert(approx_equal(vd.pow(3.0), Vector3d(8.0, 1.0, 27.0)));
}

void test_convert()
{
    constexpr Vector3i vi(10, 5, -3);
    constexpr Vector3f vf(1.1234567f, -1.1234567f, 2.5f);
    constexpr Vector3d vd(1.1234567891234567, -1.1234567891234567, -0.75);

    // Int -> Float
    static_assert(static_cast<Vector3f>(vi).x == 10.0f && static_cast<Vector3f>(vi).y == 5.0f && static_cast<Vector3f>(vi).z == -3.0f);

    // Int -> Double
    static_assert(static_cast<Vector3d>(vi).x == 10.0 && static_cast<Vector3d>(vi).y == 5.0 && static_cast<Vector3d>(vi).z == -3.0);

    // Float -> Int
    static_assert(static_cast<Vector3i>(vf).x == 1 && static_cast<Vector3i>(vf).y == -1 && static_cast<Vector3i>(vf).z == 2);

    // Float -> Double
    static_assert(static_cast<Vector3d>(vf).x == 1.1234567165374756 && static_cast<Vector3d>(vf).y == -1.1234567165374756 && static_cast<Vector3d>(vf).z == 2.5);

    // Double -> Int
    static_assert(static_cast<Vector3i>(vd).x == 1 && static_cast<Vector3i>(vd).y == -1 && static_cast<Vector3i>(vd).z == 0);

    // Double -> Float
    static_assert(static_cast<Vector3f>(vd).x == 1.1234568f && static_cast<Vector3f>(vd).y == -1.1234568f && static_cast<Vector3f>(vd).z == -0.75f);
}

void test_stream_output()
{
    Vector3f v(1.124f, 2.0f, -1.45f);
    std::ostringstream oss{};
    oss << v;
    assert(oss.str() == "Vector3(x=1.124, y=2, z=-1.45)");
}

int main()
{
    test_addition();
    test_substraction();
    test_multiplication();
    test_division();
    test_dot();
    test_cross();
    test_norm();
    test_norm_squared();
    test_normalize();
    test_sign();
    test_pow();
    test_convert();
    test_stream_output();
    return 0;
}