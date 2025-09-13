#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>

class QLabel;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QMediaCaptureSession *session;
    QCamera *camera;

    QImageCapture *imageCapture;
    QSoundEffect *soundEffect;
    QMediaRecorder *recorder;

    bool m_isWorking;

    QLabel *labDuration;
    QLabel *labInfo;
    QLabel *labFormatInfo;

    void showCameraDeviceInfo(QCameraDevice *device);
    void showCameraSupportFeatured(QCamera *aCamera);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void do_activeChanged(bool);
    void do_currentIndexChanged(int index);

    void on_actStartCamera_triggered();

    void on_actStopCamera_triggered();

    void on_actCapture_triggered();

    void on_btnVideoFile_clicked();

    void on_actVideoRecord_triggered();

    void on_actVideoStop_triggered();

    void do_readyForCaptureChanged(bool ready);

    void do_imageCaptured(int id, const QImage &preview);

    void do_imageSaved(int id, const QString &fileName);

    void do_durationChanged(qint64 duration);

    void do_recorderStateChanged(QMediaRecorder::RecorderState state);

    void do_errorOccurred(QMediaRecorder::Error error, const QString &errorString);

private:
    Ui::MainWindow *ui;

    // QWidget interface
protected:
    virtual void closeEvent(QCloseEvent *event) override;
};


#endif // MAINWINDOW_H
