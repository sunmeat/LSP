#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Order {
public:
    Order(int orderNumber, string orderDate, float orderCost)
        : m_orderNumber(orderNumber), m_orderDate(orderDate), m_orderCost(orderCost)
    {}

    virtual void displayDetails() const {
        cout << "Order #" << m_orderNumber << " was placed on " << m_orderDate
            << " and cost " << m_orderCost << " UAH.\n\n";
    }

    int getOrderNumber() const {
        return m_orderNumber;
    }

    float getOrderCost() const {
        return m_orderCost;
    }

    string getOrderDate() const {
        return m_orderDate;
    }

private:
    int m_orderNumber;
    string m_orderDate;
    float m_orderCost;
};

class OnlineOrder : public Order {
public:
    OnlineOrder(int orderNumber, string orderDate, float orderCost,
        string userEmail, string userName, string userLastName, string userPhone)
        : Order(orderNumber, orderDate, orderCost), m_userEmail(userEmail), m_userName(userName),
        m_userLastName(userLastName), m_userPhone(userPhone)
    {}

    void displayDetails() const override {
        cout << "Online order #" << getOrderNumber() << " was placed by user\n"
            << m_userName << " " << m_userLastName << " (" << m_userEmail << ")"
            << " on " << getOrderDate() << " and cost " << getOrderCost() << " UAH." << endl;
    }

private:
    string m_userEmail;
    string m_userName;
    string m_userLastName;
    string m_userPhone;
};

class StoreOrder : public Order {
public:
    StoreOrder(int orderNumber, string orderDate, float orderCost,
        string storeAddress, string storeName)
        : Order(orderNumber, orderDate, orderCost), m_storeAddress(storeAddress), m_storeName(storeName)
    {}

    void displayDetails() const override {
        cout << "Store order #" << getOrderNumber() << " was placed at\n" << m_storeName
            << " (" << m_storeAddress << ")" << " on " << getOrderDate()
            << " and cost " << getOrderCost() << " UAH." << endl;
    }

private:
    string m_storeAddress;
    string m_storeName;
};

class DiscountedOrder : public Order {
public:
    DiscountedOrder(int orderNumber, string orderDate, float orderCost, float discount)
        : Order(orderNumber, orderDate, orderCost), m_discount(discount)
    {}

    void displayDetails() const override {
        cout << "Discounted order #" << getOrderNumber() << " was placed on\n" << getOrderDate()
            << " and cost " << getOrderCost() << " UAH with a discount of " << m_discount
            << " %." << endl;
    }

private:
    float m_discount;
};

int main() {
    vector<Order*> orders;

    auto onlineOrder = new OnlineOrder(1, "2023-03-28", 100.0, "alex@proton.me", "Oleksandr", "Zahoruiko", "+38-063-03-000-35");
    auto storeOrder = new StoreOrder(2, "2023-03-27", 200.0, "Sadova street 3", "IT Step Store");
    auto discountedOrder = new DiscountedOrder(3, "2023-03-26", 300.0, 0.1);

    orders.push_back(onlineOrder);
    orders.push_back(storeOrder);
    orders.push_back(discountedOrder);

    for (Order* order : orders) {
        order->displayDetails();
        cout << endl;
    }

    delete onlineOrder;
    delete storeOrder;
    delete discountedOrder;
}

/*
Разработать систему для управления заказами в интернет-магазине. В системе
должны быть реализованы следующие классы:

Order - базовый класс для заказа. Содержит общую информацию о заказе
(номер заказа, дата заказа, стоимость заказа и т.д.).

OnlineOrder - класс для интернет-заказа. Дополнительно содержит информацию
об интернет-пользователе, сделавшем заказ (адрес электронной почты, имя,
фамилия, телефон и т.д.).

StoreOrder - класс для заказа в розничном магазине. Дополнительно содержит
информацию о магазине, в котором был сделан заказ (адрес, название и т.д.).

DiscountedOrder - класс для заказа со скидкой. Дополнительно содержит
информацию о размере скидки.

!!!
Необходимо, чтобы система управления заказами удовлетворяла принципу
Liskov Substitution. То есть любой объект типа OnlineOrder, StoreOrder
или DiscountedOrder должен можно использовать вместо объекта типа Order
без изменения поведения системы.

Для этого необходимо создать интерфейс или базовый абстрактный класс,
содержащий общие методы для работы с заказами, которые будут переопределены
в подклассах. Каждый из подклассов должен реализовывать свой собственный
интерфейс, но при этом должен сохраняться контракт, определенный
в базовом классе.

Кроме того, необходимо предусмотреть возможность добавления новых типов
заказов без изменения существующего кода. Для этого можно создать
новый подкласс Order и переопределить его методы в соответствии
с новыми требованиями, не затрагивая при этом существующие классы.
*/

/*
Принцип подстановки Барбары Лисков (Liskov Substitution Principle) гласит,
что если класс A является подклассом класса B, то объекты класса A могут
безопасно использоваться везде, где ожидаются объекты класса B, не нарушая
работоспособности программы.

В примере кода, классы OnlineOrder, StoreOrder и DiscountedOrder являются
подклассами класса Order. Каждый из подклассов переопределяет метод
displayDetails(), который выводит информацию о соответствующем типе заказа.

В основной функции main() создаются объекты каждого из подклассов и
помещаются в вектор типа Order*. Затем в цикле for перебираются элементы
вектора, и для каждого вызывается метод displayDetails(). Таким образом,
в коде выполняется принцип подстановки Барбары Лисков: объекты каждого
из подклассов могут использоваться везде, где ожидаются объекты класса Order,
не нарушая работоспособности программы.
*/

/*
Liskov Substitution Principle (LSP) – принцип замещения (функции,
которые используют указатели на базовые классы, должны иметь возможность
использовать объекты производных классов, не зная об их конкретных типах.
Для создания взаимозаменяемых частей эти части должны соответствовать контракту,
который позволяет заменять эти части друг другом. Этот принцип на самом
деле говорит про наследование, о том, как правильно наследоваться,
и при этом как правильно абстрагироваться.

Проблемы:
1.Проверка абстракции на конкретный тип
2.Ошибочное наследование. Нарушение контракта при реализации интерфейса
(смотрим видео Димы, начиная с 1:38:00).
В результате мы должны вставлять костыль и обратно уменьшать уровень абстракции.
*/

// https://www.youtube.com/watch?v=ph6IIeGTmmw

// another examples: https://gist.github.com/sunmeat/07b01f99bba5b2150a3fc7f53967d6be