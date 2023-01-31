#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGraphicsView>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    QTableWidget *dataTable;
    QPushButton *runButton;
    QGraphicsView *graphView;
};

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    dataTable = new QTableWidget(this);
    runButton = new QPushButton("Run Algorithm", this);
    graphView = new QGraphicsView(this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(dataTable);
    layout->addWidget(runButton);
    layout->addWidget(graphView);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

#include "mainwindow.moc"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
{
    delete ui;
}