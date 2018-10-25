// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>

#include <header.hpp>
class TestLab : public ::testing::Test
{
protected:
    void SetUp() {
        std::vector<unsigned> Ratings1 = { 3, 5, 4, 5, 5, 4 };
        std::vector<unsigned> Ratings2 = { 5, 5, 5, 5, 5, 5 };
        std::vector<unsigned> Ratings3 = { 3, 3, 3, 4, 3, 3 };
        std::vector<unsigned> Ratings4 = { 4, 4, 5, 4, 4, 4 };
        std::vector<unsigned> Ratings5 = { 4, 4, 5, 5, 5, 4 };
        std::vector<unsigned> Ratings6 = { 5, 5, 5, 5, 5, 5 };
        std::vector<unsigned> Ratings7 = { 3, 5, 3, 3, 5, 4 };
        std::vector<unsigned> Ratings8 = { 5, 4, 5, 4, 5, 4 };
        std::vector<unsigned> Ratings9 = { 5, 2, 5, 4, 5, 4 };
        std::vector<unsigned> Ratings10 = { 2, 2, 5, 4, 5, 4 };
        std::vector<std::string> Subjects1 =
        { "Math", "Physics", "IT", "English", "Ecology", "Literature" };
        std::vector<std::string> Subjects2 =
        { "Physics", "Russian", "Politology", "Biology", "History" };
        std::vector<std::string> Subjects3 =
        { "IT", "English", "Math", "PE", "Electronic", "IT" };
        Student student1 = { "Asya", "iu8-34", Ratings2, Subjects1 }; // 30
        Student student2 = { "Romka", "iu8-34", Ratings6, Subjects1 }; // 30
        Student student3 = { "Petya", "iu9-54", Ratings1, Subjects3 }; // 26
        Student student4 = { "Vasya", "iu9-54", Ratings7, Subjects3 }; // 23
        Student student5 = { "Alice", "iu9-54", Ratings8, Subjects3 }; // 27
        Student student6 = { "Anton", "ibm3-12", Ratings3, Subjects2 }; // 19
        Student student7 = { "Robert", "ibm3-12", Ratings4, Subjects2 }; // 25
        Student student8 = { "Vanya", "ibm3-12", Ratings5, Subjects2 }; // 27
        Student student9 = { "Uma", "ibm3-12", Ratings9, Subjects2 }; // 25
        Student student10 = { "Inga", "ibm3-12", Ratings10, Subjects2 }; // 22
    }
};
// Сортировка студентов по именам
TEST_F(TestLab, SortByName) {
    // базовый сценарий
    std::vector<Student> students =
    { student1, student2, student3, student4,
    student5, student6, student7, student8 };
    std::vector<Student> result =
    { student5, student6, student1, student8,
    student4, student3, student7, student2 };
    SortByName(students);
    EXPECT_EQ(students, result);
    // пустой вектор
    students = { };
    result = { };
    SortByName(students);
    EXPECT_EQ(students, result);
    // вектор, состоящий из имен, начинающихся на одну букву
    students = { student1, student6, student5 };
    result = { student5, student6, student1 };
    SortByName(students);
    EXPECT_EQ(students, result);
    // вектор из одного элемента
    students = { student4 };
    result = { student4 };
    SortByName(students);
    EXPECT_EQ(students, result);
}
// Сортировка всех студентов по средней оценке
TEST_F(TestLab, SortByRating) {
    // базовый сценарий
    std::vector<Student> students =
    { student1, student2, student3, student4, student5,
    student6, student7, student8 };
    std::vector<Student> result =
    { student1, student2, student5, student8,
    student3, student7, student4, student6 };
    SortByRating(students);
    EXPECT_EQ(students, result);
    // вектор, состоящий из ребят с одинаковым рейтингом
    students = { student8, student5 };
    result = { student8, student5 };
    SortByRating(students);
    EXPECT_EQ(students, result);
    // вектор из одного элемента
    students = { student4 };
    result = { student4 };
    SortByRating(students);
    EXPECT_EQ(students, result);
    // пустой вектор
    students = { };
    result = { };
    SortByRating(students);
    EXPECT_EQ(students, result);
}
// Возвращаем количество двоечников
TEST_F(TestLab, CountTwoness) {
    // базовый сценарий
    std::vector<Student> students =
    { student1, student2, student3, student4, student5,
    student6, student10, student7, student8, student9 };
    size_t count = 0;
    count = CountTwoness(students);
    EXPECT_EQ(2, count);
    // без двоечников
    students =
    { student1, student2, student3, student4,
    student5, student6, student7, student8 };
    count = CountTwoness(students);
    EXPECT_EQ(0, count);
    // вектор с одним элементом
    students = { student9 };
    count = CountTwoness(students);
    EXPECT_EQ(1, count);
    // пустой вектор
    students = { };
    result = { };
    count = CountTwoness(students);
    EXPECT_EQ(0, count);
}
// Количество отличников
TEST_F(TestLab, CountExcellent) {
    // базовый сценарий
    std::vector<Student> students =
    { student1, student2, student3, student4, student5,
    student6, student10, student7, student8, student9 };
    size_t count = 0;
    count = CountExcellent(students);
    EXPECT_EQ(2, count);
    // без отличников
    students =
    { student9, student10, student3, student4,
    student5, student6, student7, student8 };
    count = CountExcellent(students);
    EXPECT_EQ(0, count);
    // вектор с одним элементом
    students = { student1 };
    count = CountExcellent(students);
    EXPECT_EQ(1, count);
    // пустой вектор
    students = { };
    result = { };
    count = CountExcellent(students);
    EXPECT_EQ(0, count);
}
// Создаем массив тех, кто получил по математике 5
TEST_F(TestLab, VectorMathExcellent) {
    // базовый сценарий
    std::vector<Student> students =
    { student1, student2, student3, student4, student5,
    student6, student10, student7, student8, student9 };
    std::vector<Student> result = { student1, student2, student5 };
    students = VectorMathExcellent(students);
    EXPECT_EQ(students, result);
    // без отличников по математике
    students = { student9, student10, student3, student4,
    student6, student7, student8 };
    result = { };
    students = VectorMathExcellent(students);
    EXPECT_EQ(students, result);
    // без ребят с предметом математика
    students = { student6, student7, student8, student9, student10 };
    result = { };
    students = VectorMathExcellent(students);
    EXPECT_EQ(students, result);
    // вектор с одним элементом
    students = { student1 };
    result = { student1 };
    students = VectorMathExcellent(students);
    EXPECT_EQ(students, result);
    // пустой вектор
    students = { };
    result = { };
    students = VectorMathExcellent(students);
    EXPECT_EQ(students, result);
}
// Массив уникальных названий групп
TEST_F(TestLab, GroupsId) {
    // базовый сценарий
    std::vector<Student> students =
    { student1, student2, student3, student4, student5,
    student6, student10, student7, student8, student9 };
    std::vector<std::string> result = { "iu8-34", "iu9-54", "ibm3-12"};
    std::vector<std::string> groups = GroupsId(students);
    EXPECT_EQ(result, groups);
    // все из одной группы
    students = { student3, student4, student5 };
    result = { "iu9-54" };
    groups = GroupsId(students);
    EXPECT_EQ(result, groups);
    // вектор с одним элементом
    students = { student1 };
    result = { "iu8-34" };
    groups = GroupsId(students);
    EXPECT_EQ(result, groups);
    // пустой вектор
    students = { };
    result = { };
    groups = GroupsId(students);
    EXPECT_EQ(result, groups);
}
// массив структур Group
TEST_F(TestLab, Groups) {
    // базовый сценарий
    std::vector<Student> students =
    { student1, student2, student3, student4, student5,
    student6, student10, student7, student8, student9 };
    std::vector<Student> students1group = { student1, student2 };
    std::vector<Student> students2group = { student3, student4, student5 };
    std::vector<Student> students3group = { student6, student7, student8,
    student9, student10 };
    Group group1 = { "iu8-34", students1group };
    Group group2 = { "iu9-54", students2group };
    Group group3 = { "ibm3-12", students3group };
    std::vector<Group> result = { group1, group2, group3 };
    std::vector<Group> groups = VectorGroups(students);
    EXPECT_EQ(result, groups);
    // все из одной группы
    students = { student3, student4, student5 };
    students2group = { student3, student4, student5 };
    group2 = { "iu9-54", students2group };
    result = { group2 };
    groups = VectorGroups(students);
    EXPECT_EQ(result, groups);
    // вектор с одним элементом
    students = { student1 };
    students1group = { student1 };
    group1 = { "iu8-34", students1group };
    result = { group1 };
    groups = VectorGroups(students);
    EXPECT_EQ(result, groups);
    // пустой вектор
    students = { };
    result = { };
    groups = VectorGroups(students);
    EXPECT_EQ(result, groups);
}
