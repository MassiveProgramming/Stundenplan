#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow )
{
    time = new Time();
    fp = new FileParser();
    ui->setupUi( this );

    day = time->getDay();

    setWeekButton( ( time->getCurrWeek() + 1 ) % 2 );
    selectedDayButton( day );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setWeekButton( int e )
{
    switch ( e ) {
    case 0:
        ui->buttonWeek->setText( "Woche: gerade" );
        break;
    case 1:
        ui->buttonWeek->setText( "Woche: ungerade" );
        break;
    default:
        char text[ 80 ];
        sprintf( text, "Fehler: Woche %d", e );
        ui->buttonWeek->setText( text );
        break;
    }
}

void freeData( struct tag data )
{
    free( (void *)data.name );
    for ( ; data.stunden > 0; data.stunden-- ) {
        free( (void *)data.std[ data.stunden ].fach );
        free( (void *)data.std[ data.stunden ].lehrer );
        free( (void *)data.std[ data.stunden ].raum );
    }
}

void MainWindow::selectedDayButton( int day )
{
    QPushButton *buttons[] = {
        ui->buttonMonday,
        ui->buttonMonday,
        ui->buttonTuesday,
        ui->buttonWednesday,
        ui->buttonThursday,
        ui->buttonFriday,
        ui->buttonMonday
    };
    QString days[] = {
        "Montag",
        "Montag",
        "Dienstag",
        "Mittwoch",
        "Donnerstag",
        "Freitag",
        "Montag"
    };
    char *daysNumber[] = {
        "1",
        "1",
        "2",
        "3",
        "4",
        "5",
        "1"
    };
    day = day % 7;
    buttons[ this->day ]->setDisabled( false );
    buttons[ day ]->setDisabled( true );
    this->day = day;
    QString title = "Stundenplan - ";
    setWindowTitle( title.append( days[ day ] ) );
    char path[ 80 ] = "/home/thomas/.stundenplan/data/";
    if ( this->week == 0 ) {
        strcat( path, "even/" );
    } else {
        strcat( path, "odd/" );
    }
    strcat( path, daysNumber[ day ] );
    fp->loadFile( path );
    struct tag data = fp->parseFile();
    clearData();
    displayData( data );
    freeData( data );
}

void MainWindow::clearData()
{
    QLabel *fach[] = {
        ui->fach1,
        ui->fach2,
        ui->fach3,
        ui->fach4,
        ui->fach5,
        ui->fach6,
        ui->fach7,
        ui->fach8,
        ui->fach9,
        ui->fach10
    };
    QLabel *lehrer[] = {
        ui->lehrer1,
        ui->lehrer2,
        ui->lehrer3,
        ui->lehrer4,
        ui->lehrer5,
        ui->lehrer6,
        ui->lehrer7,
        ui->lehrer8,
        ui->lehrer9,
        ui->lehrer10,
    };

    QLabel *raum[] = {
        ui->raum1,
        ui->raum2,
        ui->raum3,
        ui->raum4,
        ui->raum5,
        ui->raum6,
        ui->raum7,
        ui->raum8,
        ui->raum9,
        ui->raum10,
    };

    for( int i = 0; i < 10; i++ ) {
        fach[ i ]->setText( "" );
        lehrer[ i ]->setText( "" );
        raum[ i ]->setText( "" );
    }
}

void MainWindow::displayData( struct tag data )
{
    QLabel *fach[] = {
        ui->fach1,
        ui->fach2,
        ui->fach3,
        ui->fach4,
        ui->fach5,
        ui->fach6,
        ui->fach7,
        ui->fach8,
        ui->fach9,
        ui->fach10
    };
    QLabel *lehrer[] = {
        ui->lehrer1,
        ui->lehrer2,
        ui->lehrer3,
        ui->lehrer4,
        ui->lehrer5,
        ui->lehrer6,
        ui->lehrer7,
        ui->lehrer8,
        ui->lehrer9,
        ui->lehrer10,
    };

    QLabel *raum[] = {
        ui->raum1,
        ui->raum2,
        ui->raum3,
        ui->raum4,
        ui->raum5,
        ui->raum6,
        ui->raum7,
        ui->raum8,
        ui->raum9,
        ui->raum10,
    };

    for ( int i = 0; i < data.stunden; i++ ) {
        fach[ i ]->setText( data.std[ i ].fach );
        lehrer[ i ]->setText( data.std[ i ].lehrer );
        raum[ i ]->setText( data.std[ i ].raum );
    }
}

void MainWindow::on_buttonWeek_clicked()
{
    toggleWeek();
    selectedDayButton( day );
    setWeekButton( week );
}

void MainWindow::on_buttonMonday_clicked(bool checked)
{
    (void)checked;
}

void MainWindow::toggleWeek()
{
    if ( week == 0 ) {
        week = 1;
        return;
    }
    week = 0;
}


void MainWindow::on_buttonMonday_pressed()
{
    selectedDayButton( 1 );
}

void MainWindow::on_buttonTuesday_pressed()
{
    selectedDayButton( 2 );
}

void MainWindow::on_buttonWednesday_pressed()
{
    selectedDayButton( 3 );
}

void MainWindow::on_buttonThursday_pressed()
{
    selectedDayButton( 4 );
}

void MainWindow::on_buttonFriday_pressed()
{
    selectedDayButton( 5 );
}
