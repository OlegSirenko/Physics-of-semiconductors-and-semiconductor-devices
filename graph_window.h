#ifndef GRAPH_WINDOW_H
#define GRAPH_WINDOW_H

#include <QDialog>
#include <QChart>
#include <QChartView>
#include <QLineSeries>


namespace Ui {
class Graph_window;
}

class Graph_window : public QDialog
{
    Q_OBJECT

public:
    explicit Graph_window(QWidget *parent = nullptr);
    ~Graph_window();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Graph_window *ui;
};

#endif // GRAPH_WINDOW_H
