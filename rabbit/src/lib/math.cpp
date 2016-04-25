//
// Created by Yuki miyatake on 2016/02/06.
//

#include "./math.h"

#include <cmath>

#include<cfloat>
//#include<memory.h>

namespace rabbit{

    const float fPI = float(4.0 * std::atan(1.0));
/*	--------------------------------
 *				vec2
 *	--------------------------------
*/
    // construct
    vec2::vec2()
    {
        x_ = y_ = 0.0f;
    }

    vec2::vec2(float x, float y)
    {
        this->x_ = x;
        this->y_ = y;
    }

    vec2::vec2(const std::array<float,2>& f){
        f_ = f;
    }


    // assign
    vec2 &vec2::set(float x, float y)
    {
        this->x_ = x;
        this->y_ = y;

        return(*this);
    }


    vec2& vec2::init(){
        x_ = y_ = 0.0f;
        return *this;
    }

    float vec2::length() const
    {
        return std::sqrt(x_ * x_ + y_ * y_);
    }

    vec2 &vec2::normalize()
    {
        float len = length();
        //return(set(x_ / len, y_ / len));
        return( *this /= len );
    }

    vec2& vec2::operator+=(const vec2 &other){
        x_ += other.x_;
        y_ += other.y_;
        return *this;
    }

    vec2& vec2::operator-=(const vec2 &other){
        x_ -= other.x_;
        y_ -= other.y_;
        return *this;
    }

    vec2& vec2::operator*=(float f){
        x_ *= f;
        y_ *= f;
        return *this;
    }

    vec2& vec2::operator/=(float f){
        return *this *= (1.0f/f) ;
    }

    vec2 vec2::operator+() const{
        return vec2(*this);
    }

    vec2 vec2::operator-() const{
        return  (*this) * -1.0f;
    }



    vec2 vec2::operator+(const vec2 & other) const
    {
        return vec2(x_ + other.x_, y_ + other.y_);
    }

    vec2 vec2::operator-(const vec2 & other) const
    {
        return vec2(x_ - other.x_, y_ - other.y_);
    }

    vec2 vec2::operator* (float f) const{
        return vec2( x_*f, y_*f );
    }

    vec2 vec2::operator/ (float f) const{
        float ff = 1.0f / f;
        return vec2( x_*ff, y_*ff );
    }


    vec2& operator+=( vec2 &me, float f){
        me.x_ += f;
        me.y_ += f;
        return me;
    }
    /*
    vec2& operator+=( vec2 &me, const vec2 &other){
        me.x_ += other.x_;
        me.y_ += other.y_;
        return me;
    }
     */
    vec2& operator-=( vec2 &me, float f){
        me.x_ -= f;
        me.y_ -= f;
        return me;
    }


/*	--------------------------------
 *				Vec3
 *	--------------------------------
 */
    //コンストラクタ
    Vec3::Vec3(){ x = y = z = 0.0f; }
    Vec3::Vec3(float x,float y,float z){
        this->x=x;		this->y=y;		this->z=z;
    }

    Vec3::Vec3( Vec4 vec )
    {
        this->x = vec.x; this->y=vec.y; this->z=vec.z;
    }

