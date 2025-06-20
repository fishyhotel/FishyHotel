/* MIT/Unlicense */
#ifndef AUX_H
#define AUX_H

// render state id's
GLint projection_id;
GLint modelview_id;
GLint position_id;
GLint normal_id;
GLint color_id;
GLint lightpos_id;
GLint ambient_id;
GLint specular_id;
GLint specpower_id;
GLint viewdist_id;
GLint opacity_id;

typedef struct {float x,y,z,w;} vec; // Vector
typedef struct {float m[4][4];} mat; // Matrix

// render states
mat projection, view, model, modelview;
#define updateModelView(); mMul(&modelview,&model,&view);glUniformMatrix4fv(modelview_id,1,GL_FALSE,(float*)&modelview.m[0][0]);
#define toView(); glUniformMatrix4fv(modelview_id,1,GL_FALSE,(float*)&view.m[0][0]);
#define toModelView(); glUniformMatrix4fv(modelview_id,1,GL_FALSE,(float*)&modelview.m[0][0]);
void makeShader();

// :: MODEL
typedef struct
{
    GLuint vid; // Vertex Array Buffer ID
    GLuint iid;	// Index Array Buffer ID
    GLuint cid;	// Colour Array Buffer ID
    GLuint nid;	// Normal Array Buffer ID
#ifdef MAX_MODELS
    GLuint itp; // Index Type (GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT, GL_UNSIGNED_INT)
    GLuint ni;  // Number of Indices
    GLuint nv;  // num vertices
    GLfloat *vertices; // pointer to vertex position data
    GLbyte  *normals;  // pointer to vertex normal data
    GLubyte *colors;   // pointer to color data
    vec pos;    // world pos
    GLfloat rad;// radius
    GLfloat rsq;// radius squared
#endif
} ESModel;

// :: UTILITY
GLuint  esRand(const GLuint min, const GLuint max);
GLfloat esRandFloat(const GLfloat min, const GLfloat max);
void    esBind(const GLenum target, GLuint* buffer, const void* data, const GLsizeiptr datalen, const GLenum usage);

// :: VECTOR
#define PI     3.14159265359f // PI
#define x2PI   6.28318530718f // PI * 2
#define d2PI   1.57079632679f // PI / 2
#define DEGREE 57.2957795131f // 1 Radian as Degrees
#define RADIAN 0.01745329251f // PI / 180 (1 Degree as Radians)
#define RAD2DEG DEGREE
#define DEG2RAD RADIAN

static inline float randf();  // uniform [0 to 1]
static inline float randfc(); // uniform [-1 to 1]
static inline float fRandFloat(const float min, const float max);
static inline int   fRand(const float min, const float max);

int vec_ftoi(float f); // float to integer quantise
float smoothstep(float x){return x*x*(3.f-2.f*x);}

void  vCross(vec* r, const vec v1, const vec v2);
float vDot(const vec v1, const vec v2);
float vSum(const vec v);
float vSumAbs(const vec v);
void  vReflect(vec* r, const vec v, const vec n);
void  vSlerp(vec* r, const vec v1, const vec v2, const float t);

int  vEqualTol(const vec a, const vec b, const float tol);
int  vEqualInt(const vec a, const vec b);
void vMin(vec* r, const vec v1, const vec v2);
void vMax(vec* r, const vec v1, const vec v2);

void  vNorm(vec* v);
float vDist(const vec v1, const vec v2);
float vDistSq(const vec a, const vec b);
float vDistMh(const vec a, const vec b); // manhattan
float vDistLa(const vec a, const vec b); // longest axis
float vMod(const vec v); // modulus
float vMag(const vec v); // magnitude
void  vInv(vec* v); // invert
void  vCopy(vec* r, const vec v);
void  vDir(vec* r, const vec v1, const vec v2); // direction vector from v1 to v2

void vRotX(vec* v, const float radians);
void vRotY(vec* v, const float radians);
void vRotZ(vec* v, const float radians);

void vAdd(vec* r, const vec v1, const vec v2);
void vSub(vec* r, const vec v1, const vec v2);
void vDiv(vec* r, const vec numerator, const vec denominator);
void vMul(vec* r, const vec v1, const vec v2);

void vAddS(vec* r, const vec v1, const float v2);
void vSubS(vec* r, const vec v1, const float v2);
void vDivS(vec* r, const vec v1, const float v2);
void vMulS(vec* r, const vec v1, const float v2);

