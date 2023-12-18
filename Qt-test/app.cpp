#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>

class MyWidget : public QWidget {
public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        // Creating a Button
        QPushButton *button = new QPushButton("Click me!", this);

        // Connecting a button click signal to a slot (handler)
        connect(button, &QPushButton::clicked, this, &MyWidget::showMessage);

        // Setting the button to the center of the widget
        button->setGeometry(50, 50, 100, 30);
    }

private slots:
    // Slot to display a message when a button is pressed
    void showMessage() {
        QMessageBox::information(this, "Hello", "Hello, Desktop App!");
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Creating a Main Window Object
    MyWidget widget;
    widget.setWindowTitle("Simple Desktop App");
    widget.setGeometry(100, 100, 300, 200);
    widget.show();

    // Starting the main application loop
    return app.exec();
}
