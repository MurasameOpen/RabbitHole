//
// Created by Yuki miyatake on 2016/02/06.
//

#ifndef RABBIT_MATH_H
#define RABBIT_MATH_H

#include<array>

// TODO: divide some file
namespace rabbit{

    // to common header
    using GLfloat = float;



    struct MATRIX4x3
    {
        union {
            struct {
                GLfloat        _11, _12, _13, _14;
                GLfloat        _21, _22, _23, _24;
                GLfloat        _31, _32, _33, _34;
            };
            GLfloat m[3][4];
        };
    };
//}__attribute__ ((aligned (16)));

    struct MATRIX4x4
    {
        union {
            struct {
                GLfloat        _11, _12, _13, _14;
                GLfloat        _21, _22, _23, _24;
                GLfloat        _31, _32, _33, _34;
                GLfloat        _41, _42, _43, _44;
            };
            GLfloat m[4][4];
        };
    } ;


    class Matrix;
    class Vec4;
//class Vec3;


    class vec2
    {
    public:
        vec2();
        vec2(float x, float y);
        vec2(const std::array<float,2>& );

        operator std::array<float,2>&(){return f_;};
        operator const std::array<float,2>&()const {return f_;} ;

        vec2& init();
//        vec2& operator =(const vec2& other);
        vec2& set(float x, float y);
        float length() const;
        vec2& normalize();


        vec2 operator+() const;
        vec2 operator-() const;

        // friendだよねー　こっからした・・
        vec2& operator+=(const vec2 &);
        vec2& operator-=(const vec2 &);
        vec2& operator*=(float);
        vec2& operator/=(float);

        friend vec2& operator+=( vec2 &me, float f);
//        friend vec2& operator+=( vec2 &me, const vec2 &other);
        friend vec2& operator-=( vec2 &me, float f);
//        friend vec2& operator-=( vec2 &me, const vec2 &other);


        vec2 operator+(const vec2 &) const;
        vec2 operator-(const vec2 &) const;
        vec2 operator*(float) const;
        vec2 operator/(float) const;

        union{
            std::array<float,2> f_;
            float x_, y_;
        };
    };

    class Vec3{
    public:
        //メンバ変数
        float x;
        float y;
        float z;
        //コンストラクタ
        Vec3();
        Vec3(float x,float y,float z);
        Vec3( Vec4 vec );
        //代入演算子
        Vec3& operator=(const Vec3& v);
        //単項演算子
        Vec3 operator+=(const Vec3& v);
        Vec3 operator-=(const Vec3& v);
        Vec3 operator*=(float k);
        Vec3 operator/=(float k);
        Vec3 operator+()const;
        Vec3 operator-()const;
        //添え字演算子
        float& operator[](int i);
        //比較演算子
        bool operator==(const Vec3& v ) const;
        bool operator!=(const Vec3& v ) const;
        //べクトルの長さ
        float Length() const;
        //正規化
        Vec3 Normalize() const;
        //
        void Set(float x,float y,float z);



    };
    //ベクトル演算
    Vec3 operator *( const Vec3& v, const Matrix &mat );
    //Vec3+Vec3
    Vec3 operator+(const Vec3& u,const Vec3& v);
    //Vec3-Vec3
    Vec3 operator-(const Vec3& u,const Vec3& v);
    //float*Vec3
    Vec3 operator*(float k,const  Vec3& v);
    //Vec3*float
    Vec3 operator*(const Vec3& v,float k);
    //Vec3/float
    Vec3 operator/(const Vec3& v,float k);
    //内積 Vec3*Vec3
    float dot(const Vec3& u,const Vec3& v);
    //外積 Vec3%Vec3
    Vec3 cross(const Vec3& u,const Vec3& v);
    //2つのベクトルのなす角度
    float angleTo(const Vec3& u,const Vec3& v);
    //
    float distanceTo(const Vec3 &p1, const Vec3 &p2);
    Vec3 dirTo(const Vec3 &p1, const Vec3 &p2);
    Vec3 lerp(const Vec3 &vec1, const Vec3 &vec2, float t);


