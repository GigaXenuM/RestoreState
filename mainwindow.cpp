#include "mainwindow.h"

#include <QDockWidget>
#include <QSettings>

MainWindow::MainWindow() : _textEdit(new QTextEdit) {
  setCentralWidget(_textEdit);

  createDockWindows();

  setWindowTitle(tr("Dock Widgets"));

  setUnifiedTitleAndToolBarOnMac(true);
  restoreSettings();
}

void MainWindow::createDockWindows() {

  QDockWidget *dock = new QDockWidget(tr("Customers"), this);
  dock->setObjectName("Customers");
  _customersDockWidget = dock;
  _customersDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea |
                                        Qt::RightDockWidgetArea);
  _customerList = new QListWidget(_customersDockWidget);
  _customerList->addItems(QStringList() << "Customers");
  _customersDockWidget->setWidget(_customerList);
  addDockWidget(Qt::RightDockWidgetArea, _customersDockWidget);

  dock = new QDockWidget(tr("Paragraphs"), this);
  _paragraphsDockWidget = dock;
  dock->setObjectName("Paragraphs");
  _paragraphsList = new QListWidget(dock);
  _paragraphsList->addItems(QStringList() << "Paragraphs");
  dock->setWidget(_paragraphsList);
  addDockWidget(Qt::RightDockWidgetArea, dock);
}

void MainWindow::closeEvent(QCloseEvent *event) {
  QSettings settings("MyCompany", "RestoreState");
  settings.setValue("geometry", saveGeometry());
  settings.setValue("windowState", saveState());
  QMainWindow::closeEvent(event);
}

void MainWindow::restoreSettings() {
  QSettings settings("MyCompany", "RestoreState");
  restoreGeometry(settings.value("geometry").toByteArray());

  setWindowState(Qt::WindowMaximized);
  restoreState(settings.value("windowState").toByteArray());

  tabifyDockWidget(_paragraphsDockWidget, _customersDockWidget);
}
