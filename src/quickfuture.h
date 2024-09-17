#ifndef QUICKFUTURE_H
#define QUICKFUTURE_H

#include <QtQml/QQmlExtensionPlugin>
#include <functional>
#include "qffuture.h"
#include "quickfuture_include.h"
namespace QuickFuture {

    template <typename T>
    static void registerType() {
        Future::registerType<T>();
    }

    template <typename T>
    static void registerType(std::function<QVariant(T)> converter) {
        Future::registerType<T>(converter);
    }

}

#ifdef QUICK_FUTURE_BUILD_PLUGIN
class QUICK_FUTURE_EXPORT QuickFutureQmlPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri);
};
#endif

#endif // QUICKFUTURE_H
