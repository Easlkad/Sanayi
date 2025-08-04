/****************************************************************************
** Meta object code from reading C++ file 'transactionmodel.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../transactionmodel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transactionmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
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
struct qt_meta_tag_ZN16TransactionModelE_t {};
} // unnamed namespace

template <> constexpr inline auto TransactionModel::qt_create_metaobjectdata<qt_meta_tag_ZN16TransactionModelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "TransactionModel",
        "totalsChanged",
        "",
        "refresh",
        "addTransaction",
        "date",
        "plate",
        "km",
        "owner",
        "brand",
        "customer",
        "jobDesc",
        "debt",
        "receivable",
        "external",
        "sparePart",
        "exitDate",
        "total",
        "updateTransaction",
        "row",
        "field",
        "QVariant",
        "value",
        "deleteTransaction",
        "searchTransactions",
        "searchText",
        "filterByDateRange",
        "startDate",
        "endDate",
        "clearFilter",
        "sumField",
        "fieldName"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'totalsChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'refresh'
        QtMocHelpers::MethodData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'addTransaction'
        QtMocHelpers::MethodData<bool(const QString &, const QString &, int, const QString &, const QString &, const QString &, const QString &, double, double, double, const QString &, const QString &, double)>(4, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 5 }, { QMetaType::QString, 6 }, { QMetaType::Int, 7 }, { QMetaType::QString, 8 },
            { QMetaType::QString, 9 }, { QMetaType::QString, 10 }, { QMetaType::QString, 11 }, { QMetaType::Double, 12 },
            { QMetaType::Double, 13 }, { QMetaType::Double, 14 }, { QMetaType::QString, 15 }, { QMetaType::QString, 16 },
            { QMetaType::Double, 17 },
        }}),
        // Method 'updateTransaction'
        QtMocHelpers::MethodData<bool(int, const QString &, const QVariant &)>(18, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 19 }, { QMetaType::QString, 20 }, { 0x80000000 | 21, 22 },
        }}),
        // Method 'deleteTransaction'
        QtMocHelpers::MethodData<bool(int)>(23, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 19 },
        }}),
        // Method 'searchTransactions'
        QtMocHelpers::MethodData<void(const QString &)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 25 },
        }}),
        // Method 'filterByDateRange'
        QtMocHelpers::MethodData<void(const QString &, const QString &)>(26, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 27 }, { QMetaType::QString, 28 },
        }}),
        // Method 'clearFilter'
        QtMocHelpers::MethodData<void()>(29, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'sumField'
        QtMocHelpers::MethodData<double(const QString &) const>(30, 2, QMC::AccessPublic, QMetaType::Double, {{
            { QMetaType::QString, 31 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<TransactionModel, qt_meta_tag_ZN16TransactionModelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject TransactionModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QSqlTableModel::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16TransactionModelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16TransactionModelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16TransactionModelE_t>.metaTypes,
    nullptr
} };

void TransactionModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<TransactionModel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->totalsChanged(); break;
        case 1: _t->refresh(); break;
        case 2: { bool _r = _t->addTransaction((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[13])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->updateTransaction((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->deleteTransaction((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->searchTransactions((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->filterByDateRange((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 7: _t->clearFilter(); break;
        case 8: { double _r = _t->sumField((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (TransactionModel::*)()>(_a, &TransactionModel::totalsChanged, 0))
            return;
    }
}

const QMetaObject *TransactionModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TransactionModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16TransactionModelE_t>.strings))
        return static_cast<void*>(this);
    return QSqlTableModel::qt_metacast(_clname);
}

int TransactionModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSqlTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void TransactionModel::totalsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
