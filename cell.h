#ifndef CELL_H
#define CELL_H

#include <QPushButton>
#include <QLabel>

#include <string>

class Cell : public QObject
{
public:
    Cell(QWidget* parent = nullptr);
    Cell(const QString& contents, QWidget* parent = nullptr);

    void move(int x, int y);

private slots:
    void hide();

private:
    QLabel      label_;
    QPushButton button_;
};

#endif // CELL_H
