/**
 *Реализуйте класс Distance, который хранит в себе информацию о дистанции в двух целочисленных полях - метрах и километрах. По умолчанию класс хранит в себе нулевые значения. Реализуйте геттеры getMeters и getKilometers для обоих полей, реализуйте аналогичные сеттеры. Реализуйте методы add и sub, которые позволяют сложить или вычесть дистанции и получить новую дистанцию. Количество метров может лежать в диапазоне от 0 до 999 включительно. Расставьте правильно модификаторы доступа.

 */
class  Distance{

private:

    int metr;
    int kilometr;

    void convert_distance() {
        int count = this->metr/1000;
        this->kilometr += count;
        this->metr -=  1000*count;
    }
    void convert_to_metr(){
        this->metr+= this->kilometr*1000;
        this->kilometr=0;
    }
    void check(){
        if (this->metr<0){
            this->metr = 0;
        }
        if (this->kilometr<0){
            this->kilometr = 0;
        }
    }
public:

    Distance(){
        this->kilometr = 0;
        this->metr = 0;
    }

    [[nodiscard]]  int getMeters() const{
        return  this->metr;
    }
    [[nodiscard]]  int getKiloMeters() const{
        return  this->kilometr;
    }
    void setMeters(int m) {
        this->metr = m;
    }
    void setKiloMeters(int k) {
        this->kilometr = k;
    }

    Distance add(Distance l){
        this->metr += l.getMeters();
        this->kilometr += l.getKiloMeters();
        convert_distance();
        check();
        return *this;
    }
    Distance sub(Distance l){
        this->kilometr -= l.getKiloMeters();
        convert_to_metr();
        this->metr -= l.getMeters();
        convert_distance();
        check();
        return *this;
    }
};