//
// Created by visha on 12/3/2024.
//

#ifndef STARTMENU_H
#define STARTMENU_H

#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

class StartMenu : public QDialog {
    Q_OBJECT

public:
    explicit StartMenu(QWidget *parent = nullptr) : QDialog(parent), selectedOption(-1) {
        setWindowTitle("Select Data Structure");
        resize(400, 200);

        QVBoxLayout *layout = new QVBoxLayout(this);

        QLabel *label = new QLabel("Choose a Data Structure to Use:");
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("font-size: 14pt;");

        QPushButton *hashTableButton = new QPushButton("HashTable", this);
        QPushButton *multiMapButton = new QPushButton("MultiMap", this);

        layout->addWidget(label);
        layout->addWidget(hashTableButton);
        layout->addWidget(multiMapButton);

        setLayout(layout);

        // Connect buttons to slots
        connect(hashTableButton, &QPushButton::clicked, [this]() {
            selectedOption = 0;
            accept();
        });
        connect(multiMapButton, &QPushButton::clicked, [this]() {
            selectedOption = 1;
            accept();
        });
    }

    int getSelectedOption() const { return selectedOption; }

private:
    int selectedOption;
};

#endif // STARTMENU_H
