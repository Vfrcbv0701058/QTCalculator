#include "mainwindow.h"
#include "./ui_mainwindow.h"

double first_num;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_1, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::digits_numbers);

    connect(ui->pushButton_dot, &QPushButton::clicked, this, &MainWindow::on_pushButton_dot_clicked);
    connect(ui->pushButton_p_m, &QPushButton::clicked, this, &MainWindow::plus_minus);
    connect(ui->pushButton_per, &QPushButton::clicked, this, &MainWindow::percent);
    connect(ui->pushButton_clear, &QPushButton::clicked, this, &MainWindow::clear_label);
    connect(ui->pushButton_plus, &QPushButton::clicked, this, &MainWindow::math_operations);
    connect(ui->pushButton_minus, &QPushButton::clicked, this, &MainWindow::math_operations);
    connect(ui->pushButton_divide, &QPushButton::clicked, this, &MainWindow::math_operations);
    connect(ui->pushButton_multiply, &QPushButton::clicked, this, &MainWindow::math_operations);
    connect(ui->pushButton_equals, &QPushButton::clicked, this, &MainWindow::push_button_equals);

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers(){
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if(ui->result->text().contains(".") && button->text() == "0"){
        new_label = ui->result->text()+button->text();
    } else{

        all_numbers = (ui->result->text()+button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 10);
    }

    ui->result->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked(){
    if(!ui->result->text().contains("."))
        ui->result->setText(ui->result->text() + ".");
}

void MainWindow::plus_minus() {
    double all_numbers;
    QString new_label;

    all_numbers = (ui->result->text()).toDouble();
    all_numbers = all_numbers * (-1);
    new_label = QString::number(all_numbers, 'g', 10);
    ui->result->setText(new_label);
}

void MainWindow::percent(){
    double all_numbers;
    QString new_label;

    all_numbers = (ui->result->text()).toDouble();
    all_numbers = all_numbers * 0.01;
    new_label = QString::number(all_numbers, 'g', 10);

    ui->result->setText(new_label);
}

void MainWindow::clear_label(){
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);

    ui->result->setText("0");
}

void MainWindow::math_operations(){
    QPushButton *button = (QPushButton *)sender();

    first_num = ui->result->text().toDouble();
    ui->result->setText("");
    button->setChecked(true);
}


void MainWindow::push_button_equals(){

    double label_num, second_num;
    QString new_label;

    second_num = ui->result->text().toDouble();

    if(ui->pushButton_plus->isChecked()){

        label_num = first_num + second_num;

        new_label = QString::number(label_num, 'g', 10);
        ui->result->setText(new_label);

        ui->pushButton_plus->setChecked(false);

    } else if(ui->pushButton_minus->isChecked()){

        label_num = first_num - second_num;

        new_label = QString::number(label_num, 'g', 10);
        ui->result->setText(new_label);

        ui->pushButton_minus->setChecked(false);

    } else if(ui->pushButton_multiply->isChecked()){

        label_num = first_num * second_num;

        new_label = QString::number(label_num, 'g', 10);
        ui->result->setText(new_label);

        ui->pushButton_multiply->setChecked(false);

    } else if(ui->pushButton_divide->isChecked()){

        if(second_num == 0){
            qDebug() << "dividing on 0";
            ui->result->setText("Err2!");
        }

        label_num = first_num / second_num;

        new_label = QString::number(label_num, 'g', 10);
        ui->result->setText(new_label);

        ui->pushButton_divide->setChecked(false);

    } else{
        qDebug() << "Error in void MainWindow::push_button_equals()";
        ui->result->setText("Err01!");
    }
}
