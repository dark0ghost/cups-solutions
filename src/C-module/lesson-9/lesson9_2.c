/**
 * Напишите функцию с названием upperCase, которая принимает строку и видоизменяет ее таким образом, что все буквенные символы в ней переводятся в верхний регистр. Функция ничего не возвращает, библиотечные функции использовать запрещено.
 */

void upperCase(char* g){
    int i = 0;
    while (g[i]) {
        char chr = g[i];
        g[i] = toupper(chr);
        i++;
    }
}