//
// Created by Vishakh Surendran on 11/6/2024.
//

#include <iostream>
#include <fstream>
#include <string>
#include <QApplication>
#include <QtWidgets>
#include <QPushButton>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QTextEdit>
#include <QChart>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include "Crash.h"
#include "HashTable.h"

// Possible directives for Graph Creation
/*
#include <QChart>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>

using namespace QtCharts;
*/

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.resize(800, 600);

    // Create a layout for the window
    QVBoxLayout *layout = new QVBoxLayout(&window);

    // Create the QLabel for the title
    QLabel title("Crash Data Analysis", &window);
    title.setAlignment(Qt::AlignCenter);
    title.setStyleSheet("font-size: 18pt;");

    // Add the title at the top of the layout
    layout->addWidget(&title);
    layout->setAlignment(&title, Qt::AlignTop);

    // Set the layout for the window
    window.setLayout(layout);

    // Set the window properties
    window.setWindowTitle("Crash Data Analysis");
    window.show();

    return app.exec();
}

/*
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}

int main() {
    // auto crashes2 = parseToMap();
    auto crashes3 = new HashTable();
    crashes3->parseDataToTable();

    if (!crashes2.empty()) {
        std::cout << "Incident at :(40.667202, -73.8665)" << std::endl;

        search_Location("(40.667202, -73.8665)", crashes2);
        totals_borough("Queens", crashes2);

    }
    else {
        std::cerr << "No data present in file" << std::endl;
    }

    crashes3->displayCrashes("(40.667202, -73.8665)");

    crashes3->getTotalsByBorough("BROOKLYN");
    return 0;
}
*/
