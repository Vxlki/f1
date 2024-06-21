/****************************************************************************
** Meta object code from reading C++ file 'serverconnection.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../serverconnection.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverconnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSServerConnectionENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSServerConnectionENDCLASS = QtMocHelpers::stringData(
    "ServerConnection",
    "connected",
    "",
    "disconnected",
    "dataReceived",
    "data",
    "sendChangePassword",
    "obj",
    "sendLogInResponse",
    "sendSignInResponse",
    "sendTeamsWindowPersonnel",
    "sendTeamsWindowTeams",
    "sendCircuit1Window",
    "sendCircuit2Window",
    "sendPersonnelFunctionRegister",
    "sendTeamsFunctionRegister",
    "sendAutoLogIn",
    "connectToServer",
    "host",
    "port",
    "onConnected",
    "onDisconnected",
    "onReadyRead"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSServerConnectionENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  116,    2, 0x06,    1 /* Public */,
       3,    0,  117,    2, 0x06,    2 /* Public */,
       4,    1,  118,    2, 0x06,    3 /* Public */,
       6,    1,  121,    2, 0x06,    5 /* Public */,
       8,    1,  124,    2, 0x06,    7 /* Public */,
       9,    1,  127,    2, 0x06,    9 /* Public */,
      10,    1,  130,    2, 0x06,   11 /* Public */,
      11,    1,  133,    2, 0x06,   13 /* Public */,
      12,    1,  136,    2, 0x06,   15 /* Public */,
      13,    1,  139,    2, 0x06,   17 /* Public */,
      14,    1,  142,    2, 0x06,   19 /* Public */,
      15,    1,  145,    2, 0x06,   21 /* Public */,
      16,    1,  148,    2, 0x06,   23 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      17,    2,  151,    2, 0x0a,   25 /* Public */,
      20,    0,  156,    2, 0x08,   28 /* Private */,
      21,    0,  157,    2, 0x08,   29 /* Private */,
      22,    0,  158,    2, 0x08,   30 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void, QMetaType::QJsonObject,    7,
    QMetaType::Void, QMetaType::QJsonObject,    7,
    QMetaType::Void, QMetaType::QJsonObject,    7,
    QMetaType::Void, QMetaType::QJsonObject,    7,
    QMetaType::Void, QMetaType::QJsonObject,    7,
    QMetaType::Void, QMetaType::QJsonObject,    7,
    QMetaType::Void, QMetaType::QJsonObject,    7,
    QMetaType::Void, QMetaType::QJsonObject,    7,
    QMetaType::Void, QMetaType::QJsonObject,    7,
    QMetaType::Void, QMetaType::QJsonObject,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,   18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ServerConnection::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSServerConnectionENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSServerConnectionENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSServerConnectionENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ServerConnection, std::true_type>,
        // method 'connected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'disconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dataReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'sendChangePassword'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>,
        // method 'sendLogInResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>,
        // method 'sendSignInResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>,
        // method 'sendTeamsWindowPersonnel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>,
        // method 'sendTeamsWindowTeams'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>,
        // method 'sendCircuit1Window'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>,
        // method 'sendCircuit2Window'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>,
        // method 'sendPersonnelFunctionRegister'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>,
        // method 'sendTeamsFunctionRegister'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>,
        // method 'sendAutoLogIn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>,
        // method 'connectToServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        // method 'onConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ServerConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ServerConnection *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->disconnected(); break;
        case 2: _t->dataReceived((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 3: _t->sendChangePassword((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 4: _t->sendLogInResponse((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 5: _t->sendSignInResponse((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 6: _t->sendTeamsWindowPersonnel((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 7: _t->sendTeamsWindowTeams((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 8: _t->sendCircuit1Window((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 9: _t->sendCircuit2Window((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 10: _t->sendPersonnelFunctionRegister((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 11: _t->sendTeamsFunctionRegister((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 12: _t->sendAutoLogIn((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 13: _t->connectToServer((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2]))); break;
        case 14: _t->onConnected(); break;
        case 15: _t->onDisconnected(); break;
        case 16: _t->onReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ServerConnection::*)();
            if (_t _q_method = &ServerConnection::connected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ServerConnection::*)();
            if (_t _q_method = &ServerConnection::disconnected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ServerConnection::*)(const QByteArray & );
            if (_t _q_method = &ServerConnection::dataReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ServerConnection::*)(const QJsonObject & );
            if (_t _q_method = &ServerConnection::sendChangePassword; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ServerConnection::*)(const QJsonObject & );
            if (_t _q_method = &ServerConnection::sendLogInResponse; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ServerConnection::*)(const QJsonObject & );
            if (_t _q_method = &ServerConnection::sendSignInResponse; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ServerConnection::*)(const QJsonObject & );
            if (_t _q_method = &ServerConnection::sendTeamsWindowPersonnel; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ServerConnection::*)(const QJsonObject & );
            if (_t _q_method = &ServerConnection::sendTeamsWindowTeams; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ServerConnection::*)(const QJsonObject & );
            if (_t _q_method = &ServerConnection::sendCircuit1Window; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (ServerConnection::*)(const QJsonObject & );
            if (_t _q_method = &ServerConnection::sendCircuit2Window; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (ServerConnection::*)(const QJsonObject & );
            if (_t _q_method = &ServerConnection::sendPersonnelFunctionRegister; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (ServerConnection::*)(const QJsonObject & );
            if (_t _q_method = &ServerConnection::sendTeamsFunctionRegister; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (ServerConnection::*)(const QJsonObject & );
            if (_t _q_method = &ServerConnection::sendAutoLogIn; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
    }
}

const QMetaObject *ServerConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSServerConnectionENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ServerConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void ServerConnection::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ServerConnection::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ServerConnection::dataReceived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ServerConnection::sendChangePassword(const QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ServerConnection::sendLogInResponse(const QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ServerConnection::sendSignInResponse(const QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ServerConnection::sendTeamsWindowPersonnel(const QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ServerConnection::sendTeamsWindowTeams(const QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ServerConnection::sendCircuit1Window(const QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void ServerConnection::sendCircuit2Window(const QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void ServerConnection::sendPersonnelFunctionRegister(const QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void ServerConnection::sendTeamsFunctionRegister(const QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void ServerConnection::sendAutoLogIn(const QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_WARNING_POP
