/**
Напишите функцию с названием printer. Функция принимает два указателя на целое число. Первый указатель указывает на начало массива, а второй на элемент, следующий за последним элементом массива.
Напишите код, который выводит каждый четвертый элемент массива, если он делится на 4 нацело.
Примените для вывода функцию printf("%ld\n", num), где num - это очередное число для вывода
 **/

void printer(const long int* begin, const long int* end){
    begin += 3;
    for(; begin < end;){
        if(*begin % 4 == 0)
            printf("%ld ",*begin);
        begin += 4;
    }
}