Cpp
#include "cpp-24-25-string.hpp"
#include <cstring> // Для strlen и memcpy

// Вспомогательный метод для выделения памяти
void String::Allocate(size_t newCapacity) {
    char* newData = new char[newCapacity + 1]; // +1 для нуль-терминатора
    if (data1_) {
        std::memcpy(newData, data1_, size1_);
        delete[] data1_;
    }
    data1_ = newData;
    capacity_ = newCapacity;
    data1_[size1_] = '0'; // Обязательно добавляем нуль-терминатор
}

// Конструктор по умолчанию
String::String() : data1_(nullptr), size1_(0), capacity_(0) {}

// Конструктор с размером и символом
String::String(size_t size1, char character) : size1_(size1), capacity_(size1) {
    data1_ = new char[capacity_ + 1];
    std::memset(data1_, character, size1_);
    data1_[size1_] = '0'; // Нуль-терминатор
}

// Конструктор от const char*
String::String(const char* str) : size1_(strlen(str)), capacity_(size1_) {
    data1_ = new char[capacity_ + 1];
    std::memcpy(data1_, str, size1_);
    data1_[size1_] = '0'; // Нуль-терминатор
}

// Конструктор копирования
String::String(const String& other) : size1_(other.size1_), capacity_(other.capacity_) {
    data1_ = new char[capacity_ + 1];
    std::memcpy(data1_, other.data1_, size1_);
    data1_[size1_] = '0'; // Нуль-терминатор
}

// Оператор присваивания
String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] data1_; // Освобождаем старую память
        size1_ = other.size1_;
        capacity_ = other.capacity_;
        data1_ = new char[capacity_ + 1];
        std::memcpy(data1_, other.data1_, size1_);
        data1_[size1_] = '0'; // Нуль-терминатор
    }
    return *this;
}

// Деструктор
String::~String() {
    delete[] data1_;
}

// Метод Clear()
void String::Clear() {
    size1_ = 0;
}
// Метод PushBack()
void String::PushBack(char character) {
    if (size1_ >= capacity_) {
        Reserve(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    data1_[size1_++] = character;
    data1_[size1_] = '0'; // Нуль-терминатор
}

// Метод PopBack()
void String::PopBack() {
    if (size1_ > 0) {
        --size1_;
        data1_[size1_] = '0'; // Нуль-терминатор
    }
}

// Метод Resize()
void String::Resize(size_t newSize) {
    if (newSize > capacity_) {
        Reserve(newSize);
    }
    size1_ = newSize;
    data1_[size1_] = '0'; // Нуль-терминатор
}

// Метод Resize с заполнением
void String::Resize(size_t newSize, char character) {
    if (newSize > capacity_) {
        Reserve(newSize);
    }
    
    if (newSize > size1_) {
        std::memset(data1_ + size1_, character, newSize - size1_);
    }
    
    size1_ = newSize;
    data1_[size1_] = '0'; // Нуль-терминатор
}

// Метод Reserve()
void String::Reserve(size_t newCap) {
    if (newCap > capacity_) {
        Allocate(newCap);
    }
}

// Метод ShrinkToFit()
void String::ShrinkToFit() {
    if (capacity_ > size1_) {
        Allocate(size1_);
    }
}

// Метод Swap()
void String::Swap(String& other) {
    std::swap(data1_, other.data1_);
    std::swap(size1_, other.size1_);
    std::swap(capacity_, other.capacity_);
}

// Неконстантный оператор доступа по индексу
char& String::operator[](size_t index) {
    return data1_[index];
}

// Константный оператор доступа по индексу
const char& String::operator[](size_t index) const {
    return data1_[index];
}

// Метод Front()
char String::Front() const {
    return data1_[0];
}

// Метод Back()
char String::Back() const {
    return data1_[size1_ - 1];
}

// Метод Empty()
bool String::Empty() const {
    return size1_ == 0;
}

// Метод Size()
size_t String::Size() const {
    return size1_;
}

// Метод Capacity()
size_t String::Capacity() const {
    return capacity_;
}

// Метод Data()
const char* String::Data() const {
    return data1_;
}

// Операторы сравнения
bool String::operator<(const String& other) const {
    return std::strcmp(data1_, other.data1_) < 0;
}

bool String::operator>(const String& other) const {
   return std::strcmp(data1_, other.data1_) > 0;
}

bool String::operator<=(const String& other) const {
   return !(*this > other);
}

bool String::operator>=(const String& other) const {
   return !(*this < other);
}

bool String::operator==(const String& other) const {
   return std::strcmp(data1_, other.data1_) == 0;
}

bool String::operator!=(const String& other) const {
   return !(*this == other);
}

// Оператор конкатенации +
String String::operator+(const String& other) const {
   String result(size1_ + other.size1_, ' '); // Создаем строку с достаточным размером
   std::memcpy(result.data1_, data1_, size1_);
   std::memcpy(result.data1_ + size1_, other.data1_, other.size1_);
   result.size1_ = size1_ + other.size1_;
   result.data1_[result.size1_] = '0'; // Нуль-терминатор
   return result;
}

// Оператор +=
String& String::operator+=(const String& other) {
   for (size_t i = 0; i < other.size1_; ++i) {
       PushBack(other[i]);
   }
   return *this;
}

// Оператор умножения на число
String operator*(const String& str, size_t n) {
   if (n == 0) return String(); // Если n == 0 возвращаем пустую строку
   
   String result; 
   for (size_t i = 0; i < n; ++i) {
       result += str; // Используем оператор += для конкатенации
   }
   return result;
}

// Операторы ввода и вывода
std::ostream& operator<<(std::ostream& input, const String& str) {
   input << str.Data();
   return input;
}

std::istream& operator>>(std::istream& output, String& str) {
   char buffer[1024]; // Буфер для ввода строки (можно изменить размер)
   output >> buffer; 
   str = String(buffer); // Используем конструктор от const char*
   return output;
}

// Метод Split()
std::vector<String> String::Split(const String& delim) const {
   std::vector<String> result;
   size_t start = 0, end;

   while ((end = data1_.find(delim.data1_, start)) != std::string::npos) {
       result.push_back(String(data1_.substr(start, end - start).c_str()));
       start = end + delim.size1_;
   }
   result.push_back(String(data1_.substr(start).c_str())); // Последняя часть после последнего делиметра

   return result;
}

// Метод Join()
String String::Join(const std::vector<String>& strings) {
   if (strings.empty()) return String();

   size_t total_length = 0;

   for (const auto& str : strings) {
       total_length += str.Size();
   }

   total_length += strings.size() - 1; // Для разделителей

   String result(total_length, ' '); // Создаем строку с достаточным размером

   size_t pos = 0;

   for (size_t i = 0; i < strings.size(); ++i) {
       for (size_t j = 0; j < strings[i].Size(); ++j) {
           result[pos++] = strings[i][j];
       }
       if (i < strings.size() - 1) { // Не добавляем разделитель после последнего элемента
           result[pos++] = ' '; 
       }
   }

   result.Resize(pos); // Устанавливаем правильный размер

   return result;
}

