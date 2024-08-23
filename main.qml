import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

/*1
ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "ComboBox Example"

    // Определите модель данных для ComboBox
    property var mFilterType: [
        "TF_NONE",
        "TF_SLIDING_LOWPASS_FIR",
        "TF_SLIDING_BANDPASS_FIR"
    ]

    ComboBox {
        id: comboBPFilterType
        width: 400
        height: 50
        anchors.centerIn: parent
        font.pixelSize: 20  // уменьшен размер шрифта для соответствия размеру ComboBox
        model: mFilterType
        currentIndex: 0

        background: Rectangle {
            id: bgComboBPFilterType
            radius: 5
            color: "lightgray"
            width: comboBPFilterType.width
            height: comboBPFilterType.height
        }

        onActivated: {
            console.log("Selected item:", comboBPFilterType.currentText)
        }
    }
}

*/


/*2
ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Page with ComboBox and Controller"

    // Пример других компонентов
    Rectangle {
        width: parent.width
        height: parent.height

        // Ваш ComboBox
        ComboBox {
            id: comboBPFilterType
            width: 200
            height: 50
            anchors.centerIn: parent
            font.pixelSize: 20
            model: pageController.filterModel
            currentIndex: 0

            background: Rectangle {
                id: bgComboBPFilterType
                radius: 5
                color: "lightgray"
                width: comboBPFilterType.width
                height: comboBPFilterType.height
            }

            onActivated: {
                console.log("Selected item:", comboBPFilterType.currentText)
            }
        }

        // Пример другого компонента
        Text {
            text: "Another component"
            anchors.top: comboBPFilterType.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 20
        }
    }
}
*/


ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Page with ComboBox and Controller"

    Rectangle {
        width: parent.width
        height: parent.height

        ComboBox {
            id: comboBPFilterType
            width: 400
            height: 50
            anchors.centerIn: parent
            font.pixelSize: 20
            model: pageController.filterModel
            currentIndex: 0

            background: Rectangle {
                id: bgComboBPFilterType
                radius: 5
                color: "lightgray"
                width: comboBPFilterType.width
                height: comboBPFilterType.height
            }

            onActivated: {
                pageController.selectedFilterType = comboBPFilterType.currentText
            }
            Component.onCompleted: pageController.selectedFilterType = comboBPFilterType.currentText
        }

        Text {
            text: "Selected Filter Type: " + pageController.selectedFilterType
            anchors.top: comboBPFilterType.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 20
        }
    }
}
