#include <iostream>
#include "task1.h"
#include "task2.h"
#include "task3.h"


int main() {

    //*************** task1 ******************
    std::cout << "\n########## task 1 ##########\n";

    auto showMealInfo { [](CompositeMenuItem* meal) {
        std::printf("\n****** %s *****\n", meal->getName().c_str());

        for (const auto &menuItem : meal->getMenuItems())
            std::printf ("%s: %.2f\n",
                menuItem->getName().c_str(), menuItem->getPrice());

        std::puts("---------------");
        std::printf("Full price is: %.2f\n", meal->getPrice());
    }};

    CompositeMenuItem *breakfast { createBreakfast() };
    showMealInfo(breakfast);

    CompositeMenuItem *lunch{ createLunch() };
    showMealInfo(lunch);

    delete breakfast;
    delete lunch;

    //*************** task2 ******************
    std::cout << "\n########## task 2 ##########\n";

    Mediator* mediator { new Mediator };

    Calendar calendar(mediator);
    Coffee coffee(mediator);
    TeaPot teaPot(mediator);
    Alarm alarm(mediator);

    mediator->init(&calendar, &coffee, &teaPot, &alarm);

    //Будильник звонит в будний день
    alarm.doAlarm();

    //Наступили выходные
    calendar.setCurrentDay(false);
    alarm.doAlarm();

    delete mediator;


    //*************** task3 ******************
    std::cout << "\n########## task 3 ##########\n";

    BitmapImage bitmapImage;
    bitmapImage.doImage("picture.bmp");

    VectorImage vectorImage;
    vectorImage.doImage("picture.svg");

    return 0;
}
