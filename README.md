# Liskov Substitution Principle

Liskov Substitution Principle (LSP) – принцип замещения (функции, которые используют указатели на базовые классы, должны иметь возможность использовать объекты производных классов, не зная об их конкретных типах. Для создания взаимозаменяемых частей эти части должны соответствовать контракту, который позволяет заменять эти части друг другом. Этот принцип на самом деле говорит про наследование, о том, как правильно наследоваться, и при этом как правильно абстрагироваться.

Проблемы:
1.Проверка абстракции на конкретный тип
2.Ошибочное наследование. Нарушение контракта при реализации интерфейса.
В результате мы должны вставлять костыль и обратно уменьшать уровень абстракции.

=========================================================

практические задания:

1. Напишите программу для расчёта оплаты за электроэнергию. Создайте базовый класс для всех типов счетчиков электроэнергии, имеющий метод для вычисления стоимости потребленной электроэнергии. Реализуйте несколько подклассов счетчиков, например, обычный, двухтарифный, многотарифный и т.д. Переопределите метод для каждого подкласса так, чтобы он корректно вычислял стоимость в соответствии с тарифами. Создайте вектор указателей на объекты базового класса и заполните его объектами каждого из подклассов. Напишите функцию для вывода стоимости потребленной электроэнергии для каждого счетчика.

2. Напишите программу для работы с базой данных сотрудников. Создайте базовый класс для всех сотрудников, имеющий методы для получения их данных и вывода информации. Реализуйте несколько подклассов сотрудников, например, менеджер, инженер, бухгалтер и т.д. Для каждого подкласса переопределите методы базового класса так, чтобы они выводили соответствующую информацию о сотруднике. Создайте вектор указателей на объекты базового класса и заполните его объектами каждого из подклассов. Напишите функцию для вывода информации о каждом сотруднике.