// :: MATRIX
void mIdent(mat *m);
void mCopy(mat *r, const mat *v);
void mMul(mat *r, const mat *a, const mat *b);
void mMulP(vec *r, const mat *a, const float x, const float y, const float z);
void mMulV(vec *r, const mat *a, const vec v);
void mScale(mat *r, const float x, const float y, const float z);
void mScale1(mat *r, const float s);
void mTranslate(mat *r, const float x, const float y, const float z);
void mRotX(mat *r, const float radians); // rotate on axis
void mRotY(mat *r, const float radians); // rotate on axis
void mRotZ(mat *r, const float radians); // rotate on axis
void mFrustum(mat *r, const float left, const float right, const float bottom, const float top, const float nearZ, const float farZ);
void mPerspective(mat *r, const float fovy, const float aspect, const float nearZ, const float farZ);
void mLookAt(mat *r, const vec origin, const vec unit_dir);
void mSetViewDir(mat *r, const vec dir_norm);
void mGetViewDir(vec *r, const mat matrix);
void mGetViewX(vec *r, const mat matrix);
void mGetViewY(vec *r, const mat matrix);
void mGetViewZ(vec *r, const mat matrix);
void mSetDir(mat *r, const vec dir_norm);
void mGetDirX(vec *r, const mat matrix);
void mGetDirY(vec *r, const mat matrix);
void mGetDirZ(vec *r, const mat matrix);
void mGetPos(vec *r, const mat matrix);
void mSetPos(mat *r, const vec pos);
void mDump(const mat matrix);
float mGetRotX(const mat *m);
float mGetRotY(const mat *m);
float mGetRotZ(const mat *m);
void mSetRotX(mat *r, const float radians);
void mSetRotY(mat *r, const float radians);
void mSetRotZ(mat *r, const float radians);

//*************************************
// UTILITY CODE
//*************************************
GLuint esRand(const GLuint min, const GLuint max)
{
    //return (GLuint)roundf(esRandFloat((GLfloat)min, (GLfloat)max));
    GLuint r = (rand()%(max+1u-min))+min;
    if(r > max){r=max;}else if(r < min){r=min;}
    return r;
}
GLfloat esRandFloat(const GLfloat min, const GLfloat max)
{
    static GLfloat rrndmax = 1.f/(GLfloat)RAND_MAX;
    return (((GLfloat)rand()) * rrndmax) * (max-min) + min;
}
void esBind(const GLenum target, GLuint* buffer, const void* data, const GLsizeiptr datalen, const GLenum usage)
{
    glGenBuffers(1, buffer);
    glBindBuffer(target, *buffer);
    glBufferData(target, datalen, data, usage);
}

#ifdef MAX_MODELS // once esLoadModel() is called just esBindModel(id) and esRenderModel() or just esBindRender(id)
    ESModel esModelArray[MAX_MODELS]; // just create new "sub - index arrays" of categories that index this master array
    uint esModelArray_index = 0;      // e.g; 0-10 index of fruit 3d models A-Z by name?
    uint esBoundModel = 0;
    void esBindModel(const uint id)
    {
        glBindBuffer(GL_ARRAY_BUFFER, esModelArray[id].vid);
        glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(position_id);

        glBindBuffer(GL_ARRAY_BUFFER, esModelArray[id].nid);
        glVertexAttribPointer(normal_id, 3, GL_BYTE, GL_TRUE, 0, 0);
        glEnableVertexAttribArray(normal_id);

        glBindBuffer(GL_ARRAY_BUFFER, esModelArray[id].cid);
        glVertexAttribPointer(color_id, 3, GL_UNSIGNED_BYTE, GL_TRUE, 0, 0);
        glEnableVertexAttribArray(color_id);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, esModelArray[id].iid);
        esBoundModel = id;
    }
    void esRenderModel()
    {
        glDrawElements(GL_TRIANGLES, esModelArray[esBoundModel].ni, esModelArray[esBoundModel].itp, 0);
    }
    /// above is; bind it, draw a few instances of it. ... below is ... bind it, draw it, draw something different.
    void esBindRender(const uint id)
    {
        glBindBuffer(GL_ARRAY_BUFFER, esModelArray[id].vid);
        glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(position_id);

        glBindBuffer(GL_ARRAY_BUFFER, esModelArray[id].nid);
        glVertexAttribPointer(normal_id, 3, GL_BYTE, GL_TRUE, 0, 0);
        glEnableVertexAttribArray(normal_id);

        glBindBuffer(GL_ARRAY_BUFFER, esModelArray[id].cid);
        glVertexAttribPointer(color_id, 3, GL_UNSIGNED_BYTE, GL_TRUE, 0, 0);
        glEnableVertexAttribArray(color_id);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, esModelArray[id].iid);

        glDrawElements(GL_TRIANGLES, esModelArray[id].ni, esModelArray[id].itp, 0);
    }
