#include "mainfile.h"
#include "ui_mainfile.h"

#include <QMessageBox>
#include <qDebug>
/*
-------
-------
-------
-------
-------623
-------564
FF0000 = jaune
FF0000 = red
FFFFFF = blanc
0000FF = bleu
listeLabelList[k]->setStyleSheet("background-color: #FFFFFF;");
listeLabelList[k]->setStyleSheet("");


setStyleSheet("background-color: #FFFFFF; border-radius: 34px;");//blanc
setStyleSheet("background-color: #FF0000; border-radius: 34px;");//jaune
setStyleSheet("background-color: #FF0000; border-radius: 34px;");//red
setStyleSheet("background-color: #0000FF; border-radius: 34px;");//bleu

*/
mainFile::mainFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainFile),
    auJoueurDeJouer(false)
{//Le premier a jouer est jaune
    ui->setupUi(this);
    //QList<QLabel*> listeLabelList;
    setWindowTitle("Puissance 4 !");
    setMinimumSize(468,525);//lrgeur,hauteur
    setModal(true);
    int k=0,j=0;
    for(int i=1;i<7;i++)//i=1 car les boutons sont huste au dessus.
    {
        for(j=0;j<7;j++)// < 6 car un tableaux commence par 0
        {
            listeLabelList.push_back(new QLabel());
            ui->gridLayout->addWidget(listeLabelList[k],i,j);//0,0 = colone,ligne
            listeLabelList[k]->setStyleSheet("background-color: #FFFFFF; border-radius: 34px;");
            k++;
        }
    }
    ordiJaune = false;
}
mainFile::~mainFile()
{
    for(int i=0;i<42;i++)
    {
        delete listeLabelList[i];
        listeLabelList[i]=0;
    }
    delete ui;
}
bool mainFile::partieACommence()
{
    if(listeLabelList[35]->styleSheet()!="background-color: #FFFFFF; border-radius: 34px;")
        return true;
    else if(listeLabelList[36]->styleSheet()!="background-color: #FFFFFF; border-radius: 34px;")
        return true;
    else if(listeLabelList[37]->styleSheet()!="background-color: #FFFFFF; border-radius: 34px;")
        return true;
    else if(listeLabelList[38]->styleSheet()!="background-color: #FFFFFF; border-radius: 34px;")
        return true;
    else if(listeLabelList[39]->styleSheet()!="background-color: #FFFFFF; border-radius: 34px;")
        return true;
    else if(listeLabelList[40]->styleSheet()!="background-color: #FFFFFF; border-radius: 34px;")
        return true;
    else if(listeLabelList[41]->styleSheet()!="background-color: #FFFFFF; border-radius: 34px;")
        return true;
    return false;//la partie n'a pas commencé
}

