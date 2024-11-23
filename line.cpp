#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    int score;
};

bool compareByName(const Student& a, const Student& b) {
    return a.name < b.name;
}

bool compareByScore(const Student& a, const Student& b) {
    return a.score > b.score;
}

void removeStudentByName(std::vector<Student>& students, const std::string& name) {
    students.erase(std::remove_if(students.begin(), students.end(),
                                 [&](const Student& s) { return s.name == name; }), students.end());
}

void removeStudentByScore(std::vector<Student>& students, int score) {
    students.erase(std::remove_if(students.begin(), students.end(),
                                 [&](const Student& s) { return s.score == score; }), students.end());
}

int main() {
    std::vector<Student> students;
    std::vector<Student> sortedByName;
    std::vector<Student> sortedByScore;
    char choice;

    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Ввести данные студента\n";
        std::cout << "2. Вывести записи в порядке ввода\n";
        std::cout << "3. Вывести записи по именам (алфавиту)\n";
        std::cout << "4. Вывести записи по баллам (от больших к меньшим)\n";
        std::cout << "5. Найти студента по имени\n";
        std::cout << "6. Удалить студента\n";
        std::cout << "0. Выход\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                Student student;
                std::cout << "Введите имя студента: ";
                std::cin.ignore();
                std::getline(std::cin, student.name);
                std::cout << "Введите баллы студента: ";
                std::cin >> student.score;
                students.push_back(student);
                sortedByName = students;
                sortedByScore = students;
                break;
            }
            case '2':
                std::cout << "\nЗаписи в порядке ввода:\n";
                for (const auto& student : students) {
                    std::cout << "Имя: " << student.name << ", Баллы: " << student.score << std::endl;
                }
                break;
            case '3':
                std::sort(sortedByName.begin(), sortedByName.end(), compareByName);
                std::cout << "\nЗаписи по именам (алфавиту):\n";
                for (const auto& student : sortedByName) {std::cout << "Имя: " << student.name << ", Баллы: " << student.score << std::endl;
                }
                break;
            case '4':
                std::sort(sortedByScore.begin(), sortedByScore.end(), compareByScore);
                std::cout << "\nЗаписи по баллам (от больших к меньшим):\n";
                for (const auto& student : sortedByScore) {
                    std::cout << "Имя: " << student.name << ", Баллы: " << student.score << std::endl;
                }
                break;
            case '5': {
                std::string searchName;
                std::cout << "Введите имя студента для поиска: ";
                std::cin.ignore();
                std::getline(std::cin, searchName);
                bool found = false;
                for (const auto& student : students) {
                    if (student.name == searchName) {
                        std::cout << "Имя: " << student.name << ", Баллы: " << student.score << std::endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "Студент не найден.\n";
                }
                break;
            }
            case '6': {
                std::cout << "Выберите атрибут для удаления:\n";
                std::cout << "1. Имя\n";
                std::cout << "2. Балл\n";
                int delChoice;
                std::cin >> delChoice;
                if (delChoice == 1) {
                    std::string name;
                    std::cout << "Введите имя студента для удаления: ";
                    std::cin.ignore();
                    std::getline(std::cin, name);
                    removeStudentByName(students, name);
                    sortedByName = students;
                    sortedByScore = students;
                } else if (delChoice == 2) {
                    int score;
                    std::cout << "Введите баллы студента для удаления: ";
                    std::cin >> score;
                    removeStudentByScore(students, score);
                    sortedByName = students;
                    sortedByScore = students;
                } else {
                    std::cout << "Неверный выбор.\n";
                }
                break;
            }
            case '0':
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор.\n";
        }
    } while (choice != '0');

    return 0;
}