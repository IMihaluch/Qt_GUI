import QtQuick 2.5
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Qt.labs.qmlmodels 1.0
import Organizer 1.0

Window  {
    id: _main
    width: 645
    height: 480
    visible: true
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width
    title: qsTr("Органайзер")

    Component.onCompleted: startupFunction();
    onClosing: { 
        if(_txtTaskName.text) { 
            _Organizer.Write = _txtTaskName.text + ";;" + _txtDeadLine.text + ";;" + _sbProgress.displayText
        }
    }

    BorderImage {
        source: "qrc:///img/background.jpg"
        anchors.fill: parent
    }

    Organizer {
        id: _Organizer
    }

    function startupFunction() {
        console.log(_Organizer.readFile())
    }

    GridLayout  {
        id: _mainGrid
        columns: 3
        rows: 4
        rowSpacing: 5
        anchors.fill: parent
        Rectangle {
            height: (_main.height*3)/4
            width: _main.width
            Layout.columnSpan: 3
            Layout.rowSpan: 1
            Layout.row: 0
            Layout.column: 0

            TableModel{
                id: _myTable
                TableModelColumn { display: "Name" }
                TableModelColumn { display: "DeadLine" }
                TableModelColumn { display: "Progress" }
                rows:[
                    {
                        Name: "<b>Наименование задачи<b>",
                        DeadLine: "<b>Дата <b>",
                        Progress: "<b>Прогресс выполнения<b>"
                    }
                ]
            }

            TableView {
                id: _myTableView
                anchors.fill: parent
                model: _myTable

                delegate:  Rectangle {
                    implicitWidth: 215
                    implicitHeight: 30
                    color: "gray"
                    border.color: "black"
                    Text {
                        text: display
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                    }
                }
            }
        }

        Rectangle{
            height: 20
            Layout.row: 1
            Layout.column: 0
            Text {
                text: "<b>Наименование задачи<b>"
                font.pointSize: 10
            }
        }
        Rectangle{
            height: 20
            Layout.row: 1
            Layout.column: 1
            Text {
                text: "<b>Дата <b>"
                font.pointSize: 10
            }
        }
        Rectangle{
            height: 20
            Layout.row: 1
            Layout.column: 2
            Text {
                text: "<b>Прогресс (0-10)<b>"
                font.pointSize: 10
            }
        }

        TextField{
            id: _txtTaskName
            placeholderText: "Введите название задачи"
            horizontalAlignment: TextInput.AlignHLeft
            selectByMouse: true
            wrapMode: TextEdit.Wrap

            Layout.row: 2
            Layout.column: 0
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        TextField{
            id: _txtDeadLine
            placeholderText: "Дата : dd.mm.yyyy"
            inputMethodHints: Qt.ImhDigitsOnly
            verticalAlignment: TextInput.AlignVCenter
            horizontalAlignment: TextInput.AlignHCenter
            validator: RegularExpressionValidator { regularExpression: /^[0-9]{2}\.[0-9]{2}\.[0-9]{4}$/}

            Layout.row: 2
            Layout.column: 1
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        SpinBox{
            id: _sbProgress
            value: 0
            from: 0
            to: 10
            editable: false

            Layout.row: 2
            Layout.column: 2
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Row {
            spacing: 10
            Layout.row: 3
            Layout.column: 2

            AcceptButton {
                id: _btnOK
                ToolTip{
                    text: "Принять"
                    visible: false
                }
                width: 40
                height: 40
                onClicked: {
                    _myTable.appendRow({
                                           Name: _txtTaskName.text,
                                           DeadLine: _txtDeadLine.text,
                                           Progress: _sbProgress.displayText
                                       })
                   
                    if(_txtTaskName.text) { *_Organizer.Write = _txtTaskName.text + ";;" + _txtDeadLine.text + ";;" + _sbProgress.displayText
                    }
                }
            }

            DeleteButton {
                id: _btnDel
                ToolTip{
                    text: "Удалить"
                    visible: false
                }
                width: 40
                height: 40
                onClicked: {
                    Qt.quit() 
                }
            }
        }
    }
}
