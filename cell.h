#ifndef CELL_H
#define CELL_H

#include <QPushButton>
#include <QLabel>
#include <QObject>

#include <string>

class Cell : public QObject
{
    Q_OBJECT
public:
    Cell(QWidget* parent = nullptr);
    Cell(const QString& contents, QWidget* parent = nullptr);

    virtual ~Cell(){}

    void move(int x, int y);

private slots:
    void hide();

private:
    QLabel      label_;
    QPushButton button_;
    QString     contents_;
};

#endif // CELL_H
