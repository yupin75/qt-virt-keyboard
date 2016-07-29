#include <QCoreApplication>
#include <QGuiApplication>
#include <QKeyEvent>
#include <QQuickItem>
#include <QDebug>
#include "key_emitter.h"

#if 1
#include <stdio.h>
#include <linux/input.h>
#include <fcntl.h>
#include <sys/time.h>
#include <unistd.h>

void simulate_key(int fd, int kval)
{
         struct input_event event;
        gettimeofday(&event.time, 0);
       //按下kval鍵
         event.type = EV_KEY;
         event.value = 1;
         event.code = kval;
         write(fd, &event, sizeof(event));
       //同步，也就是把它報告給系統
         event.type = EV_SYN;
         event.value = 0;
         event.code = SYN_REPORT;
         write(fd, &event, sizeof(event));

         memset(&event, 0, sizeof(event));
         gettimeofday(&event.time, 0);
         //鬆開kval鍵
        event.type = EV_KEY;
         event.value = 0;
         event.code = kval;
         write(fd, &event, sizeof(event));
       //同步，也就是把它報告給系統
       event.type = EV_SYN;
       event.value = 0;
       event.code = SYN_REPORT;
       write(fd, &event, sizeof(event));
}
#endif

KeyEmitter::KeyEmitter()
{
}
#include <QDebug>
KeyEmitter::~KeyEmitter()
{
}

void KeyEmitter::emitKey(Qt::Key key)
{
	QQuickItem* receiver = qobject_cast<QQuickItem*>(QGuiApplication::focusObject());
	if(!receiver) {
		return;
	}
    //QKeyEvent pressEvent = QKeyEvent(QEvent::KeyPress, key, Qt::NoModifier, QKeySequence(key).toString());
    //QKeyEvent releaseEvent = QKeyEvent(QEvent::KeyRelease, key, Qt::NoModifier);
    //QCoreApplication::sendEvent(receiver, &pressEvent);
    //QCoreApplication::sendEvent(receiver, &releaseEvent);

    qDebug() << key;
#if 1
    //int fd0 = open("/dev/input/event0", O_RDWR);
    //int fd1 = open("/dev/input/event1", O_RDWR);
    int fd2 = open("/dev/input/event2", O_RDWR);
    //int fd3 = open("/dev/input/event3", O_RDWR);
    //int fd4 = open("/dev/input/event4", O_RDWR);
    //int fd5 = open("/dev/input/event5", O_RDWR);
    //int fd6 = open("/dev/input/event6", O_RDWR);
    //simulate_key(fd0, key);
    //simulate_key(fd1, key);
    simulate_key(fd2, key);
    simulate_key(fd2, 2);
    simulate_key(fd2, 3);
    //simulate_key(fd3, key);
    //simulate_key(fd4, key);
    //simulate_key(fd5, key);
    //simulate_key(fd6, key);

    //close(fd0);
    //close(fd1);
    close(fd2);
    //close(fd3);
    //close(fd4);
    //close(fd5);
    //close(fd6);
#endif



}