#endif

//*************************************
// SHADER CODE
//*************************************
const GLchar* v1 = // vertex shader
    "#version 100\n"
    "uniform mat4 modelview;\n"
    "uniform mat4 projection;\n"
    "uniform float ambient;\n"
    "uniform float specular;\n"
    "uniform float specpower;\n"
    "uniform float viewdist;\n"
    "uniform float opacity;\n"
    "uniform vec3 lightpos;\n"
    "attribute vec4 position;\n"
    "attribute vec3 normal;\n"
    "attribute vec3 color;\n"
    "varying vec3 vertPos;\n"
    "varying vec3 vertNorm;\n"
    "varying vec3 vertCol;\n"
    "varying float vertAmb;\n"
    "varying float vertSpec;\n"
    "varying float vertSpecPow;\n"
    "varying float vertViewDist;\n"
    "varying float vertOpa;\n"
    "varying vec3 vlightPos;\n"
    "void main()\n"
    "{\n"
        "vec4 vertPos4 = modelview * position;\n"
        "vertPos = vertPos4.xyz / vertPos4.w;\n"
        "vertNorm = normalize(vec3(modelview * vec4(normal, 0.0)));\n" // this normalize could be removed by passing in the inverse scaling factor and scaling the vector back up
        "vertCol = color;\n"
        "vertAmb = ambient;\n"
        "vertSpec = specular;\n"
        "vertSpecPow = specpower;\n"
        "vertViewDist = viewdist;\n"
        "vertOpa = opacity;\n"
        "vlightPos = lightpos;\n"
        "gl_Position = projection * vertPos4;\n"
    "}\n";
const GLchar* f1 =  // fragment shader
    "#version 100\n"
    "precision highp float;\n"
    "varying vec3 vertPos;\n"
    "varying vec3 vertNorm;\n"
    "varying vec3 vertCol;\n"
    "varying float vertAmb;\n"
    "varying float vertSpec;\n"
    "varying float vertSpecPow;\n"
    "varying float vertViewDist;\n"
    "varying float vertOpa;\n"
    "varying vec3 vlightPos;\n"
    "void main()\n"
    "{\n"
        "vec3 lightDir = normalize(vlightPos - vertPos);\n"
        "vec3 viewDir = normalize(-vertPos);\n"

        "vec3 vertNormN = normalize(vertNorm);\n"
        "if(dot(lightDir, vertNormN) < 0.0){vertNormN = -vertNormN;}\n" // HAX

#ifndef BLINN_PHONG
        "vec3 reflectDir = reflect(-lightDir, vertNormN);\n"
#else
        "vec3 halfDir = normalize(viewDir + lightDir);\n"
#endif

        "float lumosity = max(dot(lightDir, vertNormN), 0.0) * 0.5;\n" // HAX
        "vec3 specular = vertCol;\n" // starts at diffuse color

#ifndef BLINN_PHONG
        "float specAngle = max(dot(reflectDir, viewDir), 0.0);\n"
#else
        "float specAngle = max(dot(halfDir, vertNormN), 0.0);\n"
#endif

        "specular += pow(specAngle, vertSpecPow) * (vertCol*vertSpec);\n" // specColor * specularMultiplier
        "gl_FragColor = vec4( ((vertCol*vertAmb) + (specular * lumosity)) * clamp(1.0 - (length(vertPos)*vertViewDist), 0.0, 1.0), vertOpa);\n"
    "}\n";
void makeShader()
{
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &v1, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &f1, NULL);
    glCompileShader(fragmentShader);

    GLuint shader = glCreateProgram();
        glAttachShader(shader, vertexShader);
        glAttachShader(shader, fragmentShader);
    glLinkProgram(shader);

    position_id   = glGetAttribLocation(shader,  "position");
    normal_id     = glGetAttribLocation(shader,  "normal");
    color_id      = glGetAttribLocation(shader,  "color");
    
    projection_id = glGetUniformLocation(shader, "projection");
    modelview_id  = glGetUniformLocation(shader, "modelview");
    lightpos_id   = glGetUniformLocation(shader, "lightpos");
    ambient_id    = glGetUniformLocation(shader, "ambient");
    specular_id   = glGetUniformLocation(shader, "specular");
    specpower_id  = glGetUniformLocation(shader, "specpower");
    viewdist_id   = glGetUniformLocation(shader, "viewdist");
    opacity_id    = glGetUniformLocation(shader, "opacity");

    glUseProgram(shader);
}

