#ifndef QFFUTURE_H
#define QFFUTURE_H

#include <QObject>
#include <QFuture>
#include <QQmlEngine>
#include <QVariantMap>
#include "qfvariantwrapper.h"
#include <qqmlengine.h>
#include "quickfuture_include.h"

namespace QuickFuture {

class QUICK_FUTURE_EXPORT Future : public QObject
{
    Q_OBJECT;
    QML_SINGLETON;
    QML_ELEMENT;
public:
    explicit Future(QQmlEngine* qmlEngine, QObject *parent = 0);
    static Future* create(QQmlEngine* qmlEngine, QJSEngine*)
    {
        return new Future(qmlEngine);
    }

    template <typename T>
    static void registerType() {
        registerType(qRegisterMetaType<QFuture<T> >(), new VariantWrapper<T>() );
    }

    template <typename T>
    static void registerType(std::function<QVariant(T)> converter ) {
        VariantWrapper<T>* wrapper = new VariantWrapper<T>();
        wrapper->converter = [=](void* data) {
            return converter(*(T*) data);
        };
        registerType(qRegisterMetaType<QFuture<T> >(), wrapper);
    }

    QJSEngine *engine() const;

    void setEngine(QQmlEngine *engine);

signals:

public slots:
    bool isFinished(const QVariant& future);

    bool isRunning(const QVariant& future);

    bool isCanceled(const QVariant& future);

    int progressValue(const QVariant& future);

    int progressMinimum(const QVariant& future);

    int progressMaximum(const QVariant& future);

    void onFinished(const QVariant& future, QJSValue func, QJSValue owner = QJSValue());

    void onCanceled(const QVariant& future, QJSValue func, QJSValue owner = QJSValue());

    void onProgressValueChanged(const QVariant& future, QJSValue func);

    QVariant result(const QVariant& future);

    QVariant results(const QVariant& future);

    QJSValue promise(QJSValue future);

    void sync(const QVariant& future, const QString& propertyInFuture, QObject* target, const QString& propertyInTarget = QString());

private:
    static void registerType(int typeId, VariantWrapperBase* wrapper);

    QPointer<QQmlEngine> m_engine;
    QJSValue promiseCreator;
};

}

#endif // QFFUTURE_H
