#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "HashTable.h"
#include <QMainWindow>
#include <qboxlayout.h>
#include <qcombobox.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(HashTable *crashesHash, std::multimap<std::string, Crash> *crashesMap, QWidget *parent = nullptr)
        : QMainWindow(parent), hashTable(crashesHash), crashesMap(crashesMap) {
        resize(1200, 800);

        // Set the background color
        QPalette pal = palette();
        pal.setColor(QPalette::Window, QColorConstants::Svg::lightsteelblue);
        setPalette(pal);

        // Central widget and main layout
        QWidget *centralWidget = new QWidget(this);
        QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

        // Left layout for the title
        QVBoxLayout *leftLayout = new QVBoxLayout();

        QLabel *title = new QLabel("Crash Data Analysis", this);
        title->setAlignment(Qt::AlignCenter);
        title->setStyleSheet("font-size: 18pt; color:black;");
        leftLayout->addWidget(title);
        leftLayout->setAlignment(title, Qt::AlignTop);
        leftLayout->addStretch();

        // Right Layout (Drop-down Menu and Text Box)
        QVBoxLayout *rightLayout = new QVBoxLayout();
        QComboBox *dropDown = new QComboBox(this);
        dropDown->addItems({"Bronx", "Brooklyn", "Manhattan", "Queens", "Staten Island"});
        QLabel *dropDownLabel = new QLabel("Select a Borough:", this);

        QVBoxLayout *dropDownLayout = new QVBoxLayout();
        dropDownLayout->addWidget(dropDownLabel);
        dropDownLayout->addWidget(dropDown);
        dropDownLayout->addStretch();
        rightLayout->addLayout(dropDownLayout);

        textDisplay = new QTextEdit(this);
        textDisplay->setPlaceholderText("Crash details will appear here...");
        textDisplay->setReadOnly(true);
        textDisplay->setMinimumHeight(650);
        textDisplay->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        rightLayout->addWidget(textDisplay);

        QWidget *rightWidget = new QWidget();
        rightWidget->setLayout(rightLayout);
        rightWidget->setMaximumWidth(width() / 3);

        mainLayout->addLayout(leftLayout);
        mainLayout->addWidget(rightWidget);

        setCentralWidget(centralWidget);

        connect(dropDown, QOverload<int>::of(&QComboBox::currentIndexChanged),
                this, &MainWindow::updateTextBox);
        updateTextBox(0);
    }

    ~MainWindow() {
        delete ui;
    }

private slots:
    void updateTextBox(int index) {
        static const QStringList boroughs = {"BRONX", "BROOKLYN", "MANHATTAN", "QUEENS", "STATEN ISLAND"};
        if (index >= 0 && index < boroughs.size()) {
            std::ostringstream output;
            if (hashTable) {
                hashTable->displayCrashesByBorough(boroughs[index].toStdString(), output);
            } else if (crashesMap) {
                displayMapCrashesByBorough(boroughs[index].toStdString(), *crashesMap, output);
            }
            textDisplay->setText(QString::fromStdString(output.str()));
        } else {
            textDisplay->setText("Invalid borough selected.");
        }
    }

private:
    QTextEdit *textDisplay;
    Ui::MainWindow *ui;
    HashTable *hashTable;
    std::multimap<std::string, Crash> *crashesMap;
};

#endif // MAINWINDOW_H