void mainFile::disableAllButonColon()
{
    ui->pushButton_1->setDisabled(true);
    ui->pushButton_2->setDisabled(true);
    ui->pushButton_3->setDisabled(true);
    ui->pushButton_4->setDisabled(true);
    ui->pushButton_5->setDisabled(true);
    ui->pushButton_6->setDisabled(true);
    ui->pushButton_7->setDisabled(true);
    ui->pushButton->setDisabled(false);
}
void mainFile::enableAllButonColon()
{
    ui->pushButton_1->setDisabled(false);
    ui->pushButton_2->setDisabled(false);
    ui->pushButton_3->setDisabled(false);
    ui->pushButton_4->setDisabled(false);
    ui->pushButton_5->setDisabled(false);
    ui->pushButton_6->setDisabled(false);
    ui->pushButton_7->setDisabled(false);
    ui->pushButton->setDisabled(true);
}
void mainFile::on_pushButton_1_clicked()
{
    if(!partieACommence())
        ordiJaune=false;
    if(ordiJaune && auJoueurDeJouer)
    {set1CouleurTo(false,0);auJoueurDeJouer = false;disableAllButonColon();}
    else if(!ordiJaune && auJoueurDeJouer)
    {set1CouleurTo(true,0);auJoueurDeJouer = false;disableAllButonColon();}
    else if(ordiJaune && !auJoueurDeJouer)
    {set1CouleurTo(true,0);auJoueurDeJouer = false;disableAllButonColon();}
    else if(!ordiJaune && !auJoueurDeJouer)
    {set1CouleurTo(false,0);auJoueurDeJouer = false;disableAllButonColon();}
    else
        QMessageBox::critical(this,"Erreur","on_pushButton_1_clicked():in else");
    qDebug() << "ordiJaune : " << ordiJaune;
}
void mainFile::on_pushButton_2_clicked()
{
    if(!partieACommence())
        ordiJaune=false;
    if(ordiJaune && auJoueurDeJouer)
    {set1CouleurTo(false,1);auJoueurDeJouer = false;disableAllButonColon();}
    else if(!ordiJaune && auJoueurDeJouer)
    {set1CouleurTo(true,1);auJoueurDeJouer = false;disableAllButonColon();}
    else if(ordiJaune && !auJoueurDeJouer)
    {set1CouleurTo(true,1);auJoueurDeJouer = false;disableAllButonColon();}
    else if(!ordiJaune && !auJoueurDeJouer)
    {set1CouleurTo(false,1);auJoueurDeJouer = false;disableAllButonColon();}
    else
        QMessageBox::critical(this,"Erreur","on_pushButton_4_clicked():in else");
}
void mainFile::on_pushButton_3_clicked()
{
    if(!partieACommence())
        ordiJaune=false;
    if(ordiJaune && auJoueurDeJouer)
    {set1CouleurTo(false,2);auJoueurDeJouer = false;disableAllButonColon();}
    else if(!ordiJaune && auJoueurDeJouer)
    {set1CouleurTo(true,2);auJoueurDeJouer = false;disableAllButonColon();}
    else if(ordiJaune && !auJoueurDeJouer)
    {set1CouleurTo(true,2);auJoueurDeJouer = false;disableAllButonColon();}
    else if(!ordiJaune && !auJoueurDeJouer)
    {set1CouleurTo(false,2);auJoueurDeJouer = false;disableAllButonColon();}
    else
        QMessageBox::critical(this,"Erreur","on_pushButton_3_clicked():in else");
}
void mainFile::on_pushButton_4_clicked()
{
    if(!partieACommence())
        ordiJaune=false;
    if(ordiJaune && auJoueurDeJouer)
    {set1CouleurTo(false,3);auJoueurDeJouer = false;disableAllButonColon();}
    else if(!ordiJaune && auJoueurDeJouer)
    {set1CouleurTo(true,3);auJoueurDeJouer = false;disableAllButonColon();}
    else if(ordiJaune && !auJoueurDeJouer)
    {set1CouleurTo(true,3);auJoueurDeJouer = false;disableAllButonColon();}
    else if(!ordiJaune && !auJoueurDeJouer)
    {set1CouleurTo(false,3);auJoueurDeJouer = false;disableAllButonColon();}
    else
        QMessageBox::critical(this,"Erreur","on_pushButton_4_clicked():in else");
}
void mainFile::on_pushButton_5_clicked()
{
    if(!partieACommence())
        ordiJaune=false;
    if(ordiJaune && auJoueurDeJouer)
    {set1CouleurTo(false,4);auJoueurDeJouer = false;disableAllButonColon();}
    else if(!ordiJaune && auJoueurDeJouer)
    {set1CouleurTo(true,4);auJoueurDeJouer = false;disableAllButonColon();}
    else if(ordiJaune && !auJoueurDeJouer)
    {set1CouleurTo(true,4);auJoueurDeJouer = false;disableAllButonColon();}
    else if(!ordiJaune && !auJoueurDeJouer)
    {set1CouleurTo(false,4);auJoueurDeJouer = false;disableAllButonColon();}
    else
        QMessageBox::critical(this,"Erreur","on_pushButton_5_clicked():in else");
}
void mainFile::on_pushButton_6_clicked()
{
    if(!partieACommence())
        ordiJaune=false;
    if(ordiJaune && auJoueurDeJouer)
    {set1CouleurTo(false,5);auJoueurDeJouer = false;disableAllButonColon();}
    else if(!ordiJaune && auJoueurDeJouer)
    {set1CouleurTo(true,5);auJoueurDeJouer = false;disableAllButonColon();}
    else if(ordiJaune && !auJoueurDeJouer)
    {set1CouleurTo(true,5);auJoueurDeJouer = false;disableAllButonColon();}
    else if(!ordiJaune && !auJoueurDeJouer)
    {set1CouleurTo(false,5);auJoueurDeJouer = false;disableAllButonColon();}
    else
        QMessageBox::critical(this,"Erreur","on_pushButton_6_clicked():in else");
}
void mainFile::on_pushButton_7_clicked()
{
    if(!partieACommence())
        ordiJaune=false;
    if(ordiJaune && auJoueurDeJouer)
    {set1CouleurTo(false,6);auJoueurDeJouer = false;disableAllButonColon();}
    else if(!ordiJaune && auJoueurDeJouer)
    {set1CouleurTo(true,6);auJoueurDeJouer = false;disableAllButonColon();}
    else if(ordiJaune && !auJoueurDeJouer)
    {set1CouleurTo(true,6);auJoueurDeJouer = false;disableAllButonColon();}
    else if(!ordiJaune && !auJoueurDeJouer)
    {set1CouleurTo(false,6);auJoueurDeJouer = false;disableAllButonColon();}
    else
        QMessageBox::critical(this,"Erreur","on_pushButton_7_clicked():in else");
}

void mainFile::on_pushButton_clicked()
{
    if(!partieACommence())
    {
        auJoueurDeJouer = false;
        ordiJaune = true;
        ordi();
        return;
    }
    else
        ordi();
}

