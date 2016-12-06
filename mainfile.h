#ifndef MAINFILE_H
#define MAINFILE_H

#include <QDialog>
#include <QList>
#include <QLabel>
#include <QWidget>
#include <QObject>

namespace Ui {
class mainFile;
}

class mainFile : public QDialog
{
    Q_OBJECT

public:
    explicit mainFile(QWidget *parent = 0);
    ~mainFile();
    bool partieACommence();
    void disableAllButonColon();
    void enableAllButonColon();
    void set1CouleurTo(const bool &setjaune, const int &colonne/*de 0 a 6*/);
    void ordi();
    int ouAtteriraLaPieceDansCetColonne(int colonne);
    bool partieFini();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();


    void on_pushButton_clicked();


private:
    Ui::mainFile *ui;
    QLabel *listeLabel;
    QList<QLabel*> listeLabelList;
    bool auJoueurDeJouer;
    bool ordiJaune;
};

#endif // MAINFILE_H
