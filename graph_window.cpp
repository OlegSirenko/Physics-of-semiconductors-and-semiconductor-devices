#include "graph_window.h"
#include "ui_graph_window.h"
#include <QValueAxis>
#include <math.h>
#include <utilities.h>
#include <QInputDialog>
#include <QFile>
#include <QTextStream>

Graph_window::Graph_window(QWidget *parent) : //
    QDialog(parent), //
    ui(new Ui::Graph_window) // объявляем user_interface для класса Graph_window
{
    ui->setupUi(this); // создание user_interface для класса Graph_window

    QLineSeries *series = new QLineSeries(); // создаем новый объект класса QLineSeries (график который соеденяет точки прямой)
    QInputDialog qDialog ;

    QStringList items;
    items << QString("Лабораторная работа 1, таблица 1 - первое измерение");
    items << QString("Лабораторная работа 1, таблица 1 - второе измерение");
    items << QString("Лабораторная работа 1, таблица 2");
    items << QString("Лабораторная работа 1, таблица 3");
    qDialog.setFixedSize(500, 200);
    qDialog.setOptions(QInputDialog::UseListViewForComboBoxItems);
    qDialog.setComboBoxItems(items);
    qDialog.setWindowTitle("Choose action");
    connect(&qDialog, SIGNAL(textValueChanged(const QString &)), this, SLOT(onCompute(const QString &)));
    qDialog.exec();

    qDebug()<<text;
    if (text.isEmpty()){
        for (int i=0; i<=10000; i++){  // здесь типо функция, которая читает из файла значения
            int y   = 180*sin(i)/3.14;
            *series<<QPointF(i,y); //    другой способ добавлять точки в объект графика.
        }
    }

    QChart *chart = new QChart();  // объявляем объект класса QChart
    chart->setTitle("Измерение зависимости напряжения от ширины щели d"); // здесь вводим название графика
    chart->legend()->hide(); // прячем легенду, чтобы не мешалось
    QValueAxis *axisX = new QValueAxis; // создаем оси
    QValueAxis *axisY = new QValueAxis;
    QFile file("/home/tehnokrat/Documents/BSU/laba4/Измерение зависимости напряжения от ширины щели d.txt");

    if (text == "1"){
        chart->setTitle("Измерение зависимости напряжения от ширины щели d"); // здесь вводим название графика
        qDebug()<<"Start first lab";
        QFile file("/home/tehnokrat/Documents/BSU/laba4/Измерение зависимости напряжения от ширины щели d.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           qDebug()<<"ERROR READING FILE!";

        QTextStream in(&file);
        int i = 0;
        while(!in.atEnd()){
            i++;
            QString line = in.readLine();
            QStringList fields = line.split(" ");
            qDebug()<<fields[0].toFloat()<<fields[1].toFloat();
            series->append(fields[0].toFloat(), fields[1].toFloat());
        }
        file.close();
        axisX->setTickCount(i);
        axisY->setTickCount(i);
        axisY->setTitleText("U");
        axisX->setTitleText("деление барабана");
        axisX->setLabelFormat("%.0f"); // то, с какой точностью будет отображаться
        axisY->setLabelFormat("%.0f");
    }
    if (text == "1_1"){
        QFile file("/home/tehnokrat/Documents/BSU/laba4/Спектральная зависимость фотопроводимости.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           qDebug()<<"ERROR READING FILE!";

        QTextStream in(&file);
        int i = 0;
        while(!in.atEnd()){
            i++;
            QString line = in.readLine();
            QStringList fields = line.split(" ");
            qDebug()<<fields[0].toFloat()<<fields[1].toFloat();
            series->append(fields[0].toFloat(), fields[1].toFloat());
        }
        file.close();

        axisX->setLabelFormat("%.5f"); // то, с какой точностью будет отображаться
        axisY->setLabelFormat("%.5f");
        //axisX->setRange(1.3, 3); // ставим промежутки для отображения
        //axisY->setRange(0, 1.3);
        axisX->setTickCount(i);
        axisX->setTickInterval(0.09);
        axisY->setTickInterval(0.03);
        chart->setTitle("Измерение зависимости напряжения от ширины щели d (Второе измерение)"); // здесь вводим название графика
    }
    if (text == "2"){
        QFile file("/home/tehnokrat/Documents/BSU/laba4/Спектральная зависимость фотопроводимости.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           qDebug()<<"ERROR READING FILE!";

        QTextStream in(&file);
        int i = 0;
        while(!in.atEnd()){
            i++;
            QString line = in.readLine();
            QStringList fields = line.split(" ");
            qDebug()<<fields[0].toFloat()<<fields[1].toFloat();
            series->append(fields[0].toFloat(), fields[1].toFloat());
        }
        file.close();

        axisX->setLabelFormat("%.5f"); // то, с какой точностью будет отображаться
        axisY->setLabelFormat("%.5f");
        //axisX->setRange(1.3, 3); // ставим промежутки для отображения
        //axisY->setRange(0, 1.3);
        axisX->setTickCount(i);
        axisX->setTickInterval(0.09);
        axisY->setTickInterval(0.03);
        chart->setTitle("Спектральная зависимость фотопроводимости"); // здесь вводим название графика
    }
    if (text == "3"){
        qDebug()<<"Starting 3";
        QFile file("/home/tehnokrat/Documents/BSU/laba4/result.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           qDebug()<<"ERROR READING FILE!";

        QTextStream in(&file);
        int i = 0;
        while(!in.atEnd()){
            i++;
            QString line = in.readLine();
            QStringList fields = line.split(" ");
            qDebug()<<fields[0].toFloat()<<fields[1].toFloat();
            series->append(fields[0].toFloat(), fields[1].toFloat());
        }
        file.close();
        axisX->setTickCount(i);
        axisY->setTickCount(i);
        axisX->setLabelFormat("%.1f"); // то, с какой точностью будет отображаться
        axisY->setLabelFormat("%.1f");
        chart->setTitle("Спектральная зависимость фотопроводимости 2"); // здесь вводим название графика
    }

    axisY->setLineVisible();
    axisY->setLabelsFont(QFont("Arial", 9));

    axisX->setLineVisible();
    axisX->setLabelsFont(QFont("Arial", 9));
    axisX->setLabelsAngle(90);

    chart->addAxis(axisX, Qt::AlignBottom);  // фактически верстка, т.е. ось Х внизу, т.е. горизонтально
    chart->addAxis(axisY, Qt::AlignLeft); // ось У слева т.е. вертикально слева

    chart->addSeries(series);
    series->attachAxis(axisX); // присоеденяем оси к графику
    series->attachAxis(axisY); //

    QChartView *chartView = new QChartView(chart);  // объявляем объект класса QChartView
    chartView->setRenderHint(QPainter::Antialiasing); // начинаем создавать изображение
    chartView->setGeometry(0,0,890,800);
    chartView->setParent(ui->horizontalFrame); // родительский класс у графика -- область на экране -- horizontalFrame.
}

Graph_window::~Graph_window() // деструктор (знаем с первого сема, да ведь?)
{
    delete ui; // удаляем user_interface из оперативки
}

void Graph_window::on_pushButton_clicked() // закрытие окна на нажатие клавиши ОК
{
    this->close(); // то же самое, что и в MainWindow
}


void Graph_window::onCompute(const QString result)
{
    qDebug()<<result;
    if (result == "Лабораторная работа 1, таблица 1 - первое измерение"){
        text = "1";
    }
    if (result == "Лабораторная работа 1, таблица 1 - второе измерение"){
        text="1_1";
    }
    if (result == "Лабораторная работа 1, таблица 2"){
        text="2";
    }
    if (result == "Лабораторная работа 1, таблица 3"){
        text="3";
    }
}
