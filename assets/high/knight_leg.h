
#ifndef knight_leg_H
#define knight_leg_H

GLfloat knight_leg_vertices[] = {-0.730459,-0.235408,-2.83041,-0.730459,-0.330572,-2.73525,-0.825623,-0.235408,-2.73525,-0.730459,0.235408,-2.83041,-0.825623,0.235408,-2.73525,-0.730459,0.330572,-2.73525,-0.259643,-0.235408,-2.83041,-0.164479,-0.235408,-2.73525,-0.259643,-0.330572,-2.73525,-0.259643,0.235408,-2.83041,-0.259643,0.330572,-2.73525,-0.164479,0.235408,-2.73525,-0.0966626,0.2837,-2.46239,-0.211349,-0.398386,-2.46239,-0.308256,-0.26234,0.215292,-0.778779,-0.398382,-2.46239,-0.232734,0.186824,0.215292,-0.0966939,-0.283696,-2.46239,-0.681898,0.186824,0.290815,-0.308256,-0.186818,0.290815,-0.308256,0.186824,0.290815,-0.75742,-0.186818,0.215292,-0.893465,0.283703,-2.46239,-0.893465,-0.283696,-2.46239,-0.681898,0.262346,0.215292,-0.21138,0.398389,-2.46239,-0.778779,0.398389,-2.46239,-0.681898,-0.26234,0.215292,-0.681898,-0.186818,0.290815,-0.75742,0.186824,0.215292,-0.232734,-0.186818,0.215292,-0.308256,0.262346,0.215292};
GLbyte knight_leg_normals[] = {-43,-43,-111,-39,-105,-60,-105,-39,-60,-43,43,-111,-104,39,-60,-39,105,-60,43,-43,-111,105,-39,-60,39,-105,-60,43,43,-111,39,105,-60,105,39,-60,116,49,-14,49,-116,-14,43,-110,47,-49,-116,-14,110,43,47,116,-49,-14,-43,43,111,43,-43,111,43,43,111,-110,-43,47,-116,49,-14,-116,-49,-14,-43,110,47,49,116,-14,-49,116,-14,-43,-110,47,-43,-43,111,-110,43,47,110,-43,47,43,110,47};
GLubyte knight_leg_colors[] = {203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254,203,223,254};
const GLubyte knight_leg_indices[] = {0,1,2,3,4,5,6,7,8,9,10,11,0,4,3,26,4,22,3,10,9,12,10,25,9,7,6,13,7,17,6,1,0,9,0,3,1,23,2,26,10,5,23,4,2,11,17,7,13,1,8,14,15,13,16,17,12,18,19,20,21,22,23,24,25,26,27,28,21,18,24,29,19,14,30,20,16,31,27,23,15,18,21,28,20,24,18,19,16,20,28,14,19,13,30,14,12,31,16,26,29,24,0,2,4,26,5,4,3,5,10,12,11,10,9,11,7,13,8,7,6,8,1,9,6,0,1,15,23,26,25,10,23,22,4,11,12,17,13,15,1,14,27,15,16,30,17,18,28,19,21,29,22,24,31,25,27,21,23,18,29,21,20,31,24,19,30,16,28,27,14,13,17,30,12,25,31,26,22,29};
const GLsizeiptr knight_leg_numind = 180;
const GLsizeiptr knight_leg_numvert = 32;

void register_knight_leg()
{
    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].vid, knight_leg_vertices, sizeof(knight_leg_vertices), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].nid, knight_leg_normals, sizeof(knight_leg_normals), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].cid, knight_leg_colors, sizeof(knight_leg_colors), GL_STATIC_DRAW);
    esBind(GL_ELEMENT_ARRAY_BUFFER, &esModelArray[esModelArray_index].iid, knight_leg_indices, sizeof(knight_leg_indices), GL_STATIC_DRAW);
    esModelArray[esModelArray_index].itp = GL_UNSIGNED_BYTE;
    esModelArray[esModelArray_index].ni = knight_leg_numind;
    esModelArray[esModelArray_index].nv = knight_leg_numvert;
    esModelArray[esModelArray_index].pos = (vec){-0.495064, 1.81794e-06, -1.2698};
    esModelArray[esModelArray_index].rad = 1.56061;
    esModelArray[esModelArray_index].rsq = 2.43552;
    esModelArray[esModelArray_index].vertices = knight_leg_vertices;
    esModelArray[esModelArray_index].normals = knight_leg_normals;
    esModelArray[esModelArray_index].colors = knight_leg_colors;
    esModelArray_index++;
}

#endif