#include <math.h>   // sqrtf logf fabsf cosf sinf
#include <string.h> // memset memcpy

//*************************************
// FAST RANDOMS
//*************************************

int srandfq = 74235;
static inline void srandf(const int seed){srandfq = seed;}
static inline float randf()
{
    // https://www.musicdsp.org/en/latest/Other/273-fast-float-random-numbers.html (moc.liamg@seir.kinimod)
    srandfq *= 16807;
    return (float)(srandfq & 0x7FFFFFFF) * 4.6566129e-010f;
}
static inline float randfc()
{
    // https://www.musicdsp.org/en/latest/Other/273-fast-float-random-numbers.html (dominik.ries@gmail.com)
    srandfq *= 16807;
    return ((float)(srandfq)) * 4.6566129e-010f;
}
static inline float fRandFloat(const float min, const float max)
{
    return min + randf() * (max-min); 
}
static inline int fRand(const float min, const float max)
{
    return (int)((min + randf() * (max-min))+0.5f); 
}

//*************************************
// VECTOR FUNCTIONS
//*************************************

void vCross(vec* r, const vec v1, const vec v2)
{
    r->x = (v1.y * v2.z) - (v2.y * v1.z);
    r->y = -((v1.x * v2.z) - (v2.x * v1.z));
    r->z = (v1.x * v2.y) - (v2.x * v1.y);
}

