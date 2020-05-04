#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QComboBox>
#include <QButtonGroup>

class Canvas;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void addRobot(double x, double y);
    void clearData();
    void place();
    ~MainWindow();

private slots:
    void on_butClear_clicked();

private:
    Ui::MainWindow *ui;

    QVector<double> qv_x, qv_y;

    Canvas *scene;
    QGraphicsView *view;
    QMenu *itemMenu;
};
#endif // MAINWINDOW_H
