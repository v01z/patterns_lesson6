class Mediator;

class Thing{
protected:
    Mediator* _mediator;
public:
    Thing(Mediator* mediator): _mediator { mediator } {}

    virtual void onEvent();
};

class Calendar: public Thing{
private:
    bool _isWorkDay;
public:
    Calendar(Mediator* mediator): Thing(mediator),  _isWorkDay{ true } {}

    // Упрощенная реализация, должен возвращать true, если рабочий день.
    const bool getCurrentDay() const{
        return _isWorkDay;
    }

    //Задать календарю день: рабочий, либо выходной
    void setCurrentDay(bool isWorkDay = true){
        onEvent();

       _isWorkDay = isWorkDay;
    }
};

class Coffee: public Thing{
public:
    Coffee(Mediator* mediator): Thing(mediator) {}

    void doCoffee(){
        onEvent();
        std::cout << "Starting coffee." << std::endl;
    }
};

class TeaPot: public Thing{
public:
    TeaPot(Mediator* mediator) : Thing(mediator) {}

    void doTea(){
        onEvent();
        std::cout << "Starting tea." << std::endl;
    }
};

class Alarm: public Thing{
public:
    Alarm(Mediator* mediator): Thing(mediator) {}

    void doAlarm(){
        onEvent();

        std::cout << "Rise and shine, Mr. Freeman" << std::endl;
    }
};

class Mediator{
private:
    Calendar* _calendar;
    Coffee* _coffee;
    TeaPot* _teapot;
    Alarm* _alarm;
public:
    Mediator(): _calendar{ nullptr },
                _coffee{ nullptr },
                _teapot{ nullptr },
                _alarm{ nullptr }
                {}

    void init (Calendar* calendar, Coffee* coffee,
                TeaPot* teaPot, Alarm* alarm){

        _calendar = calendar;
        _coffee = coffee;
        _teapot = teaPot;
        _alarm = alarm;
    }

    void doAction(Thing* thing){
        if(thing == _calendar)
        {
            std::cout << "\nTime flies so fast..\n";
        }
        else if(thing == _coffee)
        {
            std::cout << "\nMediator got order to make coffee.\n";
        }
        else if (thing == _teapot)
        {
            std::cout << "\nMediator got order to make tea.\n";
        }
        else if (thing == _alarm)
        {
            if (_calendar->getCurrentDay())
            {
                std::cout << "\nToday is workday.";
                _coffee->doCoffee();
            }
            else
            {
                std::cout << "\nToday is holiday.";
                _teapot->doTea();
            }
        }
        else if (thing == _calendar)
        {

        }
    }
};

void Thing::onEvent() {
    _mediator->doAction(this);
}