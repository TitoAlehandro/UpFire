#ifndef NDISAPI_QT_GLOBAL_H
#define NDISAPI_QT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(NDISAPI_QT_LIBRARY)
#  define NDISAPI_QTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define NDISAPI_QTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // NDISAPI_QT_GLOBAL_H
