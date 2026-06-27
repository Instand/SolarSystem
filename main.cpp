#include <QGuiApplication>
#include <UI/quickui.h>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

#if defined(Q_OS_ANDROID)
    QNativeInterface::QAndroidApplication::runOnAndroidMainThread([]() {
        QJniObject activity = QNativeInterface::QAndroidApplication::context();
        if (activity.isValid())
        {
            QJniObject window = activity.callObjectMethod("getWindow", "()Landroid/view/Window;");
            QJniObject decorView = window.callObjectMethod("getDecorView", "()Landroid/view/View;");

            // SYSTEM_UI_FLAG_LAYOUT_STABLE |
            // SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION |
            // SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN |
            // SYSTEM_UI_FLAG_HIDE_NAVIGATION |
            // SYSTEM_UI_FLAG_FULLSCREEN |
            // SYSTEM_UI_FLAG_IMMERSIVE_STICKY
            const int flags = 0x00000300 | 0x00000200 | 0x00000400 | 0x00000002 | 0x00000004 | 0x00001000;
            decorView.callMethod<void>("setSystemUiVisibility", "(I)V", flags);
        }
    }).waitForFinished();
#endif

    // show our beautiful solar system to us
    SolarSystem::QuickUi ui;
    ui.show();

    return a.exec();
}

