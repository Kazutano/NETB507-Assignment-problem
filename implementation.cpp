#include <QMainWindow>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMainWindow.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QFormLayout *formLayout;
    QLineEdit *numAgentsEdit;
    QLineEdit *numTasksEdit;
    QPushButton *inputCostsButton;
    QLabel *costsLabel;

private slots:
    void inputCosts();
};

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    formLayout = new QFormLayout();
    numAgentsEdit = new QLineEdit();
    numTasksEdit = new QLineEdit();
    inputCostsButton = new QPushButton("Input Costs");
    costsLabel = new QLabel("");

    formLayout->addRow("Number of Agents:", numAgentsEdit);
    formLayout->addRow("Number of Tasks:", numTasksEdit);
    formLayout->addRow("", inputCostsButton);
    formLayout->addRow("Costs:", costsLabel);

    setCentralWidget(new QWidget());
    centralWidget()->setLayout(formLayout);

    connect(inputCostsButton, SIGNAL(clicked()), this, SLOT(inputCosts()));
}

MainWindow::~MainWindow()
{
    delete formLayout;
    delete numAgentsEdit;
    delete numTasksEdit;
    delete inputCostsButton;
    delete costsLabel;
}

void MainWindow::inputCosts()
{
    int numAgents = numAgentsEdit->text().toInt();
    int numTasks = numTasksEdit->text().toInt();


    costsLabel->setText("Costs inputted successfully");
}

#include "mainwindow.moc"
