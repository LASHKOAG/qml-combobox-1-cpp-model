#include "filtermodel.h"

FilterModel::FilterModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int FilterModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_filterTypes.size();
}

QVariant FilterModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_filterTypes.size())
        return QVariant();

    if (role == FilterRole)
        return m_filterTypes.at(index.row());

    return QVariant();
}

QHash<int, QByteArray> FilterModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[FilterRole] = "filterType";
    return roles;
}

void FilterModel::setFilterTypes(const QStringList &types)
{
    beginResetModel();
    m_filterTypes = types;
    endResetModel();
}
