#include "mainwindow.h"
#include "ui_mainwindow.h"

static QString flag ="";
static int count = 0;
static double point = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    visibleFalse();
    ui->begin_scrollArea->setVisible(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::checkRadioButton()
{
    if(ui->radioButton_0->isChecked())
        return 0;
    if(ui->radioButton_1->isChecked())
        return 1;
    if(ui->radioButton_2->isChecked())
        return 2;
    if(ui->radioButton_3->isChecked())
        return 3;
    if(ui->radioButton_4->isChecked())
        return 4;
    if(ui->radioButton_5->isChecked())
        return 5;
    if(ui->radioButton_6->isChecked())
        return 6;
    if(ui->radioButton_7->isChecked())
        return 7;
    if(ui->radioButton_8->isChecked())
        return 8;
    if(ui->radioButton_9->isChecked())
        return 9;
    if(ui->radioButton_10->isChecked())
        return 10;
    return -1;
}

void MainWindow::checkFalse()
{
    ui->radioButton_0->setAutoExclusive(false);
    ui->radioButton_1->setAutoExclusive(false);
    ui->radioButton_2->setAutoExclusive(false);
    ui->radioButton_3->setAutoExclusive(false);
    ui->radioButton_4->setAutoExclusive(false);
    ui->radioButton_5->setAutoExclusive(false);
    ui->radioButton_6->setAutoExclusive(false);
    ui->radioButton_7->setAutoExclusive(false);
    ui->radioButton_8->setAutoExclusive(false);
    ui->radioButton_9->setAutoExclusive(false);
    ui->radioButton_10->setAutoExclusive(false);

    ui->radioButton_0->setChecked(false);
    ui->radioButton_1->setChecked(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_3->setChecked(false);
    ui->radioButton_4->setChecked(false);
    ui->radioButton_5->setChecked(false);
    ui->radioButton_6->setChecked(false);
    ui->radioButton_7->setChecked(false);
    ui->radioButton_8->setChecked(false);
    ui->radioButton_9->setChecked(false);
    ui->radioButton_10->setChecked(false);

    ui->radioButton_0->setAutoExclusive(true);
    ui->radioButton_1->setAutoExclusive(true);
    ui->radioButton_2->setAutoExclusive(true);
    ui->radioButton_3->setAutoExclusive(true);
    ui->radioButton_4->setAutoExclusive(true);
    ui->radioButton_5->setAutoExclusive(true);
    ui->radioButton_6->setAutoExclusive(true);
    ui->radioButton_7->setAutoExclusive(true);
    ui->radioButton_8->setAutoExclusive(true);
    ui->radioButton_9->setAutoExclusive(true);
    ui->radioButton_10->setAutoExclusive(true);
}

void MainWindow::questInitial()
{
    if(flag == "basdai")
    {
        if(count >= 6)
        {
            count = 0;
            ui->index_label->setText("Индекс BASDAI");
            ui->result_label->setText(QString("Ваш результат: ").toUtf8() + QString::number(point/6) + QString("\nЕсли индекс BASDAI меньше 4, то активность заболевания – низкая.\n"
                                                                                                             "Если индекс BASDAI больше 4, то активность заболевания – высокая.\n"
                                                                                                             "Если результат индекса увеличился на 20% по сравнению с предыдущей его оценкой, необходимо обратиться к лечащему врачу для изменения терапии."));
            visibleFalse();
            ui->result_scrollArea->setVisible(true);
        }

        switch(count)
        {
            case 0:
                ui->quest_label->setText("Как бы Вы расценили уровень общей слабости (утомляемости) за последнюю неделю?");
                ui->progressBar->setValue(17);
            break;
            case 1:
                ui->quest_label->setText("Как бы Вы расценили уровень боли в шее, спине или тазобедренных суставах за последнюю неделю?");
                ui->progressBar->setValue(33);
            break;
            case 2:
                ui->quest_label->setText("Как бы Вы расценили уровень боли (или степень припухлости) в суставах (помимо шеи, спины или тазобедренных суставов) за последнюю неделю?");
                ui->progressBar->setValue(50);
            break;
            case 3:
                ui->quest_label->setText("Как бы Вы расценили степень неприятных ощущений, возникающих при дотрагивании до каких-либо болезненных областей или давлении на них (за последнюю неделю)?");
                ui->progressBar->setValue(67);
            break;
            case 4:
                ui->quest_label->setText("Как бы Вы расценили степень выраженности утренней скованности, возникающей после просыпания (за последнюю неделю)?");
                ui->progressBar->setValue(83);
            break;
            case 5:
                ui->quest_label->setText("Как долго длится утренняя скованность, возникающая после просыпания (за последнюю неделю)?");
                ui->progressBar->setValue(100);
            break;
        }

        count++;
    }
    else
        if(flag == "basfi")
        {
            if(count >= 10)
            {
                count = 0;
                ui->index_label->setText("Индекс BASDAI");
                ui->result_label->setText(QString("Ваш результат: ").toUtf8() + QString::number(point/10) + QString("\nЕсли у Вас нет функциональных нарушений, то индекс BASFI будет равен «0».\n"
                                                                                                                 "При умеренных функциональных ограничениях индекс равен «5».\n"
                                                                                                                 "Если индекс BASFI больше 5, то функциональные нарушения – выраженные.\n"
                                                                                                                 "Чем ближе результаты оценки индекса к «10», тем хуже функция позвоночника и суставов.\n"
                                                                                                                 "Если результат индекса увеличился на 20% по сравнению с предыдущей его оценкой, необходимо обратиться к лечащему врачу для изменения терапии."));
                visibleFalse();
                ui->result_scrollArea->setVisible(true);
            }

            switch(count)
            {
                case 0:
                    ui->quest_label->setText("Могли ли Вы надеть носки или колготки без посторонней помощи или использования приспособлений, в течение последней недели?");
                    ui->progressBar->setValue(10);
                break;
                case 1:
                    ui->quest_label->setText("Могли ли Вы нагнуться вперед, чтобы поднять ручку с пола без использования приспособлений, в течение последней недели?");
                    ui->progressBar->setValue(20);
                break;
                case 2:
                    ui->quest_label->setText("Могли ли Вы дотянуться рукой до высоко расположенной полки без посторонней помощи или использования приспособлений, в течение последней недели?");
                    ui->progressBar->setValue(30);
                break;
                case 3:
                    ui->quest_label->setText("Могли ли Вы встать со стула без помощи рук и без посторонней помощи, в течение последней недели?");
                    ui->progressBar->setValue(40);
                break;
                case 4:
                    ui->quest_label->setText("Могли ли Вы встать с пола из положения лежа на спине без посторонней помощи, в течение последней недели?");
                    ui->progressBar->setValue(50);
                break;
                case 5:
                    ui->quest_label->setText("Могли ли Вы стоять без дополнительной опоры в течение 10 минут, не ощущая дискомфорта, в течение последней недели?");
                    ui->progressBar->setValue(60);
                break;
                case 6:
                    ui->quest_label->setText("Могли ли Вы подняться вверх на 12-15 ступенек, не опираясь на перила или трость (опираясь одной ногой на каждую ступеньку), в течение последней недели?");
                    ui->progressBar->setValue(70);
                break;
                case 7:
                    ui->quest_label->setText("Могли ли Вы повернуть голову и посмотреть за спину, не поворачивая туловище, в течение последней недели?");
                    ui->progressBar->setValue(80);
                break;
                case 8:
                    ui->quest_label->setText("Могли ли Вы заниматься физически активными видами деятельности (например, физическими упражнениями, спортом, работой в саду), в течение последней недели?");
                    ui->progressBar->setValue(90);
                break;
                case 9:
                    ui->quest_label->setText("Могли ли Вы поддерживать активность в течение всего дня (дома или на работе), в течение последней недели?");
                    ui->progressBar->setValue(100);
                break;
            }

            count++;
        }
}

void MainWindow::visibleFalse()
{
    ui->begin_scrollArea->setVisible(false);
    ui->tests_scrollArea->setVisible(false);
    ui->test_scrollArea->setVisible(false);
    ui->result_scrollArea->setVisible(false);
}

void MainWindow::on_begin_pushButton_clicked()
{
    visibleFalse();
    ui->begin_scrollArea->setVisible(true);
}

void MainWindow::on_tests_pushButton_clicked()
{
    visibleFalse();
    ui->tests_scrollArea->setVisible(true);
}

void MainWindow::on_exit_pushButton_clicked()
{
    QApplication::exit();
}

void MainWindow::on_basdai_pushButton_clicked()
{
    count = 0;
    point = 0;
    flag = "basdai";
    questInitial();
    visibleFalse();
    ui->test_scrollArea->setVisible(true);
}

void MainWindow::on_basfi_pushButton_clicked()
{
    count = 0;
    point = 0;
    flag = "basfi";
    questInitial();
    visibleFalse();
    ui->test_scrollArea->setVisible(true);
}


void MainWindow::on_next_pushButton_clicked()
{
    int temp = checkRadioButton();
    if(temp != -1)
    {
        checkFalse();
        questInitial();
        if(flag == "basdai")
        {
            if(count == 4 || count == 5)
                point += temp/2;
            else
                point += temp;
        }
        else
        {
            if(flag == "basfi")
                point += temp;
        }
    }
    else
    {
        QMessageBox::warning(this, "Внимание", "Ответ на вопрос обязателен!");
    }
}

void MainWindow::on_pushButton_clicked()
{
    visibleFalse();
    ui->begin_scrollArea->setVisible(true);
}
