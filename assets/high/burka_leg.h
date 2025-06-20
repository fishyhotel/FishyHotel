
#ifndef burka_leg_H
#define burka_leg_H

GLfloat burka_leg_vertices[] = {-0.595571,-0.10052,-2.79406,-0.595571,-0.141155,-2.75343,-0.636206,-0.10052,-2.75343,-0.595571,0.10052,-2.79406,-0.636206,0.10052,-2.75343,-0.595571,0.141155,-2.75343,-0.394531,-0.10052,-2.79406,-0.353896,-0.10052,-2.75343,-0.394531,-0.141155,-2.75343,-0.394531,0.10052,-2.79406,-0.394531,0.141155,-2.75343,-0.353896,0.10052,-2.75343,-0.730485,-0.330569,0.208745,-0.825649,-0.235405,0.208745,-0.730485,0.330575,0.208745,-0.259669,0.330575,0.208745,-0.164505,-0.235405,0.208745,-0.164505,0.235411,0.208745,-0.825649,0.235411,0.208745,-0.259669,-0.330569,0.208745,-0.691667,0.140015,-1.45743,-0.355036,0.196616,-1.45743,-0.298434,-0.140015,-1.45743,-0.691667,-0.140015,-1.45743,-0.635066,0.196616,-1.45743,-0.355036,-0.196616,-1.45743,-0.298434,0.140015,-1.45743,-0.635066,-0.196616,-1.45743};
GLbyte burka_leg_normals[] = {-43,-43,-111,-43,-110,-46,-110,-43,-46,-43,43,-111,-110,43,-46,-43,110,-46,43,-43,-111,110,-43,-46,43,-110,-46,43,43,-111,43,110,-46,110,43,-46,-49,-117,-12,-117,-49,-12,-49,117,-12,49,117,-12,117,-49,-12,117,49,-12,-117,49,-12,49,-117,-12,-117,48,-9,48,117,-9,117,-48,-9,-117,-48,-9,-48,117,-9,48,-117,-9,117,48,-9,-48,-117,-9};
GLubyte burka_leg_colors[] = {254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181,254,184,181};
const GLubyte burka_leg_indices[] = {0,1,2,3,4,5,6,7,8,9,10,11,5,20,24,5,9,3,11,6,9,8,22,25,8,0,6,6,3,9,12,23,27,24,10,5,20,2,23,26,16,22,27,8,25,11,21,26,2,3,0,17,21,15,19,27,25,26,7,11,13,20,23,15,24,14,27,2,1,25,16,19,14,20,18,5,4,20,5,10,9,11,7,6,8,7,22,8,1,0,6,0,3,12,13,23,24,21,10,20,4,2,26,17,16,27,1,8,11,10,21,2,4,3,17,26,21,19,12,27,26,22,7,13,18,20,15,21,24,27,23,2,25,22,16,14,24,20};
const GLsizeiptr burka_leg_numind = 138;
const GLsizeiptr burka_leg_numvert = 28;

void register_burka_leg()
{
    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].vid, burka_leg_vertices, sizeof(burka_leg_vertices), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].nid, burka_leg_normals, sizeof(burka_leg_normals), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].cid, burka_leg_colors, sizeof(burka_leg_colors), GL_STATIC_DRAW);
    esBind(GL_ELEMENT_ARRAY_BUFFER, &esModelArray[esModelArray_index].iid, burka_leg_indices, sizeof(burka_leg_indices), GL_STATIC_DRAW);
    esModelArray[esModelArray_index].itp = GL_UNSIGNED_BYTE;
    esModelArray[esModelArray_index].ni = burka_leg_numind;
    esModelArray[esModelArray_index].nv = burka_leg_numvert;
    esModelArray[esModelArray_index].pos = (vec){-0.495077, 3.36766e-06, -1.29266};
    esModelArray[esModelArray_index].rad = 1.5014;
    esModelArray[esModelArray_index].rsq = 2.25421;
    esModelArray[esModelArray_index].vertices = burka_leg_vertices;
    esModelArray[esModelArray_index].normals = burka_leg_normals;
    esModelArray[esModelArray_index].colors = burka_leg_colors;
    esModelArray_index++;
}

#endif