    //代入演算子
    Vec3& Vec3::operator=(const Vec3& v){
        this->x=v.x;	this->y=v.y;	this->z=v.z;
        return *this;
    }
    //単項演算子
    Vec3 Vec3::operator+=(const Vec3& v){
        this->x += v.x;	this->y += v.y;		this->z += v.z;
        return *this;
    }
    Vec3 Vec3::operator-=(const Vec3& v){
        this->x -= v.x;	this->y -= v.y;		this->z -= v.z;
        return *this;
    }
    Vec3 Vec3::operator*=(float k){
        this->x *= k;		this->y *= k;		this->z *= k;
        return *this;
    }
    Vec3 Vec3::operator/=(float k){
        this->x /= k;		this->y /= k;		this->z /= k;
        return *this;
    }
    Vec3 Vec3::operator+()const{		//+Vec3
        return *this;
    }
    Vec3 Vec3::operator-()const{		//-Vec3
        return Vec3(-x,-y,-z);
    }
    //添え字演算子
    float& Vec3::operator[](int i){
        if(i == 0){
            return x;
        }
        else if(i == 1){
            return y;
        }
        else if(i == 2){
            return z;
        }
        else{
            return x;
        }
    }
    //比較演算子
    bool Vec3::operator==(const Vec3& v ) const{
        return (x == v.x) && (y == v.y) && (z == v.z);
    }
    bool Vec3::operator!=(const Vec3& v ) const{
        return !(*this == v);
    }
    //べクトルの長さ
    float Vec3::Length()const{
        return std::pow(x*x+y*y+z*z,0.5f);
    }
    //正規化
    Vec3 Vec3::Normalize() const{
        return *this / Length();
    }
    void Vec3::Set(float x,float y,float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    // global
    //Vec3+Vec3
    Vec3 operator+(const Vec3& u,const Vec3& v){
        Vec3 w;
        w.x=u.x+v.x;
        w.y=u.y+v.y;
        w.z=u.z+v.z;
        return w;
    }
    //Vec3-Vec3
    Vec3 operator-(const Vec3& u,const Vec3& v){
        Vec3 w;
        w.x=u.x-v.x;
        w.y=u.y-v.y;
        w.z=u.z-v.z;
        return w;
    }
    //float*Vec3
    Vec3 operator*(float k,const  Vec3& v){
        return Vec3(k*v.x,k*v.y,k*v.z);
    }
    //Vec3*float
    Vec3 operator*(const Vec3& v,float k){
        return Vec3(v.x*k,v.y*k,v.z*k);
    }
    //Vec3/float
    Vec3 operator/(const Vec3& v,float k){
        return Vec3(v.x/k,v.y/k,v.z/k);
    }
    //内積 Vec3*Vec3
    float dot(const Vec3& u,const Vec3& v){
        return u.x*v.x + u.y*v.y + u.z*v.z;
    }
    //外積 Vec3%Vec3
    Vec3 cross(const Vec3& u,const Vec3& v){
        Vec3 w;
        w.x=u.y*v.z-u.z*v.y;
        w.y=u.z*v.x-u.x*v.z;
        w.z=u.x*v.y-u.y*v.x;
        return w;
    }

    //2つのベクトルのなす角
    float angleTo(const Vec3& u,const Vec3& v){
        float cos = dot(u, v)/(u.Length()*v.Length());
        return float(acos(cos));
    }

    float distanceTo(const Vec3 &p1, const Vec3 &p2)
    {
        return (p2 - p1).Length();
    }

    Vec3 dirTo(const Vec3 &p1, const Vec3 &p2)
    {
        return (p2 - p1).Normalize();
    }

    Vec3 lerp(const Vec3 &vec1, const Vec3 &vec2, float t)
    {
        return vec1 + (vec2 - vec1) * t;
    }


    Vec3 operator *(const Vec3& vec, const Matrix &mat )
    {
        Vec3 out;
#if 1
        out.x = mat.m[0] * vec.x + mat.m[4] * vec.y + mat.m[8] * vec.z + mat.m[12] * 1.0f;
        out.y = mat.m[1] * vec.x + mat.m[5] * vec.y + mat.m[9] * vec.z + mat.m[13] * 1.0f;
        out.z = mat.m[2] * vec.x + mat.m[6] * vec.y + mat.m[10] * vec.z + mat.m[14] * 1.0f;
#else
		out.x = m[0] * vec.x + m[1] * vec.y + m[2] * vec.z + m[3] * 1.0f;
		out.y = m[4] * vec.x + m[5] * vec.y + m[6] * vec.z + m[7] * 1.0f;
		out.z = m[8] * vec.x + m[9] * vec.y + m[10] * vec.z + m[11] * 1.0f;
#endif
        return out;
    }






/*	--------------------------------
 *				Vec4
 *	--------------------------------
 */
    //コンストラクタ
    Vec4::Vec4(){ x = y = z = 0.0f; }
    Vec4::Vec4( float x,float y,float z, float w ){
        this->x=x;		this->y=y;		this->z=z;
    }

    //代入演算子
    Vec4& Vec4::operator=(const Vec4& v){
        this->x=v.x;	this->y=v.y;	this->z=v.z; this->w=v.w;
        return *this;
    }
    //単項演算子
    Vec4 Vec4::operator+=(const Vec4& v){
        this->x += v.x;	this->y += v.y;		this->z += v.z; this->w=v.w;
        return *this;
    }
    Vec4 Vec4::operator-=(const Vec4& v){
        this->x -= v.x;	this->y -= v.y;		this->z -= v.z; this->w=v.w;
        return *this;
    }
    Vec4 Vec4::operator*=(float k){
        this->x *= k;		this->y *= k;		this->z *= k;  this->w *=k;
        return *this;
    }
    Vec4 Vec4::operator/=(float k){
        this->x /= k;		this->y /= k;		this->z /= k; this->w /= k;
        return *this;
    }
    Vec4 Vec4::operator+()const{		//+Vec4
        return *this;
    }
    Vec4 Vec4::operator-()const{		//-Vec4
        return Vec4(-x,-y,-z,-w);
    }
    //添え字演算子
    float& Vec4::operator[](int i){
        if(i == 0){
            return x;
        }
        else if(i == 1){
            return y;
        }
        else if(i == 2){
            return z;
        }
        else if(i == 3){
            return w;
        }
        else{
            return x;
        }
    }
    //比較演算子
    bool Vec4::operator==(const Vec4& v ) const{
        return (x == v.x) && (y == v.y) && (z == v.z) && (w == v.w);
    }
    bool Vec4::operator!=(const Vec4& v ) const{
        return !(*this == v);
    }
    //べクトルの長さ
    float Vec4::Length()const{
        return std::pow( x*x+y*y+z*z+w*w, 0.5f );
    }
    //正規化
    Vec4 Vec4::Normalize() const{
        return *this / Length();
    }
    void Vec4::Set(float x,float y,float z, float w ){
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    // global
    //Vec4+Vec4
    Vec4 operator+(const Vec4& u,const Vec4& v){
        Vec4 w;
        w.x = u.x+v.x;
        w.y = u.y+v.y;
        w.z = u.z+v.z;
        w.w = u.w+v.w;
        return w;
    }
    //Vec4-Vec4
    Vec4 operator-(const Vec4& u,const Vec4& v){
        Vec4 w;
        w.x = u.x-v.x;
        w.y = u.y-v.y;
        w.z = u.z-v.z;
        w.w = u.w-v.w;
        return w;
    }
    //float*Vec4
    Vec4 operator*(float k,const  Vec4& v){
        return Vec4( k*v.x, k*v.y, k*v.z, k*v.w  );
    }
    //Vec4*float
    Vec4 operator*(const Vec4& v,float k){
        return Vec4( v.x*k, v.y*k, v.z*k, v.w*k );
    }
    //Vec4/float
    Vec4 operator/(const Vec4& v,float k){
        return Vec4( v.x/k, v.y/k, v.z/k, v.w/k );
    }
    //内積 Vec4*Vec4
    float dot(const Vec4& u,const Vec4& v){
        return( u.x*v.x + u.y*v.y + u.z*v.z + u.w*v.w );
    }
    //外積 Vec4%Vec4
    // Crossとりあえずなし

    //2つのベクトルのなす角
    float angleTo(const Vec4& u,const Vec4& v){
        float cos = dot(u, v)/(u.Length()*v.Length());
        return float(acos(cos));
    }

    float distanceTo(const Vec4 &p1, const Vec4 &p2)
    {
        return (p2 - p1).Length();
    }

    Vec4 dirTo(const Vec4 &p1, const Vec4 &p2)
    {
        return (p2 - p1).Normalize();
    }

    Vec4 lerp(const Vec4 &vec1, const Vec4 &vec2, float t)
    {
        return vec1 + (vec2 - vec1) * t;
    }


    Vec4 operator *(const Vec4& vec, const Matrix &mat )
    {
        Vec4 out;
#if 1
        out.x = mat.m[0] * vec.x + mat.m[4] * vec.y + mat.m[8] * vec.z + mat.m[12] * vec.w;
        out.y = mat.m[1] * vec.x + mat.m[5] * vec.y + mat.m[9] * vec.z + mat.m[13] * vec.w;
        out.z = mat.m[2] * vec.x + mat.m[6] * vec.y + mat.m[10] * vec.z + mat.m[14] * vec.w;
        out.w = mat.m[3] * vec.x + mat.m[7] * vec.y + mat.m[11] * vec.z + mat.m[15] * vec.w;
#else
		out.x = m[0] * vec.x + m[1] * vec.y + m[2] * vec.z + m[3] * 1.0f;
		out.y = m[4] * vec.x + m[5] * vec.y + m[6] * vec.z + m[7] * 1.0f;
		out.z = m[8] * vec.x + m[9] * vec.y + m[10] * vec.z + m[11] * 1.0f;
#endif
        return out;
    }


/*	--------------------------------
 *				Matrix
 *	--------------------------------
 */
    void Matrix::Identity()
    {
        for(int i=0; i<16; i++)
        {
            m[i] = 0.0f;
        }
        m[0+4*0] = 1.0f;
        m[1+4*1] = 1.0f;
        m[2+4*2] = 1.0f;
        m[3+4*3] = 1.0f;
    }

    void Matrix::Set(
            float _11, float _12, float _13, float _14,
            float _21, float _22, float _23, float _24,
            float _31, float _32, float _33, float _34,
            float _41, float _42, float _43, float _44
    )
    {
        m[0] = _11;
        m[1] = _12;
        m[2] = _13;
        m[3] = _14;
        m[4] = _21;
        m[5] = _22;
        m[6] = _23;
        m[7] = _24;
        m[8] = _31;
        m[9] = _32;
        m[10] = _33;
        m[11] = _34;
        m[12] = _41;
        m[13] = _42;
        m[14] = _43;
        m[15] = _44;
    }

    float Matrix::Get(int line, int col) const
    {
        return m[line * 4 + col];
    }

    void Matrix::MakeTranslation(float x_trans, float y_trans, float z_trans)
    {
        m[0*4 + 0] = 1.0f;     m[0*4 + 1] = 0.0f;     m[0*4 + 2] = 0.0f;     m[0*4 + 3] = 0.0f;
        m[1*4 + 0] = 0.0f;     m[1*4 + 1] = 1.0f;     m[1*4 + 2] = 0.0f;     m[1*4 + 3] = 0.0f;
        m[2*4 + 0] = 0.0f;     m[2*4 + 1] = 0.0f;     m[2*4 + 2] = 1.0f;     m[2*4 + 3] = 0.0f;
        m[3*4 + 0] = x_trans;  m[3*4 + 1] = y_trans;  m[3*4 + 2] = z_trans;  m[3*4 + 3] = 1.0f;
    }

    void Matrix::MakeTranslation(const Vec3 &vec)
    {
        MakeTranslation(vec.x, vec.y, vec.z);
    }

    void Matrix::MakeScaling(float x_scale, float y_scale, float z_scale)
    {
        m[0*4 + 0] = x_scale;  m[0*4 + 1] = 0.0f;     m[0*4 + 2] = 0.0f;     m[0*4 + 3] = 0.0f;
        m[1*4 + 0] = 0.0f;     m[1*4 + 1] = y_scale;  m[1*4 + 2] = 0.0f;     m[1*4 + 3] = 0.0f;
        m[2*4 + 0] = 0.0f;     m[2*4 + 1] = 0.0f;     m[2*4 + 2] = z_scale;  m[2*4 + 3] = 0.0f;
        m[3*4 + 0] = 0.0f;     m[3*4 + 1] = 0.0f;     m[3*4 + 2] = 0.0f;     m[3*4 + 3] = 1.0f;
    }

    void Matrix::MakeRotationX(float x_angle)
    {
        float s = std::sin(x_angle);
        float c = std::cos(x_angle);

        m[0*4 + 0] = c;        m[0*4 + 1] = 0.0f;	m[0*4 + 2] = s;       m[0*4 + 3] = 0.0f;
        m[1*4 + 0] = 0.0f;     m[1*4 + 1] = 1.0f;     m[1*4 + 2] = 0.0f;     m[1*4 + 3] = 0.0f;
        m[2*4 + 0] = -s;        m[2*4 + 1] = 0.0f;     m[2*4 + 2] = c;        m[2*4 + 3] = 0.0f;
        m[3*4 + 0] = 0.0f;     m[3*4 + 1] = 0.0f;     m[3*4 + 2] = 0.0f;     m[3*4 + 3] = 1.0f;
    }

    void Matrix::MakeRotationY(float y_angle)
    {
        float s = std::sin(y_angle);
        float c = std::cos(y_angle);

        m[0*4 + 0] = c;        m[0*4 + 1] = 0.0f;	m[0*4 + 2] = -s;       m[0*4 + 3] = 0.0f;
        m[1*4 + 0] = 0.0f;     m[1*4 + 1] = 1.0f;     m[1*4 + 2] = 0.0f;     m[1*4 + 3] = 0.0f;
        m[2*4 + 0] = s;        m[2*4 + 1] = 0.0f;     m[2*4 + 2] = c;        m[2*4 + 3] = 0.0f;
        m[3*4 + 0] = 0.0f;     m[3*4 + 1] = 0.0f;     m[3*4 + 2] = 0.0f;     m[3*4 + 3] = 1.0f;
    }

    void Matrix::MakeRotationZ(float z_angle)
    {
        float s = std::sin(z_angle);
        float c = std::cos(z_angle);

        m[0*4 + 0] = c;        m[0*4 + 1] = s;        m[0*4 + 2] = 0.0f;     m[0*4 + 3] = 0.0f;
        m[1*4 + 0] = -s;       m[1*4 + 1] = c;        m[1*4 + 2] = 0.0f;     m[1*4 + 3] = 0.0f;
        m[2*4 + 0] = 0.0f;     m[2*4 + 1] = 0.0f;     m[2*4 + 2] = 1.0f;     m[2*4 + 3] = 0.0f;
        m[3*4 + 0] = 0.0f;     m[3*4 + 1] = 0.0f;     m[3*4 + 2] = 0.0f;     m[3*4 + 3] = 1.0f;
    }

    void Matrix::MakeOrthogonalProjection(
            float left, float right,
            float bottom, float top,
            float near, float far
    )
    {
        float dx = right - left;
        float dy = top - bottom;
        float dz = far - near;

        m[ 0] =  2.0f / dx;
        m[ 5] =  2.0f / dy;
        m[10] = -2.0f / dz;
        m[12] = -(right + left) / dx;
        m[13] = -(top + bottom) / dy;
        m[14] = -(far + near) / dz;
        m[15] =  1.0f;
        m[ 1] = m[ 2] = m[ 3] = m[ 4] =
        m[ 6] = m[ 7] = m[ 8] = m[ 9] = m[11] = 0.0f;
    }

    void Matrix::MakePerspectiveProjection(
            float fovY, float aspect,
            float near, float far
    )
    {
        GLfloat xmin, xmax, ymin, ymax;

        ymax = near * std::tan(fovY);
        ymin = -ymax;
        xmin = ymin * aspect;
        xmax = ymax * aspect;

        MakePerspectiveProjection( xmin, xmax, ymax, ymin, near, far );
    }

    void Matrix::MakeViewPort( float _fx, float _fy, float _fw, float _fh )
    {
        float  fw = _fw * 0.5f;
        float  fh = _fh * 0.5f;

        this->Identity();
        this->m[0] = fw;
        this->m[5] = -fh;
        this->m[12] = fw + _fx;
        this->m[13] = fh + _fy;
    }

    void Matrix::MakePerspectiveProjection(
            float left, float right,
//		float right, float left,
//		float top, float bottom,
            float bottom, float top,
            float near, float far
    )
    {
        float dx = right - left;
        float dy = top - bottom;
        float dz = far - near;

#if 1
//	  m[ 0] =  2.0f * near / dx;
//	  m[ 5] =  2.0f * near / dy;
//	  m[ 8] =  (right + left) / dx;
//	  m[ 9] =  (top + bottom) / dy;
//	  m[10] = (far + near) / dz;
//	  m[11] = 1.0f;
//	  m[14] = -far * near / dz;
//	  m[ 1] = m[ 2] = m[ 3] = m[ 4] =
//	  m[ 6] = m[ 7] = m[12] = m[13] = m[15] = 0.0f;

        m[ 0] =  2.0f * near / dx;
        m[ 5] =  2.0f * near / dy;
        m[ 8] =  (right + left) / dx;
        m[ 9] =  (top + bottom) / dy;
        m[10] = -(far + near) / dz;
        m[11] = -1.0f;
        m[14] = -2.0f * far * near / dz;
        m[ 1] = m[ 2] = m[ 3] = m[ 4] =
        m[ 6] = m[ 7] = m[12] = m[13] = m[15] = 0.0f;

#else
	  m[ 0] =  2.0f * near / dx;
	  m[ 5] =  2.0f * near / dy;
	  m[ 2] =  (right + left) / dx;
	  m[ 6] =  (top + bottom) / dy;
	  m[10] = -(far + near) / dz;
	  m[14] = -1.0f;
	  m[11] = -2.0f * far * near / dz;
	  m[ 1] = m[ 8] = m[ 3] = m[ 4] =
	  m[ 9] = m[ 7] = m[12] = m[13] = m[15] = 0.0f;
#endif
//	  this->Transpose();

    }

    void Matrix::LookAt(
            const Vec3 &eye,
            const Vec3 &lookAt,
            const Vec3 &up
    )
    {
        float l;

        /*
        ** 下の l は 0 になることがあるから,
        ** 必要ならエラー処理を追加して.
        */

        /* z 軸 = e - t */
        float tx = eye.x - lookAt.x;
        float ty = eye.y - lookAt.y;
        float tz = eye.z - lookAt.z;
        l = sqrtf(tx * tx + ty * ty + tz * tz); /* この l と, */
        if(l <= 0.0001f){
            return;
        }
        m[ 2] = tx / l;
        m[ 6] = ty / l;
        m[10] = tz / l;

        /* x 軸 = u x z 軸 */
        tx = up.y * m[10] - up.z * m[ 6];
        ty = up.z * m[ 2] - up.x * m[10];
        tz = up.x * m[ 6] - up.y * m[ 2];
        l = sqrtf(tx * tx + ty * ty + tz * tz); /* この l. */
        if(l <= 0.0001f){
            return;
        }
        m[ 0] = tx / l;
        m[ 4] = ty / l;
        m[ 8] = tz / l;

        /* y 軸 = z 軸 x x 軸 */
        m[ 1] = m[ 6] * m[ 8] - m[10] * m[ 4];
        m[ 5] = m[10] * m[ 0] - m[ 2] * m[ 8];
        m[ 9] = m[ 2] * m[ 4] - m[ 6] * m[ 0];

        /* 平行移動 */
        m[12] = -(eye.x * m[ 0] + eye.y * m[ 4] + eye.z * m[ 8]);
        m[13] = -(eye.x * m[ 1] + eye.y * m[ 5] + eye.z * m[ 9]);
        m[14] = -(eye.x * m[ 2] + eye.y * m[ 6] + eye.z * m[10]);

        /* 残り */
        m[ 3] = m[ 7] = m[11] = 0.0f;
        m[15] = 1.0f;

//	  this->Transpose();

    }

    Vec3 Matrix::GetTranslation() const
    {
        return Vec3(m[3 * 4 + 0], m[3 * 4 + 1], m[3 * 4 + 2]);
    }

    void Matrix::GetPosAxis(
            Vec3 *p_pos,
            Vec3 *p_xaxis,
            Vec3 *p_yaxis,
            Vec3 *p_zaxis
    )
    {
        if( p_xaxis != NULL ){
            p_xaxis->x = m[0];
            p_xaxis->y = m[1];
            p_xaxis->z = m[2];
        }
        if( p_yaxis != NULL ){
            p_yaxis->x = m[4];
            p_yaxis->y = m[5];
            p_yaxis->z = m[6];
        }
        if( p_zaxis != NULL ){
            p_zaxis->x = m[8];
            p_zaxis->y = m[9];
            p_zaxis->z = m[10];
        }
        if( p_pos != NULL ){
            p_pos->x = m[12];
            p_pos->y = m[13];
            p_pos->z = m[14];
        }
    }
//#define _FSWAP(x,y)  {float _f=(y); (y)=(x); (x)=_f; }
    void Matrix::Transpose()
    {
        std::swap( m[1],m[4]);
        std::swap( m[2],m[8]);
        std::swap( m[3],m[12]);
        std::swap( m[6],m[9]);
        std::swap( m[7],m[13]);
        std::swap( m[11],m[14]);
    }

    void Matrix::FromYawPitchRoll(float yaw, float pitch, float roll)
    {
        Matrix zRotMat;
        Matrix xRotMat;
        Matrix yRotMat;
        zRotMat.MakeRotationZ(roll);
        xRotMat.MakeRotationX(pitch);
        yRotMat.MakeRotationY(yaw);
        *this = zRotMat * xRotMat * yRotMat;
    }

    void Matrix::Inverse()
    {
/*
		m[1] = m[4];
		m[2] = m[8];
		m[6] = m[9];
		m[3] = m[12];
		m[7] = m[13];
		m[11] = m[14];
*/
        Matrix inv;

        double buf; //一時的なデータを蓄える
        int i,j,k; //カウンタ
        int n=4;  //配列の次数
        //単位行列を作る
        // TODO: constant
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                inv.m[i*4+j]=(i==j)?1.0f:0.0f;
            }
        }
        //掃き出し法
        for(i=0;i<n;i++){
            buf=1/ m[i*4+i];
            for(j=0;j<n;j++){
                m[i*4+j]*=buf;
                inv.m[i*4+j]*=buf;
            }
            for(j=0;j<n;j++){
                if(i!=j){
                    buf=m[j*4+i];
                    for(k=0;k<n;k++){
                        m[j*4+k]-=m[i*4+k]*buf;
                        inv.m[j*4+k]-=inv.m[i*4+k]*buf;
                    }
                }
            }
        }

        *this = inv;
    }

