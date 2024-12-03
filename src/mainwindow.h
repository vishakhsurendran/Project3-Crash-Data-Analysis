#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "HashTable.h"
#include <QMainWindow>
#include <qboxlayout.h>
#include <qcombobox.h>
#include <qlabel.h>
#include <qtextedit.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(HashTable *crashesHash, QWidget *parent = nullptr) : QMainWindow(parent), hashTable(crashesHash) {
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

        // Create the QLabel for the title
        QLabel *title = new QLabel("Crash Data Analysis", this);
        title->setAlignment(Qt::AlignCenter);
        title->setStyleSheet("font-size: 18pt; color:black;");

        // Add the title to the left layout
        leftLayout->addWidget(title);
        leftLayout->setAlignment(title, Qt::AlignTop);

        // Add a stretch to push the title to the top
        leftLayout->addStretch();

        // Right Layout (Drop-down Menu and Text Box)
        QVBoxLayout *rightLayout = new QVBoxLayout();

        // Drop-down Menu
        QComboBox *dropDown = new QComboBox(this);
        dropDown->addItems({"Bronx", "Brooklyn", "Manhattan", "Queens", "Staten Island"});
        QLabel *dropDownLabel = new QLabel("Select a Borough:", this);

        QVBoxLayout *dropDownLayout = new QVBoxLayout();
        dropDownLayout->addWidget(dropDownLabel);
        dropDownLayout->addWidget(dropDown);
        dropDownLayout->addStretch();
        rightLayout->addLayout(dropDownLayout);

        // Text Display Box
        textDisplay = new QTextEdit(this);
        textDisplay->setPlaceholderText("Crash details will appear here...");
        textDisplay->setReadOnly(true);  // Makes the text box read-only for list display
        textDisplay->setMinimumHeight(650);
        textDisplay->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        // Set default text for Option 1


        // Add the text box to the right layout
        rightLayout->addWidget(textDisplay);

        // Limit the right layout size to 1/4 of the window
        QWidget *rightWidget = new QWidget();
        rightWidget->setLayout(rightLayout);
        rightWidget->setMaximumWidth(width() / 3);

        // Add layouts to the main layout
        mainLayout->addLayout(leftLayout);
        mainLayout->addWidget(rightWidget);

        // Set the main layout as the central widget
        setCentralWidget(centralWidget);

        // Connect drop-down to text box update
        connect(dropDown, QOverload<int>::of(&QComboBox::currentIndexChanged),
                this, &MainWindow::updateTextBox);
        updateTextBox(0);
        resize(1200, 800);
    }

    ~MainWindow() {
        delete ui;
    }

private slots:
    void updateTextBox(int index) {
        static const QStringList boroughs = {"BRONX", "BROOKLYN", "MANHATTAN", "QUEENS", "STATEN ISLAND"};
        if (index >= 0 && index < boroughs.size()) {
            std::ostringstream output;
            hashTable->displayCrashesByBorough(boroughs[index].toStdString(), output);
            textDisplay->setText(QString::fromStdString(output.str()));
        } else {
            textDisplay->setText("Invalid borough selected.");
        }
    }

private:
    QTextEdit *textDisplay;
    Ui::MainWindow *ui;
    HashTable *hashTable;
};

#endif // MAINWINDOW_H
