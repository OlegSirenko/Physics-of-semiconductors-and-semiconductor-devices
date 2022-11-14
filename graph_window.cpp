#include "graph_window.h"
#include "ui_graph_window.h"
#include <QValueAxis>
#include <math.h>
#include <utilities.h>
#include <QInputDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

Graph_window::Graph_window(QWidget *parent) : //
    QDialog(parent), //
    ui(new Ui::Graph_window) // объявляем user_interface для класса Graph_window
{
    ui->setupUi(this); // создание user_interface для класса Graph_window

    QLineSeries *series = new QLineSeries(); // создаем новый объект класса QLineSeries (график который соеденяет точки прямой)

    QInputDialog qDialog;  // Создаем диалоговое окно с выбором варианта
    QStringList items; // список строк
    items << QString("Лабораторная работа 1, таблица 1"); // добавляем варианты
    items << QString("Лабораторная работа 1, таблица 2"); //
    items << QString("Лабораторная работа 1, таблица 3"); //
    qDialog.setFixedSize(500, 200); // выставляем размер диалогового окна
    qDialog.setOptions(QInputDialog::UseListViewForComboBoxItems); // ставим, что у нас выбор из вариантов (комбо бокс)
    qDialog.setComboBoxItems(items); // добавляем варинаты
    qDialog.setWindowTitle("Выбор лабораторной"); // здесь ставим название диалогового окна
    // ВОТ ЗДЕСЬ БУДЕТ СЛОЖНЕЕ
    // Мы конектим сигнал о изменении выбора, и отдаем результат в функцию OnCompute - переходим на строчку 180
    connect(&qDialog, SIGNAL(textValueChanged(const QString &)), this, SLOT(onCompute(const QString &)));
    // конектим объект кьюДиалог с объектом граф-виндоу (зис)
    qDialog.exec(); // запускаем диалоговое окно



    QValueAxis *axisX = new QValueAxis; // создаем оси
    QValueAxis *axisY = new QValueAxis; //

    QChart *chart = new QChart();  // объявляем объект класса QChart
    chart->setTitle(""); // здесь вводим название графика
    chart->legend()->hide(); // прячем легенду, чтобы не мешалось

    switch (text) {
    case 1:{
        title = "Измерение зависимости напряжения от ширины щели d";
        chart->setTitle("Измерение зависимости напряжения от ширины щели d"); // здесь вводим название графика

        // создаем объект класса QFile и открываем путь
        QFile file("/home/tehnokrat/Documents/BSU/laba4/Измерение зависимости напряжения от ширины щели d.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           qDebug()<<"ERROR READING FILE!";

        QTextStream in(&file); // читаем файл и создаем объект in как итерируемый
        int i = 0; // просто счетчик
        while(!in.atEnd()){ // итерируем пока курсор не дойдет до конца файла
            i++; // прибавляем 1, чтобы узнать кол-во строк
            QString line = in.readLine(); // читаем строку
            QStringList fields = line.split(" "); // разделяем строку на два объекта
            series->append(fields[0].toInt(), fields[1].toInt()); // добавляем данные в объект
        }
        file.close(); // закрываем файл


        QLineSeries *series2 = new QLineSeries(); // для еще одного графика
        QFile file2("/home/tehnokrat/Documents/BSU/laba4/data1.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           qDebug()<<"ERROR READING FILE!";

        QTextStream in2(&file);
        i = 0;
        while(!in.atEnd()){
            i++;
            QString line = in.readLine();
            QStringList fields = line.split(" ");
            qDebug()<<fields[0].toInt()<<fields[1].toInt();
            series2->append(fields[0].toInt(), fields[1].toInt());
        }
        file.close();

        axisX->setTickCount(i); // ставим кол-во значений на оси
        axisY->setTickCount(i); //
        axisY->setRange(10, 2990);
        axisY->setTitleText("U");
        axisX->setTitleText("деление барабана");
        axisX->setLabelFormat("%.0f"); // то, с какой точностью будет отображаться
        axisY->setLabelFormat("%.0f");
        series->setName("Первое измерение");
        series2->setName("Второе измерение");
        chart->legend()->show(); // показываем
        chart->addSeries(series2);
        chart->addSeries(series);
        break;
    }
    case 2:{
        title = "Спектральная зависимость фотопроводимости";
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

        axisX->setLabelFormat("%.4f"); // то, с какой точностью будет отображаться
        axisY->setLabelFormat("%.4f");

        axisX->setTickCount(i);
        axisY->setTickCount(i);
        chart->setTitle("Спектральная зависимость фотопроводимости"); // здесь вводим название графика
        chart->addSeries(series);
        break;
    }
    case 3:{
        title = "Спектральная зависимость фотопроводимости 2";
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
        axisX->setLabelFormat("%.4f"); // то, с какой точностью будет отображаться
        axisY->setLabelFormat("%.4f");
        chart->setTitle("Спектральная зависимость фотопроводимости 2"); // здесь вводим название графика
        chart->addSeries(series);
        break;
    }
    default:
        for (int i=0; i<=10000; i++){  // здесь типо функция, которая читает из файла значения
            int y   = 180*sin(i)/3.14;
            *series<<QPointF(i,y); //    другой способ добавлять точки в объект графика.
        }
        axisX->setRange(0, 90);
        axisY->setRange(-65,65);
        break;
    }


    axisY->setLineVisible();
    axisY->setLabelsFont(QFont("Arial", 9)); // значения подписываем 9 размером шрифта

    axisX->setLineVisible();
    axisX->setLabelsFont(QFont("Arial", 9)); //
    axisX->setLabelsAngle(90); // на оси Х поворачиваем на 90, чтобы каждые 27 чисел было видно

    chart->addAxis(axisX, Qt::AlignBottom);  // фактически верстка, т.е. ось Х внизу, т.е. горизонтально
    chart->addAxis(axisY, Qt::AlignLeft); // ось У слева т.е. вертикально слева


    series->attachAxis(axisX); // присоеденяем оси к графику
    series->attachAxis(axisY); //

    chartView.setChart(chart);  // объявляем объект класса QChartView
    chartView.setRenderHint(QPainter::Antialiasing); // начинаем создавать изображение
    chartView.setGeometry(0,0,890,800);
    chartView.setParent(ui->horizontalFrame); // родительский класс у графика -- область на экране -- horizontalFrame.
}


Graph_window::~Graph_window() // деструктор (знаем с первого сема, да ведь?)
{
    delete ui; // удаляем user_interface из оперативки
}

void Graph_window::on_pushButton_clicked() // закрытие окна на нажатие клавиши ОК
{
    this->close(); // то же самое, что и в MainWindow
}


void Graph_window::onCompute(const QString result) // здесь мы получаем строку
{
    qDebug()<<result; // выводим в терминал инфоормацию
    if (result == "Лабораторная работа 1, таблица 1"){ // сравнение двух строк
        text = 1; //  заносим в глобальную переменную типа инт, чтобы далее сделать свитч
    }
    if (result == "Лабораторная работа 1, таблица 2"){
        text = 2;
    }
    if (result == "Лабораторная работа 1, таблица 3"){
        text = 3;
    }
}

void Graph_window::on_pushButton_2_clicked()
{
    QPixmap p = chartView.grab(); // захватываем объект chartView и заносим его в объект Pixmap -- изобраэение
    QString filename = title + ".png"; // берем название графика и добавляем разрешение
    p.save(filename, "PNG"); // сохраняем изображение
    QMessageBox msgBox; // Выкидываем сообщение, что график сохранен
    msgBox.setText("График сохранен!");
    msgBox.exec();
}