    Matrix Matrix::operator *(const Matrix &other) const
    {
        Matrix out;
        for(int i=0; i<16; i++)
        {
            float sum = 0.0f;
            for(int j=0; j<4; j++)
            {
                //sum += m[i%4*4 + j] * other.m[j*4 + i>>2];
                sum += m[i / 4 * 4 + j] * other.m[j * 4 + i % 4];
            }
            out.m[i] = sum;
        }
        return out;
    }


    Vec3 Matrix::operator *(const Vec3 &vec )
    {
        Vec3 out;
#if 0
		out.x = m[0] * vec.x + m[4] * vec.y + m[8] * vec.z + m[12] * 1.0f;
		out.y = m[1] * vec.x + m[5] * vec.y + m[9] * vec.z + m[13] * 1.0f;
		out.z = m[2] * vec.x + m[6] * vec.y + m[10] * vec.z + m[14] * 1.0f;
#else
        out.x = m[0] * vec.x + m[1] * vec.y + m[2] * vec.z + m[3] * 1.0f;
        out.y = m[4] * vec.x + m[5] * vec.y + m[6] * vec.z + m[7] * 1.0f;
        out.z = m[8] * vec.x + m[9] * vec.y + m[10] * vec.z + m[11] * 1.0f;
#endif
        return out;
    }

