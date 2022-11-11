#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])  // основа основ -- главная функция приложения
{
    QApplication a(argc, argv);  // Объявляем приложение, со всеми сопутствующими аргуметами
    MainWindow w; // объявляем объект главного окна
    w.setWindowTitle("Отчеты по лабораторным работам"); // вызываем метод setWindowTitle из объекта w (mainWindow) и устанавливаем ему новое название
    w.show();  // отобразить главное окно.
    return a.exec();  // начинаем выполнение приложения.
}
