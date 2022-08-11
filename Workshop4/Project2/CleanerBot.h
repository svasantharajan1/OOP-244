#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H
namespace sdds {
    class CleanerBot {
        char* C_location;
        double C_battery;
        int C_brush;
        bool C_active;
        void resetInfo();
    public:
        CleanerBot();
        CleanerBot(const char* location, double battery, int brush, bool active);
        ~CleanerBot();

        CleanerBot& set(const char* location, double battery, int brush, bool active);


        char* getLocation(); 
        double getBattery();
        int getBrush();
        bool getActive();
        bool isValid() const;
        void display() const;
        void deallocate();





    };
    int report(const CleanerBot bot[], short num_robot);
}
#endif