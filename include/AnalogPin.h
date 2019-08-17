#ifndef ANALOG_PIN_H
#define ANALOG_PIN_H


class AnalogPin
{

    private:
        int _pin;
    public:        
       // AnalogPin();
        AnalogPin();        
        AnalogPin(int pin, bool write = true);
        // 0 and 1023
        int read();

        const int pin()const { return _pin; }

        //0 to 255
        void write(int value);
};

#endif