void mainFile::set1CouleurTo(bool const&setjaune,int const&colonne/*de 0 a 6*/)
{
    if(!partieACommence())
        auJoueurDeJouer = true;
    if(setjaune)
    {
        if(listeLabelList[colonne+35]->styleSheet()=="background-color: #FFFFFF; border-radius: 34px;")
        {    //
            listeLabelList[colonne+35]->setStyleSheet("background-color: #FF0000; border-radius: 34px;");
        }
        else if(listeLabelList[colonne+28]->styleSheet()=="background-color: #FFFFFF; border-radius: 34px;")
        {    //
            listeLabelList[colonne+28]->setStyleSheet("background-color: #FF0000; border-radius: 34px;");
        }
        else if(listeLabelList[colonne+21]->styleSheet()=="background-color: #FFFFFF; border-radius: 34px;")
        {    //
            listeLabelList[colonne+21]->setStyleSheet("background-color: #FF0000; border-radius: 34px;");
        }
        else if(listeLabelList[colonne+14]->styleSheet()=="background-color: #FFFFFF; border-radius: 34px;")
        {    //
            listeLabelList[colonne+14]->setStyleSheet("background-color: #FF0000; border-radius: 34px;");
        }
        else if(listeLabelList[colonne+7]->styleSheet()=="background-color: #FFFFFF; border-radius: 34px;")
        {    //
            listeLabelList[colonne+7]->setStyleSheet("background-color: #FF0000; border-radius: 34px;");
        }
        else if(listeLabelList[colonne]->styleSheet()=="background-color: #FFFFFF; border-radius: 34px;")
        {    //
            listeLabelList[colonne]->setStyleSheet("background-color: #FF0000; border-radius: 34px;");
        }
        else
            QMessageBox::critical(this,"Erreur","on_pushButton_1_clicked():in else");
    }
    else
    {
        if(listeLabelList[colonne+35]->styleSheet()=="background-color: #FFFFFF; border-radius: 34px;")
        {    //
            listeLabelList[colonne+35]->setStyleSheet("background-color: #FFFF00; border-radius: 34px;");
        }
        else if(listeLabelList[colonne+28]->styleSheet()=="background-color: #FFFFFF; border-radius: 34px;")
        {    //
            listeLabelList[colonne+28]->setStyleSheet("background-color: #FFFF00; border-radius: 34px;");
        }
        else if(listeLabelList[colonne+21]->styleSheet()=="background-color: #FFFFFF; border-radius: 34px;")
        {    //
            listeLabelList[colonne+21]->setStyleSheet("background-color: #FFFF00; border-radius: 34px;");
        }
        else if(listeLabelList[colonne+14]->styleSheet()=="background-color: #FFFFFF; border-radius: 34px;")
        {    //
            listeLabelList[colonne+14]->setStyleSheet("background-color: #FFFF00; border-radius: 34px;");
        }
        else if(listeLabelList[colonne+7]->styleSheet()=="background-color: #FFFFFF; border-radius: 34px;")
        {    //
            listeLabelList[colonne+7]->setStyleSheet("background-color: #FFFF00; border-radius: 34px;");
        }
        else if(listeLabelList[colonne]->styleSheet()=="background-color: #FFFFFF; border-radius: 34px;")
        {    //
            qDebug()<<"set1TOOnecolonne : "<<colonne;
            listeLabelList[colonne]->setStyleSheet("background-color: #FFFF00; border-radius: 34px;");
        }
        else
            QMessageBox::critical(this,"Erreur","Toutes les case de cet colonne sont occupé. Jouer sur une autre colonne.");
    }
}
int mainFile::ouAtteriraLaPieceDansCetColonne(int colonne)//cherche la ou la pièce attérie pour une colonne donné en argument
{
    if(colonne>7)
        QMessageBox::information(this,"titre","message");
    if(listeLabelList[colonne+35]->styleSheet()=="background-color: #FFFFFF; border-radius: 34px;")
        return colonne+35;
    else if(listeLabelList[colonne+28]->styleSheet()=="background-color: #FFFFFF; border-radius: 34px;")
        return colonne+28;
    else if(listeLabelList[colonne+21]->styleSheet()=="background-color: #FFFFFF; border-radius: 34px;")
        return colonne+21;
    else if(listeLabelList[colonne+12]->styleSheet()=="background-color: #FFFFFF; border-radius: 34px;")
        return colonne+12;
    else if(listeLabelList[colonne+5]->styleSheet()=="background-color: #FFFFFF; border-radius: 34px;")
        return colonne+5;
    else if(listeLabelList[colonne-1]->styleSheet()=="background-color: #FFFFFF; border-radius: 34px;")
        return colonne-1;
    QMessageBox::information(this,"titre","Vous ne pouvez plus jouer, Aucune case ne sont disponnible !");
    return 0;
}

bool mainFile::partieFini()
{
    //
    return true;
}

