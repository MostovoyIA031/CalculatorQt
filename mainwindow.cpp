#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <locale>
#include <math.h>

double num_first;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_min,SIGNAL(clicked()),this,SLOT(operations()));

    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_del,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_umn,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_step,SIGNAL(clicked()),this,SLOT(math_operations()));
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_del->setCheckable(true);
    ui->pushButton_umn->setCheckable(true);
    ui->pushButton_step->setCheckable(true);

    connect(ui->pushButton_clear,SIGNAL(clicked()),this,SLOT(math_operations()));
     ui->pushButton_clear->setCheckable(true);

     connect(ui->pushButton_sqrt,SIGNAL(clicked()),this,SLOT(math_operations()));
      ui->pushButton_sqrt->setCheckable(true);

      connect(ui->pushButton_fuck,SIGNAL(clicked()),this,SLOT(math_operations()));
       ui->pushButton_fuck->setCheckable(true);

       connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(math_operations()));
        ui->pushButton_sin->setCheckable(true);
        connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(math_operations()));
         ui->pushButton_cos->setCheckable(true);
         connect(ui->pushButton_tg,SIGNAL(clicked()),this,SLOT(math_operations()));
          ui->pushButton_tg->setCheckable(true);
          connect(ui->pushButton_ctg,SIGNAL(clicked()),this,SLOT(math_operations()));
           ui->pushButton_ctg->setCheckable(true);

           connect(ui->pushButton_log,SIGNAL(clicked()),this,SLOT(math_operations()));
            ui->pushButton_log->setCheckable(true);


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers(){

    QPushButton *button=(QPushButton *)sender();

    double all_numbers;
    QString new_label;
    all_numbers=(ui->result_show->text()+button->text()).toDouble();
    new_label=QString::number(all_numbers, 'g', 15);

    ui->result_show->setText(new_label);

}

void MainWindow::on_pushButton_tochk_clicked()
{
    if(!ui->result_show->text().contains('.'))
    ui->result_show->setText(ui->result_show->text() + ".");

}

void MainWindow::operations(){

    QPushButton *button=(QPushButton *)sender();

    double all_numbers;
    QString new_label;

    if(button->text()=="*-"){
    all_numbers=(ui->result_show->text()).toDouble();
    all_numbers=all_numbers * -1;
    new_label=QString::number(all_numbers, 'g', 15);

    ui->result_show->setText(new_label);
    }

}


void MainWindow::math_operations(){

    QPushButton *button=(QPushButton*)sender();

    num_first = ui->result_show->text().toDouble();
    ui->result_show->setText("");

    button->setChecked(true);
}

void MainWindow::on_pushButton_clear_clicked()
{

}

void MainWindow::on_pushButton_ravn_clicked()
{
    double labelNumber, num_second;
    QString new_label;

    num_second = ui->result_show->text().toDouble();

    if(ui->pushButton_plus->isChecked()){
        labelNumber=num_first+num_second;
        new_label=QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(new_label);
        ui->pushButton_plus->setChecked(false);

    }else if(ui->pushButton_minus->isChecked()){
        labelNumber=num_first-num_second;
        new_label=QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(new_label);
        ui->pushButton_minus->setChecked(false);


    }else if(ui->pushButton_del->isChecked()){
        if(num_second==0){
            ui->result_show->setText("0");
        }else{
        labelNumber=num_first/num_second;
        new_label=QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(new_label);
        }
        ui->pushButton_del->setChecked(false);
    }else if((ui->pushButton_umn->isChecked())){
        labelNumber=num_first*num_second;
        new_label=QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(new_label);
        ui->pushButton_umn->setChecked(false);

    }

    else if((ui->pushButton_step->isChecked())){
            labelNumber=pow(num_first, num_second);
            new_label=QString::number(labelNumber, 'g', 15);

            ui->result_show->setText(new_label);
            ui->pushButton_step->setChecked(false);
        }

    else if((ui->pushButton_sqrt->isChecked())){
            labelNumber=sqrt(num_first);
            new_label=QString::number(labelNumber, 'g', 15);

            ui->result_show->setText(new_label);
            ui->pushButton_sqrt->setChecked(false);
        }

    else if((ui->pushButton_fuck->isChecked())){
        double f=1;

        for(double i=1; i<=num_first; i++){
            f=f*i;
            labelNumber=f;
        }
            new_label=QString::number(labelNumber, 'g', 15);

            ui->result_show->setText(new_label);
            ui->pushButton_fuck->setChecked(false);
        }

    else if((ui->pushButton_sin->isChecked())){
            labelNumber=sin(num_first);
            new_label=QString::number(labelNumber, 'g', 15);

            ui->result_show->setText(new_label);
            ui->pushButton_sin->setChecked(false);
        }
    else if((ui->pushButton_cos->isChecked())){
        labelNumber=cos(num_first);
        new_label=QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(new_label);
        ui->pushButton_cos->setChecked(false);
    }
    else if((ui->pushButton_tg->isChecked())){
            labelNumber=tan(num_first);
            new_label=QString::number(labelNumber, 'g', 15);

            ui->result_show->setText(new_label);
            ui->pushButton_tg->setChecked(false);
        }
    else if((ui->pushButton_ctg->isChecked())){
            labelNumber=1/(tan(num_first));
            new_label=QString::number(labelNumber, 'g', 15);

            ui->result_show->setText(new_label);
            ui->pushButton_ctg->setChecked(false);
        }

    else if((ui->pushButton_log->isChecked())){
            labelNumber=log(num_first)/log(num_second);
            new_label=QString::number(labelNumber, 'g', 15);

            ui->result_show->setText(new_label);
            ui->pushButton_log->setChecked(false);
        }



    else if(ui->pushButton_clear->isChecked()){
                ui->result_show->setText("0");
    }


}