    bool Matrix::operator==(const Matrix& other ) const
    {
        return( *this == other );
//        return( memcmp( this, &other, sizeof(m))   == 0);
    }

    bool Matrix::operator!=(const Matrix& other ) const
    {
        return( !(*this==other) );
    }


/*	--------------------------------
 *				Quaternion
 *	--------------------------------
 */

    Quaternion::Quaternion()
    {
        W = 1.0;
        X = 0.0;
        Y = 0.0;
        Z = 0.0;
    }

    Quaternion::Quaternion(const float w, const float x, const float y, const float z)
    {
        W = w;
        X = x;
        Y = y;
        Z = z;
    }

    Quaternion operator * (const Quaternion &a, const Quaternion &b)
    {
        float w,x,y,z;

        w = a.W*b.W - (a.X*b.X + a.Y*b.Y + a.Z*b.Z);

        x = a.W*b.X + b.W*a.X + a.Y*b.Z - a.Z*b.Y;
        y = a.W*b.Y + b.W*a.Y + a.Z*b.X - a.X*b.Z;
        z = a.W*b.Z + b.W*a.Z + a.X*b.Y - a.Y*b.X;

        return Quaternion(w,x,y,z);
    }

    const Quaternion& Quaternion::operator *= (const Quaternion &q)
    {
        float w = W*q.W - (X*q.X + Y*q.Y + Z*q.Z);

        float x = W*q.X + q.W*X + Y*q.Z - Z*q.Y;
        float y = W*q.Y + q.W*Y + Z*q.X - X*q.Z;
        float z = W*q.Z + q.W*Z + X*q.Y - Y*q.X;

        W = w;
        X = x;
        Y = y;
        Z = z;
        return *this;
    }

