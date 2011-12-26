#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(IAppModel *model, QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow),
Model(model)
{
  ui->setupUi(this);
  InitConnections();
}

void MainWindow::InitConnections()
{
  QObject::connect(ui->actionOpenProject, SIGNAL(triggered()), this, SLOT(OnOpenProject()));
  QObject::connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(OnExit()));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::OnOpenProject()
{
  Model->OpenProject();
}

void MainWindow::OnExit()
{
  //emit Exit();
  Model->Exit();
}
