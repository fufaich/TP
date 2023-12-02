#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Функция для разделения текста на предложения
void printSentencesWithWord(const std::string& text, const std::string& wordToFind) {
    std::istringstream iss(text);
    std::string sentence;

    while (std::getline(iss, sentence, '.')) {
        // Проверяем текущее предложение на наличие заданного слова
        if (sentence.find(wordToFind) != std::string::npos) {
            std::cout << sentence << '.' << std::endl;
        }
    }
}

int partTwo() {
    std::string wordToFind;

    std::cout << "Enter the aim word: ";
    std::cin >> wordToFind;

    std::ifstream file("file.txt"); // Открываем файл для чтения

    if (!file.is_open()) {
        std::cout << "Error open file." << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf(); // Считываем содержимое файла в строковый поток

    std::string fileContent = buffer.str(); // Получаем содержимое файла как строку
    file.close(); // Закрываем файл

    // Выводим предложения с заданным словом
    printSentencesWithWord(fileContent, wordToFind);

    return 0;
}