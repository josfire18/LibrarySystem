/****************************************************************************
** Meta object code from reading C++ file 'editmembers.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LibrarySystem/editmembers.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editmembers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EditMembers_t {
    QByteArrayData data[13];
    char stringdata[234];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditMembers_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditMembers_t qt_meta_stringdata_EditMembers = {
    {
QT_MOC_LITERAL(0, 0, 11), // "EditMembers"
QT_MOC_LITERAL(1, 12, 22), // "on_cmdListMems_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 24), // "on_cmdUniqueMems_clicked"
QT_MOC_LITERAL(4, 61, 20), // "on_cmdReturn_clicked"
QT_MOC_LITERAL(5, 82, 21), // "on_cmdEditMem_clicked"
QT_MOC_LITERAL(6, 104, 21), // "on_cmdConfirm_clicked"
QT_MOC_LITERAL(7, 126, 24), // "on_cmdCancelEdit_clicked"
QT_MOC_LITERAL(8, 151, 14), // "on_Checked_Box"
QT_MOC_LITERAL(9, 166, 14), // "on_Box_Checked"
QT_MOC_LITERAL(10, 181, 20), // "on_cmdDelete_clicked"
QT_MOC_LITERAL(11, 202, 26), // "on_txtEmployee_textChanged"
QT_MOC_LITERAL(12, 229, 4) // "arg1"

    },
    "EditMembers\0on_cmdListMems_clicked\0\0"
    "on_cmdUniqueMems_clicked\0on_cmdReturn_clicked\0"
    "on_cmdEditMem_clicked\0on_cmdConfirm_clicked\0"
    "on_cmdCancelEdit_clicked\0on_Checked_Box\0"
    "on_Box_Checked\0on_cmdDelete_clicked\0"
    "on_txtEmployee_textChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditMembers[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    1,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,

       0        // eod
};

void EditMembers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EditMembers *_t = static_cast<EditMembers *>(_o);
        switch (_id) {
        case 0: _t->on_cmdListMems_clicked(); break;
        case 1: _t->on_cmdUniqueMems_clicked(); break;
        case 2: _t->on_cmdReturn_clicked(); break;
        case 3: _t->on_cmdEditMem_clicked(); break;
        case 4: _t->on_cmdConfirm_clicked(); break;
        case 5: _t->on_cmdCancelEdit_clicked(); break;
        case 6: _t->on_Checked_Box(); break;
        case 7: _t->on_Box_Checked(); break;
        case 8: _t->on_cmdDelete_clicked(); break;
        case 9: _t->on_txtEmployee_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject EditMembers::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EditMembers.data,
      qt_meta_data_EditMembers,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EditMembers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditMembers::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EditMembers.stringdata))
        return static_cast<void*>(const_cast< EditMembers*>(this));
    return QWidget::qt_metacast(_clname);
}

int EditMembers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
