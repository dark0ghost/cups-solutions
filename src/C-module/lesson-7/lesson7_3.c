/**
Объявите структуру данных Vector, представляющую собой вектор из трех координат вещественного типа.
Напишите функцию с названием scalar, которая принимает на вход два указателя на вектор и возвращает скалярное произведение векторов вещественного типа.
 **/

struct Vector{
    float x;
    float y;
    float z;
};

float scalar(struct Vector* one,struct Vector* two){
    return one->x*two->x+one->y*two->y+one->z*two->z;
}