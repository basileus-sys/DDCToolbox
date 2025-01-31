#ifndef CURVEFITTINGWORKERDIALOG_H
#define CURVEFITTINGWORKERDIALOG_H

#include <QDialog>
#include <QThread>

#include <model/CurveFittingOptions.h>
#include <model/DeflatedBiquad.h>

class CurveFittingWorker;

namespace Ui {
class CurveFittingWorkerDialog;
}

class CurveFittingWorkerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CurveFittingWorkerDialog(const CurveFittingOptions &_options, QWidget *parent = nullptr);
    ~CurveFittingWorkerDialog();

    virtual void reject();

    QVector<DeflatedBiquad> getResults() const;

signals:
    void beginWork();

private slots:
    void workerFinished();
    void mseReceived(float mse);
    void graphReceived(std::vector<double> temp);

private:
    Ui::CurveFittingWorkerDialog *ui;

    CurveFittingOptions options;
    CurveFittingWorker* worker;
    QThread thread;

    int iteration = 0;
};

#endif // CURVEFITTINGWORKERDIALOG_H