void mainFile::ordi()
{
    int tableauScore[6];
    for(int j=0;j<6;j++)
        tableauScore[j]=0;
    /*
 0  1 2 3 4 5 6 7 8 9
    3 3 1 5 1 3 3
 .  - - - . - - - . 3
 -  . - - . - - . 3
 -  - . - . - . - 3
 .  . . . . . . . 5
 -  - . - . - . - 3
 -  . - - . - - . 3
 .  - - - . - - - . 3
    */
   // int tableau1[10]=0;//4 car la première colonne ne possède pas d'ouest
    /*
    . - . .
    . . .
    . . . */
/** . . . **//*
    . .

    */
   // int tableau2[19];

    QString colorOrdi="",colorUser="";
    if(ordiJaune)
        colorOrdi="background-color: #FF0000; border-radius: 34px;";//jaune
    else
        colorOrdi="background-color: #FFFF00; border-radius: 34px;";//rouge
    if(ordiJaune)
        colorUser="background-color: #FFFF00; border-radius: 34px;";//rouge
    else
        colorUser="background-color: #FF0000; border-radius: 34px;";//jaune
    QString colorBlanc="background-color: #FFFFFF; border-radius: 34px;";
    //defense:
        //1 point : un jeton pouvant etre bloqué
        //2 point : deux jeton sont a proximité mais pas dans la même trajectoire
        //4 ou 3 point : deux jeton sont a bloqué (3point pour évité le coup du berger)
        //8 point : trois jeton sont a bloqué
    //attaque:
        //1 point : un jeton est a proximité(pour le rejoindre)
        //3 point : 2 jetons sont déja aligné mais on ne pourra pas faire de puissance 5(pour faire un coup du berger)
        //6 point : 2 jetons sont aligné ont pourra faire un puissance 5.
        //30 point : 3 jetons sont en place, IL EN MANQUE PLUS QU'UN !
    int indexCaseEnQ/*indexCaseEnQuestion*/,score=0,nbNotBlack=0,nbBlack=0;//nbNotBlack= nb de couleur aligné
    //qui ne sont pas de la couleur du vrai joueur

    //    \/|-
    for(int i=0;i<=6;i++)
    {
        qDebug() << "360 : " << QString::number(ouAtteriraLaPieceDansCetColonne(i));
        indexCaseEnQ=ouAtteriraLaPieceDansCetColonne(i);
        if(indexCaseEnQ>24 && indexCaseEnQ!=28 && indexCaseEnQ!=29 && indexCaseEnQ!=35 && indexCaseEnQ!=36 && indexCaseEnQ!=37 && listeLabelList[indexCaseEnQ-24]->styleSheet()==colorUser)
        {
            nbNotBlack=0;nbBlack++;
        }
        else if(indexCaseEnQ>24 && indexCaseEnQ!=28 && indexCaseEnQ!=29 && indexCaseEnQ!=35 && indexCaseEnQ!=36 && indexCaseEnQ!=37 && listeLabelList[indexCaseEnQ-24]->styleSheet()==colorOrdi){
            nbNotBlack+=1;score+=20;
        }
        else if(indexCaseEnQ>24 && indexCaseEnQ!=28 && indexCaseEnQ!=29 && indexCaseEnQ!=35 && indexCaseEnQ!=36 && indexCaseEnQ!=37 && listeLabelList[indexCaseEnQ-24]->styleSheet()==colorBlanc){//couleur=blanc
            nbNotBlack+=1;score+=11;
        }
        if(indexCaseEnQ>16 && indexCaseEnQ!=28 && indexCaseEnQ!=29 && indexCaseEnQ!=35 && indexCaseEnQ!=36 && listeLabelList[indexCaseEnQ-16]->styleSheet()==colorUser)
        {
            nbNotBlack=0;nbBlack++;
        }
        else if(indexCaseEnQ>16 && indexCaseEnQ!=28 && indexCaseEnQ!=29 && indexCaseEnQ!=35 && indexCaseEnQ!=36 && listeLabelList[indexCaseEnQ-16]->styleSheet()==colorOrdi){
            nbNotBlack+=1;score+=20;
        }
        else if(indexCaseEnQ>16 && indexCaseEnQ!=28 && indexCaseEnQ!=29 && indexCaseEnQ!=35 && indexCaseEnQ!=36 && listeLabelList[indexCaseEnQ-16]->styleSheet()==colorBlanc){//couleur=blanc
            nbNotBlack+=1;score+=11;
        }
        if(indexCaseEnQ>8 && indexCaseEnQ!=18 && indexCaseEnQ!=21 && indexCaseEnQ!=28 && indexCaseEnQ!=35 && listeLabelList[indexCaseEnQ-8]->styleSheet()==colorUser)
        {
            nbNotBlack=0;nbBlack++;
        }
        else if(indexCaseEnQ>8 && indexCaseEnQ!=18 && indexCaseEnQ!=21 && indexCaseEnQ!=28 && indexCaseEnQ!=35 && listeLabelList[indexCaseEnQ-8]->styleSheet()==colorOrdi){
            nbNotBlack+=1;score+=20;
        }
        else if(indexCaseEnQ>8 && indexCaseEnQ!=18 && indexCaseEnQ!=21 && indexCaseEnQ!=28 && indexCaseEnQ!=35 && listeLabelList[indexCaseEnQ-8]->styleSheet()==colorBlanc){//couleur=blanc
            nbNotBlack+=1;score+=11;
        }
        else
            qDebug() << "errrrrrreur... indexCaseEnQ : "<< indexCaseEnQ << " : " <<listeLabelList[indexCaseEnQ-8]->styleSheet();

//centre

        if(indexCaseEnQ<34 && indexCaseEnQ!=27 && indexCaseEnQ!=20 && indexCaseEnQ!=13 && listeLabelList[indexCaseEnQ+8]->styleSheet()==colorUser)
        {
            nbNotBlack=0;nbBlack++;
        }
        else if(indexCaseEnQ<34 && indexCaseEnQ!=27 && indexCaseEnQ!=20 && indexCaseEnQ!=13 && listeLabelList[indexCaseEnQ+8]->styleSheet()==colorOrdi){
            nbNotBlack+=1;score+=20;
        }
        else if(indexCaseEnQ<34 && indexCaseEnQ!=27 && indexCaseEnQ!=20 && indexCaseEnQ!=13 && listeLabelList[indexCaseEnQ+8]->styleSheet()==colorBlanc){//couleur=blanc
            nbNotBlack+=1;score+=11;
        }
        if(indexCaseEnQ<26 && indexCaseEnQ!=20 && indexCaseEnQ!=13 && indexCaseEnQ!=6 && indexCaseEnQ!=5 && indexCaseEnQ!=12 && indexCaseEnQ!=19 && indexCaseEnQ!=26 && indexCaseEnQ!=33 && indexCaseEnQ!=40  && listeLabelList[indexCaseEnQ+16]->styleSheet()==colorUser)
        {
            nbNotBlack=0;nbBlack++;
        }
        else if(indexCaseEnQ<26 && indexCaseEnQ!=20 && indexCaseEnQ!=13 && indexCaseEnQ!=6 && indexCaseEnQ!=5 && indexCaseEnQ!=12 && indexCaseEnQ!=19 && indexCaseEnQ!=26 && indexCaseEnQ!=33 && indexCaseEnQ!=40  && listeLabelList[indexCaseEnQ+16]->styleSheet()==colorOrdi){
            nbNotBlack+=1;score+=20;
        }
        else if(indexCaseEnQ<26 && indexCaseEnQ!=20 && indexCaseEnQ!=13 && indexCaseEnQ!=6 && indexCaseEnQ!=5 && indexCaseEnQ!=12 && indexCaseEnQ!=19 && indexCaseEnQ!=26 && indexCaseEnQ!=33 && indexCaseEnQ!=40  && listeLabelList[indexCaseEnQ+16]->styleSheet()==colorBlanc){//couleur=blanc
            nbNotBlack+=1;score+=11;
        }
        if(indexCaseEnQ<17 && indexCaseEnQ!=4 && indexCaseEnQ!=11 && indexCaseEnQ!=13 && indexCaseEnQ!=6 && indexCaseEnQ!=5 && indexCaseEnQ!=12 && indexCaseEnQ!=19 && listeLabelList[indexCaseEnQ+24]->styleSheet()==colorUser)
        {
            nbNotBlack=0;nbBlack++;
        }
        else if(indexCaseEnQ<17 && indexCaseEnQ!=4 && indexCaseEnQ!=11 && indexCaseEnQ!=13 && indexCaseEnQ!=6 && indexCaseEnQ!=5 && indexCaseEnQ!=12 && indexCaseEnQ!=19 && listeLabelList[indexCaseEnQ+24]->styleSheet()==colorOrdi){
            nbNotBlack+=1;score+=20;
        }
        else if(indexCaseEnQ<17 && indexCaseEnQ!=4 && indexCaseEnQ!=11 && indexCaseEnQ!=13 && indexCaseEnQ!=6 && indexCaseEnQ!=5 && indexCaseEnQ!=12 && indexCaseEnQ!=19 && listeLabelList[indexCaseEnQ+24]->styleSheet()==colorBlanc){//couleur=blanc
            nbNotBlack+=1;score+=11;
        }
        else
        if(nbBlack>=3)
            score+=80;
        nbBlack=0;
        qDebug() << "429 : " << QString::number(score);


        /// /             \   (se dirige vers le bas)      ///////////////////////
        /// /             /   (se dirige vers le haut)      ///////////////////////

        /// / suivant :   -   (se dirige vers la droite)   ///////////////////////
        /// / suivant :   |   (se dirige vers le bas)      ///////////////////////


        if(indexCaseEnQ<20 && indexCaseEnQ!=0 && indexCaseEnQ!=1 && indexCaseEnQ!=2 && indexCaseEnQ!=7 && indexCaseEnQ!=8 && indexCaseEnQ!=9 && indexCaseEnQ!=14 && indexCaseEnQ!=15 && indexCaseEnQ!=16 && listeLabelList[indexCaseEnQ+18]->styleSheet()==colorUser)
        {
            nbBlack++;
            if(nbNotBlack<4)
                nbNotBlack=0;
        }
        else if(indexCaseEnQ<20 && indexCaseEnQ!=0 && indexCaseEnQ!=1 && indexCaseEnQ!=2 && indexCaseEnQ!=7 && indexCaseEnQ!=8 && indexCaseEnQ!=9 && indexCaseEnQ!=14 && indexCaseEnQ!=15 && indexCaseEnQ!=16 && listeLabelList[indexCaseEnQ+18]->styleSheet()==colorOrdi){
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=20;
        }
        else if(indexCaseEnQ<20 && indexCaseEnQ!=0 && indexCaseEnQ!=1 && indexCaseEnQ!=2 && indexCaseEnQ!=7 && indexCaseEnQ!=8 && indexCaseEnQ!=9 && indexCaseEnQ!=14 && indexCaseEnQ!=15 && indexCaseEnQ!=16 && listeLabelList[indexCaseEnQ+18]->styleSheet()==colorBlanc){//couleur=blanc
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=11;
        }
        if(indexCaseEnQ<28 && indexCaseEnQ!=0 && indexCaseEnQ!=1 && indexCaseEnQ!=7 && indexCaseEnQ!=8 && indexCaseEnQ!=14 && indexCaseEnQ!=15 && indexCaseEnQ!=21 && indexCaseEnQ!=22 &&  listeLabelList[indexCaseEnQ+12]->styleSheet()==colorUser)
        {
            nbBlack++;
            if(nbNotBlack<4)
                nbNotBlack=0;
        }
        else if(indexCaseEnQ<28 && indexCaseEnQ!=0 && indexCaseEnQ!=1 && indexCaseEnQ!=7 && indexCaseEnQ!=8 && indexCaseEnQ!=14 && indexCaseEnQ!=15 && indexCaseEnQ!=21 && indexCaseEnQ!=22 &&  listeLabelList[indexCaseEnQ+12]->styleSheet()==colorOrdi){
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=20;
        }
        else if(indexCaseEnQ<28 && indexCaseEnQ!=0 && indexCaseEnQ!=1 && indexCaseEnQ!=7 && indexCaseEnQ!=8 && indexCaseEnQ!=14 && indexCaseEnQ!=15 && indexCaseEnQ!=21 && indexCaseEnQ!=22 &&  listeLabelList[indexCaseEnQ+12]->styleSheet()==colorBlanc){//couleur=blanc
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=11;
        }
        if(indexCaseEnQ<35 && indexCaseEnQ!=0 && indexCaseEnQ!=7 && indexCaseEnQ!=14 && indexCaseEnQ!=21 && indexCaseEnQ!=28 && listeLabelList[indexCaseEnQ+6]->styleSheet()==colorUser)
        {
            nbBlack++;
            if(nbNotBlack<4)
                nbNotBlack=0;
        }
        else if(indexCaseEnQ<35 && indexCaseEnQ!=0 && indexCaseEnQ!=7 && indexCaseEnQ!=14 && indexCaseEnQ!=21 && indexCaseEnQ!=28 && listeLabelList[indexCaseEnQ+6]->styleSheet()==colorOrdi){
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=20;
        }
        else if(indexCaseEnQ<35 && indexCaseEnQ!=0 && indexCaseEnQ!=7 && indexCaseEnQ!=14 && indexCaseEnQ!=21 && indexCaseEnQ!=28 && listeLabelList[indexCaseEnQ+6]->styleSheet()==colorBlanc){//couleur=blanc
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=11;
        }
        if(indexCaseEnQ>6 && indexCaseEnQ!=13 && indexCaseEnQ!=20 && indexCaseEnQ!=27 && indexCaseEnQ!=34 && indexCaseEnQ!=41 && listeLabelList[indexCaseEnQ-6]->styleSheet()==colorUser)
        {
            nbBlack++;
            if(nbNotBlack<4)
                nbNotBlack=0;
        }
        else if(indexCaseEnQ>6 && indexCaseEnQ!=13 && indexCaseEnQ!=20 && indexCaseEnQ!=27 && indexCaseEnQ!=34 && indexCaseEnQ!=41 && listeLabelList[indexCaseEnQ-6]->styleSheet()==colorOrdi){
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=20;
        }
        else if(indexCaseEnQ>6 && indexCaseEnQ!=13 && indexCaseEnQ!=20 && indexCaseEnQ!=27 && indexCaseEnQ!=34 && indexCaseEnQ!=41 && listeLabelList[indexCaseEnQ-6]->styleSheet()==colorBlanc){//couleur=blanc
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=11;
        }
        if(indexCaseEnQ>13 && indexCaseEnQ!=19 && indexCaseEnQ!=20 && indexCaseEnQ!=26 && indexCaseEnQ!=27 && indexCaseEnQ!=33 && indexCaseEnQ!=34 && indexCaseEnQ!=40 && indexCaseEnQ!=41 && listeLabelList[indexCaseEnQ-12]->styleSheet()==colorUser)
        {
            nbBlack++;
            if(nbNotBlack<4)
                nbNotBlack=0;
        }
        else if(indexCaseEnQ>13 && indexCaseEnQ!=19 && indexCaseEnQ!=20 && indexCaseEnQ!=26 && indexCaseEnQ!=27 && indexCaseEnQ!=33 && indexCaseEnQ!=34 && indexCaseEnQ!=40 && indexCaseEnQ!=41 && listeLabelList[indexCaseEnQ-12]->styleSheet()==colorOrdi){
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=20;
        }
        else if(indexCaseEnQ>13 && indexCaseEnQ!=19 && indexCaseEnQ!=20 && indexCaseEnQ!=26 && indexCaseEnQ!=27 && indexCaseEnQ!=33 && indexCaseEnQ!=34 && indexCaseEnQ!=40 && indexCaseEnQ!=41 && listeLabelList[indexCaseEnQ-12]->styleSheet()==colorBlanc){//couleur=blanc
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=11;
        }
        if(indexCaseEnQ>20 && indexCaseEnQ!=11 && indexCaseEnQ!=12 && indexCaseEnQ!=13 && indexCaseEnQ!=18 && indexCaseEnQ!=19 && indexCaseEnQ!=20 && indexCaseEnQ!=25 && indexCaseEnQ!=26 && indexCaseEnQ!=27 && indexCaseEnQ!=32 && indexCaseEnQ!=33 && indexCaseEnQ!=34 && indexCaseEnQ!=39 && indexCaseEnQ!=40 && indexCaseEnQ!=41 && listeLabelList[indexCaseEnQ-18]->styleSheet()==colorUser)
        {
            nbBlack++;
            if(nbNotBlack<4)
                nbNotBlack=0;
        }
        else if(indexCaseEnQ>20 && indexCaseEnQ!=11 && indexCaseEnQ!=12 && indexCaseEnQ!=13 && indexCaseEnQ!=18 && indexCaseEnQ!=19 && indexCaseEnQ!=20 && indexCaseEnQ!=25 && indexCaseEnQ!=26 && indexCaseEnQ!=27 && indexCaseEnQ!=32 && indexCaseEnQ!=33 && indexCaseEnQ!=34 && indexCaseEnQ!=39 && indexCaseEnQ!=40 && indexCaseEnQ!=41 && listeLabelList[indexCaseEnQ-18]->styleSheet()==colorOrdi){
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=20;
        }
        else if(indexCaseEnQ>20 && indexCaseEnQ!=11 && indexCaseEnQ!=12 && indexCaseEnQ!=13 && indexCaseEnQ!=18 && indexCaseEnQ!=19 && indexCaseEnQ!=20 && indexCaseEnQ!=25 && indexCaseEnQ!=26 && indexCaseEnQ!=27 && indexCaseEnQ!=32 && indexCaseEnQ!=33 && indexCaseEnQ!=34 && indexCaseEnQ!=39 && indexCaseEnQ!=40 && indexCaseEnQ!=41 && listeLabelList[indexCaseEnQ-18]->styleSheet()==colorBlanc){//couleur=blanc
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=11;
        }
        if(nbBlack>=3)
            score+=80;
        nbBlack=0;
        qDebug() << "360 : " << QString::number(score);


        /// - puis | ///////////////////////


        if(indexCaseEnQ>2 && indexCaseEnQ!=7 && indexCaseEnQ!=8 && indexCaseEnQ!=9 && indexCaseEnQ!=14 && indexCaseEnQ!=15 && indexCaseEnQ!=16 && indexCaseEnQ!=21 && indexCaseEnQ!=22 && indexCaseEnQ!=23 && indexCaseEnQ!=28 && indexCaseEnQ!=29 && indexCaseEnQ!=30 && indexCaseEnQ!=35 && indexCaseEnQ!=36 && indexCaseEnQ!=37 && listeLabelList[indexCaseEnQ-3]->styleSheet()==colorUser)
        {
            nbBlack++;
            if(nbNotBlack<4)
                nbNotBlack=0;
        }
        else if(indexCaseEnQ>2 && indexCaseEnQ!=7 && indexCaseEnQ!=8 && indexCaseEnQ!=9 && indexCaseEnQ!=14 && indexCaseEnQ!=15 && indexCaseEnQ!=16 && indexCaseEnQ!=21 && indexCaseEnQ!=22 && indexCaseEnQ!=23 && indexCaseEnQ!=28 && indexCaseEnQ!=29 && indexCaseEnQ!=30 && indexCaseEnQ!=35 && indexCaseEnQ!=36 && indexCaseEnQ!=37 && listeLabelList[indexCaseEnQ-3]->styleSheet()==colorOrdi){
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=20;
        }
        else if(indexCaseEnQ>2 && indexCaseEnQ!=7 && indexCaseEnQ!=8 && indexCaseEnQ!=9 && indexCaseEnQ!=14 && indexCaseEnQ!=15 && indexCaseEnQ!=16 && indexCaseEnQ!=21 && indexCaseEnQ!=22 && indexCaseEnQ!=23 && indexCaseEnQ!=28 && indexCaseEnQ!=29 && indexCaseEnQ!=30 && indexCaseEnQ!=35 && indexCaseEnQ!=36 && indexCaseEnQ!=37 && listeLabelList[indexCaseEnQ-3]->styleSheet()==colorBlanc){//couleur=blanc
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=11;
        }
        if(indexCaseEnQ>1 && indexCaseEnQ!=7 && indexCaseEnQ!=8 && indexCaseEnQ!=14 && indexCaseEnQ!=15 && indexCaseEnQ!=21 && indexCaseEnQ!=22 && indexCaseEnQ!=28 && indexCaseEnQ!=29 && indexCaseEnQ!=35 && indexCaseEnQ!=36 && listeLabelList[indexCaseEnQ-2]->styleSheet()==colorUser)
        {
            nbBlack++;
            if(nbNotBlack<4)
                nbNotBlack=0;
        }
        else if(indexCaseEnQ>1 && indexCaseEnQ!=7 && indexCaseEnQ!=8 && indexCaseEnQ!=14 && indexCaseEnQ!=15 && indexCaseEnQ!=21 && indexCaseEnQ!=22 && indexCaseEnQ!=28 && indexCaseEnQ!=29 && indexCaseEnQ!=35 && indexCaseEnQ!=36 && listeLabelList[indexCaseEnQ-2]->styleSheet()==colorOrdi){
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=20;
        }
        else if(indexCaseEnQ>1 && indexCaseEnQ!=7 && indexCaseEnQ!=8 && indexCaseEnQ!=14 && indexCaseEnQ!=15 && indexCaseEnQ!=21 && indexCaseEnQ!=22 && indexCaseEnQ!=28 && indexCaseEnQ!=29 && indexCaseEnQ!=35 && indexCaseEnQ!=36 && listeLabelList[indexCaseEnQ-2]->styleSheet()==colorBlanc){//couleur=blanc
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=11;
        }
        if(indexCaseEnQ!=0 && indexCaseEnQ!=7 && indexCaseEnQ!=14 && indexCaseEnQ!=21 && indexCaseEnQ!=28 && indexCaseEnQ!=35 && listeLabelList[indexCaseEnQ-1]->styleSheet()==colorUser)
        {
            nbBlack++;
            if(nbNotBlack<4)
                nbNotBlack=0;
        }
        else if(indexCaseEnQ!=0 && indexCaseEnQ!=7 && indexCaseEnQ!=14 && indexCaseEnQ!=21 && indexCaseEnQ!=28 && indexCaseEnQ!=35 && listeLabelList[indexCaseEnQ-1]->styleSheet()==colorOrdi){
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=20;
        }
        else if(indexCaseEnQ!=0 && indexCaseEnQ!=7 && indexCaseEnQ!=14 && indexCaseEnQ!=21 && indexCaseEnQ!=28 && indexCaseEnQ!=35 && listeLabelList[indexCaseEnQ-1]->styleSheet()==colorBlanc){//couleur=blanc
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=11;
        }
        if(nbNotBlack==3)
        {score+=50;nbNotBlack=0;}
        if(indexCaseEnQ!=6 && indexCaseEnQ!=13 && indexCaseEnQ!=20 && indexCaseEnQ!=27 && indexCaseEnQ!=34 && indexCaseEnQ!=41 && listeLabelList[indexCaseEnQ+1]->styleSheet()==colorUser)
        {
            nbBlack++;
            if(nbNotBlack<4)
                nbNotBlack=0;
        }
        else if(indexCaseEnQ!=6 && indexCaseEnQ!=13 && indexCaseEnQ!=20 && indexCaseEnQ!=27 && indexCaseEnQ!=34 && indexCaseEnQ!=41 && listeLabelList[indexCaseEnQ+1]->styleSheet()==colorOrdi){
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=20;
        }
        else if(indexCaseEnQ!=6 && indexCaseEnQ!=13 && indexCaseEnQ!=20 && indexCaseEnQ!=27 && indexCaseEnQ!=34 && indexCaseEnQ!=41 && listeLabelList[indexCaseEnQ+1]->styleSheet()==colorBlanc){//couleur=blanc
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=11;
        }
        if(nbNotBlack==3)
            {score+=50;nbNotBlack=0;}
        if(indexCaseEnQ!=5 && indexCaseEnQ!=12 && indexCaseEnQ!=19 && indexCaseEnQ!=26 && indexCaseEnQ!=33 && indexCaseEnQ!=40 && indexCaseEnQ!=6 && indexCaseEnQ!=13 && indexCaseEnQ!=20 && indexCaseEnQ!=27 && indexCaseEnQ!=34 && indexCaseEnQ!=41 && listeLabelList[indexCaseEnQ+2]->styleSheet()==colorUser)
        {
            nbBlack++;
            if(nbNotBlack<4)
                nbNotBlack=0;
        }
        else if(indexCaseEnQ!=5 && indexCaseEnQ!=12 && indexCaseEnQ!=19 && indexCaseEnQ!=26 && indexCaseEnQ!=33 && indexCaseEnQ!=40 && indexCaseEnQ!=6 && indexCaseEnQ!=13 && indexCaseEnQ!=20 && indexCaseEnQ!=27 && indexCaseEnQ!=34 && indexCaseEnQ!=41 && listeLabelList[indexCaseEnQ+2]->styleSheet()==colorOrdi){
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=20;
        }
        else if(indexCaseEnQ!=5 && indexCaseEnQ!=12 && indexCaseEnQ!=19 && indexCaseEnQ!=26 && indexCaseEnQ!=33 && indexCaseEnQ!=40 && indexCaseEnQ!=6 && indexCaseEnQ!=13 && indexCaseEnQ!=20 && indexCaseEnQ!=27 && indexCaseEnQ!=34 && indexCaseEnQ!=41 && listeLabelList[indexCaseEnQ+2]->styleSheet()==colorBlanc){//couleur=blanc
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=11;
        }
        if(nbNotBlack==3)
            {score+=50;nbNotBlack=0;}
        if(indexCaseEnQ!=5 && indexCaseEnQ!=12 && indexCaseEnQ!=19 && indexCaseEnQ!=26 && indexCaseEnQ!=33 && indexCaseEnQ!=40 && indexCaseEnQ!=6 && indexCaseEnQ!=13 && indexCaseEnQ!=20 && indexCaseEnQ!=27 && indexCaseEnQ!=34 && indexCaseEnQ!=41 &&  indexCaseEnQ!=4 && indexCaseEnQ!=11 && indexCaseEnQ!=18 && indexCaseEnQ!=25 && indexCaseEnQ!=32 && indexCaseEnQ!=39 && listeLabelList[indexCaseEnQ+3]->styleSheet()==colorUser)
        {
            nbBlack++;
            if(nbNotBlack<4)
                nbNotBlack=0;
        }
        else if(indexCaseEnQ!=5 && indexCaseEnQ!=12 && indexCaseEnQ!=19 && indexCaseEnQ!=26 && indexCaseEnQ!=33 && indexCaseEnQ!=40 && indexCaseEnQ!=6 && indexCaseEnQ!=13 && indexCaseEnQ!=20 && indexCaseEnQ!=27 && indexCaseEnQ!=34 && indexCaseEnQ!=41 &&  indexCaseEnQ!=4 && indexCaseEnQ!=11 && indexCaseEnQ!=18 && indexCaseEnQ!=25 && indexCaseEnQ!=32 && indexCaseEnQ!=39 && listeLabelList[indexCaseEnQ+3]->styleSheet()==colorOrdi){
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=20;
        }
        else if(indexCaseEnQ!=5 && indexCaseEnQ!=12 && indexCaseEnQ!=19 && indexCaseEnQ!=26 && indexCaseEnQ!=33 && indexCaseEnQ!=40 && indexCaseEnQ!=6 && indexCaseEnQ!=13 && indexCaseEnQ!=20 && indexCaseEnQ!=27 && indexCaseEnQ!=34 && indexCaseEnQ!=41 &&  indexCaseEnQ!=4 && indexCaseEnQ!=11 && indexCaseEnQ!=18 && indexCaseEnQ!=25 && indexCaseEnQ!=32 && indexCaseEnQ!=39 && listeLabelList[indexCaseEnQ+3]->styleSheet()==colorBlanc){//couleur=blanc
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=11;
        }
        if(nbNotBlack==3)
        {score+=50;}
        if(nbBlack>=3)
            score+=80;
        nbBlack=0;nbNotBlack=0;


        /// avant - maintenant :  | ///////////////////////


        if(indexCaseEnQ>20 && listeLabelList[indexCaseEnQ-21]->styleSheet()==colorUser)
        {
            nbBlack++;
            if(nbNotBlack<4)
                nbNotBlack=0;
        }
        else if(indexCaseEnQ>20 && listeLabelList[indexCaseEnQ-21]->styleSheet()==colorOrdi){
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=20;
        }
        else if(indexCaseEnQ>20 && listeLabelList[indexCaseEnQ-21]->styleSheet()==colorBlanc){//couleur=blanc
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=11;
        }
        if(indexCaseEnQ>13 && listeLabelList[indexCaseEnQ-14]->styleSheet()==colorUser)
        {
            nbBlack++;
            if(nbNotBlack<4)
                nbNotBlack=0;
        }
        else if(indexCaseEnQ>13 && listeLabelList[indexCaseEnQ-14]->styleSheet()==colorOrdi){
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=20;
        }
        else if(indexCaseEnQ>13 && listeLabelList[indexCaseEnQ-14]->styleSheet()==colorBlanc){//couleur=blanc
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=11;
        }
        if(indexCaseEnQ>6 && listeLabelList[indexCaseEnQ-7]->styleSheet()==colorUser)
        {
            nbBlack++;
            if(nbNotBlack<4)
                nbNotBlack=0;
        }
        else if(indexCaseEnQ>6 && listeLabelList[indexCaseEnQ-7]->styleSheet()==colorOrdi){
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=20;
        }
        else if(indexCaseEnQ>6 && listeLabelList[indexCaseEnQ-7]->styleSheet()==colorBlanc){//couleur=blanc
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=11;
        }
        if(nbNotBlack==2)
            score+=4;
        if(nbNotBlack==3)
            {score+=80;nbNotBlack=0;}
        if(indexCaseEnQ<35 && listeLabelList[indexCaseEnQ+7]->styleSheet()==colorUser)
        {
            nbBlack++;
            if(nbNotBlack<4)
                nbNotBlack=0;
        }
        else if(indexCaseEnQ<35 && listeLabelList[indexCaseEnQ+7]->styleSheet()==colorOrdi){
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=20;
        }
        else if(indexCaseEnQ<35 && listeLabelList[indexCaseEnQ+7]->styleSheet()==colorBlanc){//couleur=blanc
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=11;
        }
        if(nbNotBlack==3)
        {
            score+=80;
            nbNotBlack=0;
        }
        if(indexCaseEnQ<28 && listeLabelList[indexCaseEnQ+14]->styleSheet()==colorUser)
        {
            nbBlack++;
            if(nbNotBlack<4)
                nbNotBlack=0;
        }
        else if(indexCaseEnQ<28 && listeLabelList[indexCaseEnQ+14]->styleSheet()==colorOrdi){
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=20;
        }
        else if(indexCaseEnQ<28 && listeLabelList[indexCaseEnQ+14]->styleSheet()==colorBlanc){//couleur=blanc
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=11;
        }
        if(nbNotBlack==3)
        {
            score+=80;
            nbNotBlack=0;
        }
        if(indexCaseEnQ<21 && listeLabelList[indexCaseEnQ+3]->styleSheet()==colorUser)
        {
            nbBlack++;
            if(nbNotBlack<4)
                nbNotBlack=0;
        }
        else if(indexCaseEnQ<21 && listeLabelList[indexCaseEnQ+3]->styleSheet()==colorOrdi){
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=20;
        }
        else if(indexCaseEnQ<21 && listeLabelList[indexCaseEnQ+3]->styleSheet()==colorBlanc){//couleur=blanc
            if(nbNotBlack<4)
                nbNotBlack+=1;
            score+=11;
        }
        if(nbNotBlack==3)
        {
            score+=80;
            nbNotBlack=0;
        }
        if(nbBlack>=3)
            score+=80;
        nbBlack=0;
        indexCaseEnQ=0;
        tableauScore[i]=score;
        score=0;
    }
    int best=0,indexBest=0;
    for(int j=0;j<6;j++)
    {
        if(tableauScore[j]>best)
        {
            best=tableauScore[j];indexBest=j;
        }
    }
    enableAllButonColon();
    set1CouleurTo(!ordiJaune,indexBest/*de 0 a 6*/);
    qDebug() << " set OneCouleur to est fait. \n" << ordiJaune << ":"<<!ordiJaune;
    //QMessageBox::critical(this,"Erreur","la2 !");
        //else if()
      //  if(listeLabelList[i]->styleSheet()==colorUser)
        //
     //   if(listeLabelList[i+1]->styleSheet()==colorUser)//si a droite un jeton a l'adversaire
}
