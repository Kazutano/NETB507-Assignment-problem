#include <QtWidgets>
#include <vector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow w;
    w.resize(500, 500);
    w.setWindowTitle("Assignment Problem");

    QHBoxLayout *inputLayout = new QHBoxLayout;

    QLineEdit *numAgentsLineEdit = new QLineEdit;
    QLineEdit *numTasksLineEdit = new QLineEdit;

    inputLayout->addWidget(new QLabel("Number of Agents:"));
    inputLayout->addWidget(numAgentsLineEdit);
    inputLayout->addWidget(new QLabel("Number of Tasks:"));
    inputLayout->addWidget(numTasksLineEdit);

    QPushButton *defineGraphButton = new QPushButton("Define Graph");

    QObject::connect(defineGraphButton, &QPushButton::clicked,
                     []() {
    });

    inputLayout->addWidget(defineGraphButton);

    QPushButton *runAlgorithmButton = new QPushButton("Run Algorithm");

    QObject::connect(runAlgorithmButton, &QPushButton::clicked,
                     []() {
    });

    inputLayout->addWidget(runAlgorithmButton);

    w.setCentralWidget(new QWidget);
    w.centralWidget()->setLayout(inputLayout);

    w.show();

    return a.exec();
}
