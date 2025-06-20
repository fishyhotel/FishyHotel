
#ifndef banana_arm_H
#define banana_arm_H

GLfloat banana_arm_vertices[] = {0.235421,-0.349017,0.103056,-0.150643,-0.00633255,-0.436025,0.211561,0.355872,-0.436025,0.330585,-0.253854,0.103056,0.211561,0.0545679,-0.436025,-0.235395,0.119522,0.198219,0.235421,-0.253854,0.198219,0.235421,0.119522,0.198219,-0.330559,-0.253854,0.103056,-0.211544,0.355872,-0.436025,-0.211544,0.0545679,-0.436025,-0.235395,0.214686,0.103056,0.15066,0.416773,-0.436025,-0.150643,0.416773,-0.436025,-0.235395,-0.349017,0.103056,-0.235395,-0.253854,0.198219,-0.330559,0.119522,0.103056,0.330585,0.119522,0.103056,0.235421,0.214686,0.103056,-0.235421,-0.253851,-1.63218,-0.235421,-0.349014,-1.53702,-0.330585,-0.253851,-1.53702,-0.235421,0.216966,-1.63218,-0.330585,0.216966,-1.53702,-0.235421,0.31213,-1.53702,0.235395,-0.253851,-1.63218,0.330559,-0.253851,-1.53702,0.235395,-0.349014,-1.53702,0.235395,0.216966,-1.63218,0.235395,0.31213,-1.53702,0.330559,0.216966,-1.53702,0.150643,-0.00633061,-0.436025};
GLbyte banana_arm_normals[] = {44,-119,10,-50,-115,-19,113,57,4,115,-51,18,120,-39,-11,-43,43,111,43,-43,111,43,43,111,-115,-51,18,-113,57,4,-120,-39,-11,-46,103,59,43,119,14,-43,119,14,-44,-119,10,-43,-43,111,-116,36,38,116,36,38,46,103,59,-43,-43,-111,-44,-116,-25,-114,-48,-31,-43,43,-111,-113,41,-40,-45,109,-47,43,-43,-111,114,-48,-31,44,-116,-25,43,43,-111,45,109,-47,113,41,-40,50,-115,-19};
GLubyte banana_arm_colors[] = {249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,90,249,219,91,249,219,90};
const GLubyte banana_arm_indices[] = {0,1,31,2,3,4,5,6,7,8,9,10,11,12,13,14,15,8,5,11,16,6,0,3,7,17,18,1,8,10,5,8,15,7,11,5,6,17,7,15,0,6,31,3,0,2,18,17,11,9,16,19,20,21,22,23,24,25,26,27,28,29,30,19,23,22,24,9,13,22,29,28,30,12,2,28,26,25,27,4,31,25,20,19,28,19,22,1,21,20,13,29,24,21,9,23,2,26,30,31,20,27,0,14,1,2,17,3,5,15,6,8,16,9,11,18,12,1,14,8,5,16,8,7,18,11,6,3,17,15,14,0,31,4,3,2,12,18,11,13,9,19,21,23,24,23,9,22,24,29,30,29,12,28,30,26,27,26,4,25,27,20,28,25,19,1,10,21,13,12,29,21,10,9,2,4,26,31,1,20};
const GLsizeiptr banana_arm_numind = 180;
const GLsizeiptr banana_arm_numvert = 32;

void register_banana_arm()
{
    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].vid, banana_arm_vertices, sizeof(banana_arm_vertices), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].nid, banana_arm_normals, sizeof(banana_arm_normals), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].cid, banana_arm_colors, sizeof(banana_arm_colors), GL_STATIC_DRAW);
    esBind(GL_ELEMENT_ARRAY_BUFFER, &esModelArray[esModelArray_index].iid, banana_arm_indices, sizeof(banana_arm_indices), GL_STATIC_DRAW);
    esModelArray[esModelArray_index].itp = GL_UNSIGNED_BYTE;
    esModelArray[esModelArray_index].ni = banana_arm_numind;
    esModelArray[esModelArray_index].nv = banana_arm_numvert;
    esModelArray[esModelArray_index].pos = (vec){0, 0.0338779, -0.716981};
    esModelArray[esModelArray_index].rad = 0.9152;
    esModelArray[esModelArray_index].rsq = 0.837591;
    esModelArray[esModelArray_index].vertices = banana_arm_vertices;
    esModelArray[esModelArray_index].normals = banana_arm_normals;
    esModelArray[esModelArray_index].colors = banana_arm_colors;
    esModelArray_index++;
}

#endif
