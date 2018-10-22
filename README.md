## Лабораторная работа 5

### Теоретическая справка
**Что такое структуры?**
* Структура — это некое объединение различных переменных (даже с разными типами данных), которому можно присвоить имя.
* Например, можно объединить данные об  объекте Дом: город (в котором дом находится), улица, количество квартир, интернет(проведен или нет) и т.д. в одной структуре.

**Для чего они нужны?**
* Структуры полезны, когда нам надо объединить несколько переменных с разными типами под одним именем. Это делает программу более компактной и более гибкой для внесения изменений.
* Также структуры незаменимы, когда необходимо сгруппировать некоторые данные.

**Как использовать, синтаксис**
* Объявление и определение структур
    ```cpp
    struct Student
    {
        std::string Name;
        std::string LastName;
        std::vector<int> Ratings;
    };
    ```
Мы определили структуру с именем `Student`. Она содержит 3 переменные: `Name` типа `std::string`, `LastName` типа `std::string` и `ratings` типа `std::vector<int>`. Эти переменные, которые являются частью структуры, называются членами (или полями). `Student` — это просто объявленная структура, хоть мы и сообщаем компилятору, что она имеет переменные-члены, память под неё сейчас не выделяется.
**Внимание!** Одна из самых простых ошибок в C++ — забыть точку с запятой в конце объявления структуры. Это приведет к ошибке компилятора.
* Чтобы использовать структуру `Student`, мы просто объявим переменную типа `Student`:
    ```cpp
    Student anna;
    ```
* Объявить можно и несколько переменных одной структуры:
    ```cpp
    Student anna;
    Student ivan;
    ```
**Доступ к членам структур**

* Когда мы определяем переменную, такую как `Student anna`, то `anna` ссылается на всю структуру. Для того, чтобы получить доступ к отдельным элементам-полям, используется оператор выбора члена (точка). Ниже приведен пример использования оператора выбора членов для инициализации каждого поля структуры:
    ```cpp
    Student anna;
    anna.Name = "Anna";
    anna.LastName = "Ivanova";
    anna.Ratings = {4, 5, 5, 3};
    ```
* Инициализация структур путем присваивания значений каждому члену по порядку – занятие довольно громоздкое (особенно, если этих членов много), поэтому в C++ есть более быстрый способ инициализации структур — список инициализации. Он позволяет инициализировать некоторые или все члены структуры во время объявления.
    ```cpp
    Student anna = {
        "Anna",
        "Ivanova",
        {4, 5, 5, 3}
    };

    Student ivan = {
        "Ivan",
        "Petrov",
        {4, 5, 5, 3}
    };
    ```
* Переменные-члены структуры работают так же, как и простые переменные, поэтому с ними можно и выполнять обычные операции:
    ```cpp
    std::cout << anna.Name << ", " << anna.LastName << std::endl;
    ```
* [Еще больше примеров практического применения.](https://github.com/bmstu-iu8-cpp/cpp-beginner-2017/tree/master/lab5)

### Задание
Пусть есть структура `Student`
```cpp
struct Student
{
  std::string Name;
  std::string GroupId;
  std::vector<unsigned> Ratings;
  std::vector<std::string> Subjects;
};
```
В поле `Ratings` представлены оценки по соответсвующему предмету из поля `Subjects`.
Предположим есть список студентов `std::vector<Student> students`.
Ваше задание состоит в реализации ряда функций. Все прототипы функций необходимо разместить
в файле header.hpp.
Реазилуйте функции, которые выполяют следующие действия с этим списком:
* отсортируют всех студентов по именам;

Прототип:
```cpp
std::vector<Student> SortByName(std::vector<Student>&)
```
* отсортируют всех студентов по средней оценке;

Прототип:
```cpp
std::vector<Student> SortByRating(std::vector<Student>&)
```
* вернет количество студентов имеющих неудовлетворительную оценку хотя бы по одному предмету;

Прототип:
```cpp
size_t CountTwoness(const std::vector<Student>&)
```
* определит, сколько студентов сдали все экзамены на 5.

Прототип:
```cpp
size_t CountExcellent(const std::vector<Student>&)
```
* создадут массив `std::vector<Student>`, в который войдут студенты имеющие отметку отлично, по предмету "Math";

Прототип:
```cpp
std::vector<Student> VectorMathExcellent(const std::vector<Student>&)
```
* вернет массив уникальных названий групп студентов из списка students

Прототип:
```cpp
std::vector<std::string> GroupsId(const std::vector<Student>&)
```
* сформирует список групп, т.е. создаст массив структур `Group`
```cpp
struct Group
{
    std::string Id;
    std::vector<Student> Students;
};
```

Прототип:
```cpp
std::vector<Group> Groups(const std::vector<Student>&)
```