    const Quaternion& Quaternion::operator ~ ()
    {
        X = -X;
        Y = -Y;
        Z = -Z;
        return *this;
    }

    const Quaternion& Quaternion::operator - ()
    {
        float norme = std::sqrt(W*W + X*X + Y*Y + Z*Z);
        if (norme == 0.0f)
            norme = 1.0f;

        float recip = 1.0f / norme;

        W =  W * recip;
        X = -X * recip;
        Y = -Y * recip;
        Z = -Z * recip;

        return *this;
    }

    const Quaternion& Quaternion::Normalize()
    {
        float norme = std::sqrt(W*W + X*X + Y*Y + Z*Z);
        if (norme == 0.0)
        {
            W = 1.0;
            X = Y = Z = 0.0;
        }
        else
        {
            float recip = 1.0f/norme;

            W *= recip;
            X *= recip;
            Y *= recip;
            Z *= recip;
        }
        return *this;
    }

    const Quaternion& Quaternion::FromAxis(const float Angle, float x, float y, float z)
    {
        float omega, s, c;
        int i;

        s = std::sqrt(x*x + y*y + z*z);

        if (std::fabsf(s) > FLT_EPSILON)
        {
            c = 1.0f/s;

            x *= c;
            y *= c;
            z *= c;

            omega = -0.5f * Angle;
            s = std::sin(omega);

            X = s*x;
            Y = s*y;
            Z = s*z;
            W = (float)cos(omega);
        }
        else
        {
            X = Y = 0.0f;
            Z = 0.0f;
            W = 1.0f;
        }
        Normalize();
        return *this;
    }

