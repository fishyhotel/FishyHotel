
#ifndef burka_arm_H
#define burka_arm_H

GLfloat burka_arm_vertices[] = {-0.235409,-0.330572,0.228384,-0.235409,-0.235409,0.323547,-0.330573,-0.235409,0.228384,-0.235409,0.235408,0.323547,-0.235409,0.330572,0.228384,-0.330573,0.235408,0.228384,0.235406,-0.235409,0.323547,0.235406,-0.330572,0.228384,0.33057,-0.235409,0.228384,0.235406,0.235408,0.323547,0.33057,0.235408,0.228384,0.235406,0.330572,0.228384,-0.0974682,-0.136857,-1.16341,-0.136866,-0.0974595,-1.16341,-0.0974682,0.136858,-1.16341,0.0974508,0.136858,-1.16341,0.0974508,-0.136857,-1.16341,0.136849,-0.0974595,-1.16341,0.136849,0.0974602,-1.16341,-0.136866,0.0974602,-1.16341,-0.0768211,-0.0767914,-1.46411,-0.107865,-0.0767914,-1.43306,-0.0768211,-0.107835,-1.43306,-0.0768211,0.0767964,-1.46411,0.0767662,-0.0767914,-1.46411,0.0767662,-0.107835,-1.43306,0.10781,-0.0767914,-1.43306,0.0767662,0.0767964,-1.46411,0.10781,0.0767964,-1.43306,0.0767662,0.10784,-1.43306,-0.0768211,0.10784,-1.43306,0.0974402,0.13686,-1.16341,0.136838,0.0974616,-1.16341,-0.0974789,0.13686,-1.16341,-0.136877,0.0974616,-1.16341,-0.107865,0.0767964,-1.43306,-0.136877,-0.0974582,-1.16341,-0.0974789,-0.136856,-1.16341,0.0974402,-0.136856,-1.16341,0.136838,-0.0974582,-1.16341};
GLbyte burka_arm_normals[] = {-45,-114,34,-43,-43,111,-114,-45,34,-43,43,111,-45,114,34,-114,45,34,43,-43,111,45,-114,34,114,-45,34,43,43,111,114,45,34,45,114,34,-47,-116,-21,-116,-47,-21,-47,116,-21,47,116,-21,47,-116,-21,116,-47,-21,116,47,-21,-116,47,-21,-43,-43,-111,-109,-42,-51,-42,-109,-51,-43,43,-111,43,-43,-111,42,-109,-51,109,-42,-51,43,43,-111,109,42,-51,42,109,-51,-42,109,-51,49,116,-16,116,49,-16,-49,116,-16,-116,49,-16,-109,42,-51,-116,-49,-16,-49,-116,-16,49,-116,-16,116,-49,-16};
GLubyte burka_arm_colors[] = {69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,253,179,177,253,179,177,253,179,177,253,179,177,253,179,177,253,179,177,253,179,177,253,179,177,253,179,177,253,179,177,253,179,177,253,179,177,253,179,177,253,179,177,253,179,177,253,179,177,253,179,177,253,179,177,253,179,177,253,179,177};
const GLubyte burka_arm_indices[] = {10,17,18,1,9,3,5,13,2,4,15,14,11,3,9,0,1,2,3,4,5,6,7,8,9,10,11,18,11,10,12,2,13,0,6,1,14,5,4,8,9,6,17,7,16,5,1,3,0,16,7,20,22,21,21,23,20,25,20,24,24,23,27,24,26,25,28,24,27,27,29,28,30,27,23,28,31,32,33,29,30,30,34,33,21,34,35,36,22,37,37,25,38,26,38,25,32,26,28,23,35,30,10,8,17,1,6,9,5,19,13,4,11,15,11,4,3,18,15,11,12,0,2,0,7,6,14,19,5,8,10,9,17,8,7,5,2,1,0,12,16,21,35,23,25,22,20,24,20,23,28,26,24,30,29,27,28,29,31,33,31,29,30,35,34,21,36,34,36,21,22,37,22,25,26,39,38,32,39,26};
const GLsizeiptr burka_arm_numind = 180;
const GLsizeiptr burka_arm_numvert = 40;

void register_burka_arm()
{
    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].vid, burka_arm_vertices, sizeof(burka_arm_vertices), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].nid, burka_arm_normals, sizeof(burka_arm_normals), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].cid, burka_arm_colors, sizeof(burka_arm_colors), GL_STATIC_DRAW);
    esBind(GL_ELEMENT_ARRAY_BUFFER, &esModelArray[esModelArray_index].iid, burka_arm_indices, sizeof(burka_arm_indices), GL_STATIC_DRAW);
    esModelArray[esModelArray_index].itp = GL_UNSIGNED_BYTE;
    esModelArray[esModelArray_index].ni = burka_arm_numind;
    esModelArray[esModelArray_index].nv = burka_arm_numvert;
    esModelArray[esModelArray_index].pos = (vec){-1.60933e-06, 8.9407e-08, -0.57028};
    esModelArray[esModelArray_index].rad = 0.893827;
    esModelArray[esModelArray_index].rsq = 0.798926;
    esModelArray[esModelArray_index].vertices = burka_arm_vertices;
    esModelArray[esModelArray_index].normals = burka_arm_normals;
    esModelArray[esModelArray_index].colors = burka_arm_colors;
    esModelArray_index++;
}

#endif
