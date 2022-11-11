#include "graph_window.h"
#include "ui_graph_window.h"
#include <QValueAxis>
#include <math.h>
#include <utilities.h>


Graph_window::Graph_window(QWidget *parent) : //
    QDialog(parent), //
    ui(new Ui::Graph_window) // объявляем user_interface для класса Graph_window
{
    ui->setupUi(this); // создание user_interface для класса Graph_window

    QLineSeries *series = new QLineSeries(); // создаем новый объект класса QLineSeries (график который соеденяет точки прямой)

    series->append(0, 0); // добавляем точку 0, 0 чтобы график не масштабировался на первое значение (не обязателно)
    for (int i=0; i<=10000; i++){  // здесь типо функция, которая читает из файла значения
        int y = 180*sin(i)/3.14;
        *series<<QPointF(i,y); //    другой способ добавлять точки в объект графика.
    }
    constexpr qreal marker_size = 20.; // задаем значение размера маркеров точки
    series->setMarkerSize(marker_size); // применяем на графике
    /* тут делаем маркеры для точек, может еще доделаю, но пока что нет :-)
    series->setLightMarker(Utilities::redRectangle(marker_size)); //
    series->setSelectedLightMarker(Utilities::blueTriangle(marker_size));
    */

    QChart *chart = new QChart();  // объявляем объект класса QChart
    chart->setTitle("Лабораторная работа 1"); // здесь вводим название графика
    chart->legend()->hide(); // прячем легенду, чтобы не мешалось
    //chart->createDefaultAxes(); /*  U/alfa   */
    QValueAxis *axisX = new QValueAxis; // созддаем оси
    QValueAxis *axisY = new QValueAxis;
    axisX->setRange(-10, 70); // ставим промежутки для отображения
    axisY->setRange(-70, 70);
    axisX->setTickCount(10); // значение шагов
    axisY->setTickCount(10);
    axisX->setLabelFormat("%.2f"); // то, с какой точностью будет отображаться
    axisY->setLabelFormat("%.2f");
    chart->addAxis(axisX, Qt::AlignBottom);  // фактически верстка, т.е. ось Х внизу, т.е. горизонтально
    chart->addAxis(axisY, Qt::AlignLeft); // ось У слева т.е. вертикально слева
    chart->addSeries(series);
    series->attachAxis(axisX); // присоеденяем оси к графику
    series->attachAxis(axisY); //

    chart->setTitle("FPP_Laba4_graph"); // название графика

    QChartView *chartView = new QChartView(chart);  // объявляем объект класса QChartView
    chartView->setRenderHint(QPainter::Antialiasing); // начинаем создавать изображение
    chartView->setParent(ui->horizontalFrame); // родительский класс у графика -- область на экране -- horizontalFrame.
}

Graph_window::~Graph_window() // деструктор (знаем с первого сема, да ведь?)
{
    delete ui; // удаляем user_interface из оперативки
}

void Graph_window::on_pushButton_clicked() // закрытие окна на нажатие клавиши ОК
{
    Graph_window::close(); // то же самое, что и в MainWindow
}