    const Quaternion& Quaternion::FromMatrix(const Matrix &matrix)
    {
        W = std::sqrt(1.0f + matrix.m[0] + matrix.m[1 * 4 + 1] + matrix.m[2 * 4 + 2]);
        float w4 = 4.0f * W;
        X = (matrix.m[2 * 4 + 1] - matrix.m[1 * 4 + 2]) / w4;
        Y = (matrix.m[0 * 4 + 2] - matrix.m[2 * 4 + 0]) / w4;
        Z = (matrix.m[1 * 4 + 0] - matrix.m[0 * 4 + 1]) / w4;
        return *this;
    }

    void Quaternion::ToMatrix(Matrix *out) const
    {
        out->Identity();

        out->m[0] = 1.0f - 2.0f*Y*Y - 2.0f*Z*Z;
        out->m[0] = 2.0f*X*Y + 2.0f*W*Z;
        out->m[0] = 2.0f*X*Z - 2.0f*W*Y;

        out->m[4] = 2.0f*X*Y - 2.0f*W*Z;
        out->m[5] = 1.0f - 2.0f*X*X - 2.0f*Z*Z;
        out->m[6] = 2.0f*Y*Z + 2.0f*W*X;

        out->m[8] = 2.0f*X*Z + 2.0f*W*Y;
        out->m[9] = 2.0f*Y*Z - 2.0f*W*X;
        out->m[10] = 1.0f - 2.0f*X*X - 2.0f*Y*Y;
    }

