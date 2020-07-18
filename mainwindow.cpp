#include "mainwindow.h"
#include "ui_mainwindow.h"


double num_first = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_addition, SIGNAL(clicked()), this, SLOT(math_operation()));//+
    connect(ui->pushButton_change, SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->pushButton_division, SIGNAL(clicked()), this, SLOT(math_operation()));//"/"
    connect(ui->pushButton_multipl, SIGNAL(clicked()), this, SLOT(math_operation()));//*
    connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->pushButton_subtraction, SIGNAL(clicked()), this, SLOT(math_operation()));//-


    ui->pushButton_addition->setCheckable(true);
    ui->pushButton_division->setCheckable(true);
    ui->pushButton_subtraction->setCheckable(true);
    ui->pushButton_multipl->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString new_label;

    if(ui->resalt_show->text().contains(".") && button->text() == "0")
    {
        new_label = ui->resalt_show->text() + button->text();
    }
    else
    {
        all_numbers = (ui->resalt_show->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 10);
    }
        ui->resalt_show->setText(new_label);

}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->resalt_show->text().contains(".")))
        {
            ui->resalt_show->setText(ui->resalt_show->text() + ".");//"."
        }
}


void MainWindow::operation()
{
    QPushButton * button = (QPushButton *)sender();

    double all_numbers;
    QString new_label;

    if(button->text() == "-/+")
    {
        all_numbers = (ui->resalt_show->text()).toDouble();
        all_numbers = all_numbers * -1;
        new_label = QString::number(all_numbers, 'g', 10);
        ui->resalt_show->setText(new_label);
    }
    else if(button->text() == "%")
    {
        all_numbers = (ui->resalt_show->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g', 10);
        ui->resalt_show->setText(new_label);
    }

}


void MainWindow::math_operation()
{
    QPushButton *button = (QPushButton *)sender();

    num_first = ui->resalt_show->text().toDouble();
    ui->resalt_show->setText("");

    button->setChecked(true);

}



void MainWindow::on_pushButton_result_clicked()//математические операции и =
{
    double labelNumber, num_second;
    QString new_label;

    num_second = ui->resalt_show->text().toDouble();

         if(ui->pushButton_addition->isChecked())
        {
            labelNumber = num_first + num_second;

            new_label = QString::number(labelNumber, 'g', 10);
            ui->resalt_show->setText(new_label);
            ui->pushButton_addition->setChecked(false);

        }
        else if(ui->pushButton_subtraction->isChecked())
            {
                labelNumber = num_first - num_second;

                new_label = QString::number(labelNumber, 'g', 10);
                ui->resalt_show->setText(new_label);
                ui->pushButton_subtraction->setChecked(false);
            }
                else if(ui->pushButton_multipl->isChecked())
                {
                    labelNumber = num_first * num_second;

                    new_label = QString::number(labelNumber, 'g', 10);
                    ui->resalt_show->setText(new_label);
                    ui->pushButton_multipl->setChecked(false);
                }
                    else if(ui->pushButton_division->isChecked())
                        {
                            if(num_second == 0)
                            {
                                ui->resalt_show->setText("0");
                            }
                            else
                                {
                                    labelNumber = num_first / num_second;

                                    new_label = QString::number(labelNumber, 'g', 10);
                                    ui->resalt_show->setText(new_label);
                                    ui->pushButton_division->setChecked(false);
                                }
                        }

}







void MainWindow::on_pushButton_clean_clicked()// кнопка очищения окна
{

    ui->pushButton_addition->setChecked(false);
    ui->pushButton_addition->setChecked(false);
    ui->pushButton_addition->setChecked(false);
    ui->pushButton_addition->setChecked(false);

    ui->resalt_show->setText("0");

}










