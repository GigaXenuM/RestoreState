#pragma once

#include <QListWidget>
#include <QMainWindow>
#include <QMenu>
#include <QTextEdit>

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow();

protected:
  void closeEvent(QCloseEvent *event) override;

private:
  void createDockWindows();
  void restoreSettings();

  QTextEdit *_textEdit;
  QListWidget *_customerList;
  QListWidget *_paragraphsList;

  QDockWidget *_customersDockWidget{nullptr};
  QDockWidget *_paragraphsDockWidget{nullptr};
};