    const Quaternion& Quaternion::FromYawPitchRoll(float yaw, float pitch, float roll)
    {
        //回転軸ごとにクォータニオンを作成し、ZYX軸の順にクォータニオンを乗算する
        Quaternion zQuat;
        FromAxis(roll, 0.0f, 0.0f, 1.0f);
        Quaternion xQuat;
        FromAxis(pitch, 1.0f, 0.0f, 0.0f);
        Quaternion yQuat;
        FromAxis(yaw, 0.0f, 1.0f, 0.0f);
        X = Y = Z = W = 0.0f;
        *this *= zQuat;
        *this *= xQuat;
        *this *= yQuat;
        return *this;
    }

    void Quaternion::Slerp(const Quaternion &a,const Quaternion &b, const float t)
    {
        float omega, cosom, sinom, sclp, sclq;
        int i;


        cosom = a.X*b.X + a.Y*b.Y + a.Z*b.Z + a.W*b.W;


        if ((1.0f+cosom) > FLT_EPSILON)
        {
            if ((1.0f-cosom) > FLT_EPSILON)
            {
                omega = std::acos(cosom);
                sinom = std::sin(omega);
                sclp = std::sin((1.0f-t)*omega) / sinom;
                sclq = std::sin(t*omega) / sinom;
            }
            else
            {
                sclp = 1.0f - t;
                sclq = t;
            }

            X = sclp*a.X + sclq*b.X;
            Y = sclp*a.Y + sclq*b.Y;
            Z = sclp*a.Z + sclq*b.Z;
            W = sclp*a.W + sclq*b.W;

        }
        else
        {
            X =-a.Y;
            Y = a.X;
            Z =-a.W;
            W = a.Z;

            sclp = std::sin((1.0f-t) * fPI * 0.5f);
            sclq = std::sin(t * fPI * 0.5f);

            X = sclp*a.X + sclq*b.X;
            Y = sclp*a.Y + sclq*b.Y;
            Z = sclp*a.Z + sclq*b.Z;

        }
    }