    class Vec4{
    public:
        //メンバ変数
        float x;
        float y;
        float z;
        float w;
        //コンストラクタ
        Vec4();
        Vec4(float x,float y,float z, float w);
        Vec4( Vec3& vec ){ this->x = vec.x; this->y=vec.y; this->z=vec.z; this->w=1.0f; };
        //代入演算子
        Vec4& operator=(const Vec4& v);
        //単項演算子
        Vec4 operator+=(const Vec4& v);
        Vec4 operator-=(const Vec4& v);
        Vec4 operator*=(float k);
        Vec4 operator/=(float k);
        Vec4 operator+()const;
        Vec4 operator-()const;
        //添え字演算子
        float& operator[](int i);
        //比較演算子
        bool operator==(const Vec4& v ) const;
        bool operator!=(const Vec4& v ) const;
        //べクトルの長さ
        float Length() const;
        //正規化
        Vec4 Normalize() const;
        //
        void Set(float x,float y,float z, float w );

    };
    //ベクトル演算
    Vec4 operator *( const Vec4& v, const Matrix &mat );
    //Vec4+Vec4
    Vec4 operator+(const Vec4& u,const Vec4& v);
    //Vec4-Vec4
    Vec4 operator-(const Vec4& u,const Vec4& v);
    //float*Vec4
    Vec4 operator*(float k,const  Vec4& v);
    //Vec4*float
    Vec4 operator*(const Vec4& v,float k);
    //Vec4/float
    Vec4 operator/(const Vec4& v,float k);
    //内積 Vec4*Vec4
    float dot(const Vec4& u,const Vec4& v);
    //外積 Vec3%Vec3
//	Vec4 cross(const Vec4& u,const Vec4& v);
    //2つのベクトルのなす角度
    float angleTo(const Vec4& u,const Vec4& v);
    //
    float distanceTo(const Vec4 &p1, const Vec4 &p2);
    Vec4 dirTo(const Vec4 &p1, const Vec4 &p2);
    Vec4 lerp(const Vec4 &vec1, const Vec4 &vec2, float t);


    class Matrix
    {
    public:
        float m[16];

        void Identity();
        void Set(
                float _11, float _12, float _13, float _14,
                float _21, float _22, float _23, float _24,
                float _31, float _32, float _33, float _34,
                float _41, float _42, float _43, float _44
        );
        float Get(int line, int col) const;
        void Transpose();
        void MakeTranslation(float x_trans, float y_trans, float z_trans);
        void MakeTranslation(const Vec3 &vec);
        void MakeScaling(float x_scale, float y_scale, float z_scale);
        void MakeRotationX(float x_angle);
        void MakeRotationY(float y_angle);
        void MakeRotationZ(float z_angle);
        void MakeOrthogonalProjection(
                float left, float right,
                float bottom, float top,
                float near, float far
        );
        void MakePerspectiveProjection(
                float left, float right,
                float top, float bottom,
                float near, float far
        );
        void MakePerspectiveProjection(
                float fovY, float aspect,
                float near, float far
        );

        void MakeViewPort( float _fx, float _fy, float _fw, float _fh );

        void LookAt(
                const Vec3 &eye,
                const Vec3 &lookAt,
                const Vec3 &up
        );
        void GetPosAxis(
                Vec3 *p_pos,
                Vec3 *p_xaxis,
                Vec3 *p_yaxis,
                Vec3 *p_zaxis
        );
        void FromYawPitchRoll(float yaw, float pitch, float roll);
        Vec3 GetTranslation() const;
        void Inverse();
        Matrix operator *(const Matrix &other) const;
        //比較演算子
        bool operator==(const Matrix& m ) const;
        bool operator!=(const Matrix& m ) const;

        Vec3 operator *(const Vec3 &vec );

    };

    class Quaternion
    {
    private:
        float W, X, Y, Z;      // components of a quaternion

    public:
        // default constructor
        Quaternion();
        Quaternion(const float, const float = 0.0, const float = 0.0, const float = 0.0);

        // quaternion multiplication
        friend Quaternion operator * (const Quaternion&, const Quaternion&);
        const Quaternion& operator *= (const Quaternion&);

        // konjugiertes Quaternion
        const Quaternion& operator ~ ();

        // this function inverts the quaternion
        const Quaternion& operator - ();

        // this normalizes a quaternion
        const Quaternion& Normalize();
        const Quaternion& FromAxis(const float, float, float, float);
        const Quaternion& FromMatrix(const Matrix &matrix);
        const Quaternion& FromYawPitchRoll(float yaw, float pitch, float roll);
        void ToMatrix(Matrix *out) const;

        void Slerp(const Quaternion&, const Quaternion&, const float);

        // some additional Quaternion functions
        // getting the exponent of a quaternion
        const Quaternion& exp();
        const Quaternion& log();
    };

    class Color
    {
    public:
        Color();
        Color(float r, float g, float b, float a);
        float r, g, b, a;
    };
    /*
    struct Rect
    {
        float left;
        float right;
        float top;
        float bottom;
    };

    */


