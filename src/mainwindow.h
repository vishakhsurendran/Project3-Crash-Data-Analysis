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
        QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

        // Back Button
        QPushButton *backButton = new QPushButton("Menu", this);
        backButton->setFixedSize(100, 40); // Optional: Set button size
        backButton->setStyleSheet("font-size: 12pt;"); // Optional: Style the button
        connect(backButton, &QPushButton::clicked, this, &MainWindow::backToStartMenu);
        mainLayout->addWidget(backButton, 0, Qt::AlignLeft); // Add button at top-left

        // Add the rest of the UI below the back button
        QHBoxLayout *contentLayout = new QHBoxLayout();

        // Left layout for the title and image
        QVBoxLayout *leftLayout = new QVBoxLayout();

        QLabel *title = new QLabel("Crash Data Analysis", this);
        title->setAlignment(Qt::AlignCenter);
        title->setStyleSheet("font-size: 24pt; color:black;");
        leftLayout->addWidget(title);
        leftLayout->setAlignment(title, Qt::AlignTop);

        leftLayout->addStretch();

        // Add the image to the left layout
        QLabel *imageLabel = new QLabel(this);
        QPixmap image("../src/DataBarGraph.png");
        if (!image.isNull()) {
            image = image.scaled(700, 600, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            imageLabel->setPixmap(image);
            imageLabel->setAlignment(Qt::AlignCenter);
            leftLayout->addWidget(imageLabel);
        } else {
            imageLabel->setText("Image not found");
            imageLabel->setAlignment(Qt::AlignCenter);
            imageLabel->setStyleSheet("color: red; font-size: 12pt;");
            leftLayout->addWidget(imageLabel);
        }

        leftLayout->addStretch();

        // Right Layout (Drop-down Menu and Text Box)
        QVBoxLayout *rightLayout = new QVBoxLayout();

        QVBoxLayout *dropDownLayout = new QVBoxLayout();
        QLabel *dropDownLabel = new QLabel("Select a Borough:", this);
        dropDownLabel->setStyleSheet("color: black; font-size: 12pt;");
        dropDownLayout->addWidget(dropDownLabel);

        QComboBox *dropDown = new QComboBox(this);
        dropDown->addItems({"Bronx", "Brooklyn", "Manhattan", "Queens", "Staten Island"});
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

        contentLayout->addLayout(leftLayout);
        contentLayout->addWidget(rightWidget);

        // Add content layout to the main layout (below the back button)
        mainLayout->addLayout(contentLayout);

        setCentralWidget(centralWidget);

        connect(dropDown, QOverload<int>::of(&QComboBox::currentIndexChanged),
                this, &MainWindow::updateTextBox);
        updateTextBox(0);
    }

signals:
    void backRequested(); // Signal to notify back button press

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

    void backToStartMenu() {
        emit backRequested(); // Emit signal to return to StartMenu
    }

private:
    QTextEdit *textDisplay;
    Ui::MainWindow *ui;
    HashTable *hashTable;
    std::multimap<std::string, Crash> *crashesMap;
};

#endif // MAINWINDOW_H