    const Quaternion& Quaternion::exp()
    {
        float Mul;
        float Length = std::sqrt(X*X + Y*Y + Z*Z);

        if (Length > 1.0e-4)
            Mul = std::sin(Length)/Length;
        else
            Mul = 1.0;

        W = std::cos(Length);

        X *= Mul;
        Y *= Mul;
        Z *= Mul;

        return *this;
    }

    const Quaternion& Quaternion::log()
    {
        float Length;

        Length = std::sqrt(X*X + Y*Y + Z*Z);
        Length = std::atan(Length/W);

        W = 0.0;

        X *= Length;
        Y *= Length;
        Z *= Length;

        return *this;
    }














    // スクリーン座標→3D座標
    // vecPlane: vecNormal   判定面上の1点とNormal
    // fScrX fScrY： スクリーン座標 XY
    // pMatInv: 逆行列(World * View * Projection * ViewPort の逆行列)
    Vec3 Screen2World( float fScrX, float fScrY, Vec3 *pvecPlane, Vec3 *pvecNormal,  const Matrix *pMatInv )
    {
        Vec4	vec3Dnear, vec3Dfar;
        Vec4	vec2D;
        Vec3	vec3D;


        // Zのnear far時の3D座標もとめる
        vec2D.x = fScrX; vec2D.y = fScrY; vec2D.z = 1.0f; vec2D.w = 1.0f;

        vec3Dfar = vec2D * (*pMatInv);
        vec3Dfar /= vec3Dfar.w;

        vec2D.z = 0.0f;
        vec3Dnear = vec2D * (*pMatInv);
        vec3Dnear /= vec3Dnear.w;



        // ray!!   Far～Near の線分。この線分の間に床との交点があるので内分点を探す
        Vec3 ray = Vec3( vec3Dfar - vec3Dnear );
        ray.Normalize();

        if( ray.y <= 0 ) {
            // 床交点求める

            float fRay = dot( ray, (*pvecNormal) );
            float f0 = dot( Vec3(-vec3Dnear)-(*pvecPlane), (*pvecNormal ) );

            vec3D = Vec3(vec3Dnear) + ( f0/fRay )*ray;

        }
        else {
            // 当たらない場合はとりあえずいちばん遠く
            vec3D = vec3Dfar;
        }

        return( vec3D );
    }
    // スクリーン座標→3D座標
    // y=0 地面との判定Ver
    Vec3 Screen2World( float fScrX, float fScrY, const Matrix* pMatInv )
    {
        Vec3 vecPlane;
        Vec3 vecNormal;

        vecPlane.x = vecPlane.y = vecPlane.z = vecNormal.x = vecNormal.z = 0.0f;
        vecNormal.y = 1.0f;

        return( Screen2World( fScrX, fScrY, &vecPlane, &vecNormal, pMatInv ));
    }




};