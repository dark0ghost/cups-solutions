/**
Напишите функцию с названием push_back. Функция принимает указатель на массив целый чисел, его размер и целое число для добавления в этот массив.

Функция должна добавить число к этому массиву и вернуть указатель на расширенный массив с добавленным числом. Если память невозможно выделить, верните NULL.
 **/


int* push_back(int* array,size_t size,int h){
    int* array_new = malloc((size+1)* sizeof(int));
    if (array_new == NULL){
        free(array_new);
        return NULL;
    }
    for(int i = 0; i< size;i++)
        array_new[i] = array[i];
    array_new[size] = h;
    return array_new;
}