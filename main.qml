import QtQuick 2.5
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Qt.labs.qmlmodels 1.0
import Organizer 1.0
import Organizermod 1.0

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
    }

    BorderImage {
        source: "qrc:///img/background.jpg"
        anchors.fill: parent
    }

    Organizer {
        id: _Organizer
    }

    function startupFunction() {
         _Organizermod.addObject(_Organizer.readFile())
    }

    GridLayout  {
        id: _mainGrid
        columns: 3
        rows: 4
        rowSpacing: 5
        anchors.fill: parent
        Organizermod {
            id: _Organizermod
        }
        Rectangle {
            id: _backRectangle
            height: (_main.height*3)/4
            width: _main.width
            color: "#dfd6b9"
            Layout.columnSpan: 3
            Layout.rowSpan: 1
            Layout.row: 0
            Layout.column: 0

           TableView {
                id: _OrganizermodView
                anchors.fill: parent
                clip: true
                model:  _Organizermod
                topMargin: _columnsHeader.implicitHeight

                ScrollBar.horizontal: ScrollBar{}
                ScrollBar.vertical: ScrollBar{}
                ScrollIndicator.horizontal: ScrollIndicator { }
                ScrollIndicator.vertical: ScrollIndicator { }

                onWidthChanged: _OrganizermodView.forceLayout()
                columnWidthProvider: function (column) { 
                            return _OrganezermodView.model ? _OrganezermodView.width/_OrganizermodView.model.columnCount() : 0
                        }

                rowHeightProvider: function (Row) {
                return textId.height
                }
                
                delegate:  Rectangle {
                    border{
                        color: 'black'
                        width: 1
                    }
                    color: "#dfd6b9"
                    Text {
                        id: textId
                        text: display
                        anchors.fill: parent
                        anchors.margins: 10
                        color: 'black'
                        font.pixelSize: 16
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        wrapMode: Text.WordWrap 
                        onContentHeightChanged: {
                            textId.height = contentHeight
                    
                        }
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            console.log("proba:" + textId.text)
                        }
                    }
                }
    Row 
    {
         id: _columnsHeader
         y: _OrganizermodView.contentY
         z: 2
                    Repeater 
                    {
                        model: _OrganizermodView.columns > 0 ? _OrganizermodView.columns : 1
                        Label 
                        {
                            width: _backRect.width/_OrganizermodView.columns
                            height: 35
                            text: _Organizermod.headerData(modelData, Qt.Horizontal)
                            color: 'black'

                            font.pixelSize: 15
                            padding: 10
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            background: Rectangle 
                            {
                                radius: 5
                            }
                        }
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
                    if(_txtTaskName.text.length != 0 &&
                            _txtDeadLine.text.length == 10 &&
                            _sbProgress.displayText.length != 0) {*_Organizer.Write = _txtTaskName.text + ";;" + _txtDeadLine.text + ";;" + _sbProgress.displayText
                    _Organizermod.addObject(_txtTaskName.text, _txtDeadLine.text, _sbProgress.displayText)
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
                            
                            
             
