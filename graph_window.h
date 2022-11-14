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
    Ui::Graph_window *ui;
    int text = 0;
    QString title;

private slots:
    void on_pushButton_clicked();
    void onCompute(const QString result);
    void on_pushButton_2_clicked();
private:
    QChartView chartView;
};

#endif // GRAPH_WINDOW_H
