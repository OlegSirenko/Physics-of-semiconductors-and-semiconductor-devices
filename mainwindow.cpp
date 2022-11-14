#include "mainwindow.h"
#include <stdio.h>
#include <math.h>
#include "./ui_mainwindow.h"
#include "graph_window.h"
#include "qmovie.h"


MainWindow::MainWindow(QWidget *parent) // объявление родительского класса
    : QMainWindow(parent)  // наследование из класса QMainWindow библиотеки Qt
    , ui(new Ui::MainWindow)  // Объявляем User interface для класса MainWindow
{
    ui->setupUi(this);  // создание user_interface для класса MainWindow

    QMovie *movie = new QMovie(":/Sinus.gif"); // создаем анимацию синуса

    ui->label_6->setMovie(movie); // указываем, что анимация будет проигрываться в поле label_6

    movie->start(); // начинаем анимацию
    ui->pushButton->setVisible(true);

    QPixmap pixmap(":/logo.jpg");
    ui->label_7->setPixmap(pixmap);
    ui->label_7->setMask(pixmap.mask());

}


MainWindow::~MainWindow() // деструктор
{
    delete ui; //  удаляем user_interface из оперативной памяти
}


void MainWindow::on_pushButton_clicked() // метод при нажатии на кнопку "Нарисовать график"
{
    Graph_window graph;  // объявляем объект класса Graph_window
    graph.setWindowTitle("Просмотр графика");
    //graph.setModal(true); // объявляем своство диалогового окна с графиком, как модальное
    /// P.s. модальное окно -- окно блокирующее родительское, т.е. MainWindow будет неактивно пока мы не закроем окно с графиком
    graph.exec(); // отображаем окно с графиком
}


void MainWindow::on_pushButton_2_clicked() // метод при нажатии на кнопку "Выход"
{
    this->close(); // закрыть окно
    /// P.s. можно спокойно вызывать деструктор, но тогда операционная система будет думать, что приложение крашнулось
    /// метод close полностью последовательно выгружает из оперативной памяти все элементы приложения.
}