float vDot(const vec v1, const vec v2)
{
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

float vSum(const vec v)
{
    return v.x + v.y + v.z;
}

float vSumAbs(const vec v)
{
    return fabs(v.x) + fabs(v.y) + fabs(v.z);
}

void vInv(vec* v)
{
    v->x = -v->x;
    v->y = -v->y;
    v->z = -v->z;
}

void vNorm(vec* v)
{
    const float len = 1.f/sqrtf(v->x*v->x + v->y*v->y + v->z*v->z);
    v->x *= len;
    v->y *= len;
    v->z *= len;
}

float vDist(const vec v1, const vec v2)
{
    const float xm = (v1.x - v2.x);
    const float ym = (v1.y - v2.y);
    const float zm = (v1.z - v2.z);
    return sqrtf(xm*xm + ym*ym + zm*zm);
}

float vDistSq(const vec a, const vec b)
{
    const float xm = (a.x - b.x);
    const float ym = (a.y - b.y);
    const float zm = (a.z - b.z);
    return xm*xm + ym*ym + zm*zm;
}

float vDistMh(const vec a, const vec b)
{
    return (a.x - b.x) + (a.y - b.y) + (a.z - b.z);
}

float vDistLa(const vec v1, const vec v2)
{
    const float xm = fabsf(v1.x - v2.x);
    const float ym = fabsf(v1.y - v2.y);
    const float zm = fabsf(v1.z - v2.z);

    float dist = xm;
    if(ym > dist)
        dist = ym;
    if(zm > dist)
        dist = zm;

    return dist;
}

void vReflect(vec* r, const vec v, const vec n)
{
    const float angle = vDot(v, n);
    r->x = v.x - (2.f * n.x) * angle;
    r->y = v.y - (2.f * n.y) * angle;
    r->z = v.z - (2.f * n.z) * angle;
}

void vSlerp(vec* r, const vec a, const vec b, const float t)
{
    float dab = vDot(a, b);
    /**/ if(dab >  1.0f){dab =  1.0f;}
    else if(dab < -1.0f){dab = -1.0f;}
    const float theta = acosf(dab);

    // If the angle is very small, fall back to linear interpolation
    if(theta < 1e-6)
    {
        *r = (vec){ (1.f - t) * a.x + t * b.x,
                    (1.f - t) * a.y + t * b.y,
                    (1.f - t) * a.z + t * b.z };
        vNorm(r);
        return;
    }

    const float sin_theta = sinf(theta);

    // Compute interpolation factors
    float w1 = sinf((1.f - t) * theta) / sin_theta;
    float w2 = sinf(t * theta) / sin_theta;

    // Compute interpolated vector
    *r = (vec){ w1 * a.x + w2 * b.x,
                w1 * a.y + w2 * b.y,
                w1 * a.z + w2 * b.z };
    vNorm(r);
}

int vEqualTol(const vec a, const vec b, const float tol)
{
    return  a.x >= b.x - tol && a.x <= b.x + tol &&
            a.y >= b.y - tol && a.y <= b.y + tol &&
            a.z >= b.z - tol && a.z <= b.z + tol;
}

void vMin(vec* r, const vec v1, const vec v2)
{
    if(v1.x < v2.x && v1.y < v2.y && v1.z < v2.z)
    {
        r->x = v1.x;
        r->y = v1.y;
        r->z = v1.z;
    }

    r->x = v2.x;
    r->y = v2.y;
    r->z = v2.z;
}

void vMax(vec* r, const vec v1, const vec v2)
{
    if(v1.x > v2.x && v1.y > v2.y && v1.z > v2.z)
    {
        r->x = v1.x;
        r->y = v1.y;
        r->z = v1.z;
    }

    r->x = v2.x;
    r->y = v2.y;
    r->z = v2.z;
}

int vec_ftoi(float f)
{
    if(f < 0.f)
        f -= 0.5f;
    else
        f += 0.5f;
    return (int)f;
}

int vEqualInt(const vec a, const vec b)
{
    return vec_ftoi(a.x) == vec_ftoi(b.x) && vec_ftoi(a.y) == vec_ftoi(b.y) && vec_ftoi(a.z) == vec_ftoi(b.z);
}

float vMod(const vec v)
{
    return sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
}

float vMag(const vec v)
{
    return v.x*v.x + v.y*v.y + v.z*v.z;
}

void vCopy(vec* r, const vec v)
{
    memcpy(r, &v, sizeof(vec));
}

void vDir(vec* r, const vec v1, const vec v2)
{
    vSub(r, v2, v1);
    vNorm(r);
}

void vRotX(vec* v, const float radians)
{
    v->y = v->y * cosf(radians) + v->z * sinf(radians);
    v->z = v->y * sinf(radians) - v->z * cosf(radians);
}

void vRotY(vec* v, const float radians)
{
    v->x = v->z * sinf(radians) - v->x * cosf(radians);
    v->z = v->z * cosf(radians) + v->x * sinf(radians);
}

void vRotZ(vec* v, const float radians)
{
    v->x = v->x * cosf(radians) + v->y * sinf(radians);
    v->y = v->x * sinf(radians) - v->y * cosf(radians);
}

void vAdd(vec* r, const vec v1, const vec v2)
{
    r->x = v1.x + v2.x;
    r->y = v1.y + v2.y;
    r->z = v1.z + v2.z;
}

void vSub(vec* r, const vec v1, const vec v2)
{
    r->x = v1.x - v2.x;
    r->y = v1.y - v2.y;
    r->z = v1.z - v2.z;
}

void vDiv(vec* r, const vec numerator, const vec denominator)
{
    r->x = numerator.x / denominator.x;
    r->y = numerator.y / denominator.y;
    r->z = numerator.z / denominator.z;
}

void vMul(vec* r, const vec v1, const vec v2)
{
    r->x = v1.x * v2.x;
    r->y = v1.y * v2.y;
    r->z = v1.z * v2.z;
}

void vAddS(vec* r, const vec v1, const float v2)
{
    r->x = v1.x + v2;
    r->y = v1.y + v2;
    r->z = v1.z + v2;
}

void vSubS(vec* r, const vec v1, const float v2)
{
    r->x = v1.x - v2;
    r->y = v1.y - v2;
    r->z = v1.z - v2;
}

void vDivS(vec* r, const vec v1, const float v2)
{
    r->x = v1.x / v2;
    r->y = v1.y / v2;
    r->z = v1.z / v2;
}

void vMulS(vec* r, const vec v1, const float v2)
{
    r->x = v1.x * v2;
    r->y = v1.y * v2;
    r->z = v1.z * v2;
}

//*************************************
// MATRIX FUNCTIONS
//*************************************

void mIdent(mat *m)
{
    memset(m, 0x0, sizeof(mat));
    m->m[0][0] = 1.0f;
    m->m[1][1] = 1.0f;
    m->m[2][2] = 1.0f;
    m->m[3][3] = 1.0f;
}

void mCopy(mat *r, const mat *v)
{
    memcpy(r, v, sizeof(mat));
}

void mMul(mat *r, const mat *a, const mat *b)
{
    mat tmp;
    for(int i = 0; i < 4; i++)
    {
        tmp.m[i][0] =	(a->m[i][0] * b->m[0][0]) +
                        (a->m[i][1] * b->m[1][0]) +
                        (a->m[i][2] * b->m[2][0]) +
                        (a->m[i][3] * b->m[3][0]) ;

        tmp.m[i][1] =	(a->m[i][0] * b->m[0][1]) + 
                        (a->m[i][1] * b->m[1][1]) +
                        (a->m[i][2] * b->m[2][1]) +
                        (a->m[i][3] * b->m[3][1]) ;

        tmp.m[i][2] =	(a->m[i][0] * b->m[0][2]) + 
                        (a->m[i][1] * b->m[1][2]) +
                        (a->m[i][2] * b->m[2][2]) +
                        (a->m[i][3] * b->m[3][2]) ;

        tmp.m[i][3] =	(a->m[i][0] * b->m[0][3]) + 
                        (a->m[i][1] * b->m[1][3]) +
                        (a->m[i][2] * b->m[2][3]) +
                        (a->m[i][3] * b->m[3][3]) ;
    }
    memcpy(r, &tmp, sizeof(mat));
}

void mMulP(vec *r, const mat *a, const float x, const float y, const float z)
{
    r->x =  (a->m[0][0] * x) +
            (a->m[0][1] * x) +
            (a->m[0][2] * x) +
            (a->m[0][3] * x) ;

    r->y =  (a->m[1][0] * y) +
            (a->m[1][1] * y) +
            (a->m[1][2] * y) +
            (a->m[1][3] * y) ;

    r->z =  (a->m[2][0] * z) +
            (a->m[2][1] * z) +
            (a->m[2][2] * z) +
            (a->m[2][3] * z) ;
}

void mMulV(vec *r, const mat *a, const vec v)
{
    r->x =  (a->m[0][0] * v.x) +
            (a->m[0][1] * v.x) +
            (a->m[0][2] * v.x) +
            (a->m[0][3] * v.x) ;

    r->y =  (a->m[1][0] * v.y) +
            (a->m[1][1] * v.y) +
            (a->m[1][2] * v.y) +
            (a->m[1][3] * v.y) ;

    r->z =  (a->m[2][0] * v.z) +
            (a->m[2][1] * v.z) +
            (a->m[2][2] * v.z) +
            (a->m[2][3] * v.z) ;

    r->w =  (a->m[3][0] * v.w) +
            (a->m[3][1] * v.w) +
            (a->m[3][2] * v.w) +
            (a->m[3][3] * v.w) ;
}

void mScale(mat *r, const float x, const float y, const float z)
{
    r->m[0][0] *= x;
    r->m[0][1] *= x;
    r->m[0][2] *= x;
    r->m[0][3] *= x;

    r->m[1][0] *= y;
    r->m[1][1] *= y;
    r->m[1][2] *= y;
    r->m[1][3] *= y;

    r->m[2][0] *= z;
    r->m[2][1] *= z;
    r->m[2][2] *= z;
    r->m[2][3] *= z;
}
void mScale1(mat *r, const float s){mScale(r, s, s, s);}

void mTranslate(mat *r, const float x, const float y, const float z)
{
    r->m[3][0] += (r->m[0][0] * x + r->m[1][0] * y + r->m[2][0] * z);
    r->m[3][1] += (r->m[0][1] * x + r->m[1][1] * y + r->m[2][1] * z);
    r->m[3][2] += (r->m[0][2] * x + r->m[1][2] * y + r->m[2][2] * z);
    r->m[3][3] += (r->m[0][3] * x + r->m[1][3] * y + r->m[2][3] * z);
}

void mRotX(mat *r, const float radians)
{
    const float s = sinf(radians);
    const float c = cosf(radians);
    const mat t = { c, 0.f, s, 0.f,
                    0.f, 1.f, 0.f, 0.f,
                    -s, 0.f, c, 0.f,
                    0.f, 0.f, 0.f, 1.f };
    mMul(r, &t, r);
}

void mRotY(mat *r, const float radians)
{
    const float s = sinf(radians);
    const float c = cosf(radians);
    const mat t = { 1.f, 0.f, 0.f, 0.f,
                    0.f, c, -s, 0.f,
                    0.f, s, c, 0.f,
                    0.f, 0.f, 0.f, 1.f };
    mMul(r, &t, r);
}

void mRotZ(mat *r, const float radians)
{
    const float s = sinf(radians);
    const float c = cosf(radians);
    const mat t = { c, -s, 0.f, 0.f,
                    s, c, 0.f, 0.f,
                    0.f, 0.f, 1.f, 0.f,
                    0.f, 0.f, 0.f, 1.f };
    mMul(r, &t, r);
}

void mFrustum(mat *r, const float left, const float right, const float bottom, const float top, const float nearZ, const float farZ)
{
    // MIT: Dan Ginsburg, Budirijanto Purnomo, Dave Shreiner, Aaftab Munshi
    const float dX = right - left;
    const float dY = top - bottom;
    const float dZ = farZ - nearZ;
    const float rdX = 1.f/dX;
    const float rdY = 1.f/dY;
    const float rdZ = 1.f/dZ;
    mat frust;

    if(nearZ <= 0.0f || farZ <= 0.0f || dX <= 0.0f || dY <= 0.0f || dZ <= 0.0f){return;}

    frust.m[0][0] = 2.0f * nearZ * rdX;
    frust.m[0][1] = frust.m[0][2] = frust.m[0][3] = 0.0f;

    frust.m[1][1] = 2.0f * nearZ * rdY;
    frust.m[1][0] = frust.m[1][2] = frust.m[1][3] = 0.0f;

    frust.m[2][0] = (right + left) * rdX;
    frust.m[2][1] = (top + bottom) * rdY;
    frust.m[2][2] = -(nearZ + farZ) * rdZ;
    frust.m[2][3] = -1.0f;

    frust.m[3][2] = -2.0f * nearZ * farZ * rdZ;
    frust.m[3][0] = frust.m[3][1] = frust.m[3][3] = 0.0f;

    mMul(r, &frust, r);
}

void mPerspective(mat *r, const float fovy, const float aspect, const float nearZ, const float farZ)
{
    float frustumW, frustumH;
    //frustumH = (fovy * 0.00872664625f) * nearZ;
    frustumH = tanf(fovy * 0.00872664625f) * nearZ;
    //frustumH = tanf ( fovy / 360.0f * PI ) * nearZ;
    frustumW = frustumH * aspect;
    mFrustum(r, -frustumW, frustumW, -frustumH, frustumH, nearZ, farZ);
}

void mLookAt(mat *r, const vec origin, const vec unit_dir)
{
    static const vec up = (vec){0.f, 0.f, 1.f};

    vec dirn;
    dirn.x = unit_dir.x;
    dirn.y = unit_dir.y;
    dirn.z = unit_dir.z;

    vec c;
    vCross(&c, up, dirn);
    vNorm(&c);

    vec rup;
    vCross(&rup, dirn, c);

    r->m[0][0] = c.x;
    r->m[0][1] = c.y;
    r->m[0][2] = c.z;

    r->m[1][0] = rup.x;
    r->m[1][1] = rup.y;
    r->m[1][2] = rup.z;

    r->m[2][0] = dirn.x;
    r->m[2][1] = dirn.y;
    r->m[2][2] = dirn.z;

    r->m[3][0] = origin.x;
    r->m[3][1] = origin.y;
    r->m[3][2] = origin.z;
}

//

void mSetViewDir(mat *r, const vec dir_norm)
{
    static const vec up_norm = (vec){0.f, 0.f, 1.f};

    vec c;
    vCross(&c, up_norm, dir_norm);
    vNorm(&c);

    vec rup;
    vCross(&rup, dir_norm, c);

    r->m[0][0] = -c.x;
    r->m[1][0] = -c.y;
    r->m[2][0] = -c.z;

    r->m[0][1] = -rup.x;
    r->m[1][1] = -rup.y;
    r->m[2][1] = -rup.z;

    r->m[0][2] = -dir_norm.x;
    r->m[1][2] = -dir_norm.y;
    r->m[2][2] = -dir_norm.z;
}

void mGetViewDir(vec *r, const mat matrix)
{
    mGetViewZ(r, matrix);
}

void mGetViewX(vec *r, const mat matrix)
{
    r->x = -matrix.m[0][0];
    r->y = -matrix.m[1][0];
    r->z = -matrix.m[2][0];
}

void mGetViewY(vec *r, const mat matrix)
{
    r->x = -matrix.m[0][1];
    r->y = -matrix.m[1][1];
    r->z = -matrix.m[2][1];
}

void mGetViewZ(vec *r, const mat matrix)
{
    r->x = -matrix.m[0][2];
    r->y = -matrix.m[1][2];
    r->z = -matrix.m[2][2];
}

//

void mSetDir(mat *r, const vec dir_norm)
{
    static const vec up_norm = (vec){0.f, 0.f, 1.f};

    vec c;
    vCross(&c, up_norm, dir_norm);
    vNorm(&c);

    vec rup;
    vCross(&rup, dir_norm, c);

    r->m[0][0] = c.x;
    r->m[0][1] = c.y;
    r->m[0][2] = c.z;

    r->m[2][0] = rup.x;
    r->m[2][1] = rup.y;
    r->m[2][2] = rup.z;

    r->m[1][0] = -dir_norm.x;
    r->m[1][1] = -dir_norm.y;
    r->m[1][2] = -dir_norm.z;
}

void mGetDirX(vec *r, const mat matrix)
{
    r->x = matrix.m[0][0];
    r->y = matrix.m[0][1];
    r->z = matrix.m[0][2];
}

void mGetDirY(vec *r, const mat matrix)
{
    r->x = matrix.m[1][0];
    r->y = matrix.m[1][1];
    r->z = matrix.m[1][2];
}

void mGetDirZ(vec *r, const mat matrix)
{
    r->x = matrix.m[2][0];
    r->y = matrix.m[2][1];
    r->z = matrix.m[2][2];
}

void mGetPos(vec *r, const mat matrix)
{
    r->x = matrix.m[3][0];
    r->y = matrix.m[3][1];
    r->z = matrix.m[3][2];
}

void mSetPos(mat *r, const vec pos)
{
    r->m[3][0] = pos.x;
    r->m[3][1] = pos.y;
    r->m[3][2] = pos.z;
}

void mDump(const mat matrix)
{
    printf("%+.2f %+.2f %+.2f %+.2f\n", matrix.m[0][0], matrix.m[0][1], matrix.m[0][2], matrix.m[0][3]);
    printf("%+.2f %+.2f %+.2f %+.2f\n", matrix.m[1][0], matrix.m[1][1], matrix.m[1][2], matrix.m[1][3]);
    printf("%+.2f %+.2f %+.2f %+.2f\n", matrix.m[2][0], matrix.m[2][1], matrix.m[2][2], matrix.m[2][3]);
    printf("%+.2f %+.2f %+.2f %+.2f\n", matrix.m[3][0], matrix.m[3][1], matrix.m[3][2], matrix.m[3][3]);
    printf("---\n");
}

float mGetRotX(const mat *m)
{
    return atan2f(-m->m[1][2], m->m[1][1]);
}

float mGetRotY(const mat *m)
{
    return atan2f(m->m[0][2], m->m[2][2]);
}

float mGetRotZ(const mat *m)
{
    return atan2f(m->m[1][0], m->m[0][0]);
}

void mSetRotX(mat *r, const float radians)
{
    const float s = sinf(radians);
    const float c = cosf(radians);

    r->m[0][0] = c;
    r->m[0][1] = 0.f;
    r->m[0][2] = s;
    r->m[0][3] = 0.f;

    r->m[1][0] = 0.f;
    r->m[1][1] = 1.f;
    r->m[1][2] = 0.f;
    r->m[1][3] = 0.f;

    r->m[2][0] = -s;
    r->m[2][1] = 0.f;
    r->m[2][2] = c;
    r->m[2][3] = 0.f;
}

void mSetRotY(mat *r, const float radians)
{
    const float s = sinf(radians);
    const float c = cosf(radians);

    r->m[0][0] = 1.f;
    r->m[0][1] = 0.f;
    r->m[0][2] = 0.f;
    r->m[0][3] = 0.f;

    r->m[1][0] = 0.f;
    r->m[1][1] = c;
    r->m[1][2] = -s;
    r->m[1][3] = 0.f;

    r->m[2][0] = 0.f;
    r->m[2][1] = s;
    r->m[2][2] = c;
    r->m[2][3] = 0.f;
}

void mSetRotZ(mat *r, const float radians)
{
    const float s = sinf(radians);
    const float c = cosf(radians);

    r->m[0][0] = c;
    r->m[0][1] = -s;
    r->m[0][2] = 0.f;
    r->m[0][3] = 0.f;

    r->m[1][0] = s;
    r->m[1][1] = c;
    r->m[1][2] = 0.f;
    r->m[1][3] = 0.f;

    r->m[2][0] = 0.f;
    r->m[2][1] = 0.f;
    r->m[2][2] = 1.f;
    r->m[2][3] = 0.f;
}

#endif