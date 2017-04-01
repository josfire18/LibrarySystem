/****************************************************************************
** Meta object code from reading C++ file 'authorizedwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LibrarySystem/authorizedwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'authorizedwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AuthorizedWindow_t {
    QByteArrayData data[12];
    char stringdata[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AuthorizedWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AuthorizedWindow_t qt_meta_stringdata_AuthorizedWindow = {
    {
QT_MOC_LITERAL(0, 0, 16), // "AuthorizedWindow"
QT_MOC_LITERAL(1, 17, 20), // "on_btnSearch_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 26), // "on_Checkout_Button_clicked"
QT_MOC_LITERAL(4, 66, 21), // "on_Add_Button_clicked"
QT_MOC_LITERAL(5, 88, 24), // "on_Delete_Button_clicked"
QT_MOC_LITERAL(6, 113, 14), // "on_Box_Checked"
QT_MOC_LITERAL(7, 128, 26), // "on_NewBook_Confirm_clicked"
QT_MOC_LITERAL(8, 155, 25), // "on_NewBook_Cancel_clicked"
QT_MOC_LITERAL(9, 181, 37), // "on_NewBook_ISBN_cursorPositio..."
QT_MOC_LITERAL(10, 219, 4), // "arg1"
QT_MOC_LITERAL(11, 224, 4) // "arg2"

    },
    "AuthorizedWindow\0on_btnSearch_clicked\0"
    "\0on_Checkout_Button_clicked\0"
    "on_Add_Button_clicked\0on_Delete_Button_clicked\0"
    "on_Box_Checked\0on_NewBook_Confirm_clicked\0"
    "on_NewBook_Cancel_clicked\0"
    "on_NewBook_ISBN_cursorPositionChanged\0"
    "arg1\0arg2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AuthorizedWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    2,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,

       0        // eod
};

void AuthorizedWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AuthorizedWindow *_t = static_cast<AuthorizedWindow *>(_o);
        switch (_id) {
        case 0: _t->on_btnSearch_clicked(); break;
        case 1: _t->on_Checkout_Button_clicked(); break;
        case 2: _t->on_Add_Button_clicked(); break;
        case 3: _t->on_Delete_Button_clicked(); break;
        case 4: _t->on_Box_Checked(); break;
        case 5: _t->on_NewBook_Confirm_clicked(); break;
        case 6: _t->on_NewBook_Cancel_clicked(); break;
        case 7: _t->on_NewBook_ISBN_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject AuthorizedWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AuthorizedWindow.data,
      qt_meta_data_AuthorizedWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AuthorizedWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AuthorizedWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AuthorizedWindow.stringdata))
        return static_cast<void*>(const_cast< AuthorizedWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int AuthorizedWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
