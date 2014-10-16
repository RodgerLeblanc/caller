import bb.cascades 1.3

Sheet {
    id: settingsSheet

    Page {
        titleBar: TitleBar {
            title: qsTr("Settings")
            acceptAction: ActionItem {
                title: qsTr("Ok")
                onTriggered: {
                    settingsSheet.close()
                }
            }
        }
        ScrollView {
            Container {
                layout: DockLayout {}
                horizontalAlignment: HorizontalAlignment.Fill
                Container {
                    ThemeContainer {
                        topPadding: ui.du(3)
                        leftPadding: topPadding
                        rightPadding: topPadding
                    }
                }
            }            
        }
    }         
}
