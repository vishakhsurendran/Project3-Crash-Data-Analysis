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

#include "mainwindow.h"
#include "startmenu.h"
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

    HashTable crashesHash;
    crashesHash.parseDataToTable();

    auto crashesMap = parseToMap();

    StartMenu startMenu;
    if (startMenu.exec() != QDialog::Accepted) {
        return 0; // Exit if the user closes the dialog
    }

    int selectedOption = startMenu.getSelectedOption();
    while (true) { // Loop to allow returning to the StartMenu
        if (selectedOption == 0) {
            MainWindow window(&crashesHash, nullptr);
            window.setWindowTitle("Crash Data Analysis - HashTable");

            QObject::connect(&window, &MainWindow::backRequested, [&]() {
                selectedOption = -1; // Reset to indicate returning to StartMenu
                window.close();
            });

            window.show();
            app.exec();
        } else if (selectedOption == 1) {
            MainWindow window(nullptr, &crashesMap);
            window.setWindowTitle("Crash Data Analysis - MultiMap");

            QObject::connect(&window, &MainWindow::backRequested, [&]() {
                selectedOption = -1; // Reset to indicate returning to StartMenu
                window.close();
            });

            window.show();
            app.exec();
        }

        // Reopen StartMenu if back button is pressed
        if (selectedOption == -1) {
            if (startMenu.exec() != QDialog::Accepted) {
                return 0; // Exit if the user closes the dialog
            }
            selectedOption = startMenu.getSelectedOption();
        } else {
            break; // Exit loop if no back action is required
        }
    }

    return 0;
}
