#include "label.h"

Label::Label(QObject *parent)
    : QThread{parent}
{
    output.setText("hello");
}
