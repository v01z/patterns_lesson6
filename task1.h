#include <vector>

class MenuItem{
protected:
    std::string _name;
    float _price;

    MenuItem(const std::string &name, float price):
        _name{ name }, _price{ price } {};
public:
    virtual const float getPrice() {
       return _price;
    }

    virtual const std::string &getName() const final{
        return _name;
    }

    virtual ~MenuItem(){}
};

class Pancake: public MenuItem{
public:
    Pancake(const std::string &type, float price) :
        MenuItem(type + " pancake", price) {}
};

class Icecream: public MenuItem{
public:
    Icecream(const std::string &type, float price) :
        MenuItem(type + " ice cream", price) {}
};

class Beverage: public MenuItem{
public:
    Beverage(const std::string &name, float price) :
        MenuItem(name, price) {}
};

class CompositeMenuItem: public MenuItem{
private:
    std::vector<MenuItem*> _menuItems;
public:
    // margin - дополнительная наценка к стоимости в завимости
    // от  ̶ж̶а̶д̶н̶о̶с̶т̶и̶ ̶в̶л̶а̶д̶е̶л̶ь̶ц̶а̶ ̶к̶а̶ф̶е̶ времени суток (ужин - дороже)
    CompositeMenuItem(const std::string &meal, float margin):
            MenuItem(meal, margin) {}

    void addMenuItem(MenuItem* menuItem){
        if(menuItem != nullptr)
            _menuItems.push_back(menuItem);
    }

    virtual const float getPrice() override{
        for (const auto &menuItem : _menuItems)
           _price += menuItem->getPrice();

        return _price;
    }

    const std::vector<MenuItem*> &getMenuItems() const{
        return _menuItems;
    }

    virtual ~CompositeMenuItem(){
        for (const auto &menuItem : _menuItems)
            delete menuItem;
    }
};

CompositeMenuItem* createBreakfast(){
    CompositeMenuItem * breakfast{ new CompositeMenuItem ("Breakfast", 0.01f) };

    breakfast->addMenuItem(new Pancake("Morning", 240.00f));
    breakfast->addMenuItem(new Icecream("Berry", 260.00f));
    breakfast->addMenuItem(new Beverage("Coffee", 50.00f));

    return breakfast;
}

CompositeMenuItem* createLunch(){
    CompositeMenuItem* lunch{ new CompositeMenuItem("Lunch", 0.10f) };

    lunch->addMenuItem(new Pancake("Lunch", 280.00f));
    lunch->addMenuItem(new Pancake("Mushroom", 220.00f));
    lunch->addMenuItem(new Icecream("Vanilla", 180.00f));
    lunch->addMenuItem(new Beverage("Tea", 50.00f));

    return lunch;
}

CompositeMenuItem* createDinner(){
    CompositeMenuItem* dinner{ new CompositeMenuItem("Dinner", 0.35f) };

    dinner->addMenuItem(new Pancake("Chocolate", 260.00f));
    dinner->addMenuItem(new Beverage("Pepsi", 120.00f));

    return dinner;
}