    // スクリーン→3D座標変換
    // y=0 地面との判定Ver
    Vec3 Screen2World( float fScrX, float fScrY, const Matrix* pMatInv );
    // vecPlane: vecNormal   地面のVectorとNormal
    // fScrX fScrY： スクリーン座標 XY
    // pMatInv: 逆行列(World * View * Projection * ViewPort の逆行列)
    Vec3 Screen2World( float fScrX, float fScrY, Vec3 *pvecPlane, Vec3 *pvecNormal, const Matrix *pMatInv );













// NEONのレジスタのd8-d15がFPUと共有なので避ける
/*
SKINMESH_4W_NEON
	4ウェイトのスキンメッシュ		for ARM NEON
	返り値のwは破壊されるので注意
	vec3 = vec3(pos) * mat4x4(bone) * vec4(weight)

	[in] vec3 vec			: 頂点座標
		 vec4 weight		: 4ウェイト
		 mat4x4 mat003		: 4行列
	基本は以下の bone_weight考慮した行列演算*4 だが
	パイプライン ストールを防ぐため、書き込みレジスタを分割させる
	(ARMの詳細な仕組みやクロック数わからないけど 一般的RISC CPUとして 推測)

	"vldmia %3, {q8-q11 }   \n\t"			// q9-q12 = m
	"vmla.f32 q12, q9, d0[0]\n\t"
	"vmla.f32 q12, q10, d0[1]\n\t"
	"vmla.f32 q12, q11, d1[0]\n\t"
	"vmul.f32 q1, q12, d4[0] \n\t"
*/
#define SKINMESH_4W_NEON(  out, pos, weight, mat0, mat1, mat2, mat3 )													\
{																														\
							__asm__ volatile(																			\
								/* Store m & v leaving room at top of registers for result (q0)		*/					\
								"vldmia %1, {q0}               \n\t"	/* q0    = v	*/								\
								""																						\
								/* weight 0&1 */																		\
								"vldmia %3, {q8-q11 }			\n\t"	/* q9-q12 = matrix	*/							\
								"vldmia %4, {q12-q15 }			\n\t"	/* q9-q12 = m */								\
								"vldmia %2, {q2}				\n\t"	/* q0    = weight */							\
								"vmla.f32 q11, q8, d0[0]		\n\t"													\
								"vmla.f32 q15, q12, d0[0]		\n\t"													\
								"vmla.f32 q11, q9, d0[1]		\n\t"													\
								"vmla.f32 q15, q13, d0[1]		\n\t"													\
								"vmla.f32 q11, q10, d1[0]		\n\t"													\
								"vmla.f32 q15, q14, d1[0]		\n\t"													\
								"vmul.f32 q1, q11, d4[0]		\n\t"													\
								"vmla.f32 q1, q15, d4[1]		\n\t"													\
								""																						\
								/* weight 2&3  */																		\
								"vldmia %5, {q8-q11 }			\n\t"			/* q9-q12 = matrix */					\
								"vldmia %6, {q12-q15 }			\n\t"			/* q9-q12 = m      */					\
								"vmla.f32 q11, q8, d0[0]		\n\t"													\
								"vmla.f32 q15, q12, d0[0]		\n\t"													\
								"vmla.f32 q11, q9, d0[1]		\n\t"													\
								"vmla.f32 q15, q13, d0[1]		\n\t"													\
								"vmla.f32 q11, q10, d1[0]		\n\t"													\
								"vmla.f32 q15, q14, d1[0]		\n\t"													\
								"vmla.f32 q1, q11, d5[0]		\n\t"													\
								"vmla.f32 q1, q15, d5[1]		\n\t"													\
								""																						\
								""																						\
								"vstmia %0, {q1}"																		\
								: /* no output	*/																		\
								: "r" (out), "r" (pos), "r" (weight), "r" (mat0), "r" (mat1), "r" (mat2), "r" (mat3)    \
								: "memory", "q0", "q1", "q2", "q8", "q9", "q10", "q11", "q12", "q13", "q14", "q15"		\
							);																							\
}



/*
SKINMESH_1W_NULL_NEON
	1ウェイト NULLつきスキンメッシュ		for ARM NEON
	返り値のwは破壊されるので注意
	vec3 = vec3(pos) * mat4x4(loc) * mat4x4(bone)

	[in] vec3 pos		: 頂点座標
		 vec4 loc		: NULL
		 mat4x4 mat		: Matrix

*/
#define SKINMESH_1W_NULL_NEON( out, pos, loc, mat )																		\
{																														\
						__asm__ volatile(																				\
							"vldmia %1, {q0}               \n\t"														\
							""																							\
							"vldmia %2, {q8-q11 }			\n\t"														\
							"vldmia %3, {q12-q15 }			\n\t"														\
							""																							\
							"vmla.f32 q11, q8, d0[0]		\n\t"														\
							"vmla.f32 q11, q9, d0[1]		\n\t"														\
							"vmla.f32 q11, q10, d1[0]		\n\t"														\
							""																							\
							"vmov q0, q11					\n\t"														\
							""																							\
							"vmla.f32 q15, q12, d0[0]		\n\t"														\
							"vmla.f32 q15, q13, d0[1]		\n\t"														\
							"vmla.f32 q15, q14, d1[0]		\n\t"														\
							""																							\
							"vstmia %0, {q15}"																			\
							: /* no output	*/																			\
							: "r" (out), "r" (pos), "r" (loc), "r" (mat)												\
							: "memory", "q0", "q8", "q9", "q10", "q11", "q12", "q13", "q14", "q15"						\
						);																								\
}

};




#endif //RABBIT_MATH_H
