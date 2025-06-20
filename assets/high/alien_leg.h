
#ifndef alien_leg_H
#define alien_leg_H

GLfloat alien_leg_vertices[] = {-0.575875,-0.0808193,-2.7148,-0.575875,-0.113491,-2.68213,-0.608546,-0.0808193,-2.68213,-0.575875,0.0808208,-2.7148,-0.608546,0.0808208,-2.68213,-0.575875,0.113492,-2.68213,-0.414234,-0.0808193,-2.7148,-0.381563,-0.0808193,-2.68213,-0.414234,-0.113491,-2.68213,-0.414234,0.0808208,-2.7148,-0.414234,0.113492,-2.68213,-0.381563,0.0808208,-2.68213,-0.68516,0.135379,-2.51786,-0.304949,0.135379,-2.51786,-0.359676,-0.190105,-2.51786,-0.304949,-0.135378,-2.51786,-0.259669,-0.330569,0.208745,-0.164505,0.235411,0.208745,-0.730485,0.235411,0.303909,-0.259669,-0.235405,0.303909,-0.259669,0.235411,0.303909,-0.825649,-0.235405,0.208745,-0.685175,-0.135376,-2.51786,-0.730485,0.330575,0.208745,-0.359691,0.190108,-2.51786,-0.630448,0.190108,-2.51786,-0.730485,-0.330569,0.208745,-0.730485,-0.235405,0.303909,-0.825649,0.235411,0.208745,-0.164505,-0.235405,0.208745,-0.259669,0.330575,0.208745,-0.630433,-0.190105,-2.51786};
GLbyte alien_leg_normals[] = {-43,-43,-111,-36,-97,-73,-97,-36,-73,-43,43,-111,-97,36,-73,-36,97,-73,43,-43,-111,97,-36,-73,36,-97,-73,43,43,-111,36,97,-73,97,36,-73,-113,48,-34,113,48,-34,48,-113,-34,113,-48,-34,44,-112,40,112,44,40,-43,43,111,43,-43,111,43,43,111,-112,-44,40,-113,-48,-34,-44,112,40,48,113,-34,-48,113,-34,-44,-112,40,-43,-43,111,-112,44,40,112,-44,40,44,112,40,-48,-113,-34};
GLubyte alien_leg_colors[] = {167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139,167,254,139};
const GLubyte alien_leg_indices[] = {0,1,2,3,4,5,6,7,8,9,10,11,0,4,3,25,4,12,3,10,9,13,10,24,9,7,6,14,7,15,6,1,0,9,0,3,1,22,2,25,10,5,22,4,2,11,15,7,14,1,8,16,31,14,17,15,13,18,19,20,21,12,22,23,24,25,26,27,21,18,23,28,19,16,29,20,17,30,26,22,31,18,21,27,20,23,18,19,17,20,27,16,19,14,29,16,13,30,17,25,28,23,0,2,4,25,5,4,3,5,10,13,11,10,9,11,7,14,8,7,6,8,1,9,6,0,1,31,22,25,24,10,22,12,4,11,13,15,14,31,1,16,26,31,17,29,15,18,27,19,21,28,12,23,30,24,26,21,22,18,28,21,20,30,23,19,29,17,27,26,16,14,15,29,13,24,30,25,12,28};
const GLsizeiptr alien_leg_numind = 180;
const GLsizeiptr alien_leg_numvert = 32;

void register_alien_leg()
{
    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].vid, alien_leg_vertices, sizeof(alien_leg_vertices), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].nid, alien_leg_normals, sizeof(alien_leg_normals), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].cid, alien_leg_colors, sizeof(alien_leg_colors), GL_STATIC_DRAW);
    esBind(GL_ELEMENT_ARRAY_BUFFER, &esModelArray[esModelArray_index].iid, alien_leg_indices, sizeof(alien_leg_indices), GL_STATIC_DRAW);
    esModelArray[esModelArray_index].itp = GL_UNSIGNED_BYTE;
    esModelArray[esModelArray_index].ni = alien_leg_numind;
    esModelArray[esModelArray_index].nv = alien_leg_numvert;
    esModelArray[esModelArray_index].pos = (vec){-0.495077, 2.95043e-06, -1.20544};
    esModelArray[esModelArray_index].rad = 1.50935;
    esModelArray[esModelArray_index].rsq = 2.27815;
    esModelArray[esModelArray_index].vertices = alien_leg_vertices;
    esModelArray[esModelArray_index].normals = alien_leg_normals;
    esModelArray[esModelArray_index].colors = alien_leg_colors;
    esModelArray_index++;
}

#endif
