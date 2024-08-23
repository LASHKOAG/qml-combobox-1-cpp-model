#ifndef FILTERMODEL_H
#define FILTERMODEL_H

#include <QAbstractListModel>
#include <QStringList>

class FilterModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum FilterRoles {
        FilterRole = Qt::UserRole + 1
    };

    explicit FilterModel(QObject *parent = nullptr);



    // QAbstractListModel interface
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void setFilterTypes(const QStringList &types);

private:
    QStringList m_filterTypes;
};

#endif // FILTERMODEL_H
