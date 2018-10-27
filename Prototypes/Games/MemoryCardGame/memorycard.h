#ifndef MEMORYCARD_H
#define MEMORYCARD_H

#include <QMainWindow>

namespace Ui {
class MemoryCard;
}

class MemoryCard : public QMainWindow
{
    Q_OBJECT

public:
    explicit MemoryCard(QWidget *parent = nullptr);
    ~MemoryCard();

private:
    Ui::MemoryCard *ui;
};

#endif // MEMORYCARD_H
