#include<iostream>
using namespace std;

class vehicle { // 定义汽车类 
    protected:
        int wheels; // 车轮数
        float weight; // 重量
    public:
        vehicle(int wheels,float weight);
        int get_wheels();
        float get_weight();
        float wheel_load();
        void show();
};

class car: public vehicle{ // 定义小车类 ，TODO：定义不完整，请补充
    int passenger_load; // 载人数
    public:
        car(int wheels,float weight,int passengers=4);
        int get_passengers();
        void show();
};

class truck: public vehicle{ // 定义卡车类，TODO：定义不完整，请补充
    int passenger_load; // 载人数
    float payload; // 载重量
        public:
        truck(int wheels,float weight,int passengers=2,float max_load=24000.00);
        int get_passengers();
        float efficiency();
        void show();
};

vehicle::vehicle(int wheels,float weight) {
    vehicle::wheels=wheels;
    vehicle::weight=weight;
// 注释1 cout << "vehicle类" << endl;
}

int vehicle::get_wheels() {
    return wheels; 
}

float vehicle::get_weight() { // TODO
    return weight;
}
void vehicle::show() {
        cout << "车轮:" << wheels << "个" << endl;
        cout << "重量:" << weight << "公斤" << endl; 
 }
 
car::car(int wheels, float weight, int passengers) : vehicle(wheels,weight){ // TODO：定义不完整，请补充
    passenger_load=passengers;
// 注释2 cout << "car类" << endl;
}

int car::get_passengers () {
    return passenger_load; // TODO
}
void car::show() {	
        cout <<"车型:小车" << endl;
        vehicle::show();
        cout << "载人:" << passenger_load << "人" << endl;
        cout << endl; 
}
truck::truck(int wheels, float weight,int passengers, float max_load): vehicle(wheels,weight){ //
//TODO：定义不完整，请补充
    passenger_load=passengers;
    payload=max_load;
// /注释3 cout << "truck类" << endl;
}
int truck::get_passengers() { // TODO
    return passenger_load;
}
float truck::efficiency() {
    return payload/(payload+weight);
}
void truck::show() {
    cout <<"车型:卡车" << endl;
    vehicle::show ();
    cout << "载人:" << passenger_load << "人" << endl;
    cout << "效率:" << efficiency() << endl;
    cout << endl;
}
int main () {
    car car1(4,2000,5);
    truck tru1(10,8000,3,340000);
    cout << "输出结果" << endl;
    car1.show ();
    tru1.show ();
    return 0; 
}
