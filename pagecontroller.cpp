#include "pagecontroller.h"

PageController::PageController(QObject *parent)
    : QObject(parent)
{
    m_filterModel.setFilterTypes({"TF_NONE", "TF_SLIDING_LOWPASS_FIR", "TF_SLIDING_BANDPASS_FIR"});
}

FilterModel* PageController::filterModel() const
{
    return const_cast<FilterModel*>(&m_filterModel);
}


QString PageController::selectedFilterType() const
{
    return m_selectedFilterType;
}

void PageController::setSelectedFilterType(const QString &filterType)
{
    if (m_selectedFilterType != filterType) {
        m_selectedFilterType = filterType;
        emit selectedFilterTypeChanged();
    }
}
