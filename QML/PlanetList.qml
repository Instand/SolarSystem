import QtQuick 2.0

//planet item
Item {
    id: root

    //base property
    property int buttonSize: 70
    property int fontSize: 14

    //planet view model
    ListModel {
        id: planetModel

        //sun
        ListElement {
            name: "Sun"
            planetImageSource: "qrc:/Resources/Images/sun.png"
        }

        //mercury
        ListElement {
            name: "Mercury"
            planetImageSource: "qrc:/Resources/Images/mercury.png"
        }

        //venus
        ListElement {
            name: "Venus"
            planetImageSource: "qrc:/Resources/Images/venus.png"
        }

        //earth
        ListElement {
            name: "Earth"
            planetImageSource: "qrc:/Resources/Images/earth.png"
        }

        //mars
        ListElement {
            name: "Mars"
            planetImageSource: "qrc:/Resources/Images/mars.png"
        }

        //jupiter
        ListElement {
            name: "Jupiter"
            planetImageSource: "qrc:/Resources/Images/jupiter.png"
        }

        //saturn
        ListElement {
            name: "Saturn"
            planetImageSource: "qrc:/Resources/Images/saturn.png"
        }

        //uranus
        ListElement {
            name: "Uranus"
            planetImageSource: "qrc:/Resources/Images/uranus.png"
        }

        //neptune
        ListElement {
            name: "Neptune"
            planetImageSource: "qrc:/Resources/Images/neptune.png"
        }
    }

    //model delegate
    Component {
        id: modelDelegate

        //use button
        PlanetButton {
            source: planetImageSource
            text: name
            //planetSelector: mainview
            buttonSize: root.buttonSize
            fontSize: root.fontSize
        }
    }

    //view element
    ListView {
        id: planetButtonView
        anchors.fill: parent
        spacing: 10
        width: root.parent.width
        interactive: false
        model: planetModel
        delegate: modelDelegate
        orientation: Qt.Horizontal
    }

}
