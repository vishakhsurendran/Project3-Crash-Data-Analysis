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

    MainWindow window(&crashesHash);
    window.setWindowTitle("Crash Data Analysis");
    window.show();

    return app.exec();
}
