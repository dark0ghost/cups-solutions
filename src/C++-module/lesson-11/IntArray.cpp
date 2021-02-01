/*
* Реализуйте класс IntArray, который представляет собой массив типа int. Реализуйте методы, указанные в примере. Конструктор инициализирует массив определенного размера, заполненный значениями по-умолчанию. Метод push_back добавляет в конец массива новый элемент. Метод erase удаляет элемент, находящийся по индексу массива. Методы get и set представляют собой геттер и сеттер. Определите спецификаторы доступа для методов и полей класса. Реализуйте конструктор копирования и деструктор.
*/

class IntArray{

private:

    int* array;
    size_t next_position = 0;
    size_t capacity;

    void rloc(size_t position){
        if (next_position + 1 >= capacity || position > capacity)
            array = static_cast<int *>(realloc(array, (capacity *= 2) * sizeof(int)));
    }
public:

    IntArray(size_t size, int defaultValue){
        array = new int[size]{defaultValue};
        capacity = size;
        next_position = size;
    }

    IntArray(const IntArray& other): next_position(other.next_position),
                                     capacity(other.capacity) {
        array = static_cast<int *>(malloc(capacity * sizeof(int)));
        for(auto i = 0; i < next_position; ++i) {
            array[i] = other.array[i];
        }
    }

    ~IntArray(){
        free(array);
    }

    void push_back(int value){
        rloc(next_position);
        array[next_position] = value;
        next_position++;
    }

    void erase(size_t position){
        for(size_t i = position; i < next_position; i++) {
            array[i] = array[i+1];
        }
        --next_position;
    }

    [[nodiscard]] int get(size_t position) const{
        return array[position];
    }

    void set(size_t position, int value){
        if (position > next_position) {
            rloc(position);
        }
        array[position] = value;
    }

    [[nodiscard]] size_t size() const{
        return next_position;
    }

    int operator[](size_t position) const{
        return this->get(position);
    }
};
