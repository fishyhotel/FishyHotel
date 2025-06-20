
#ifndef banana_leg_H
#define banana_leg_H

GLfloat banana_leg_vertices[] = {-0.730459,-0.284471,-2.82035,-0.730459,-0.379635,-2.67705,-0.825623,-0.284471,-2.67705,-0.730459,0.117577,-2.82035,-0.825623,0.117577,-2.67705,-0.730459,0.212741,-2.67705,-0.259643,-0.284471,-2.82035,-0.164479,-0.284471,-2.67705,-0.259643,-0.379635,-2.67705,-0.259643,0.117577,-2.82035,-0.259643,0.212741,-2.67705,-0.164479,0.117577,-2.67705,-0.641715,0.468147,-1.15222,-0.701003,0.408859,-1.15222,-0.348394,0.468147,-1.15222,-0.348394,0.0562506,-1.15222,-0.701003,0.115538,-1.15222,-0.259669,-0.330569,0.208745,-0.641731,0.0562525,-1.15222,-0.164505,0.235411,0.208745,-0.289123,0.11554,-1.15222,-0.289123,0.408861,-1.15222,-0.730485,0.235411,0.303909,-0.259669,-0.235405,0.303909,-0.259669,0.235411,0.303909,-0.825649,-0.235405,0.208745,-0.730485,0.330575,0.208745,-0.730485,-0.330569,0.208745,-0.730485,-0.235405,0.303909,-0.825649,0.235411,0.208745,-0.164505,-0.235405,0.208745,-0.259669,0.330575,0.208745};
GLbyte banana_leg_normals[] = {-52,-52,-104,-45,-118,-16,-115,-49,-22,-52,52,-104,-116,42,-32,-46,111,-41,52,-52,-104,115,-49,-22,45,-118,-16,52,52,-104,46,111,-41,116,42,-32,-46,118,-4,-115,54,-2,46,118,-4,50,-117,-0,-120,-42,-1,44,-116,27,-50,-117,-0,113,41,41,120,-42,-1,115,54,-2,-43,43,111,43,-43,111,43,43,111,-113,-48,32,-45,109,47,-44,-116,27,-43,-43,111,-113,41,41,113,-48,32,45,109,47};
GLubyte banana_leg_colors[] = {249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90};
const GLubyte banana_leg_indices[] = {0,1,2,3,4,5,6,7,8,9,10,11,0,4,3,12,4,13,3,10,9,21,10,14,9,7,6,15,7,20,6,1,0,9,0,3,1,16,2,12,10,5,16,4,2,11,20,7,15,1,8,17,18,15,19,20,21,22,23,24,25,13,16,26,14,12,27,28,25,22,26,29,23,17,30,24,19,31,27,16,18,22,25,28,24,26,22,23,19,24,28,17,23,15,30,17,21,31,19,12,29,26,0,2,4,12,5,4,3,5,10,21,11,10,9,11,7,15,8,7,6,8,1,9,6,0,1,18,16,12,14,10,16,13,4,11,21,20,15,18,1,17,27,18,19,30,20,22,28,23,25,29,13,26,31,14,27,25,16,22,29,25,24,31,26,23,30,19,28,27,17,15,20,30,21,14,31,12,13,29};
const GLsizeiptr banana_leg_numind = 180;
const GLsizeiptr banana_leg_numvert = 32;

void register_banana_leg()
{
    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].vid, banana_leg_vertices, sizeof(banana_leg_vertices), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].nid, banana_leg_normals, sizeof(banana_leg_normals), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].cid, banana_leg_colors, sizeof(banana_leg_colors), GL_STATIC_DRAW);
    esBind(GL_ELEMENT_ARRAY_BUFFER, &esModelArray[esModelArray_index].iid, banana_leg_indices, sizeof(banana_leg_indices), GL_STATIC_DRAW);
    esModelArray[esModelArray_index].itp = GL_UNSIGNED_BYTE;
    esModelArray[esModelArray_index].ni = banana_leg_numind;
    esModelArray[esModelArray_index].nv = banana_leg_numvert;
    esModelArray[esModelArray_index].pos = (vec){-0.495064, 0.0442562, -1.25822};
    esModelArray[esModelArray_index].rad = 1.56213;
    esModelArray[esModelArray_index].rsq = 2.44025;
    esModelArray[esModelArray_index].vertices = banana_leg_vertices;
    esModelArray[esModelArray_index].normals = banana_leg_normals;
    esModelArray[esModelArray_index].colors = banana_leg_colors;
    esModelArray_index++;
}

#endif
