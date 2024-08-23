#ifndef PAGECONTROLLER_H
#define PAGECONTROLLER_H

#include <QObject>
#include "filtermodel.h"

class PageController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(FilterModel* filterModel READ filterModel CONSTANT)
    Q_PROPERTY(QString selectedFilterType READ selectedFilterType WRITE setSelectedFilterType NOTIFY selectedFilterTypeChanged)

public:
    explicit PageController(QObject *parent = nullptr);

    FilterModel* filterModel() const;
    QString selectedFilterType() const;

public slots:
    void setSelectedFilterType(const QString &filterType);

signals:
    void selectedFilterTypeChanged();

private:
    FilterModel m_filterModel;
    QString m_selectedFilterType;
};

#endif // PAGECONTROLLER_H
